#ifndef ESTUDANTE_DE_INFORMATICA_H
#define ESTUDANTE_DE_INFORMATICA_H
#include "Defensor.h"

// Defensor de ataque: dispara projéteis contra os inimigos da própria linha.
class EstudanteDeInformatica : public Defensor {
public:
  EstudanteDeInformatica();
  std::string get_nome() const override;
  std::string get_descricao() const override;

  // A cada intervalo, dispara se houver inimigo no alcance.
  void atualizar(Tabuleiro& tabuleiro, Economia& economia, Nucleo& nucleo) override;
};

#endif
