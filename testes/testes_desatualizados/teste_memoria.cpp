#include "Tabuleiro.h"
#include "EstudanteDeInformatica.h"
#include "ProvaSurpresa.h"
#include "Projetil.h"
#include "PosicaoInvalidaException.h"
#include <iostream>
#include <cassert>
#include <vector>

// Três inimigos na linha 1, um deles com dano maior que a vida.
void testar_inimigos() {
  Tabuleiro tabuleiro(5, 9);

  // Os inimigos surgem fora da grade, à direita (coluna 9 em diante)
  Inimigo* prova1 = new ProvaSurpresa(1, 9);
  Inimigo* prova2 = new ProvaSurpresa(1, 10);
  Inimigo* prova3 = new ProvaSurpresa(1, 11);
  tabuleiro.adicionar_inimigo(prova1);
  tabuleiro.adicionar_inimigo(prova2);
  tabuleiro.adicionar_inimigo(prova3);

  // A referência aponta para a própria lista guardada no tabuleiro
  const std::vector<Inimigo*>& linha1 = tabuleiro.get_inimigos_na_linha(1);
  assert(linha1.size() == 3);
  assert(tabuleiro.get_inimigos_na_linha(0).empty());

  prova2->receber_dano(30); // a vida da prova surpresa é 25
  tabuleiro.remover_destruidos();

  // A referência já mostra a lista atualizada. A prova2 foi apagado e não pode mais ser usada.
  assert(linha1.size() == 2);
  assert(linha1[0] == prova1);
  assert(linha1[1] == prova3);
}

// Um defensor sem vida sai da grade e libera a célula.
void testar_defensores() {
  Tabuleiro tabuleiro(5, 9);
  Defensor* estudante1 = new EstudanteDeInformatica();
  Defensor* estudante2 = new EstudanteDeInformatica();
  tabuleiro.validar_e_posicionar(estudante1, 1, 0);
  tabuleiro.validar_e_posicionar(estudante2, 1, 4);
  assert(tabuleiro.get_defensores_na_linha(1).size() == 2);

  estudante2->receber_dano(60); // a vida do estudante é 50
  tabuleiro.remover_destruidos();

  assert(tabuleiro.get_defensor(1, 4) == nullptr);
  std::vector<Defensor*> defensores = tabuleiro.get_defensores_na_linha(1);
  assert(defensores.size() == 1);
  assert(defensores[0] == estudante1);

  // A célula liberada aceita outro defensor
  tabuleiro.validar_e_posicionar(new EstudanteDeInformatica(), 1, 4);
  assert(tabuleiro.get_defensores_na_linha(1).size() == 2);
}

// O projétil que saiu do tabuleiro é removido; o que continua dentro fica.
void testar_projeteis() {
  Tabuleiro tabuleiro(5, 9);
  Projetil* sai = new Projetil(1, 8.5, 0.5, 5, 9); // no próximo passo, passa da última coluna
  Projetil* fica = new Projetil(1, 1.0, 0.5, 5, 9);
  tabuleiro.adicionar_projetil(sai);
  tabuleiro.adicionar_projetil(fica);

  sai->mover();
  fica->mover();
  tabuleiro.remover_destruidos();

  assert(tabuleiro.get_projeteis().size() == 1);
  assert(tabuleiro.get_projeteis()[0] == fica);
}

// Consultar ou adicionar numa linha que não existe deve cair no catch.
void testar_linha_inexistente() {
  Tabuleiro tabuleiro(5, 9);

  try {
    tabuleiro.get_inimigos_na_linha(7);
    std::cout << "ERRO: deveria ter lançado exceção\n";
    assert(false);
  } catch (const PosicaoInvalidaException& e) {
    std::cout << "ok: " << e.what() << '\n';
  }

  // O inimigo recusado não entrou no tabuleiro, então o próprio teste o apaga
  Inimigo* fora = new ProvaSurpresa(7, 9);
  try {
    tabuleiro.adicionar_inimigo(fora);
    std::cout << "ERRO: deveria ter lançado exceção\n";
    assert(false);
  } catch (const PosicaoInvalidaException& e) {
    std::cout << "ok: " << e.what() << '\n';
  }
  delete fora;
}

int main(void) {
  testar_inimigos();
  testar_defensores();
  testar_projeteis();
  testar_linha_inexistente();
  std::cout << "teste memoria ok\n";
}