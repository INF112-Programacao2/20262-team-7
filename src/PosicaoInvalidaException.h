#ifndef POSICAO_INVALIDA_EXCEPTION_H
#define POSICAO_INVALIDA_EXCEPTION_H
#include <stdexcept>
#include <string>

// Lança a exceção
class PosicaoInvalidaException : public std::runtime_error {
public:
  PosicaoInvalidaException(const std::string& mensagem) : std::runtime_error(mensagem) {}
};

#endif
