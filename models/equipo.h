#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include "jugador.h"
#include "../structures/list.h"

using namespace std;

class equipo
{
private:

    // csv
    string pais;
    string confederacion;
    string tecnico;
    unsigned short rankingFIFA;
    unsigned short golesFavorHist;
    unsigned short golesContraHist;
    unsigned short partidosGanadosHist;
    unsigned short partidosEmpatadosHist;
    unsigned short partidosPerdidosHist;

    // Torneo
    unsigned short puntosTorneo;
    unsigned short golesFavorTorneo;
    unsigned short golesContraTorneo;

    list<jugador*> plantilla;

public:

    //Constructor
    equipo(string pais, string confederacion, string tecnico, unsigned short rankingFIFA,
           unsigned short golesFavorHist, unsigned short golesContraHist, unsigned short partidosGanadosHist,
           unsigned short partidosEmpatadosHist, unsigned short partidosPerdidosHist);

    // Destructor
    ~equipo();

    // Getters
    string getPais() const;
    string getConfederacion() const;
    string getTecnico() const;

    unsigned short getRankingFIFA() const;

    short getGolesFavorTorneo() const;
    short getGolesContraTorneo() const;
    unsigned short getPuntosTorneo() const;

    unsigned short getGanadosHist() const;
    unsigned short getEmpatadosHist() const;
    unsigned short getPerdidosHist() const;

    unsigned short getGolesFavorHist() const;
    unsigned short getGolesContraHist() const;
    short getDiferenciaGoles() const;

    // Funciones
    void sumPuntos(unsigned short puntos);
    void registerResult(short golesFavor, short golesContra);

    // Reiniciar entre pruebas
    void restartStatsTorneo();

    list<jugador*>& getPlantilla();
};

#endif // EQUIPO_H
