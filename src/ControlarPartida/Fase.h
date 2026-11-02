#ifndef FASE_H
#define FASE_H

class Fase {
private:
    std::string _nome;
    std::string _dificuldade;
    int _saldoInicial;
    int _vidaInicialNucleo;
    int _tamanhoTabuleiro;
    
public:
    Fase(const std::string& nome, const std::string& dificuldade, int saldoInicial, int vidaInicialNucleo, int tamanhoTabuleiro);
    
};

#endif // FASE_H