# 20262-team-7 — Tower Defense UFV

Jogo no estilo *tower defense*, semelhante a *Plants vs. Zombies*, com temática da Universidade Federal de Viçosa (UFV). O jogador posiciona defensores em um tabuleiro para proteger o núcleo da base contra ondas de inimigos que ficam gradualmente mais fortes.

---

## 👥 Integrantes

| Nome | Matrícula |
|------|-----------|
| Denyse Freitas Santos | 124693 |
| Gustavo Lopes Pimenta | 124684 |
| Luisa Sousa Sarti | 124666 |
| Pedro Henrique Marques Lucas | 124682 |

---

## 📌 Sumário

- [Integrantes](#-integrantes)
- [Sobre o jogo](#-sobre-o-jogo)
  - [Ambientação](#️-ambientação)
  - [Modos de operação](#️-modos-de-operação)
- [Estrutura do repositório](#-estrutura-do-repositório)
- [Tecnologias](#️-tecnologias)
- [Como compilar e executar](#-como-compilar-e-executar)

---

## 🎮 Sobre o jogo

### 🗺️ Ambientação

Os defensores representam figuras da vida universitária e os inimigos representam as "ameaças" do semestre. O recurso do jogo são as **fichas do RU**, usadas para comprar e posicionar defensores.

**🛡️ Defensores (as "torres")**

| Defensor | Função | Comportamento |
|----------|--------|---------------|
| Estudante de Informática | Ataque | Dispara projéteis na própria linha |
| Professor de Cálculo | Dano forte | Dano elevado, com recarga longa |
| Monitor da Turma | Suporte | Fortalece ou cura defensores vizinhos |
| Cozinheiro do RU | Geração de recursos | Gera fichas periodicamente |

**👾 Inimigos (as "ameaças" do semestre)**

| Inimigo | Característica | Papel |
|---------|----------------|-------|
| Prova Surpresa | Rápida e frágil | Comum |
| Prazo de Entrega | Equilíbrio entre velocidade e resistência | Comum |
| Reprovação | Lenta e muito resistente | Chefe |

---

### 🕹️ Modos de operação

| Modo | Descrição |
|------|-----------|
| **Interativo (GUI)** | Partida em tempo real, com defensores escolhidos e posicionados com o mouse. Interface em **SFML**. |
| **Headless (lote)** | Lê de um arquivo a configuração da fase e os comandos (posicionamentos e avanço de tempo), executa a partida sem interface e grava um arquivo de saída com log e estatísticas finais. |

---

## 📂 Estrutura do repositório

> ⚠️ *A ser atualizada conforme o andamento do projeto*

```text
20262-team-7/
├── docs/          # User Stories e Cartões CRC          
└── README.md
```

---

## 🛠️ Tecnologias

| Categoria | Ferramenta |
|-----------|------------|
| Linguagem | C++ |
| Interface gráfica | SFML |
| Build | a definir |
| Controle de versão | Git / GitHub |

---

## 🚀 Como compilar e executar

> ⚠️ *A ser adicionado conforme o andamento do projeto*

---

*Projeto final de Programação II (INF 112) — Universidade Federal de Viçosa (UFV)*