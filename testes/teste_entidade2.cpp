#include "Entidade.h"
#include <iostream>
#include <cassert>

class Criatura : public Entidade {
public:
  Criatura() : Entidade(10,10.0,100) {}
  virtual std::string get_nome() const override {return "Teste_Entidade"; }
};

int main(void) {
  Criatura A;

  A.receber_dano(30);
  assert(A.get_vida()==70);
  assert(A.esta_viva());
  std::cout << "teste entidade ok\n";
}