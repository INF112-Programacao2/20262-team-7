#include "Entidade.h"

Entidade::Entidade(int _linha, double _coluna, int vidaMaxima) :
  linha(_linha), coluna(_coluna), vida(vidaMaxima), vida_maxima(vidaMaxima) {}

Entidade::~Entidade() {}

void Entidade::receber_dano(int dano) {
    if(vida-dano>=0)
      vida-=dano;
    else
      vida=0;
}

bool Entidade::esta_viva() {
    return vida>0;  
}

int Entidade::get_linha() {
    return linha;
}

double Entidade::get_coluna() {
    return coluna;
}

void Entidade::set_posicao(int _linha, int _coluna) {
  linha=_linha;
  coluna=_coluna;
}

int Entidade::get_vida() {
  return vida;
}


int Entidade::get_vida_maxima() {
    return vida_maxima;
}  