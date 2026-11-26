#include "Defensor.h"
#include <iostream>
#include <cassert>

class Aluno : public Defensor {
public:
  Aluno() : Defensor(100,10,15,20,3) {} // Vida, custo, tempo de recarga, alcance, intervalo de acao
  virtual std::string get_nome() const {return "Aluno teste";}
  virtual std::string get_descricao() const {return "Ola! Sou um aluno";}
};

int main(void) {
Aluno defensor; 

assert(defensor.get_custo() == 10);
assert(defensor.get_vida_maxima() == 100);
assert(defensor.get_tempo_recarga() == 15);
assert(defensor.get_alcance() == 20);
assert(defensor.get_coluna() == 0);

std::cout << "teste defensor ok\n";
  
}
