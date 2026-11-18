#include "PrazoDeEntrega.h"

// Valores provisórios. Vida e dano seguem a tabela do README.
// Os tempos estão em passos (10 passos = 1 segundo).
static const int VIDA = 50;
static const double VELOCIDADE = 0.0625; // colunas por passo
static const int DANO = 10;
static const int INTERVALO_DE_ATAQUE = 10;
static const int RECOMPENSA = 15;

PrazoDeEntrega::PrazoDeEntrega(int _linha, double _coluna) :
  Inimigo(_linha, _coluna, VIDA, VELOCIDADE, DANO, INTERVALO_DE_ATAQUE, RECOMPENSA) {}

std::string PrazoDeEntrega::get_nome() const {
  return "Prazo de Entrega";
}
