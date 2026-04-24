#include "jugador.h"

// Constructor
jugador::jugador(string nombre, string posicion, unsigned short dorsal):
    nombre(nombre), posicion(posicion), dorsal(dorsal),
    golesPartido(0), amarillasPartido(0), rojasPartido(0),
    faltasPartido(0), minutosPartido(0), golesTotales(0), rojasTotales(0) {}


// Getters
string jugador::getName() const{
    return nombre;
}
string jugador::getPos() const{
    return posicion;
}
unsigned short jugador::getDor() const {
    return dorsal;
}

// Getters Partido
unsigned short jugador::getGolesPartido() const {
    return golesPartido;
}
unsigned short jugador::getAmarillasPartido() const {
    return amarillasPartido;
}
unsigned short jugador::getRojasPartido() const {
    return rojasPartido;
}
unsigned short jugador::getFaltasPartido() const {
    return faltasPartido;
}
unsigned int jugador::getMinutosPartido() const {
    return minutosPartido;
}
unsigned short jugador::getGolesTotales() const {
    return golesTotales;
}

// Funciones
void jugador::registerGol(){
    golesPartido ++;
    golesTotales ++;
}
void jugador::registerAmarilla() {
    amarillasPartido++;
    if (amarillasPartido == 2 && rojasPartido == 0) {
        registerRoja();
    }
}
void jugador::registerRoja() {
    rojasPartido = 1;
    rojasTotales++;
}
void jugador::registerFalta() {
    faltasPartido++;
}
void jugador::setMinPartido(unsigned short min) {
    minutosPartido = min;
}

// Reiniciar partido
void jugador::restartStatsPartido() {
    golesPartido = 0;
    amarillasPartido = 0;
    rojasPartido = 0;
    faltasPartido = 0;
    minutosPartido = 0;
}
