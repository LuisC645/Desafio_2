#ifndef PARTIDO_H
#define PARTIDO_H

#include <string>
#include "equipo.h"

using namespace std;

class partido
{
private:

    string fecha;
    string hora;
    string sede;
    string arbitros[3];

    equipo* local;
    equipo* visitante;

    unsigned short golesL;
    unsigned short golesV;
    unsigned short posesionL;
    bool eliminatoria;
    bool prorroga;

public:
    // constructor
    partido(string fecha, string hora, string sede, string arbitros[3],
            equipo* local, equipo* visitante, bool eliminatoria = false, bool prorroga = false);

    // Getters
    equipo* getLocal() const;
    equipo* getVisitante() const;

    unsigned short getGolesL() const;
    unsigned short getGolesV() const;

    // Funciones
    void simular();
    void procesarEquipo(equipo* equipo, unsigned short golesMarcados, unsigned short minutos);
    void printResultado();
    void printTablaJugadores(equipo* equipo);

};

#endif // PARTIDO_H
