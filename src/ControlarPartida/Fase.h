#ifndef FASE_H
#define FASE_H

class Fase {
private:
    std::string _nome;
    std::string _dificuldade;
    int _saldoInicial;
    int _vidaInicialNucleo;
    
public:
    Fase(const std::string& nome, const std::string& dificuldade, int saldoInicial, int vidaInicialNucleo);
    
};

#endif // FASE_H