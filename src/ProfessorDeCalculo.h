#ifndef PROFESSOR_DE_CALCULO_H
#define PROFESSOR_DE_CALCULO_H
#include "Defensor.h"

// Defensor de dano forte: acerta direto o inimigo mais próximo, mas demora a agir de novo.
class ProfessorDeCalculo : public Defensor {
public:
  ProfessorDeCalculo();
  std::string get_nome() const override;
  std::string get_descricao() const override;
  void atualizar(Tabuleiro& tabuleiro, Economia& economia, Nucleo& nucleo) override;
};

#endif
