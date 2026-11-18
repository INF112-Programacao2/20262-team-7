#include "ProfessorDeCalculo.h"
#include "Inimigo.h"

// Valores provisórios. Vida, dano e custo seguem a tabela do README.
// Os tempos estão em passos (10 passos = 1 segundo).
static const int VIDA = 75;
static const int CUSTO = 50;
static const double TEMPO_DE_RECARGA = 100;
static const int ALCANCE = 3;
static const double INTERVALO_DA_ACAO = 40;
static const int DANO = 25;

ProfessorDeCalculo::ProfessorDeCalculo() :
  Defensor(VIDA, CUSTO, TEMPO_DE_RECARGA, ALCANCE, INTERVALO_DA_ACAO) {}

std::string ProfessorDeCalculo::get_nome() const {
  return "Professor de Cálculo";
}

std::string ProfessorDeCalculo::get_descricao() const {
  return "Dano forte. Causa muito dano ao inimigo mais próximo, mas demora a agir de novo.";
}

// A cada intervalo, causa o dano direto no inimigo mais próximo, sem projétil.
void ProfessorDeCalculo::atualizar(Tabuleiro& tabuleiro, Economia&, Nucleo&) {
  if (!pronto_para_agir())
    return;

  Inimigo* alvo = inimigo_no_alcance(tabuleiro);
  if (alvo != nullptr) {
    alvo->receber_dano(DANO);
    reiniciar_intervalo();
  }
}
