#ifndef ESTUDANTE_DE_INFORMATICA_H
#define ESTUDANTE_DE_INFORMATICA_H
#include "Defensor.h"

// Defensor de ataque: dispara projéteis contra os inimigos da própria linha
// Por enquanto só define os seus valores
class EstudanteDeInformatica : public Defensor {
public:
  EstudanteDeInformatica();
  std::string get_nome() const override;
  std::string get_descricao() const override;
};

#endif
