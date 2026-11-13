#ifndef INIMIGO_H
#define INIMIGO_H
#include "Entidade.h"

class Defensor;

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

  // Defensor mais próximo à esquerda do inimigo, na mesma linha, ou nullptr.
  Defensor* defensor_a_frente(Tabuleiro& tabuleiro);

public:
  Inimigo(int linha, double coluna, int vida_maxima, double _velocidade, int _dano, int _intervalo_ataque, int _recompensa);
  virtual ~Inimigo();
  virtual std::string get_nome() const = 0;
  // Nao é chefe, até que a subclasse diga o contrário
  virtual bool eh_chefe();

  // Comportamento comum: ataca o defensor encostado à frente ou anda em direção
  // ao núcleo. Ao chegar ao núcleo, causa dano a ele.
  virtual void atualizar(Tabuleiro& tabuleiro, Economia& economia, Nucleo& nucleo) override;

  // Chamado quando o inimigo é derrotado.
  void creditar_recompensa(Economia& economia);

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
