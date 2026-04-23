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
            equipo* local, equipo* vis, bool eliminatoria = false, bool prorroga = false);

    // Getters
    equipo* getLocal() const;
    equipo* getVisitante() const;

    // Funciones
    void simular();
    void printResultado();

};

#endif // PARTIDO_H
