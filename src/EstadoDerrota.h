#ifndef EstadoDerrota_h
#define EstadoDerrota_h
 
#include "EstadoPartidaIF.h"
 
class Partida;
 
// Estado final: nenhuma transição é permitida
class EstadoDerrota : public EstadoPartidaIF {
private:
    Partida* partida;
 
public:
    EstadoDerrota(Partida* partida);
 
    void iniciarPartida() override;
    void pausarPartida() override;
    void retomarPartida() override;
    void finalizarPartida() override;
};
 
#endif // EstadoDerrota_h
 