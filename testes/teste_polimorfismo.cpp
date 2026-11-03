#include "EstudanteDeInformatica.h"
#include "ProvaSurpresa.h"
#include <iostream>
#include <cassert>
#include <vector>

int main(void) {
  // Um defensor e um inimigo guardados como ponteiros da classe-base
  std::vector<Entidade*> entidades;
  entidades.push_back(new EstudanteDeInformatica());
  entidades.push_back(new ProvaSurpresa(2, 8.0));

  // A mesma chamada executa a versão de cada subclasse
  for (Entidade* e : entidades)
    std::cout << e->get_nome() << '\n';

  assert(entidades[0]->get_nome() == "Estudante de Informática");
  assert(entidades[1]->get_nome() == "Prova Surpresa");

  for (Entidade* e : entidades)
    delete e;

  std::cout << "teste polimorfismo ok\n";
}
