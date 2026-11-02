#include "EstadoNaoIniciada.h"
#include "EstadoEmAndamento.h"
#include "Partida.h"
 
EstadoNaoIniciada::EstadoNaoIniciada(Partida* partida) : partida(partida) {
}
 
void EstadoNaoIniciada::iniciarPartida() {
    // Atenção: setEstado apaga este objeto, então deve ser a última instrução
    partida->setEstado(new EstadoEmAndamento(partida));
}
 
void EstadoNaoIniciada::pausarPartida() {
    // Ação inválida neste estado
}
 
void EstadoNaoIniciada::retomarPartida() {
    // Ação inválida neste estado
}
 
void EstadoNaoIniciada::finalizarPartida() {
    // Ação inválida neste estado
}
 