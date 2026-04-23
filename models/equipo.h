#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include "jugador.h"

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

public:

    //Constructor
    equipo(string pais, string tecnico, unsigned short rankingFIFA,
           unsigned short golesFavorHist, unsigned short golesContraHist, unsigned short partidosGanadosHist,
           unsigned short partidosEmpatadosHist, unsigned short partidosPerdidosHist);

    // Destructor
    ~equipo();

    // Getters
    string getPais() const;
    string getConfederacion() const;
    string getTecnico() const;

    unsigned short getRankingFIFA() const;
    unsigned short getPuntosTorneo() const;
    unsigned short getGolesFavorTorneo() const;
    unsigned short getGolesContraTorneo() const;
    unsigned short getGanadosHist() const;
    unsigned short getEmpatadosHist() const;
    unsigned short getPerdidosHist() const;

    short getGolesFavorHist() const;
    short getGolesContraHist() const;
    short getDiferenciaGoles() const;

    // Funciones
    void sumPuntos(unsigned short puntos);
    void registerResult(unsigned short golesFavor, unsigned short golesContra);

    // Reiniciar entre pruebas
    void restartStatsTorneo();

};

#endif // EQUIPO_H
