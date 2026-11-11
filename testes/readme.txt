// Rodar de dentro de /testes
// Atualizar conforme a classe que for testada
// classe Entidade (testar a abstração e com subclasse)
// classe Defensor (testando o construtor e getters)      \ subclasses
// classe Inimigo (testando o construtor e função reforço) / de entidade
// classe Estudante (testando construtor e funcoes herdadas)
// classe Prova (testando constutor e funcoes herdadas)
// polimorfismo prova e estudante (ambos são entidades, podendo usar as funções da mesma)
// classe Projetil (testando o construtor e os valores velocidade e posicao)
// classe Tabuleiro (teste construtor e posicoes invalidas)
// classe Tabuleiro nova(reconhecimento de quantas entidades estao na mesma linha e as condicoes para serem apagados-perder vida ou sair do "mapa"-
// -- com o delete[] ja incluso na funcao)
// -- também inclui tratamente de excecoes(posicao invalida)


g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined -I../src -Iprovisorio teste_memoria.cpp ../src/Tabuleiro.cpp 
../src/Entidade.cpp ../src/Defensor.cpp ../src/Inimigo.cpp ../src/EstudanteDeInformatica.cpp ../src/ProvaSurpresa.cpp 
../src/Projetil.cpp -o teste_memoria