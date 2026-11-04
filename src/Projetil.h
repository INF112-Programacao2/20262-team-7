#ifndef PROJETIL_H
#define PROJETIL_H

// Tiro disparado por um defensor. Anda para a direita pela própria linha
// e deixa de estar ativo quando sai do tabuleiro.
// Não herda de Entidade, porque não tem vida.
class Projetil {
private:
  int linha;
  double coluna;
  double velocidade;   // colunas andadas a cada passo
  int dano;
  int total_colunas;   // colunas do tabuleiro, usadas para saber quando ele sai
  bool ativo;

public:
  Projetil(int _linha, double _coluna, double _velocidade, int _dano, int _total_colunas);

  void mover();
  bool esta_ativo() const;

  int get_linha() const;
  double get_coluna() const;
  double get_velocidade() const;
  int get_dano() const;
};

#endif
