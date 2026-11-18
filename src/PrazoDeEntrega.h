#ifndef PRAZO_DE_ENTREGA_H
#define PRAZO_DE_ENTREGA_H
#include "Inimigo.h"

// Inimigo comum, com equilíbrio entre velocidade e resistência.
class PrazoDeEntrega : public Inimigo {
public:
  PrazoDeEntrega(int _linha, double _coluna);
  std::string get_nome() const override;
};

#endif
