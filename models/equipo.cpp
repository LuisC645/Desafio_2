#include "equipo.h"


equipo::equipo(string pais, string confederacion, string tecnico, unsigned short rankingFIFA,
               unsigned short golesFavorHist, unsigned short golesContraHist, unsigned short partidosGanadosHist,
               unsigned short partidosEmpatadosHist, unsigned short partidosPerdidosHist):

    pais(pais), confederacion(confederacion), tecnico(tecnico), rankingFIFA(rankingFIFA),
    golesFavorHist(golesFavorHist), golesContraHist(golesContraHist), partidosGanadosHist(partidosGanadosHist),
    partidosEmpatadosHist(partidosEmpatadosHist), partidosPerdidosHist(partidosPerdidosHist),
    puntosTorneo(0), golesFavorTorneo(0), golesContraTorneo(0){

    for(unsigned short i=1; i <= 26; i++){

        string pos = "";

        if(i == 1 || i == 12 || i == 23){
            pos = "Portero";
        } else if(i <= 8){
            pos = "Defensa";
        } else if(i <= 18){
            pos = "Mediocampista";
        } else{
            pos = "Delantero";
        }

        string nameJugador = "Jugador_" + to_string(i) + "_" + pais;
        plantilla.add(new jugador(nameJugador, pos, i), plantilla.getSize());

    }
}

// Destructor
equipo::~equipo(){
    for(unsigned short i = 0; i < 26; i++){
        delete plantilla.consult(i);
    }
}

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
short equipo::getGolesFavorTorneo() const {
    return golesFavorTorneo;
}
short equipo::getGolesContraTorneo() const {
    return golesContraTorneo;
}
short equipo::getDiferenciaGoles() const {
    return (unsigned short)golesFavorTorneo - (unsigned short)golesContraTorneo;
}
unsigned short equipo::getGolesFavorHist() const {
    return golesFavorHist;
}
unsigned short equipo::getGolesContraHist() const {
    return golesContraHist;
}


// Funciones
void equipo::sumPuntos(unsigned short puntos) {
    puntosTorneo += puntos;
}
void equipo::registerResult(short golesFavor, short golesContra) {
    golesFavorTorneo += golesFavor;
    golesContraTorneo += golesContra;
}
void equipo::restartStatsTorneo() {
    puntosTorneo = 0;
    golesFavorTorneo = 0;
    golesContraTorneo = 0;
}

list<jugador*>& equipo::getPlantilla(){
    return plantilla;
}


// sobrecarga rankFifa
bool equipo::operator<(const equipo& otro) const {

    // Comparar puntos
    if(puntosTorneo != otro.puntosTorneo) {
        return puntosTorneo < otro.puntosTorneo;
    }
    // Comparar diferencia de goles
    if(getDiferenciaGoles() != otro.getDiferenciaGoles()) {
        return getDiferenciaGoles() < otro.getDiferenciaGoles();
    }
    // Comparar goles a favor
    if(golesFavorTorneo != otro.golesFavorTorneo) {
        return golesFavorTorneo < otro.golesFavorTorneo;
    }
    // Comparar ranking FIFA
    return rankingFIFA > otro.rankingFIFA;
}
