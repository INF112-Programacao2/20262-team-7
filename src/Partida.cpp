#include "Partida.h"
#include "EstadoNaoIniciada.h"
#include "EstadoVitoria.h"
#include "EstadoDerrota.h"
 
Partida::Partida() : estadoAtual(nullptr), tempoDecorrido(0.0f) {
    estadoAtual = new EstadoNaoIniciada(this);
}
 
Partida::~Partida() {
    // A Partida é dona do estado atual
    delete estadoAtual;
    estadoAtual = nullptr;
}
 
void Partida::executarCiclo() {
    // TODO: atualizar tabuleiro, ondas, economia etc. quando essas classes existirem
    // TODO: somar o delta de tempo em tempoDecorrido (só quando a partida estiver em andamento)
}
 
void Partida::setEstado(EstadoPartidaIF* estado) {
    if (estado == estadoAtual) {
        return;
    }
    delete estadoAtual;
    estadoAtual = estado;
}
 
EstadoPartidaIF* Partida::getEstado() const {
    return estadoAtual;
}
void Partida::iniciarPartida() {
    if (estadoAtual) {
        estadoAtual->iniciarPartida();
    }
}
 
void Partida::pausarPartida() {
    if (estadoAtual) {
        estadoAtual->pausarPartida();
    }
}
 
void Partida::retomarPartida() {
    if (estadoAtual) {
        estadoAtual->retomarPartida();
    }
}
 
void Partida::finalizarPartida() {
    if (estadoAtual) {
        estadoAtual->finalizarPartida();
    }
}
 
void Partida::declararVitoria() {
    setEstado(new EstadoVitoria(this));
}
 
void Partida::declararDerrota() {
    setEstado(new EstadoDerrota(this));
}
 