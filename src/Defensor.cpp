#include "Defensor.h"

Defensor::Defensor(int _vida_maxima, int _custo, double _tempo_recarga, int _alcance, double _intervalo_acao) :
  Entidade(0,0,_vida_maxima), custo(_custo), tempo_recarga(_tempo_recarga), recarga_restante(0),
  alcance(_alcance), intervalo_acao(_intervalo_acao), tempo_desde_ultima_acao(0), ja_agiu(false) {}

Defensor::~Defensor() {}

int Defensor::get_custo() const {
    return custo;
}  

int Defensor::get_alcance() const {
    return alcance;
}

int Defensor::get_coluna() const {
    return coluna;
}

int Defensor::get_recarga_restante() const {
    return recarga_restante;
}

int Defensor::get_tempo_recarga() const {
    return tempo_recarga;
}


bool Defensor::pode_comprar() const {
  return recarga_restante == 0;
}

void Defensor::iniciar_recarga_de_compra() {
    recarga_restante = tempo_recarga;
}

void Defensor::avancar_recarga_compra() {
    if(recarga_restante > 0)
      recarga_restante--;
}