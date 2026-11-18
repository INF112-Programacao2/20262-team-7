#include "Tabuleiro.h"
#include "ProfessorDeCalculo.h"
#include "MonitorDaTurma.h"
#include "CozinheiroDoRU.h"
#include "ProvaSurpresa.h"
#include "PrazoDeEntrega.h"
#include "Reprovacao.h"
#include "ControlarPartida/Economia.h"
#include "ControlarPartida/Nucleo.h"
#include <iostream>
#include <cassert>

// Chama o atualizar do defensor várias vezes seguidas.
void agir(Defensor* defensor, int vezes, Tabuleiro& tabuleiro, Economia& economia, Nucleo& nucleo) {
  for (int i = 0; i < vezes; i++)
    defensor->atualizar(tabuleiro, economia, nucleo);
}

int main(void) {
  Tabuleiro tabuleiro(3, 9);
  Economia economia(0);
  Nucleo nucleo(100);

  // Professor: a reprovação ao alcance perde 25 de uma vez; a próxima ação só vem após o intervalo
  Defensor* professor = new ProfessorDeCalculo();
  Inimigo* chefe = new Reprovacao(0, 3);
  tabuleiro.validar_e_posicionar(professor, 0, 1);
  tabuleiro.adicionar_inimigo(chefe);
  int intervalo = professor->get_intervalo_acao();
  agir(professor, intervalo, tabuleiro, economia, nucleo);
  assert(chefe->get_vida() == 125);
  agir(professor, intervalo - 1, tabuleiro, economia, nucleo);
  assert(chefe->get_vida() == 125);
  agir(professor, 1, tabuleiro, economia, nucleo);
  assert(chefe->get_vida() == 100);

  // Monitor: o vizinho com metade da vida melhora; o de vida cheia, na diagonal, continua igual
  Defensor* monitor = new MonitorDaTurma();
  Defensor* ferido = new ProfessorDeCalculo();
  Defensor* cozinheiro = new CozinheiroDoRU();
  tabuleiro.validar_e_posicionar(monitor, 1, 4);
  tabuleiro.validar_e_posicionar(ferido, 1, 5);
  tabuleiro.validar_e_posicionar(cozinheiro, 2, 5);
  ferido->receber_dano(38); // fica com 37 de 75
  agir(monitor, monitor->get_intervalo_acao(), tabuleiro, economia, nucleo);
  assert(ferido->get_vida() == 57);
  assert(cozinheiro->get_vida() == cozinheiro->get_vida_maxima());

  // Cozinheiro: depois de 3 intervalos, o saldo aumentou 3 x 25 fichas
  agir(cozinheiro, 3 * cozinheiro->get_intervalo_acao(), tabuleiro, economia, nucleo);
  assert(economia.getSaldo() == 75);

  // Prazo de entrega: velocidade e vida ficam entre as da prova surpresa e as da reprovação
  ProvaSurpresa prova(2, 9);
  PrazoDeEntrega prazo(2, 9);
  assert(prova.get_velocidade() > prazo.get_velocidade() && prazo.get_velocidade() > chefe->get_velocidade());
  assert(prova.get_vida() < prazo.get_vida() && prazo.get_vida() < chefe->get_vida_maxima());

  // Só a reprovação responde que é chefe, mesmo vista como Inimigo*
  Inimigo* comuns[] = {&prova, &prazo};
  assert(!comuns[0]->eh_chefe() && !comuns[1]->eh_chefe());
  assert(chefe->eh_chefe());

  std::cout << "teste subclasses ok\n";
}
