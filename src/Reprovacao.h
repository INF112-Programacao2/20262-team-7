#ifndef REPROVACAO_H
#define REPROVACAO_H
#include "Inimigo.h"

// Inimigo chefe: lento e muito resistente.
class Reprovacao : public Inimigo {
public:
  Reprovacao(int _linha, double _coluna);
  std::string get_nome() const override;
  bool eh_chefe() override;
};

#endif
