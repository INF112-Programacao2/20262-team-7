#include "EstudanteDeInformatica.h"
#include <iostream>
#include <cassert>

int main(void) {
  EstudanteDeInformatica estudante;

  // Valores definidos no construtor
  assert(estudante.get_nome() == "Estudante de Informática");
  assert(estudante.get_vida_maxima() == 50);
  assert(estudante.get_vida() == 50);
  assert(estudante.get_custo() == 10);
  assert(estudante.get_alcance() == 9);
  assert(estudante.get_tempo_recarga() == 5);

  // Recarga de compra: começa disponível, fica indisponível depois de comprado
  // e volta a ficar disponível depois de avançar o tempo de recarga
  assert(estudante.pode_comprar());
  estudante.iniciar_recarga_de_compra();
  assert(!estudante.pode_comprar());
  for (int i = 0; i < estudante.get_tempo_recarga(); i++)
    estudante.avancar_recarga_compra();
  assert(estudante.pode_comprar());

  // Dano herdado da Entidade
  estudante.receber_dano(20);
  assert(estudante.get_vida() == 30);
  assert(estudante.esta_viva());

  std::cout << "teste estudante ok\n";
}
