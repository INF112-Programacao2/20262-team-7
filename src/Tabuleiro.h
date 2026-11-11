#ifndef TABULEIRO_H
#define TABULEIRO_H
#include <vector>

// Declarações antecipadas
class Defensor;
class Inimigo;
class Projetil;

// Grade do jogo. Guarda os defensores, os inimigos e os projéteis
// e é responsável por apagá-los da memória
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

  // Nao permite copias apagarem os mesmos ponteiros
  Tabuleiro(const Tabuleiro&) = delete;
  Tabuleiro& operator=(const Tabuleiro&) = delete;

  int get_linhas() const;
  int get_colunas() const;
  bool linha_valida(int linha) const;
  bool posicao_valida(int linha, int coluna) const;

  // Coloca o defensor na célula. Se a célula não existir ou estiver ocupada,
  // lança exceção, e quem criou o defensor continua responsável por apaga-lo
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

  // Apaga os defensores, os inimigos sem vida e os projéteis inativos
  void remover_destruidos();
};

#endif