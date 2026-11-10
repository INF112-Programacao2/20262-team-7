#include "Tabuleiro.h"
#include "EstudanteDeInformatica.h"
#include "PosicaoInvalidaException.h"
#include <iostream>
#include <cassert>

// Tenta posicionar um defensor novo numa posição que o tabuleiro deve recusar.
// Como o defensor não entra no tabuleiro, quem o criou com new precisa apagá-lo.
void testar_posicao_recusada(Tabuleiro& tabuleiro, int linha, int coluna) {
  Defensor* defensor = new EstudanteDeInformatica();
  try {
    tabuleiro.validar_e_posicionar(defensor, linha, coluna);
    std::cout << "ERRO: deveria ter lançado exceção\n";
    assert(false);
  } catch (const PosicaoInvalidaException& e) {
    std::cout << "ok: " << e.what() << '\n';
  }
  delete defensor;
}

int main(void) {
  Tabuleiro tabuleiro(5, 9); // 5 linhas (0 a 4) e 9 colunas (0 a 8)
  assert(tabuleiro.get_linhas() == 5);
  assert(tabuleiro.get_colunas() == 9);
  assert(tabuleiro.get_defensor(2, 3) == nullptr); // começa com todas as células livres

  // Posicionamento válido: não lança nada e a consulta devolve o mesmo ponteiro
  Defensor* estudante = new EstudanteDeInformatica();
  tabuleiro.validar_e_posicionar(estudante, 2, 3);
  assert(tabuleiro.get_defensor(2, 3) == estudante);
  assert(estudante->get_linha() == 2);
  assert(estudante->get_coluna() == 3);

  // Posições recusadas: cada uma deve cair no catch
  testar_posicao_recusada(tabuleiro, -1, 0); // linha antes da primeira
  testar_posicao_recusada(tabuleiro, 5, 0);  // linha depois da última

  // A célula ocupada continua com o primeiro defensor
  assert(tabuleiro.get_defensor(2, 3) == estudante);

  // Fora do tabuleiro, a consulta devolve nullptr
  assert(tabuleiro.get_defensor(5, 0) == nullptr);


  delete estudante;

  std::cout << "teste tabuleiro ok\n";
}
