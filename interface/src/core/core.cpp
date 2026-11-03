#include "../../include/core/core.h"

Aplicacao::Aplicacao()
    : m_janela(sf::VideoMode({800, 600}), "Tower Defense - Grupo 7") {
    m_janela.setFramerateLimit(60);
}

void Aplicacao::rodar() {
    while (m_janela.isOpen()) {
        float dt = m_relogio.restart().asSeconds();
        dt = std::min(dt, 0.1f);

        processarEventos();
        atualizar(dt);
        desenhar();
    }
}

void Aplicacao::processarEventos() {
    while (const std::optional<sf::Event> evento = m_janela.pollEvent()) {
        if (evento->is<sf::Event::Closed>()) {
            m_janela.close();
        }
    }
}

void Aplicacao::atualizar(float dt) {
    //std::cout << "dt: " << dt << " s" << std::endl;
}

void Aplicacao::desenhar() {
    // Desenha o fundo da janela com uma cor 
    m_janela.clear(sf::Color(30, 30, 30));

    // Desenha o mapa na tela
    m_mapa.desenhar(m_janela); // Desenha a grelha na tela
    m_janela.display();
}