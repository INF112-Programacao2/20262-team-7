#ifndef DEFENSOR_H
#define DEFENSOR_H
#include "Entidade.h"

class Defensor : public Entidade {
private:
  int custo;
  int tempo_recarga;
  int recarga_restante;
  int alcance;
  int intervalo_acao;
  int tempo_desde_ultima_acao;
  bool ja_agiu;
  // Talvez essas duas ultimas variaveis não sejam necessarias
  // Depende se será implementado uma animacao para os ataques
public:
  Defensor(int _vida_maxima, int _custo, double _tempo_recarga, int _alcance, double _intervalo_acao);
  virtual ~Defensor();
  virtual std::string get_nome() const = 0;
  virtual std::string get_descricao() const = 0;
  
  int get_custo() const;
  int get_alcance() const;
  int get_coluna() const;
  int get_tempo_recarga() const;
  int get_recarga_restante() const;
  bool pode_comprar() const;
  void iniciar_recarga_de_compra();
  void avancar_recarga_compra();
};

#endif