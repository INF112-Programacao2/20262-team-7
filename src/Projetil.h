#ifndef PROJETIL_H
#define PROJETIL_H

class Tabuleiro;

// Tiro disparado por um defensor. Anda para a direita na própria linha
// e fica inativo quando acerta um inimigo ou sai do tabuleiro.
class Projetil {
private:
  int linha;
  double coluna;
  double velocidade;   // colunas andadas a cada passo
  int dano;
  int total_colunas;   // usado para saber quando ele sai do tabuleiro
  bool ativo;

public:
  Projetil(int _linha, double _coluna, double _velocidade, int _dano, int _total_colunas);

  // Anda um passo. Ao sair do tabuleiro, fica inativo e para de andar.
  void mover();

  // Acerta o primeiro inimigo vivo da linha que estiver na mesma posição:
  // causa dano a ele e fica inativo.
  void detectar_colisao(Tabuleiro& tabuleiro);

  bool esta_ativo() const;
  int get_linha() const;
  double get_coluna() const;
  double get_velocidade() const;
  int get_dano() const;
};

#endif
