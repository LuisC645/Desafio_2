#ifndef UDEAWORLDCUP_H
#define UDEAWORLDCUP_H

#include "../structures/list.h"
#include "../models/equipo.h"
#include "../models/grupo.h"
#include "../models/partido.h"

class UdeaWorldCup
{
private:
    list<grupo*> grupos;
    list<equipo*> selecciones;
    list<partido*> partidos;
    list<equipo*> clasificados;
    unsigned long totalIteraciones;

    void recursos();
    void sortEquiposRank();
    void showGoleadores();
    void showConfederaciones();

public:
    // Constructor
    UdeaWorldCup();

    // Destructor
    ~UdeaWorldCup();

    // Funciones
    void loadData();
    void sorteoPartidos();
    void simularFaseGrupos();
    void simularEliminatorias();
    void showStatsTorneo();

};

#endif // UDEAWORLDCUP_H
