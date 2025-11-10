# Nome do executável
EXEC = main.exe

# Compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Arquivos fonte
SRCS = main.cpp Veiculo.cpp carro.cpp moto.cpp cliente.cpp contrato.cpp

# Arquivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regra padrão
all: $(EXEC)

# Como gerar o executável
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Como compilar arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos objeto e executável
clean:
	del /f /q $(OBJS) $(EXEC)

# Limpar só objetos
cleanobjs:
	del /f /q $(OBJS)

# Rodar o programa
run: $(EXEC)
	$(EXEC)
