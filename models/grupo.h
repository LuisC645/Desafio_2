#ifndef GRUPO_H
#define GRUPO_H

#include "equipo.h"
#include "../structures/list.h"

class grupo {
private:
    char identificador;
    list<equipo*> equipos;

public:
    grupo(char id);
    char getId() const;
    list<equipo*>& getEquipos();

    void addEquipo(equipo* equipo);
    unsigned long ordenFIFA();
    void printTablaPosiciones();
};

#endif // GRUPO_H
