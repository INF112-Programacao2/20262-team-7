#include "Defensor.h"
#include "Inimigo.h"
#include "Tabuleiro.h"

Defensor::Defensor(int _vida_maxima, int _custo, double _tempo_recarga, int _alcance, double _intervalo_acao) :
  Entidade(0,0,_vida_maxima), custo(_custo), tempo_recarga(_tempo_recarga), recarga_restante(0),
  alcance(_alcance), intervalo_acao(_intervalo_acao), tempo_desde_ultima_acao(0), ja_agiu(false) {}

Defensor::~Defensor() {}

int Defensor::get_custo() const {
    return custo;
}  

int Defensor::get_alcance() const {
    return alcance;
}

int Defensor::get_coluna() const {
    return coluna;
}

int Defensor::get_recarga_restante() const {
    return recarga_restante;
}

int Defensor::get_tempo_recarga() const {
    return tempo_recarga;
}

int Defensor::get_intervalo_acao() const {
    return intervalo_acao;
}


bool Defensor::pode_comprar() const {
  return recarga_restante == 0;
}

void Defensor::iniciar_recarga_de_compra() {
    recarga_restante = tempo_recarga;
}

void Defensor::avancar_recarga_compra() {
    if(recarga_restante > 0)
      recarga_restante--;
}

bool Defensor::pronto_para_agir() {
    if(tempo_desde_ultima_acao < intervalo_acao)
      tempo_desde_ultima_acao++;
    return tempo_desde_ultima_acao >= intervalo_acao;
}

void Defensor::reiniciar_intervalo() {
    tempo_desde_ultima_acao = 0;
}

Inimigo* Defensor::inimigo_no_alcance(Tabuleiro& tabuleiro) {
    Inimigo* mais_proximo = nullptr;
    for(Inimigo* inimigo : tabuleiro.get_inimigos_na_linha(linha)) {
      double distancia = inimigo->get_coluna() - coluna;
      // Só vale o inimigo que já entrou no tabuleiro
      bool valido = inimigo->esta_viva() && distancia > 0 && distancia <= alcance
        && inimigo->get_coluna() < tabuleiro.get_colunas();
      if(valido && (mais_proximo == nullptr || inimigo->get_coluna() < mais_proximo->get_coluna()))
        mais_proximo = inimigo;
    }
    return mais_proximo;
}
