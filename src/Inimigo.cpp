#include "Inimigo.h"
#include "Defensor.h"
#include "Tabuleiro.h"
#include "ControlarPartida/Economia.h"
#include "ControlarPartida/Nucleo.h"

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

Defensor* Inimigo::defensor_a_frente(Tabuleiro& tabuleiro) {
  Defensor* mais_proximo = nullptr;
  // A lista vem em ordem de coluna, então o último encontrado é o mais próximo
  for (Defensor* defensor : tabuleiro.get_defensores_na_linha(linha))
    if (defensor->get_coluna() < coluna)
      mais_proximo = defensor;
  return mais_proximo;
}

void Inimigo::atualizar(Tabuleiro& tabuleiro, Economia&, Nucleo& nucleo) {
  if (tempo_desde_ataque < intervalo_ataque)
    tempo_desde_ataque++;

  Defensor* alvo = defensor_a_frente(tabuleiro);
  atacando = alvo != nullptr && coluna <= alvo->get_coluna() + 1;

  if (atacando) {
    if (tempo_desde_ataque >= intervalo_ataque) {
      alvo->receber_dano(dano);
      ataques_realizados++;
      tempo_desde_ataque = 0;
    }
    return;
  }

  coluna -= velocidade;
  // Não passa por cima do defensor: para encostado nele
  if (alvo != nullptr && coluna < alvo->get_coluna() + 1)
    coluna = alvo->get_coluna() + 1;

  if (coluna <= 0) {
    coluna = 0;
    nucleo.receberDano(dano);
    alcancou_nucleo = true;
  }
}

void Inimigo::creditar_recompensa(Economia& economia) {
  economia.adicionarSaldo(recompensa);
}
