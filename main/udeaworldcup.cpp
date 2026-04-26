#include "udeaworldcup.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

UdeaWorldCup::UdeaWorldCup() : totalIteraciones(0), campeon(nullptr), subcampeon(nullptr), tercero(nullptr), cuarto(nullptr){
    srand(time(0) + rand());
}

UdeaWorldCup::~UdeaWorldCup() {
    for (unsigned short i = 0; i < grupos.getSize(); i++) {
        delete grupos.consult(i);
    }
    for (unsigned short i = 0; i < partidos.getSize(); i++){
        delete partidos.consult(i);
    }
    for (unsigned short i = 0; i < selecciones.getSize(); i++) {
        delete selecciones.consult(i);
    }
}

void UdeaWorldCup::recursos() {

    unsigned long memObjetos = (selecciones.getSize() * sizeof(equipo)) + (selecciones.getSize() * 26 * sizeof(jugador));

    cout << "Medicion de recursos" << endl;
    cout << "Iteraciones acumuladas: " << totalIteraciones << endl;
    cout << "Memoria nodos (listas): " << memGlobalNodos << " bytes" << endl;
    cout << "Memoria objetos: " << memObjetos << " bytes" << endl;
    cout << "TOTAL: " << (memGlobalNodos + memObjetos) / 1024.0 << " KB" << endl;
    cout << "----------------------------\n" << endl;

}

void UdeaWorldCup::loadData(){
    ifstream data("data/selecciones.csv");
    string line;
    string pais;
    string conf;
    string rank;
    string tecnico;
    string golesFavorHist;
    string golesContraHist;
    string partidosGanadosHist;
    string partidosEmpatadosHist;
    string partidosPerdidosHist;

    while(getline(data, line)){

        if(line.empty()){
            continue;
        }

        stringstream str(line);

        getline(str, pais, ',');
        getline(str, conf, ',');
        getline(str, rank, ',');
        getline(str, tecnico, ',');
        getline(str, golesFavorHist, ',');
        getline(str, golesContraHist, ',');
        getline(str, partidosGanadosHist, ',');
        getline(str, partidosEmpatadosHist, ',');
        getline(str, partidosPerdidosHist, ',');

        selecciones.add(new equipo(pais, conf, tecnico, stoi(rank), stoi(golesFavorHist), stoi(golesContraHist),
                                   stoi(partidosGanadosHist), stoi(partidosEmpatadosHist), stoi(partidosPerdidosHist)),
                        selecciones.getSize());

        totalIteraciones++;
    }

    cout << "Cargadas " << selecciones.getSize() << " selecciones." << endl;
    recursos();

};

void UdeaWorldCup::sorteoPartidos() {

    // Por rank
    for(unsigned int i = 0; i < 12; i++) {

        grupo* group = new grupo('A' + i);

        for(int j = 0; j < 4; j++) {
            group->addEquipo(selecciones.consult(i + (j * 12)));
            totalIteraciones++;
        }

        grupos.add(group, grupos.getSize());
    }

    cout << "Sorteo listo" << endl;
}

void UdeaWorldCup::simularFaseGrupos(){

    cout << "FASE DE GRUPOS (72 Partidos)" << endl;
    string arb[3] = {"Arbitro 1", "Arbitro 2", "Arbitro 3"};

    for (unsigned short i = 0; i < grupos.getSize(); i++) {
        grupo* grupo = grupos.consult(i);
        list<equipo*>& equipos = grupo->getEquipos();

        for (unsigned short j = 0; j < 4; j++) {
            for (unsigned short k = j + 1; k < 4; k++) {
                partido* part = new partido("Junio 2026", "12:00", "UdeA", arb, equipos.consult(j), equipos.consult(k), false, false);
                part->simular();
                part->printResultado();
                partidos.add(part, partidos.getSize());
                totalIteraciones += 50;
            }
        }

        grupo->ordenFIFA();
        grupo->printTablaPosiciones();
        // Faltan iteraciones?

        clasificados.add(equipos.consult(0), clasificados.getSize());
        clasificados.add(equipos.consult(1), clasificados.getSize());

        recursos();

    }
}


