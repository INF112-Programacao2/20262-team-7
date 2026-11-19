# Testes

Execute os testes a partir da pasta `testes/` e atualize o arquivo conforme a classe testada.

## Cobertura atual

- **Entidade:** abstração e subclasses.
- **Defensor:** construtor e getters.
- **Inimigo:** construtor e função de reforço, além de herdar de `Entidade`.
- **Estudante:** construtor e funções herdadas.
- **Prova:** construtor e funções herdadas.
- **Polimorfismo:** uso de entidades por meio das classes `Prova` e `Estudante`.
- **Projétil:** construtor, velocidade e posição.
- **Tabuleiro:** construtor e posições inválidas.
- **Tabuleiro novo:** reconhecimento de entidades na mesma linha e condições de remoção, perda de vida ou saída do mapa.
  - Inclusão de `delete[]` na função de remoção.
  - Tratamento de exceções para posição inválida.

Novas mudanças nas classes e subclasses podem afetar o comportamento dos testes. Até o momento, todos estão funcionando.

Testes adicionais:

- Comportamento dos inimigos: ataque, causa de dano, chegada ao núcleo e obtenção de créditos ao morrer.
- Novas subclasses defensoras e inimigas: atributos básicos e funções específicas de cada classe.

## Compilação

```bash
g++ -std=c++17 -Wall -Wextra -g "-fsanitize=address,undefined" \
    -I../src -Iprovisorio teste_subclasses.cpp \
    ../src/Entidade.cpp \
    ../src/Defensor.cpp \
    ../src/Inimigo.cpp \
    ../src/EstudanteDeInformatica.cpp \
    ../src/ProfessorDeCalculo.cpp \
    ../src/MonitorDaTurma.cpp \
    ../src/CozinheiroDoRU.cpp \
    ../src/ProvaSurpresa.cpp \
    ../src/PrazoDeEntrega.cpp \
    ../src/Reprovacao.cpp \
    ../src/Projetil.cpp \
    ../src/Tabuleiro.cpp \
    ../src/ControlarPartida/Economia.cpp \
    ../src/ControlarPartida/Nucleo.cpp \
    -o teste_subclasses
```