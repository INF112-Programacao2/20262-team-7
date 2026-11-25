#include "FabricaDeEntidades.h"
#include "EstudanteDeInformatica.h"
#include "ProfessorDeCalculo.h"
#include "MonitorDaTurma.h"
#include "CozinheiroDoRU.h"
#include "ProvaSurpresa.h"
#include "PrazoDeEntrega.h"
#include "Reprovacao.h"
#include <stdexcept>

Defensor* FabricaDeEntidades::criar_defensor(const std::string& tipo) {
  if (tipo == "estudante")
    return new EstudanteDeInformatica();
  if (tipo == "professor")
    return new ProfessorDeCalculo();
  if (tipo == "monitor")
    return new MonitorDaTurma();
  if (tipo == "cozinheiro")
    return new CozinheiroDoRU();

  throw std::invalid_argument("Defensor desconhecido: '" + tipo
    + "'. Use estudante, professor, monitor ou cozinheiro.");
}

Inimigo* FabricaDeEntidades::criar_inimigo(const std::string& tipo, int linha, double coluna) {
  if (tipo == "prova_surpresa")
    return new ProvaSurpresa(linha, coluna);
  if (tipo == "prazo_de_entrega")
    return new PrazoDeEntrega(linha, coluna);
  if (tipo == "reprovacao")
    return new Reprovacao(linha, coluna);

  throw std::invalid_argument("Inimigo desconhecido: '" + tipo
    + "'. Use prova_surpresa, prazo_de_entrega ou reprovacao.");
}
