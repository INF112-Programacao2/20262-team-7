#include "ProvaSurpresa.h"

// Valores provisórios. Vida, dano e velocidade vêm da tabela do README
static const int VIDA = 25;
static const double VELOCIDADE = 20;
static const int DANO = 5;
static const int INTERVALO_DE_ATAQUE = 1;
static const int RECOMPENSA = 10;

ProvaSurpresa::ProvaSurpresa(int _linha, double _coluna) :
  Inimigo(_linha, _coluna, VIDA, VELOCIDADE, DANO, INTERVALO_DE_ATAQUE, RECOMPENSA) {}

std::string ProvaSurpresa::get_nome() const {
  return "Prova Surpresa";
}
