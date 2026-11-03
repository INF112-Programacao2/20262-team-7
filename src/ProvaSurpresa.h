#ifndef PROVA_SURPRESA_H
#define PROVA_SURPRESA_H
#include "Inimigo.h"

// Inimigo comum, rápido e frágil.
// Por enquanto, só define os seus valores
class ProvaSurpresa : public Inimigo {
public:
  ProvaSurpresa(int _linha, double _coluna);
  std::string get_nome() const override;
};

#endif
