#include "EstadoPausada.h"
#include "EstadoEmAndamento.h"
#include "EstadoDerrota.h"
#include "Partida.h"
 
EstadoPausada::EstadoPausada(Partida* partida) : partida(partida) {
}
 
void EstadoPausada::iniciarPartida() {
    // A partida já foi iniciada; use retomarPartida()
}
 
void EstadoPausada::pausarPartida() {
    // Já está pausada
}
 
void EstadoPausada::retomarPartida() {
    // Atenção: setEstado apaga este objeto, então deve ser a última instrução
    partida->setEstado(new EstadoEmAndamento(partida));
}
 
void EstadoPausada::finalizarPartida() {
    // Encerramento manual conta como derrota
    partida->setEstado(new EstadoDerrota(partida));
}
 