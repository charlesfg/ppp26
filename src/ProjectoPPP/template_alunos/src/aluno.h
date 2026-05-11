#ifndef ALUNO_H
#define ALUNO_H

#include "conf.h"
#include "data.h"

struct Despesa;

typedef struct Aluno {
    char nome[MAX_STR];
    Data nascimento;
    int curso;
    int ano;
    int numero;
    float saldo;
    struct Despesa* despesas;
    struct Aluno* next;
} Aluno;

typedef struct {
    Aluno* head;
} AlunoLista;

int aluno_valido(const Aluno* a);
Aluno* aluno_cria(const char* nome, Data nascimento, int curso, int ano, int numero);
void aluno_liberta(Aluno* a);

void aluno_lista_init(AlunoLista* lista);
void aluno_lista_limpa(AlunoLista* lista);
Aluno* aluno_lista_procura_numero(AlunoLista* lista, int numero);
int aluno_lista_insere_ordenado(AlunoLista* lista, Aluno* novo);
int aluno_lista_remove_numero(AlunoLista* lista, int numero);

#endif
