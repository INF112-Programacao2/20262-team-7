#include "Tabuleiro.h"
#include "Defensor.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "PosicaoInvalidaException.h"
#include <string>

// A grade começa com todas as células livres e cada linha sem inimigos.
Tabuleiro::Tabuleiro(int _linhas, int _colunas) :
  linhas(_linhas), colunas(_colunas), grade(_linhas, std::vector<Defensor*>(_colunas, nullptr)),
  inimigos_por_linha(_linhas) {}

// Apaga tudo o que ainda está no tabuleiro.
Tabuleiro::~Tabuleiro() {
  for (const std::vector<Defensor*>& linha : grade) {
    for (Defensor* defensor : linha) {
      delete defensor; // delete em nullptr não faz nada
    }
  }

  for (const std::vector<Inimigo*>& linha : inimigos_por_linha) {
    for (Inimigo* inimigo : linha) {
      delete inimigo;
    }
  }

  for (Projetil* projetil : projeteis) {
    delete projetil;
  }
}

int Tabuleiro::get_linhas() const {
  return linhas;
}

int Tabuleiro::get_colunas() const {
  return colunas;
}

bool Tabuleiro::linha_valida(int linha) const {
  return linha >= 0 && linha < linhas;
}

bool Tabuleiro::posicao_valida(int linha, int coluna) const {
  return linha_valida(linha) && coluna >= 0 && coluna < colunas;
}

void Tabuleiro::conferir_linha(int linha) const {
  if (!linha_valida(linha))
    throw PosicaoInvalidaException("A linha " + std::to_string(linha) + " não existe. Escolha uma linha de 0 a "
      + std::to_string(linhas - 1) + ".");
}

void Tabuleiro::validar_e_posicionar(Defensor* defensor, int linha, int coluna) {
  std::string posicao = "(" + std::to_string(linha) + ", " + std::to_string(coluna) + ")";

  if (!posicao_valida(linha, coluna))
    throw PosicaoInvalidaException("A posição " + posicao + " está fora do tabuleiro. Escolha uma linha de 0 a "
      + std::to_string(linhas - 1) + " e uma coluna de 0 a " + std::to_string(colunas - 1) + ".");

  if (grade[linha][coluna] != nullptr)
    throw PosicaoInvalidaException("A célula " + posicao + " já está ocupada por "
      + grade[linha][coluna]->get_nome() + ". Escolha uma célula livre.");

  defensor->set_posicao(linha, coluna);
  grade[linha][coluna] = defensor;
}

void Tabuleiro::adicionar_inimigo(Inimigo* inimigo) {
  int linha = inimigo->get_linha();
  conferir_linha(linha); // só a linha é conferida, pois o inimigo surge fora da grade, à direita
  inimigos_por_linha[linha].push_back(inimigo);
}

void Tabuleiro::adicionar_projetil(Projetil* projetil) {
  conferir_linha(projetil->get_linha());
  projeteis.push_back(projetil);
}

Defensor* Tabuleiro::get_defensor(int linha, int coluna) const {
  if (!posicao_valida(linha, coluna))
    return nullptr;
  return grade[linha][coluna];
}

std::vector<Defensor*> Tabuleiro::get_defensores_na_linha(int linha) const {
  conferir_linha(linha);
  std::vector<Defensor*> defensores;
  for (Defensor* defensor : grade[linha])
    if (defensor != nullptr)
      defensores.push_back(defensor);
  return defensores;
}

const std::vector<Inimigo*>& Tabuleiro::get_inimigos_na_linha(int linha) const {
  conferir_linha(linha);
  return inimigos_por_linha[linha];
}

const std::vector<Projetil*>& Tabuleiro::get_projeteis() const {
  return projeteis;
}

void Tabuleiro::atualizar_entidades(Economia& economia, Nucleo& nucleo) {
  // Só quem está vivo age
  for (int l = 0; l < linhas; l++)
    for (int c = 0; c < colunas; c++)
      if (grade[l][c] != nullptr && grade[l][c]->esta_viva())
        grade[l][c]->atualizar(*this, economia, nucleo);

  for (std::vector<Inimigo*>& linha : inimigos_por_linha)
    for (Inimigo* inimigo : linha)
      if (inimigo->esta_viva() && !inimigo->chegou_ao_nucleo())
        inimigo->atualizar(*this, economia, nucleo);
}

void Tabuleiro::avancar_projeteis() {
  for (Projetil* projetil : projeteis) {
    projetil->mover();
    projetil->detectar_colisao(*this);
  }
}

void Tabuleiro::remover_destruidos(Economia& economia) {
  // Defensor sem vida: apaga e libera a célula
  for (int l = 0; l < linhas; l++)
    for (int c = 0; c < colunas; c++)
      if (grade[l][c] != nullptr && !grade[l][c]->esta_viva()) {
        delete grade[l][c];
        grade[l][c] = nullptr;
      }

  // Inimigos e projéteis: monta um vetor novo só com os que ficam e apaga os outros,
  // porque apagar elementos do vetor enquanto ele é percorrido causa erro
  for (std::vector<Inimigo*>& linha : inimigos_por_linha) {
    std::vector<Inimigo*> ficam;
    for (Inimigo* inimigo : linha) {
      if (!inimigo->esta_viva()) {
        inimigo->creditar_recompensa(economia);
        delete inimigo;
      } else if (inimigo->chegou_ao_nucleo()) {
        delete inimigo;
      } else {
        ficam.push_back(inimigo);
      }
    }
    linha = ficam;
  }

  std::vector<Projetil*> ficam;
  for (Projetil* projetil : projeteis) {
    if (projetil->esta_ativo())
      ficam.push_back(projetil);
    else
      delete projetil;
  }
  projeteis = ficam;
}
