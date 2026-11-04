// Rodar de dentro de /testes
// Atualizar conforme a classe que for testada
// classe Entidade (testar a abstração e com subclasse)
// classe Defensor (testando o construtor e getters)      \ subclasses
// classe Inimigo (testando o construtor e função reforço) / de entidade
// classe Estudante (testando construtor e funcoes herdadas)
// classe Prova (testando constutor e funcoes herdadas)
// polimorfismo prova e estudante (ambos são entidades, podendo usar as funções da mesma)
// classe Projetil (testando o construtor e os valores velocidade e posicao)

g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined -I../src teste_polimorfismo.cpp ../src/Entidade.cpp ../src/Defensor.cpp ../src/Inimigo.cpp
../src/EstudanteDeInformatica.cpp ../src/ProvaSurpresa.cpp -o teste_polimorfismo