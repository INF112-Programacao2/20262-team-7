#include <iostream>
#include "Nucleo.h"

Nucleo::Nucleo(int vidaMaxima) : _vidaAtual(vidaMaxima), _vidaMaxima(vidaMaxima) {
}

void Nucleo::receberDano(int dano) {
    _vidaAtual -= dano;
    if (_vidaAtual < 0) {
        _vidaAtual = 0;
    }
}

bool Nucleo::estaVivo() const {
    return _vidaAtual > 0;
}

int Nucleo::getVidaAtual() const {
    return _vidaAtual;
}

int Nucleo::getVidaMaxima() const {
    return _vidaMaxima;
}