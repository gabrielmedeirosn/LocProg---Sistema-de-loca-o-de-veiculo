# ==========================
# 🔧 CONFIGURAÇÕES
# ==========================
EXEC = build/main.exe
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

SRCDIR = src
BUILDDIR = build
DATADIR = data

# Lista automaticamente todos os .cpp em src/
SRCS = $(wildcard $(SRCDIR)/*.cpp)
# Converte para arquivos .o em build/
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRCS))

# ==========================
# 🏗️ COMPILAÇÃO
# ==========================
all: $(EXEC)

$(EXEC): $(OBJS)
	@if not exist $(BUILDDIR) mkdir $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@if not exist $(BUILDDIR) mkdir $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ==========================
# ▶️ EXECUÇÃO
# ==========================
# Executa o programa na raiz, garantindo acesso a 'data/'
run: $(EXEC)
	cmd /c "cd $(BUILDDIR) && cd .. && build\\main.exe"

# ==========================
# 🧹 LIMPEZA
# ==========================
clean:
	cmd /c "if exist $(BUILDDIR)\\*.o del /f /q $(BUILDDIR)\\*.o"
	cmd /c "if exist $(EXEC) del /f /q $(EXEC)"

cleanobjs:
	cmd /c "if exist $(BUILDDIR)\\*.o del /f /q $(BUILDDIR)\\*.o"
