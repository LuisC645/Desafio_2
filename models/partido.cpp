#include "partido.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

partido::partido(string fecha, string hora, string sede, string arb[3], equipo* local, equipo* visitante,
                 bool eliminatoria, bool prorroga):
    fecha(fecha), hora(hora), sede(sede), local(local), visitante(visitante), golesL(0), golesV(0),
    posesionL(50), eliminatoria(eliminatoria), prorroga(prorroga)
{
    for(unsigned short i = 0; i < 3; i++){
        arbitros[i] = arb[i];
    }
}

void partido::simular() {

    // Reiniciar stats partido a jugadores
    for(unsigned short i = 0; i < 26; i++) {
        local->getPlantilla().consult(i)->restartStatsPartido();
        visitante->getPlantilla().consult(i)->restartStatsPartido();
    }

    // Ranking fifa
    unsigned short rankL = local->getRankingFIFA();
    unsigned short rankV = visitante->getRankingFIFA();

    unsigned short probL = 100 - rankL;
    unsigned short probV = 100 - rankV;

    // Simular goles
    golesL = rand() % 3;
    golesV = rand() % 3;

    if(probL > probV && rand()%100 < 20){
        golesL++;
    }
    if(probV > probL && rand()%100 < 20){
        golesV++;
    }

    // Eliminatoria
    prorroga = false;

    if(eliminatoria && golesL == golesV) {
        prorroga = true;

        if(rand()%2 == 0) {
            golesL++;
        }else {
            golesV++;
        }
    }

    unsigned short minutos = 90;

    if(prorroga){
        minutos = 120;
    }

    // Posesión
    posesionL = 50 + (probL - probV)/2;

    // Procesar equipos
    procesarEquipo(local, golesL, minutos);
    procesarEquipo(visitante, golesV, minutos);

    // Tabla
    local->registerResult(golesL, golesV);
    visitante->registerResult(golesV, golesL);

    if(golesL > golesV){
        local->sumPuntos(3);
    } else if(golesV > golesL){
        visitante->sumPuntos(3);
    } else if(golesL == golesV) {
        local->sumPuntos(1);
        visitante->sumPuntos(1);
    } else {
        local->sumPuntos(0);
        visitante->sumPuntos(0);
    }
}

// Jugadores
void partido::procesarEquipo(equipo* equipo, unsigned short golesMarcados, unsigned short minutos){

    for(unsigned short i=0; i<11; i++) {

        jugador* j = equipo->getPlantilla().consult(i);

        j->setMinPartido(minutos);

        // Faltas
        if(rand()%100 < 13) {
            j->registerFalta();
        }
        if(rand()%1000 < 28) {
            j->registerFalta();
        }
        if(rand()%1000 < 7) {
            j->registerFalta();
        }

        // Tarjetas
        if(rand()%100 < 6) {
            j->registerAmarilla();
        }

        if(rand()%10000 < 115) {
            j->registerAmarilla();

            if(j->getAmarillasPartido() == 2){
                j->registerRoja();
            }
        }
    }

    // Goles
    for(unsigned short g = 0; g < golesMarcados; g++) {
        int idx = rand()%11;
        equipo->getPlantilla().consult(idx)->registerGol();
    }
}

void partido::printResultado(){

    string strPro = "";

    if(prorroga){
        strPro = " (prorroga)";
    }

    cout << "\n Partido: " << local->getPais() << " vs " << visitante->getPais() << endl;
    cout << "  Fecha: " << fecha << " | Hora: " << hora << " | Sede: " << sede << endl;
    cout << "  Resultado: " << golesL << " - " << golesV << strPro << endl;
    cout << "  Posesion: " << posesionL << "% - " << (100 - posesionL) << "%" << endl;

    printTablaJugadores(local);
    printTablaJugadores(visitante);

    // Goleadores local
    cout << "\n  Goleadores " << local->getPais() << ": ";

    bool goleadorL = false;

    for(int i=0; i<11; i++) {

        jugador* j = local->getPlantilla().consult(i);

        if(j->getGolesPartido() > 0) {
            cout << "#" << j->getDor() << "(" << j->getGolesPartido() << ") ";
            goleadorL = true;
        }
    }

    if(!goleadorL) {
        cout << "ninguno";
    }

    // Goleadores visitante
    cout << "\n  Goleadores " << visitante->getPais() << ": ";

    bool goleadorV = false;

    for(int i=0; i<11; i++) {

        jugador* j = visitante->getPlantilla().consult(i);

        if(j->getGolesPartido() > 0) {
            cout << "#" << j->getDor() << "(" << j->getGolesPartido() << ") ";
            goleadorV = true;
        }
    }

    if(!goleadorV) {
        cout << "ninguno";
    }

    cout << endl;
    cout << "  --------------------------------------------------" << endl;
}

void partido::printTablaJugadores(equipo* equipo){
    cout << "\n  Jugadores convocados "
         << equipo->getPais()
         << ":" << endl;

    cout << "  Cam  Nombre            Goles  Amarillas  Rojas  Faltas  Minutos" << endl;
    cout << "  ---------------------------------------------------------------" << endl;

    for(int i=0; i<11; i++) {

        jugador* j = equipo->getPlantilla().consult(i);

        cout << "  #"
             << left << setw(4) << j->getDor()
             << setw(18) << j->getName().substr(0,17)
             << setw(7)  << j->getGolesPartido()
             << setw(11) << j->getAmarillasPartido()
             << setw(7)  << j->getRojasPartido()
             << setw(8)  << j->getFaltasPartido()
             << j->getMinutosPartido()
             << endl;
    }
}


