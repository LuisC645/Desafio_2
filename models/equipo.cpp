#include "equipo.h"


equipo::equipo(string pais, string tecnico, unsigned short rankingFIFA,
               unsigned short golesFavorHist, unsigned short golesContraHist, unsigned short partidosGanadosHist,
               unsigned short partidosEmpatadosHist, unsigned short partidosPerdidosHist):

    pais(pais), tecnico(tecnico), rankingFIFA(rankingFIFA), golesFavorHist(golesFavorHist),
    golesContraHist(golesContraHist), partidosGanadosHist(partidosGanadosHist),
    partidosEmpatadosHist(partidosEmpatadosHist), partidosPerdidosHist(partidosPerdidosHist),
    puntosTorneo(0), golesFavorTorneo(0), golesContraTorneo(0){

    for(int i=1; i <= 26; i++){

        if(i == 1 || i == 12 || i == 23){
            string pos = "Portero";
        } else if(i <= 8){
            string pos = "Defensa";
        } else if(i <= 18){
            string pos = "Mediocampista";
        } else{
            string pos = "Delantero";
        }

        string nameJugador = "Jugador_" + to_string(i) + "_" + pais;
        // falta agregar logica para memoria (guardar pos memoria jugador)
    }
}

// Destructor
// Falta agregar logica para eliminar

// Getters
string equipo::getPais() const {
    return pais;
}
string equipo::getConfederacion() const {
    return confederacion;
}
unsigned short equipo::getRankingFIFA() const {
    return rankingFIFA;
}
string equipo::getTecnico() const {
    return tecnico;
}
unsigned short equipo::getPuntosTorneo() const {
    return puntosTorneo;
}
unsigned short equipo::getGolesFavorTorneo() const {
    return golesFavorTorneo;
}
unsigned short equipo::getGolesContraTorneo() const {
    return golesContraTorneo;
}
short equipo::getDiferenciaGoles() const {
    return (unsigned short)golesFavorTorneo - (unsigned short)golesContraTorneo;
}
short equipo::getGolesFavorHist() const {
    return golesFavorHist;
}

// Funciones
void equipo::sumPuntos(unsigned short puntos) {
    puntosTorneo += puntos;
}
void equipo::registerResult(unsigned short golesFavor, unsigned short golesContra) {
    golesFavorTorneo += golesFavor;
    golesContraTorneo += golesContra;
}
void equipo::restartStatsTorneo() {
    puntosTorneo = 0;
    golesFavorTorneo = 0;
    golesContraTorneo = 0;
}
