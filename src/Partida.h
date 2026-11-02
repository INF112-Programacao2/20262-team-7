#ifndef Partida_h
#define Partida_h
#include "EstadoPartidaIF.h"
class Partida : public EstadoPartidaIF {
    private:
    EstadoPartidaIF* estadoAtual;
    float tempoDecorrido;
    public:
    Partida();
    ~Partida();
    void executarCiclo();
    void setEstado(EstadoPartidaIF* estado);
    void iniciarPartida();
    void pausarPartida();
    void retomarPartida();
    void finalizarPartida();
};
#endif // Partida_h