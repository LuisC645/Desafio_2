#include <iostream>
#include "main/UdeaWorldCup.h"

using namespace std;

// Variable global usada por list.h
unsigned long memGlobalNodos = 0;

int main() {


    cout << "-----------------UdeAWorldCup---------------" << endl;

    UdeaWorldCup mundial;

    cout << "Cargando archivo" << endl;
    mundial.loadData();

    // Imprimir selecciones
    cout << "\nListado de selecciones convocadas: "<< endl;
    list<equipo*>& equipos = mundial.getSelecciones();

    for(unsigned short i = 0; i < equipos.getSize(); i++) {

        cout << equipos[i]->getPais()
        << " - Ranking FIFA: "
        << equipos[i]->getRankingFIFA()
        << endl;
    }

    cout << "\n-------- SORTEO ---------" << endl;
    mundial.sorteoPartidos();

    cout << "\n-------- FASE DE GRUPOS ---------" << endl;
    mundial.simularFaseGrupos();

    cout << "\n-------- ELIMINATORIAS ---------" << endl;
    mundial.simularEliminatorias();

    mundial.showStatsTorneo();

}
