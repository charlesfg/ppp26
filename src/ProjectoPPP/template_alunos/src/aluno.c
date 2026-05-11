#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>

int aluno_valido(const Aluno* a) {
    /* TODO(aluno): validar campos obrigatórios (nome, data, curso, ano, número). */
    printf("Ainda não implementado: aluno_valido\n");
    (void)a;
    return 1;
}

Aluno* aluno_cria(const char* nome, Data nascimento, int curso, int ano, int numero) {
    /* TODO(aluno): alocar memória, copiar dados e inicializar ponteiros/saldo. */
    printf("Ainda não implementado: aluno_cria\n");
    (void)nome;
    (void)nascimento;
    (void)curso;
    (void)ano;
    (void)numero;
    return NULL;
}

void aluno_liberta(Aluno* a) {
    /* TODO(aluno): libertar lista de despesas associada e depois o aluno. */
    printf("Ainda não implementado: aluno_liberta\n");
    (void)a;
}

void aluno_lista_init(AlunoLista* lista) {
    /* TODO(aluno): inicializar cabeça da lista ligada. */
    printf("Ainda não implementado: aluno_lista_init\n");
    if (lista != NULL) {
        lista->head = NULL;
    }
}

void aluno_lista_limpa(AlunoLista* lista) {
    /* TODO(aluno): percorrer nós e libertar memória com segurança. */
    printf("Ainda não implementado: aluno_lista_limpa\n");
    (void)lista;
}

Aluno* aluno_lista_procura_numero(AlunoLista* lista, int numero) {
    /* TODO(aluno): busca linear por número; retornar NULL se não existir. */
    printf("Ainda não implementado: aluno_lista_procura_numero\n");
    (void)lista;
    (void)numero;
    return NULL;
}

int aluno_lista_insere_ordenado(AlunoLista* lista, Aluno* novo) {
    /* TODO(aluno): inserir mantendo ordem alfabética e evitar duplicados por número. */
    printf("Ainda não implementado: aluno_lista_insere_ordenado\n");
    (void)lista;
    (void)novo;
    return 1;
}

int aluno_lista_remove_numero(AlunoLista* lista, int numero) {
    /* TODO(aluno): remover nó pelo número e corrigir encadeamento anterior/próximo. */
    printf("Ainda não implementado: aluno_lista_remove_numero\n");
    (void)lista;
    (void)numero;
    return 1;
}
