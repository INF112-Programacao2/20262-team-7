CXX      = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra
LDFLAGS  = -lsfml-graphics -lsfml-window -lsfml-system

# --- O que entra no build da interface ---
TESTE_SRC = testes/interface/teste1_interface.cpp
SRC_FILES = $(shell find src/core -type f -name '*.cpp')
FONTES    = $(TESTE_SRC) $(SRC_FILES)
HEADERS   = $(shell find include -type f -name '*.h')

# Objetos ficam em build/interface (nao poluem src/)
BUILD   = build/interface
OBJETOS = $(FONTES:%.cpp=$(BUILD)/%.o)
EXEC    = $(BUILD)/exec_interface

all: interface

# compila e roda (a partir da raiz, para 'assets/...' funcionar)
interface: $(EXEC)
	./$(EXEC)

$(EXEC): $(OBJETOS)
	$(CXX) $(OBJETOS) -o $@ $(LDFLAGS)

# mexeu em qualquer .h -> recompila os .o
$(BUILD)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build

.PHONY: all interface clean