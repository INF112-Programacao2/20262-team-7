#ifndef NUCLEO_H
#define NUCLEO_H

class Nucleo {
    private:
       int _vidaAtual;
       int _vidaMaxima;
    public:
       Nucleo(int vidaMaxima);
       void receberDano(int dano);
       bool estaVivo() const;
       int getVidaAtual() const;
       int getVidaMaxima() const;
};

#endif // NUCLEO_H
