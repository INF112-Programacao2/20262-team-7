#include "Inimigo.h"

Inimigo::Inimigo (int linha, double coluna, int vida_maxima,
 double _velocidade, int _dano, int _intervalo_ataque, int _recompensa) :
    Entidade(linha,coluna,vida_maxima), velocidade(_velocidade), dano(_dano) ,intervalo_ataque(_intervalo_ataque),
    tempo_desde_ataque(0), recompensa(_recompensa), ataques_realizados(0), alcancou_nucleo(false), atacando(false) {}


Inimigo::~Inimigo() {}

bool Inimigo::eh_chefe() {
  return false;
}

double Inimigo::get_velocidade() const {
  return velocidade;
}

int Inimigo::get_dano() const {
  return dano;
}

int Inimigo::get_recompensa() const {
    return recompensa;
}
bool Inimigo::chegou_ao_nucleo() {
    return alcancou_nucleo;
}
bool Inimigo::esta_atacando() {
    return atacando;
}

int Inimigo::get_ataques_realizados() {
    return ataques_realizados;
}

void Inimigo::set_velocidade(double nova_velocidade) {
  velocidade=nova_velocidade;
}

void Inimigo::aplicar_reforco(double fator) {
  this->vida*=fator;
  this->vida_maxima*=fator;
}
