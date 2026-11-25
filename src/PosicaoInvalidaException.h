#ifndef POSICAO_INVALIDA_EXCEPTION_H
#define POSICAO_INVALIDA_EXCEPTION_H
#include <stdexcept>
#include <string>

// Versão provisória, usada apenas nos testes do bloco 4.2
class PosicaoInvalidaException : public std::exception {
public:
  PosicaoInvalidaException(const std::string& mensagem) : std::exception(mensagem) {}
};

#endif
