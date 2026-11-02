#ifndef EstadoNaoIniciada_h
#define EstadoNaoIniciada_h
 
#include "EstadoPartidaIF.h"
 
class Partida;
 
class EstadoNaoIniciada : public EstadoPartidaIF {
private:
    Partida* partida;
 
public:
    EstadoNaoIniciada(Partida* partida);
 
    void iniciarPartida() override;
    void pausarPartida() override;
    void retomarPartida() override;
    void finalizarPartida() override;
};
 
#endif // EstadoNaoIniciada_h
 