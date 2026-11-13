#ifndef ENTIDADE_H
#define ENTIDADE_H
#include <string>
#include <iostream>

class Tabuleiro;
class Economia;
class Nucleo;

class Entidade {
protected:
  int linha;
  double coluna; // double porque os inimigos andam aos poucos
  int vida;
  int vida_maxima;

public:
  Entidade(int _linha, double _coluna, int vidaMaxima);
  virtual ~Entidade();

  // Chamado a cada passo de tempo. Cada subclasse age do seu jeito.
  virtual void atualizar(Tabuleiro& tabuleiro, Economia& economia, Nucleo& nucleo) = 0;
  virtual std::string get_nome() const = 0;

  void receber_dano(int dano);
  bool esta_viva();
  int get_linha();
  double get_coluna();
  void set_posicao(int _linha, double _coluna);
  int get_vida();
  int get_vida_maxima();
};

#endif
