#ifndef EstadoEmAndamento_h
#define EstadoEmAndamento_h
 
#include "EstadoPartidaIF.h"
 
class Partida;
 
class EstadoEmAndamento : public EstadoPartidaIF {
private:
    Partida* partida;
 
public:
    EstadoEmAndamento(Partida* partida);
 
    void iniciarPartida() override;
    void pausarPartida() override;
    void retomarPartida() override;
    void finalizarPartida() override;
};
 
#endif // EstadoEmAndamento_h
 