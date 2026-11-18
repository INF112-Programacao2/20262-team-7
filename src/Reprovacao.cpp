#include "Reprovacao.h"

// Valores provisórios. Vida e dano seguem a tabela do README.
// Os tempos estão em passos (10 passos = 1 segundo).
static const int VIDA = 150;
static const double VELOCIDADE = 0.03125; // colunas por passo
static const int DANO = 25;
static const int INTERVALO_DE_ATAQUE = 15;
static const int RECOMPENSA = 50;

Reprovacao::Reprovacao(int _linha, double _coluna) :
  Inimigo(_linha, _coluna, VIDA, VELOCIDADE, DANO, INTERVALO_DE_ATAQUE, RECOMPENSA) {}

std::string Reprovacao::get_nome() const {
  return "Reprovação";
}

bool Reprovacao::eh_chefe() {
  return true;
}
