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
    EstadoPartidaIF* getEstado() const;
    void iniciarPartida() override;
    void pausarPartida() override;
    void retomarPartida() override;
    void finalizarPartida() override;
 
    // Usados pela lógica do jogo para encerrar a partida
    void declararVitoria();
    void declararDerrota();
};
 
#endif // Partida_h
 