#include <iostream>
#include "main/UdeaWorldCup.h"

using namespace std;

// Variable global usada por list.h
unsigned long memGlobalNodos = 0;

int main() {


    cout << "test" << endl;

    UdeaWorldCup mundial;


    cout << "Cargando archivo\n" << endl;
    mundial.loadData();
    cout << "ok" << endl;


    cout << "\nSorteo\n" << endl;
    mundial.sorteoPartidos();
    cout << "ok" << endl;



    cout << "fase grupos\n" << endl;
    mundial.simularFaseGrupos();
    cout << "ok" << endl;

    cout << "eliminatorias" << endl;
    mundial.simularEliminatorias();
    cout << "ok" << endl;

    cout << "finales????" << endl;
    cout << "finales?????\n" << endl;
    mundial.showStatsTorneo();
    cout << "ok" << endl;

    return 0;
}
