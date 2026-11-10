#ifndef POSICAO_INVALIDA_EXCEPTION_H
#define POSICAO_INVALIDA_EXCEPTION_H
#include <stdexcept>
#include <string>

// Versão provisória, usada apenas nos testes do bloco 4.2.
// Será substituída pela exceção do bloco 4.3, que pelo CRC herda de ExcecaoDoJogo.
class PosicaoInvalidaException : public std::runtime_error {
public:
  PosicaoInvalidaException(const std::string& mensagem) : std::runtime_error(mensagem) {}
};

#endif
