#include "Inimigo.h"
#include <cassert>

class Minion : public Inimigo {
public:
  Minion() : Inimigo(0,0,100,20,10,5,50) {} // Linha,coluna,vida,velocidade,dano,intervalo de ataque e recompensa
  virtual std::string get_nome() const {return "Minion fraco";}
  virtual bool eh_chefe() {return false;}
};

int main(void) {
Minion K;
assert(K.get_vida()==100);
K.aplicar_reforco(1.5);
assert(K.get_vida()==150);

std::cout << "teste inimigo ok\n";
}