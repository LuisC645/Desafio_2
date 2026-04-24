#include <iostream>
#include <ctime>
#include <cstdlib>

#include "models/equipo.h"
#include "models/partido.h"

using namespace std;

// Variable global usada por list.h
unsigned long memGlobalNodos = 0;

int main() {

    srand(time(NULL));

    cout << "TEST" << endl;

    equipo colombia(
        "Colombia",
        "LATAM",
        "el tigre",
        90,
        0,
        200,
        1,
        2,
        200
        );

    equipo brasil(
        "Brasil",
        "KAKA",
        "silva",
        1,
        100,
        40,
        110,
        15,
        16
        );

    cout << "Equipos melos" << endl;


    for(unsigned short i = 0; i < 5; i++) {

        jugador* j = colombia.getPlantilla().consult(i);

        cout << "#"
             << j->getDor()
             << " - "
             << j->getName()
             << " - "
             << j->getPos()
             << endl;
    }

    string arbitros[3] = {
        "lucho",
        "bolo",
        "garza"
    };

    // partido

    partido p1(
        "15/07/2026",
        "18:00",
        "la curva",
        arbitros,
        &colombia,
        &brasil,
        false,
        false
        );

    cout << "partido melo" << endl;

    // simular
    cout << "conectando con betplay" << endl;

    p1.simular();

    cout << "Resultados" << endl;

    p1.printResultado();

    // =====================================
    // Tabla rápida
    // =====================================

    cout << "======================================" << endl;

    cout << colombia.getPais()
         << " | Pts: " << colombia.getPuntosTorneo()
         << " | GF: " << colombia.getGolesFavorTorneo()
         << " | GC: " << colombia.getGolesContraTorneo()
         << " | DG: " << colombia.getDiferenciaGoles()
         << endl;

    cout << brasil.getPais()
         << " | Pts: " << brasil.getPuntosTorneo()
         << " | GF: " << brasil.getGolesFavorTorneo()
         << " | GC: " << brasil.getGolesContraTorneo()
         << " | DG: " << brasil.getDiferenciaGoles()
         << endl;

    cout << "\nMemoria nodos usada: "
         << memGlobalNodos
         << " bytes" << endl;

    cout << "Gracias guerreros" << endl;

    return 0;
}
