#ifndef EstadoVitoria_h
#define EstadoVitoria_h
 
#include "EstadoPartidaIF.h"
 
class Partida;
 
// Estado final: nenhuma transição é permitida
class EstadoVitoria : public EstadoPartidaIF {
private:
    Partida* partida;
 
public:
    EstadoVitoria(Partida* partida);
 
    void iniciarPartida() override;
    void pausarPartida() override;
    void retomarPartida() override;
    void finalizarPartida() override;
};
 
#endif // EstadoVitoria_h
 