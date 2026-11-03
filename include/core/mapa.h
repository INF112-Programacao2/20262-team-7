#ifndef MAPA_H
#define MAPA_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Mapa {
public:
    Mapa();
    void desenhar(sf::RenderWindow& janela);
    void desenharMalhaDebug(sf::RenderWindow& janela);
    int getTipoCelula(int linha, int coluna) const;

private:
    // Dimensoes do mapa
    static constexpr int COLUNAS = 20;
    static constexpr int LINHAS = 15;

    // Zonas do mapa
    static constexpr int LINHAS_HUD = 2;          // 2 linhas = 80px no topo (Cards/HUD)
    static constexpr int LINHA_INICIO_LAGO = 11;  // Linhas 12, 13 e 14 = 120px em baixo (Lago)
    static constexpr int COLUNA_INICIO_JOGO = 3;  // Colunas 0, 1 e 2 = 120px à esquerda
    static constexpr int COLUNA_FIM_JOGO = 17;    // Colunas 17, 18 e 19 = 120px à direita

    static constexpr float TAMANHO_TILE = 40.0f;
    static constexpr float MARGEM = 1.0f;

    int m_grid[LINHAS][COLUNAS];

    sf::Texture m_texturaFundo;
    sf::Sprite m_spriteFundo;
    bool m_imagemCarregada;
};

#endif