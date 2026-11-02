#include "EstadoEmAndamento.h"
#include "EstadoPausada.h"
#include "EstadoDerrota.h"
#include "Partida.h"
 
EstadoEmAndamento::EstadoEmAndamento(Partida* partida) : partida(partida) {
}
 
void EstadoEmAndamento::iniciarPartida() {
    // Já está em andamento
}
 
void EstadoEmAndamento::pausarPartida() {
    // Atenção: setEstado apaga este objeto, então deve ser a última instrução
    partida->setEstado(new EstadoPausada(partida));
}
 
void EstadoEmAndamento::retomarPartida() {
    // Já está em andamento
}
 
void EstadoEmAndamento::finalizarPartida() {
    // Encerramento manual conta como derrota
    partida->setEstado(new EstadoDerrota(partida));
}
 