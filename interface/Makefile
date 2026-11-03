# Compilador e Flags
CXX      = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall
LDFLAGS  = -lsfml-graphics -lsfml-window -lsfml-system

# Pega automaticamente qualquer arquivo .cpp dentro da pasta src/
FONTES   = $(shell find src -type f -name '*.cpp')
OBJETOS  = $(FONTES:.cpp=.o)
EXEC     = tower-defense

all: $(EXEC)

# Junta tudo e cria o executavel do jogo
$(EXEC): $(OBJETOS)
	$(CXX) $(OBJETOS) -o $(EXEC) $(LDFLAGS)

# Compila cada .cpp individualmente em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compila e ja roda a janela na hora
interface: $(EXEC)
	./$(EXEC)

# Limpa os arquivos temporarios
clean:
	rm -f $(OBJETOS) $(EXEC)

.PHONY: all interface clean