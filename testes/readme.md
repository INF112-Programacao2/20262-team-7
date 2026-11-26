# Testes

Execute os testes a partir da pasta `testes/`.
Este readme foi atualizado conforme os casos de teste foram criados.

## Cobertura atual

- **Entidade:** abstração e subclasses. *(histórico)*
- **Defensor:** construtor e getters. *(histórico)*
- **Inimigo:** construtor e função de reforço, além de herdar de `Entidade`.
- **Estudante:** construtor e funções herdadas. *(histórico)*
- **Prova:** construtor e funções herdadas. *(histórico)*
- **Polimorfismo:** uso de entidades por meio das classes `Prova` e `Estudante`.
- **Projétil:** construtor, velocidade e posição.
- **Tabuleiro:** construtor e posições inválidas. *(histórico)*
- **Tabuleiro novo:** reconhecimento de entidades na mesma linha e condições de remoção, perda de vida ou saída do mapa.
  - Liberação da memória (`delete`) na função de remoção.
  - Tratamento de exceções para posição inválida.

Testes adicionais:

- Comportamento dos inimigos: ataque, causa de dano, chegada ao núcleo e obtenção de créditos ao morrer.
- Novas subclasses defensoras e inimigas: atributos básicos e funções específicas de cada classe.

## Testes históricos

Os testes marcados como *(histórico)* foram usados durante a criação das classes e
não foram atualizados depois das mudanças seguintes. Eles ficam no repositório apenas
como registro e não devem ser usados para conferir o funcionamento atual:

- `teste_entidade.cpp`: não compila mais.
- `teste_entidade2.cpp` e `teste_defensor.cpp`: as subclasses de teste não implementam `atualizar`.
- `teste_estudante.cpp` e `teste_prova_surpresa.cpp`: possuem valores desatualizados, logo, falham no assert.
- `teste_tabuleiro.cpp`: substituído pelo `teste_tabuleiro_novo.cpp`.
- `teste_memoria.cpp`: usa a versão antiga de `remover_destruidos`, sem a `Economia`.

Os testes válidos hoje são: `teste_vazio`, `teste_inimigo`, `teste_polimorfismo`,
`teste_projetil`, `teste_tabuleiro_novo`, `teste_comportamento_inimigo`,
`teste_subclasses` e `teste_simulacao`.

## Teste de jogo

- **Simulacao:** o novo programa de teste simula uma partida real, já pré-programada, contando com todas as entidades, tabuleiro, nucleo, economia e demais funcionalidades do jogo.


## Compilação

```bash
g++ -std=c++17 -Wall -Wextra -g "-fsanitize=address,undefined" -I../src \
  teste_simulacao.cpp ../src/Entidade.cpp ../src/Defensor.cpp ../src/Inimigo.cpp \
  ../src/EstudanteDeInformatica.cpp ../src/ProfessorDeCalculo.cpp \
  ../src/MonitorDaTurma.cpp ../src/CozinheiroDoRU.cpp ../src/ProvaSurpresa.cpp \
  ../src/PrazoDeEntrega.cpp ../src/Reprovacao.cpp ../src/Projetil.cpp \
  ../src/Tabuleiro.cpp ../src/FabricaDeEntidades.cpp \
  ../src/ControlarPartida/Economia.cpp ../src/ControlarPartida/Nucleo.cpp \
  -o teste_simulacao
./teste_simulacao
```

Para outro teste válido, troque `teste_simulacao` pelo nome dele nas duas linhas em que aparece.