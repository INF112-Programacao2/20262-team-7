#include "EstudanteDeInformatica.h"

// Valores provisórios. Vida e custo vêm da tabela do README
static const int VIDA = 50;
static const int CUSTO = 10;
static const double TEMPO_DE_RECARGA = 5;
static const int ALCANCE = 9;
static const double INTERVALO_DA_ACAO = 2;

EstudanteDeInformatica::EstudanteDeInformatica() :
  Defensor(VIDA, CUSTO, TEMPO_DE_RECARGA, ALCANCE, INTERVALO_DA_ACAO) {}

std::string EstudanteDeInformatica::get_nome() const {
  return "Estudante de Informática";
}

std::string EstudanteDeInformatica::get_descricao() const {
  return "Ataque. Dispara projéteis contra os inimigos da própria linha.";
}
