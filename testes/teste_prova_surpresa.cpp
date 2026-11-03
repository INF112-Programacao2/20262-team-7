#include "ProvaSurpresa.h"
#include <iostream>
#include <cassert>

int main(void) {
  ProvaSurpresa prova(2, 8.0); // linha 2, coluna 8

  // Valores definidos no construtor
  assert(prova.get_nome() == "Prova Surpresa");
  assert(prova.get_linha() == 2);
  assert(prova.get_vida() == 25);
  assert(prova.get_velocidade() == 20);
  assert(prova.get_dano() == 5);
  assert(prova.get_recompensa() == 10);

  // Comportamento padrão herdado do Inimigo
  assert(!prova.eh_chefe());
  assert(!prova.chegou_ao_nucleo());
  assert(!prova.esta_atacando());

  // Reforço de onda: dobra a vida atual e a máxima
  prova.aplicar_reforco(2.0);
  assert(prova.get_vida() == 50);
  assert(prova.get_vida_maxima() == 50);

  std::cout << "teste prova surpresa ok\n";
}
