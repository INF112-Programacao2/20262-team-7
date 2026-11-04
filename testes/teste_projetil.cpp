#include "Projetil.h"
#include <iostream>
#include <cassert>
#include <cmath>

bool quase_igual(double a, double b) {
  return std::abs(a - b) < 1e-6;
}

int main(void) {

  const int COLUNAS = 9;

  Projetil p(2, 0.0, 0.3, 5, COLUNAS); // linha, coluna, velocidade, dano e colunas do tabuleiro
  assert(p.get_linha() == 2);
  assert(p.get_dano() == 5);
  assert(quase_igual(p.get_coluna(), 0.0));
  assert(quase_igual(p.get_velocidade(), 0.3));
  assert(p.esta_ativo());

  for (int i = 0; i < 10; i++)
    p.mover();
  assert(quase_igual(p.get_coluna(), 3.0));
  assert(p.esta_ativo());

  // Saída do tabuleiro: com 0,5 por passo, a coluna chega a 9 no 18 passo
  Projetil q(0, 0.0, 0.5, 5, COLUNAS);
  for (int i = 0; i < 17; i++)
    q.mover();
  assert(quase_igual(q.get_coluna(), 8.5));
  assert(q.esta_ativo());  // ainda dentro da ultima coluna

  q.mover();
  assert(quase_igual(q.get_coluna(), 9.0));
  assert(!q.esta_ativo()); // saiu exatamente neste passo

  // Depois de inativo, ele nao anda mais
  q.mover();
  assert(quase_igual(q.get_coluna(), 9.0));

  std::cout << "teste projetil ok\n";
}
