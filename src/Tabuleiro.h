#ifndef TABULEIRO_H
#define TABULEIRO_H
#include <vector>

// Declaração antecipada
class Defensor;

// Grade de linhas x colunas onde ficam os defensores.
// Por enquanto, guarda só os defensores
class Tabuleiro {
private:
  int linhas;
  int colunas;
  std::vector<std::vector<Defensor*>> grade; // ocupante de cada célula; nullptr indica célula livre

public:
  Tabuleiro(int _linhas, int _colunas);

  int get_linhas() const;
  int get_colunas() const;

  // Verdadeiro quando a célula existe no tabuleiro.
  bool posicao_valida(int linha, int coluna) const;

  // Registra o defensor na célula. Lança PosicaoInvalidaException se a célula estiver
  // fora do tabuleiro ou ocupada
  void validar_e_posicionar(Defensor* defensor, int linha, int coluna);

  // Devolve o defensor da célula, ou nullptr se ela estiver livre ou fora do tabuleiro
  Defensor* get_defensor(int linha, int coluna) const;
};

#endif
