#ifndef ECONOMIA_H
#define ECONOMIA_H

class Economia {
    private:
        int _saldo;
    public:
        Economia(int saldoInicial);
        void adicionarSaldo(int valor);
        bool removerSaldo(int valor);
        int getSaldo() const;
    
};

#endif // ECONOMIA_H