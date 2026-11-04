#include "Projetil.h"

Projetil::Projetil(int _linha, double _coluna, double _velocidade, int _dano, int _total_colunas) :
  linha(_linha), coluna(_coluna), velocidade(_velocidade), dano(_dano),
  total_colunas(_total_colunas), ativo(true) {}

// Avança um passo. Ao passar da última coluna, deixa de estar ativo e não anda mais.
void Projetil::mover() {
  if (!ativo)
    return;

  coluna += velocidade;
  if (coluna >= total_colunas)
    ativo = false;
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
