#include "core/mapa.h"

Mapa::Mapa() : m_spriteFundo(m_texturaFundo), m_imagemCarregada(false) {
    if (m_texturaFundo.loadFromFile("assets/imagens/mapa.png")) {
        m_texturaFundo.setSmooth(false); 
        m_spriteFundo.setTexture(m_texturaFundo, true);
        m_spriteFundo.setPosition({0.0f, 0.0f});
        
        m_imagemCarregada = true;

        std::cout << "[OK] Imagem do mapa carregada com sucesso!" << std::endl;
    } else {
        std::cerr << "[ERRO] Falha em carregar a imagem do mapa!" << std::endl;
    }
    
    // Inicialização da matriz m_grid 
    for (int l = 0; l < LINHAS; l++) {
        for (int c = 0; c < COLUNAS; c++) {
            // Area proibida: LAGO / BORDA LATERAL / HUD (PAINEL SUPERIOR)
            if (l < LINHAS_HUD || c < COLUNA_INICIO_JOGO || c >= COLUNA_FIM_JOGO || l >= LINHA_INICIO_LAGO) {
                m_grid[l][c] = 0; 
            }else {
                m_grid[l][c] = 1;  // 1 = Caminho jogável
            }
        }
    }
}

void Mapa::desenhar(sf::RenderWindow& janela) {
    // Desenha a imagem do mapa
    if (m_imagemCarregada) {
        janela.draw(m_spriteFundo);
    } 

    // Desenha a grelha de debug sobre o mapa
    //desenharMalhaDebug(janela);
}

void Mapa::desenharMalhaDebug(sf::RenderWindow& janela) {
    // Quadrado base de 40x40px
    sf::RectangleShape tile({TAMANHO_TILE, TAMANHO_TILE});
    
    // Borda interna para separar os quadrados (1.5px)
    tile.setOutlineThickness(-1.5f);

    for (int l = 0; l < LINHAS; l++) {
        for (int c = 0; c < COLUNAS; c++) {
            tile.setPosition({c * TAMANHO_TILE, l * TAMANHO_TILE});

            // ZONA 1: HUD / CARDS (Vermelho)
            if (l < LINHAS_HUD) {
                tile.setFillColor(sf::Color(255, 0, 0, 0));       
                tile.setOutlineColor(sf::Color(255, 80, 80, 255));
            }
            // ZONA 2: BORDAS LATERAIS E LAGO (Laranja)
            else if (c < COLUNA_INICIO_JOGO || c >= COLUNA_FIM_JOGO || l >= LINHA_INICIO_LAGO) {
                tile.setFillColor(sf::Color(255, 140, 0, 0));      
                tile.setOutlineColor(sf::Color(255, 180, 0, 255));
            }
            // ZONA 3: AREA JOGAVEL (Ciano)
            else {
                tile.setFillColor(sf::Color(0, 255, 255, 20));  // Quadrado tom B
                tile.setOutlineColor(sf::Color(0, 255, 255, 220)); // Linhas de divisão bem definidas
            }

            janela.draw(tile);
        }
    }
}


int Mapa::getTipoCelula(int linha, int coluna) const {
    if (linha >= LINHAS_HUD && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
        return m_grid[linha][coluna];
    }
    return -1;
}