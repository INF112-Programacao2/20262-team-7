// Rodar de dentro de /testes
// Atualizar conforme a classe que for testada
// classe Entidade(testar a abstração e com subclasse)
// classe Defensor(testando o construtor e getters)      \ subclasses
// class inimigo(testando o construtor e função reforço) / de entidade

g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined -I../src -Iprovisorio teste_inimigo.cpp ../src/Entidade.cpp ../src/Inimigo.cpp -o teste_inimigo
./teste_inimigo

