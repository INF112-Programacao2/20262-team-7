#include "Projetil.h"
#include "Tabuleiro.h"
#include "Inimigo.h"
#include <cmath>

Projetil::Projetil(int _linha, double _coluna, double _velocidade, int _dano, int _total_colunas) :
  linha(_linha), coluna(_coluna), velocidade(_velocidade), dano(_dano),
  total_colunas(_total_colunas), ativo(true) {}

void Projetil::mover() {
  if (!ativo)
    return;

  coluna += velocidade;
  if (coluna >= total_colunas)
    ativo = false;
}

void Projetil::detectar_colisao(Tabuleiro& tabuleiro) {
  if (!ativo)
    return;

  for (Inimigo* inimigo : tabuleiro.get_inimigos_na_linha(linha)) {
    // Mesma posição: menos de meia coluna de distância
    bool mesma_posicao = std::abs(inimigo->get_coluna() - coluna) < 0.5;
    if (inimigo->esta_viva() && inimigo->get_coluna() < total_colunas && mesma_posicao) {
      inimigo->receber_dano(dano);
      ativo = false;
      return;
    }
  }
}

bool Projetil::esta_ativo() const {
  return ativo;
}

int Projetil::get_linha() const {
  return linha;
}

double Projetil::get_coluna() const {
  return coluna;
}

double Projetil::get_velocidade() const {
  return velocidade;
}

int Projetil::get_dano() const {
  return dano;
}