void UdeaWorldCup::simularEliminatorias() {

    list<equipo*>* rondaActual = new list<equipo*>;

    for(unsigned short i = 0; i < clasificados.getSize(); i++) {
        rondaActual->add(clasificados.consult(i), rondaActual->getSize());
    }

    string arb[3] = {"A1", "A2", "A3"};

    while(rondaActual->getSize() > 1) {

        unsigned short cantidadEquipos = rondaActual->getSize();
        unsigned short cantidadPartidos = cantidadEquipos / 2;

        if(cantidadEquipos == 32) {
            cout << "\nDIECISEISAVOS" << endl;
        } else if(cantidadEquipos == 16) {
            cout << "\nOCTAVOS" << endl;
        } else if(cantidadEquipos == 8) {
            cout << "\nCUARTOS" << endl;
        } else if(cantidadEquipos == 4) {
            cout << "\nSEMIFINAL" << endl;
        } else if(cantidadEquipos == 2) {
            cout << "\nFINAL" << endl;
        }

        list<equipo*>* siguienteRonda = new list<equipo*>;

        equipo* semiPerdedor1 = nullptr;
        equipo* semiPerdedor2 = nullptr;

        for(unsigned short j = 0; j < cantidadPartidos; j++) {

            equipo* local = rondaActual->consult(j * 2);
            equipo* visitante = rondaActual->consult(j * 2 + 1);

            partido* part = new partido("Julio 2026", "20:00", "Anastasio", arb, local, visitante, true, false);

            part->simular();
            part->printResultado();

            partidos.add(part, partidos.getSize());

            equipo* ganador;
            equipo* perdedor;

            if(part->getGolesL() > part->getGolesV()) {
                ganador = local;
                perdedor = visitante;
            } else {
                ganador = visitante;
                perdedor = local;
            }

            siguienteRonda->add(ganador, siguienteRonda->getSize());

            if(cantidadEquipos == 4) {
                if(j == 0) {
                    semiPerdedor1 = perdedor;
                } else {
                    semiPerdedor2 = perdedor;
                }
            }

            if(cantidadEquipos == 2) {
                cout << "ENTRO A FINAL" << endl;
                campeon = ganador;
                subcampeon = perdedor;
            }

            totalIteraciones += 100;
        }

        if(cantidadEquipos == 4) {

            cout << "\nTERCER PUESTO" << endl;

            partido* tercerLugar = new partido("Julio 2026", "18:00", "Anastasio", arb, semiPerdedor1, semiPerdedor2, true, false);

            tercerLugar->simular();
            tercerLugar->printResultado();

            partidos.add(tercerLugar, partidos.getSize());

            if(tercerLugar->getGolesL() > tercerLugar->getGolesV()) {
                tercero = semiPerdedor1;
                cuarto = semiPerdedor2;
            } else {
                tercero = semiPerdedor2;
                cuarto = semiPerdedor1;
            }

            totalIteraciones += 100;
        }

        delete rondaActual;
        rondaActual = siguienteRonda;
    }

    cout << "\nCAMPEON DEL MUNDIAL: " << campeon->getPais() << endl;

    recursos();

    delete rondaActual;
}


void UdeaWorldCup::showStatsTorneo() {

    cout << "\nESTADISTICAS FINALES DEL TORNEO" << endl;

    // podio
    cout << "\nPODIO:" << endl;

    cout << "Oro: " << campeon->getPais() << endl;
    cout << "Plata: " << subcampeon->getPais() << endl;
    cout << "Bronce: " << tercero->getPais() << endl;
    cout << "Diplomita uwu: " << cuarto->getPais() << endl;

    // goleador
    jugador* mejor = campeon->getPlantilla().consult(0);

    for(unsigned short i = 1; i < 26; i++) {

        jugador* actual = campeon->getPlantilla().consult(i);

        if(actual->getGolesTotales() > mejor->getGolesTotales()) {
            mejor = actual;
        }
    }

    cout << "\nGOLEADOR DEL CAMPEON: " << mejor->getName() << " (" << mejor->getGolesTotales() << " goles)" << endl;

    // Equipo mas goles hist
    equipo* mejorHistorico = selecciones.consult(0);

    for(unsigned short i = 1; i < selecciones.getSize(); i++) {

        equipo* actual = selecciones.consult(i);
        int golesActual = actual->getGolesFavorHist() + actual->getGolesFavorTorneo();
        int golesMejor = mejorHistorico->getGolesFavorHist() + mejorHistorico->getGolesFavorTorneo();

        if(golesActual > golesMejor) {
            mejorHistorico = actual;
        }
    }

    cout << "\nMAS GOLES HISTORICOS ACTUALIZADOS: " << mejorHistorico->getPais() << " ("
         << mejorHistorico->getGolesFavorHist() + mejorHistorico->getGolesFavorTorneo() << ")" << endl;

    // confederacion
    int uefa = 0;
    int conmebol = 0;
    int concacaf = 0;
    int caf = 0;
    int afc = 0;

    for(unsigned short i = 0; i < clasificados.getSize(); i++) {

        string conf = clasificados.consult(i)->getConfederacion();

        if(conf == "UEFA") {
            uefa++;
        } else if(conf == "CONMEBOL") {
            conmebol++;
        } else if(conf == "CONCACAF") {
            concacaf++;
        } else if(conf == "CAF") {
            caf++;
        } else if(conf == "AFC") {
            afc++;
        }
    }

    string dominante = "UEFA";
    int mayor = uefa;

    if(conmebol > mayor) {
        mayor = conmebol;
        dominante = "CONMEBOL";
    }
    if(concacaf > mayor) {
        mayor = concacaf;
        dominante = "CONCACAF";
    }
    if(caf > mayor) {
        mayor = caf;
        dominante = "CAF";
    }
    if(afc > mayor) {
        mayor = afc;
        dominante = "AFC";
    }

    cout << "\nMEJOR CONFEDERACION: " << dominante << " (" << mayor << " equipos clasificados)" << endl;
    recursos();
}
