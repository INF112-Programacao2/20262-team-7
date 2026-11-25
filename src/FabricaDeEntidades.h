#ifndef FABRICA_DE_ENTIDADES_H
#define FABRICA_DE_ENTIDADES_H
#include <string>

class Defensor;
class Inimigo;

// Cria os personagens a partir do nome de texto usado pela interface e pelos arquivos
// Um nome desconhecido lança std::invalid_argument com a lista dos nomes válidos
class FabricaDeEntidades {
public:
  // Nomes: "estudante", "professor", "monitor" e "cozinheiro".
  static Defensor* criar_defensor(const std::string& tipo);

  // Nomes: "prova_surpresa", "prazo_de_entrega" e "reprovacao"
  static Inimigo* criar_inimigo(const std::string& tipo, int linha, double coluna);
};

#endif
