#include <iostream>
#include "Fase.h"

Fase::Fase(const std::string& nome, const std::string& dificuldade, int saldoInicial, int vidaInicialNucleo, int tamanhoTabuleiro)
    : _nome(nome), _dificuldade(dificuldade), _saldoInicial(saldoInicial), _vidaInicialNucleo(vidaInicialNucleo), _tamanhoTabuleiro(tamanhoTabuleiro) {
}
void Fase::getInfo() const {
        std::cout << "Nome: " << _nome << std::endl;
        std::cout << "Dificuldade: " << _dificuldade << std::endl;
        std::cout << "Saldo Inicial: " << _saldoInicial << std::endl;
        std::cout << "Vida Inicial do Núcleo: " << _vidaInicialNucleo << std::endl;
        std::cout << "Tamanho do Tabuleiro: " << _tamanhoTabuleiro << std::endl;
}
std::string Fase::getNome() const { return _nome; }
std::string Fase::getDificuldade() const { return _dificuldade; }
int Fase::getSaldoInicial() const { return _saldoInicial; }
int Fase::getVidaInicialNucleo() const { return _vidaInicialNucleo; }
int Fase::getTamanhoTabuleiro() const { return _tamanhoTabuleiro; }