#include "Tabuleiro.h"
#include "FabricaDeEntidades.h"
#include "Defensor.h"
#include "Inimigo.h"
#include "ControlarPartida/Economia.h"
#include "ControlarPartida/Nucleo.h"
#include <iostream>
#include <string>

// Mostra o tabuleiro e as entidades
void desenhar(Tabuleiro& tabuleiro) {
  for (int l = 0; l < tabuleiro.get_linhas(); l++) {
    std::string celulas(tabuleiro.get_colunas(), '.');  // Cria as linhas, preenchidas com '.'(vazio)

    for (int c = 0; c < tabuleiro.get_colunas(); c++)
      if (tabuleiro.get_defensor(l, c) != nullptr)
        celulas[c] = tabuleiro.get_defensor(l, c)->get_nome()[0];  // Se tiver defensor, usa sua inicial para identificar

    for (Inimigo* inimigo : tabuleiro.get_inimigos_na_linha(l)) {
      int c = (int)inimigo->get_coluna();
      if (c < tabuleiro.get_colunas()) // Como os inimigos spawnar alem da grid, desenhamos apenas os que estao dentro
        celulas[c] = inimigo->eh_chefe() ? 'X' : 'x';  // Para nao confundir, os diferenciamos por boss ou nao
    }

    std::cout << celulas << '\n';
  }
}

int main(void) {
  Tabuleiro tabuleiro(3, 9);
  Economia economia(0);
  Nucleo nucleo(100);

  // Defensores
  tabuleiro.validar_e_posicionar(FabricaDeEntidades::criar_defensor("cozinheiro"), 0, 0);
  tabuleiro.validar_e_posicionar(FabricaDeEntidades::criar_defensor("estudante"), 0, 1);
  tabuleiro.validar_e_posicionar(FabricaDeEntidades::criar_defensor("estudante"), 1, 1);
  tabuleiro.validar_e_posicionar(FabricaDeEntidades::criar_defensor("monitor"), 2, 1);

  // Inimigos começam fora do tabuleiro, a direita, e podem demorar a entrar
  tabuleiro.adicionar_inimigo(FabricaDeEntidades::criar_inimigo("prova_surpresa", 0, 9));
  tabuleiro.adicionar_inimigo(FabricaDeEntidades::criar_inimigo("prazo_de_entrega", 1, 10));
  tabuleiro.adicionar_inimigo(FabricaDeEntidades::criar_inimigo("prova_surpresa", 2, 12));
  tabuleiro.adicionar_inimigo(FabricaDeEntidades::criar_inimigo("reprovacao", 1, 14));

  // Como nao existe um clock ainda, usaremos o termo passo para representar 0.1 segundo
  // Considerando um partida de 2 minutos, 60*10*2 = 1200
  for (int passo = 1; passo <= 1200; passo++) {
    tabuleiro.atualizar_entidades(economia, nucleo);
    tabuleiro.avancar_projeteis();
    tabuleiro.remover_destruidos(economia);

    // A cada segundo(10 passos), mostra a situação da partida
    if (passo % 10 == 0) {
      std::cout << "segundo " << passo / 10 << "  núcleo " << nucleo.getVidaAtual()
                << "  fichas " << economia.getSaldo() << '\n';
      desenhar(tabuleiro);
      std::cout << '\n';
    }

    // Acaba quando não sobra inimigo ou quando o núcleo é destruído
    if (!tabuleiro.tem_inimigos() || !nucleo.estaVivo())
      break;
  }

  std::cout << "Fim: o núcleo terminou com " << nucleo.getVidaAtual() << " de vida.\n";
}
