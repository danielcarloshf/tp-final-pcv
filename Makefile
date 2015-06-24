CC =  gcc
CFLAGS = -Wall

MKDIR = mkdir -pv
BIN_DIR = bin/
BUILD_DIR = build/

SRC_HEURISTICA = heuristica.c
SRC_TIPOS = tipos.c
SRC_MAIN = main.c

OBJS_HEURISTICA	= $(SRC_HEURISTICA:%.c=build/%.o)
OBJS_TIPOS = $(SRC_TIPOS:%.c=build/%.o)
OBJS_MAIN = $(SRC_MAIN:%.c=build/%.o)

all: directories bin/tp.exec

directories:
	@$(MKDIR) $(BUILD_DIR) $(BIN_DIR)

bin/tp.exec: $(OBJS_MAIN) $(OBJS_TIPOS) $(OBJS_HEURISTICA)
	@echo "+ Compilando o arquivo executável \"$@\""
	@$(CC) $(CFLAGS) $(OBJS_MAIN) $(OBJS_TIPOS) $(OBJS_HEURISTICA) -o bin/tp.exec

build/%.o: src/%.c src/%.h
	@echo "- Compilando objeto \"$@\""
	@$(CC) -c $(CFLAGS) $< -o $@

build/%.o: src/%.c
	@echo "- Compilando objeto \"$@\""
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "- Removendo objetos e arquivos binários."
	@rm -rfv bin/* build/*
