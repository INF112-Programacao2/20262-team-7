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
    void getInfo() const;
    std::string getNome() const;
    std::string getDificuldade() const;
    int getSaldoInicial() const;
    int getVidaInicialNucleo() const;
    int getTamanhoTabuleiro() const;
};

#endif // FASE_H