#include <iostream>
#include "Economia.h"

Economia::Economia(int saldoInicial) : _saldoFichas(saldoInicial) {
}
void Economia::adicionarSaldo(int valor) {
    _saldoFichas += valor;
}
bool Economia::removerSaldo(int valor) {
    if (valor <= _saldoFichas) {
        _saldoFichas -= valor;
        return true;
    }
    return false;
}
int Economia::getSaldo() const {
    return _saldoFichas;
}