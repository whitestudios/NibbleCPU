# Nome do executável
TARGET = MeuPrograma

# Pastas
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Compilador e flags (sem Raylib)
CC = gcc
CFLAGS = -Wall -I$(INC_DIR) -O2
LDFLAGS = 

# Lista de arquivos fonte e objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

# Regra padrão
all: $(BIN_DIR)/$(TARGET)

# Linkagem (sem Raylib)
$(BIN_DIR)/$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

# Compilação
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar pasta bin se não existir
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpar
clean:
	rm -rf $(BIN_DIR)/*.o $(BIN_DIR)/$(TARGET)

.PHONY: all clean