#include "grupo.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

grupo::grupo(char id) : identificador(id) {}

char grupo::getId() const {
    return identificador;
}

list<equipo*>& grupo::getEquipos() {
    return equipos;
}

void grupo::addEquipo(equipo* equipo) {

    if (equipos.getSize() < 4)    {
        equipos.add(equipo, equipos.getSize());
    }
}

unsigned long grupo::ordenFIFA() {

    long iter = 0;
    unsigned short n = equipos.getSize();

    for (unsigned short i = 0; i < n - 1; i++) {
        for (unsigned short j = 0; j < n - i - 1; j++) {

            iter++;

            equipo* equipo1 = equipos.consult(j);
            equipo* equipo2 = equipos.consult(j + 1);

            // Usaremos la sobrecarga del operador, toca revisar
            if ((*equipo2).operator<(*equipo1)) {
                equipos.replace(equipo2, j);
                equipos.replace(equipo1, j + 1);
            }
        }
    }
    return iter;
}

void grupo::printTablaPosiciones() {
    cout << "Grupo " << identificador << ":" << endl;

    // Encabezado
    cout << "  " << left
         << setw(22) << "Pais"
         << setw(6)  << "Pts"
         << setw(6)  << "GF"
         << setw(6)  << "GC"
         << "Dif" << endl;

    for (unsigned int i = 0; i < equipos.getSize(); i++) {
        equipo* e = equipos.consult(i);


        short dif = e->getDiferenciaGoles();
        string difConSigno = (dif > 0 ? "+" : "") + to_string(dif);


        cout << "  " << left
             << setw(22) << e->getPais()
             << setw(6)  << e->getPuntosTorneo()
             << setw(6)  << e->getGolesFavorTorneo()
             << setw(6)  << e->getGolesContraTorneo()
             << setw(6)  << difConSigno << endl;
    }
    cout << endl;
}
