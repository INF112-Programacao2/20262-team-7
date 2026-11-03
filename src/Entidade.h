#ifndef ENTIDADE_H
#define ENTIDADE_H
#include <string>
#include <iostream>

class Entidade {
protected: 
  int linha;
  int coluna;
  int vida;
  int vida_maxima;
  
public:
  Entidade(int _linha, double _coluna, int vidaMaxima);
  virtual ~Entidade();
  //  virtual void atualizar(Partida &partida) = 0;
  // Ainda não implementou partida
  // Partida será atualizada a cada tick de tempo
  virtual std::string get_nome() const = 0;

  void receber_dano(int dano);
  bool esta_viva();
  int get_linha();
  double get_coluna();
  void set_posicao(int _linha, int _coluna);
  int get_vida();
  int get_vida_maxima();
};

#endif