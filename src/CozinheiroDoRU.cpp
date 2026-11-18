#include "CozinheiroDoRU.h"
#include "ControlarPartida/Economia.h"

// Valores provisórios. Vida, fichas e custo seguem a tabela do README.
// Os tempos estão em passos (10 passos = 1 segundo).
static const int VIDA = 30;
static const int CUSTO = 25;
static const double TEMPO_DE_RECARGA = 50;
static const int ALCANCE = 0;
static const double INTERVALO_DA_ACAO = 100;
static const int FICHAS = 25;

CozinheiroDoRU::CozinheiroDoRU() :
  Defensor(VIDA, CUSTO, TEMPO_DE_RECARGA, ALCANCE, INTERVALO_DA_ACAO) {}

std::string CozinheiroDoRU::get_nome() const {
  return "Cozinheiro do RU";
}

std::string CozinheiroDoRU::get_descricao() const {
  return "Recursos. Gera fichas do RU de tempos em tempos.";
}

// A cada intervalo, credita as fichas na economia.
void CozinheiroDoRU::atualizar(Tabuleiro&, Economia& economia, Nucleo&) {
  if (pronto_para_agir()) {
    economia.adicionarSaldo(FICHAS);
    reiniciar_intervalo();
  }
}
