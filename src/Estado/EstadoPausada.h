#ifndef EstadoPausada_h
#define EstadoPausada_h
 
#include "EstadoPartidaIF.h"
 
class Partida;
 
class EstadoPausada : public EstadoPartidaIF {
private:
    Partida* partida;
 
public:
    EstadoPausada(Partida* partida);
 
    void iniciarPartida() override;
    void pausarPartida() override;
    void retomarPartida() override;
    void finalizarPartida() override;
};
 
#endif // EstadoPausada_h
 