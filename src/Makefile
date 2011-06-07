# Makefile Trabalho Sistemas operacionais
# Compilador: gcc

# Variaveis

CC = gcc
CFLAGS = -Wall -lpthread
#CFILES = 
#OBJECTS = 
MAIN = main.c main.h
EXEC = ganateli

# Ações de Compilação

all: main

main:
	$(CC) $(MAIN) -o main $(CFLAGS)

clean:
	rm -rf *.o *.a *~* *.bak core* *.gch $(EXEC) main
