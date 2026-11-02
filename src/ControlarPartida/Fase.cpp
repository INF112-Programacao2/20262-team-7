#include <iostream>
#include "Fase.h"

Fase::Fase(const std::string& nome, const std::string& dificuldade, int saldoInicial, int vidaInicialNucleo, int tamanhoTabuleiro)
    : _nome(nome), _dificuldade(dificuldade), _saldoInicial(saldoInicial), _vidaInicialNucleo(vidaInicialNucleo), _tamanhoTabuleiro(tamanhoTabuleiro) {
}
