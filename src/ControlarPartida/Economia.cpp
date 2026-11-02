#include <iostream>
#include "Economia.h"

Economia::Economia(int saldoInicial) : _saldo(saldoInicial) {
}
void Economia::adicionarSaldo(int valor) {
    _saldo += valor;
}
bool Economia::removerSaldo(int valor) {
    if (valor <= _saldo) {
        _saldo -= valor;
        return true;
    }
    return false;
}
int Economia::getSaldo() const {
    return _saldo;
}