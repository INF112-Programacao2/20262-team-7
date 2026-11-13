#ifndef TABULEIRO_H
#define TABULEIRO_H
#include <vector>

// Declarações antecipadas: o .h só precisa saber que essas classes existem.
class Defensor;
class Inimigo;
class Projetil;
class Economia;
class Nucleo;

// Grade do jogo. Guarda os defensores, os inimigos e os projéteis
// e é responsável por apagá-los da memória.
class Tabuleiro {
private:
  int linhas;
  int colunas;
  std::vector<std::vector<Defensor*>> grade; // nullptr indica célula livre
  std::vector<std::vector<Inimigo*>> inimigos_por_linha;
  std::vector<Projetil*> projeteis;

  // Lança exceção se a linha não existir.
  void conferir_linha(int linha) const;

public:
  Tabuleiro(int _linhas, int _colunas);
  ~Tabuleiro();

  // Cópia proibida: duas cópias apagariam os mesmos ponteiros.
  Tabuleiro(const Tabuleiro&) = delete;
  Tabuleiro& operator=(const Tabuleiro&) = delete;

  int get_linhas() const;
  int get_colunas() const;
  bool linha_valida(int linha) const;
  bool posicao_valida(int linha, int coluna) const;

  // Coloca o defensor na célula. Se a célula não existir ou estiver ocupada,
  // lança exceção, e quem criou o defensor continua responsável por apagá-lo.
  void validar_e_posicionar(Defensor* defensor, int linha, int coluna);

  // Guardam o inimigo ou o projétil na linha dele, com a mesma regra acima
  // quando a linha não existe.
  void adicionar_inimigo(Inimigo* inimigo);
  void adicionar_projetil(Projetil* projetil);

  // Devolve nullptr se a célula estiver livre ou fora do tabuleiro.
  Defensor* get_defensor(int linha, int coluna) const;

  // Lançam exceção se a linha não existir.
  std::vector<Defensor*> get_defensores_na_linha(int linha) const;
  const std::vector<Inimigo*>& get_inimigos_na_linha(int linha) const; // devolve a lista sem copiá-la

  const std::vector<Projetil*>& get_projeteis() const;

  // Um passo de tempo: atualizar_entidades faz os defensores agirem e depois os
  // inimigos; avancar_projeteis move os projéteis e confere se acertaram alguém.
  void atualizar_entidades(Economia& economia, Nucleo& nucleo);
  void avancar_projeteis();

  // Apaga os defensores e os inimigos sem vida e os projéteis inativos.
  // O inimigo derrotado credita a recompensa; o que chegou ao núcleo sai sem ela.
  void remover_destruidos(Economia& economia);
};

#endif
