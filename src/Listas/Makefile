CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g

.PHONY: all test test_simples test_cabeca test_descritor clean

all: teste_simples teste_cabeca teste_descritor

teste_simples: teste_listas.c lista_simples.c lista_simples.h
	$(CC) $(CFLAGS) -DTESTE_SIMPLES teste_listas.c lista_simples.c -o teste_simples

teste_cabeca: teste_listas.c lista_cabeca.c lista_cabeca.h
	$(CC) $(CFLAGS) -DTESTE_CABECA teste_listas.c lista_cabeca.c -o teste_cabeca

teste_descritor: teste_listas.c lista_descritor.c lista_descritor.h
	$(CC) $(CFLAGS) -DTESTE_DESCRITOR teste_listas.c lista_descritor.c -o teste_descritor

test: all test_simples test_cabeca test_descritor

test_simples: teste_simples
	./teste_simples

test_cabeca: teste_cabeca
	./teste_cabeca

test_descritor: teste_descritor
	./teste_descritor

clean:
	rm -f teste_simples teste_cabeca teste_descritor
