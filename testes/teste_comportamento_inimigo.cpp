#include "Tabuleiro.h"
#include "EstudanteDeInformatica.h"
#include "ProvaSurpresa.h"
#include "ControlarPartida/Economia.h"
#include "ControlarPartida/Nucleo.h"
#include <iostream>
#include <cassert>

int main(void) {
  Tabuleiro tabuleiro(2, 9);
  Economia economia(0);
  Nucleo nucleo(100);

  // Sem defensor à frente, a prova anda 0,125 coluna por passo
  Inimigo* prova = new ProvaSurpresa(0, 4);
  tabuleiro.adicionar_inimigo(prova);
  prova->atualizar(tabuleiro, economia, nucleo);
  assert(prova->get_coluna() == 3.875);

  // Com um estudante na coluna 1, ela para encostada nele e ataca a cada 10 passos
  Defensor* estudante = new EstudanteDeInformatica();
  tabuleiro.validar_e_posicionar(estudante, 0, 1);
  for (int i = 0; i < 30; i++)
    prova->atualizar(tabuleiro, economia, nucleo);
  assert(prova->get_coluna() == 2);
  assert(prova->esta_atacando());
  assert(prova->get_ataques_realizados() == 2);
  assert(estudante->get_vida() == 40);

  // Derrotada, a prova credita a recompensa ao ser removida
  prova->receber_dano(25);
  tabuleiro.remover_destruidos(economia);
  assert(economia.getSaldo() == 10);

  // Na linha 1, sem defensores, outra prova chega ao núcleo: causa dano e sai sem recompensa
  Inimigo* outra = new ProvaSurpresa(1, 0.25);
  tabuleiro.adicionar_inimigo(outra);
  outra->atualizar(tabuleiro, economia, nucleo);
  outra->atualizar(tabuleiro, economia, nucleo);
  assert(outra->chegou_ao_nucleo());
  assert(nucleo.getVidaAtual() == 95);
  tabuleiro.remover_destruidos(economia);
  assert(tabuleiro.get_inimigos_na_linha(1).empty());
  assert(economia.getSaldo() == 10);

  std::cout << "teste comportamento do inimigo ok\n";
}
