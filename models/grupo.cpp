#include "grupo.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

grupo::grupo(char id) : identificador(id) {}

char grupo::getIdentificador() const { return identificador; }

list<equipo*>& grupo::getEquipos() { return equipos; }

void grupo::agregarEquipo(equipo* e) {

    if (equipos.getSize() < 4)    {
        equipos.add(e, equipos.getSize());
    }
}

long grupo::ordenFIFA() {
    long iter = 0;
    unsigned int n = equipos.getSize();

    for (unsigned int i = 0; i < n - 1; i++) {
        for (unsigned int j = 0; j < n - i - 1; j++) {
            iter++;

            equipo* e1 = equipos.consult(j);
            equipo* e2 = equipos.consult(j + 1);

            // Usaremos la sobrecarga del operador, toca revisar

            if (*e2 < *e1) {

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
