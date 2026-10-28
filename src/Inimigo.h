#ifndef INIMIGO_H
#define INIMIGO_H
#include "Entidade.h"

class Inimigo : public Entidade {
private:
  double velocidade;
  int dano;
  int intervalo_ataque;
  int tempo_desde_ataque;
  int recompensa;
  int ataques_realizados;
  bool alcancou_nucleo;
  bool atacando;

public:
  Inimigo(int linha, double coluna, int vida_maxima, double _velocidade, int _dano, int _intervalo_ataque, int _recompensa);
  virtual ~Inimigo();
  virtual std::string get_nome() const = 0;
  // Nao é chefe, até que a subclasse diga o contrário
  virtual bool eh_chefe();

  double get_velocidade() const;
  int get_dano() const;
  int get_recompensa() const;
  bool chegou_ao_nucleo();
  bool esta_atacando();
  int get_ataques_realizados();
  void set_velocidade(double nova_velocidade);
  void aplicar_reforco(double fator);

};

#endif