#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

using namespace std;

class jugador
{
private:

    string nombre;
    string posicion;
    unsigned short dorsal;

    unsigned short golesPartido;
    unsigned short amarillasPartido;
    unsigned short rojasPartido;
    unsigned short faltasPartido;
    unsigned short minutosPartido;
    unsigned short golesTotales;
    unsigned short rojasTotales;

public:

    // Constructor
    jugador(string nombre, string posicion, unsigned short dorsal);

    // Getters
    string getName() const;
    string getPos() const;
    unsigned short getDor() const;

    //Torneo
    unsigned short getGolesPartido() const;
    unsigned short getAmarillasPartido() const;
    unsigned short getRojasPartido() const;
    unsigned short getFaltasPartido() const;
    unsigned int getMinutosPartido() const;
    unsigned short getRojasTotales() const;
    unsigned short getGolesTotales() const;

    // Funciones
    void registerGol();
    void registerAmarilla();
    void registerRoja();
    void registerFalta();
    void setMinPartido(unsigned short min);

    // Reiniciar partido
    void restartStatsPartido();

};

#endif // JUGADOR_H
