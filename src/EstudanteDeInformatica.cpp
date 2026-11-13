#include "EstudanteDeInformatica.h"
#include "Tabuleiro.h"
#include "Projetil.h"

// Valores provisórios. Os tempos estão em passos (10 passos = 1 segundo).
static const int VIDA = 50;
static const int CUSTO = 10;
static const double TEMPO_DE_RECARGA = 50;
static const int ALCANCE = 9;
static const double INTERVALO_DA_ACAO = 15;
static const int DANO = 5;
static const double VELOCIDADE_DO_PROJETIL = 0.25; // colunas por passo

EstudanteDeInformatica::EstudanteDeInformatica() :
  Defensor(VIDA, CUSTO, TEMPO_DE_RECARGA, ALCANCE, INTERVALO_DA_ACAO) {}

std::string EstudanteDeInformatica::get_nome() const {
  return "Estudante de Informática";
}

std::string EstudanteDeInformatica::get_descricao() const {
  return "Ataque. Dispara projéteis contra os inimigos da própria linha.";
}

void EstudanteDeInformatica::atualizar(Tabuleiro& tabuleiro, Economia&, Nucleo&) {
  if (pronto_para_agir() && inimigo_no_alcance(tabuleiro) != nullptr) {
    tabuleiro.adicionar_projetil(new Projetil(linha, coluna, VELOCIDADE_DO_PROJETIL, DANO, tabuleiro.get_colunas()));
    reiniciar_intervalo();
  }
}
