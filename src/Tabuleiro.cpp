#include "Tabuleiro.h"
#include "Defensor.h"
#include "PosicaoInvalidaException.h"
#include <string>

// Cria a grade já com o tamanho certo e todas as células livres
Tabuleiro::Tabuleiro(int _linhas, int _colunas) :
  linhas(_linhas), colunas(_colunas), grade(_linhas, std::vector<Defensor*>(_colunas, nullptr)) {}

int Tabuleiro::get_linhas() const {
  return linhas;
}

int Tabuleiro::get_colunas() const {
  return colunas;
}

bool Tabuleiro::posicao_valida(int linha, int coluna) const {
  return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}

void Tabuleiro::validar_e_posicionar(Defensor* defensor, int linha, int coluna) {
  std::string posicao = "(" + std::to_string(linha) + ", " + std::to_string(coluna) + ")";

  if (!posicao_valida(linha, coluna))
    throw PosicaoInvalidaException("A posição " + posicao + " está fora do tabuleiro. Escolha uma linha de 0 a "
      + std::to_string(linhas - 1) + " e uma coluna de 0 a " + std::to_string(colunas - 1) + ".");

  if (grade[linha][coluna] != nullptr)
    throw PosicaoInvalidaException("A célula " + posicao + " já está ocupada por "
      + grade[linha][coluna]->get_nome() + ". Escolha uma célula livre.");

  // Só chega aqui com a célula válida e livre
  defensor->set_posicao(linha, coluna);
  grade[linha][coluna] = defensor;
}

Defensor* Tabuleiro::get_defensor(int linha, int coluna) const {
  if (!posicao_valida(linha, coluna))
    return nullptr;
  return grade[linha][coluna];
}
