#include "MonitorDaTurma.h"
#include "Tabuleiro.h"

// Valores provisórios. Vida, cura e custo seguem a tabela do README.
// Os tempos estão em passos (10 passos = 1 segundo).
static const int VIDA = 50;
static const int CUSTO = 35;
static const double TEMPO_DE_RECARGA = 100;
static const int ALCANCE = 1; // só as células vizinhas
static const double INTERVALO_DA_ACAO = 50;
static const int CURA = 20;

MonitorDaTurma::MonitorDaTurma() :
  Defensor(VIDA, CUSTO, TEMPO_DE_RECARGA, ALCANCE, INTERVALO_DA_ACAO) {}

std::string MonitorDaTurma::get_nome() const {
  return "Monitor da Turma";
}

std::string MonitorDaTurma::get_descricao() const {
  return "Suporte. Cura os defensores ao seu redor.";
}

// A cada intervalo, cura os defensores vivos nas células vizinhas, inclusive nas
// diagonais. O monitor não cura a si mesmo, e a cura não passa da vida máxima.
void MonitorDaTurma::atualizar(Tabuleiro& tabuleiro, Economia&, Nucleo&) {
  if (!pronto_para_agir())
    return;

  for (int l = linha - get_alcance(); l <= linha + get_alcance(); l++)
    for (int c = get_coluna() - get_alcance(); c <= get_coluna() + get_alcance(); c++) {
      Defensor* vizinho = tabuleiro.get_defensor(l, c);
      if (vizinho != nullptr && vizinho != this && vizinho->esta_viva())
        vizinho->curar(CURA);
    }
  reiniciar_intervalo();
}
