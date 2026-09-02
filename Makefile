# Makefile - Calculadora RPN (DINF/UFPR)
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g -std=c99
LDLIBS  = -lm
MAIN    = avalia
ENTREGA = $(MAIN)

BINDIR  = bin

# Construir o executável (alvo padrão)
$(BINDIR)/$(MAIN): main.c avalia.c avalia.h | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ main.c avalia.c $(LDLIBS)

# Garante que o diretório de saída exista
$(BINDIR):
	mkdir -p $@

# Limpeza de binários e objetos
clean:
	rm -rf $(BINDIR) $(ENTREGA).tgz

.PHONY: clean
