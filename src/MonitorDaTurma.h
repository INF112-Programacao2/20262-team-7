#ifndef MONITOR_DA_TURMA_H
#define MONITOR_DA_TURMA_H
#include "Defensor.h"

// Defensor de suporte: cura os defensores ao seu redor.
class MonitorDaTurma : public Defensor {
public:
  MonitorDaTurma();
  std::string get_nome() const override;
  std::string get_descricao() const override;
  void atualizar(Tabuleiro& tabuleiro, Economia& economia, Nucleo& nucleo) override;
};

#endif
