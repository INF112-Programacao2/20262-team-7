#ifndef COZINHEIRO_DO_RU_H
#define COZINHEIRO_DO_RU_H
#include "Defensor.h"

// Defensor de recursos: gera fichas do RU de tempos em tempos.
class CozinheiroDoRU : public Defensor {
public:
  CozinheiroDoRU();
  std::string get_nome() const override;
  std::string get_descricao() const override;
  void atualizar(Tabuleiro& tabuleiro, Economia& economia, Nucleo& nucleo) override;
};

#endif
