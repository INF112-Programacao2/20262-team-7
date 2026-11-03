#ifndef APLICACAO_HPP
#define APLICACAO_HPP

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include "mapa.h"

class Aplicacao {
public:
    Aplicacao();
    void rodar(); // executa o loop principal do jogo

private:
    void processarEventos(); // trata as entradas
    void atualizar(float dt); // atualiza o estado do jogo com base no tempo
    void desenhar(); // renderiza os elementos gráficos na tela

    sf::RenderWindow m_janela;
    sf::Clock m_relogio;
    Mapa m_mapa; // Instância do mapa do jogo
};

#endif