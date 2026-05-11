#include "app.h"

#include <stddef.h>
#include <stdio.h>

void app_init(App* app) {
    /* TODO(aluno): inicializar estado global da aplicação e listas principais. */
    printf("Ainda não implementado: app_init\n");
    if (app != NULL) {
        app->alunos.head = NULL;
    }
}

void app_destroy(App* app) {
    /* TODO(aluno): libertar toda a memória alocada dinamicamente. */
    printf("Ainda não implementado: app_destroy\n");
    (void)app;
}

int app_carregar(App* app, const char* alunos_path, const char* despesas_path) {
    /* TODO(aluno): ler ficheiros, validar formato e preencher listas ligadas. */
    printf("Ainda não implementado: app_carregar\n");
    (void)app;
    (void)alunos_path;
    (void)despesas_path;
    return 0;
}

int app_guardar(App* app, const char* alunos_path, const char* despesas_path) {
    /* TODO(aluno): percorrer estruturas em memória e persistir em texto. */
    printf("Ainda não implementado: app_guardar\n");
    (void)app;
    (void)alunos_path;
    (void)despesas_path;
    return 0;
}

int app_inserir_aluno(App* app, const char* nome, Data nascimento, int curso, int ano, int numero) {
    /* TODO(aluno): validar dados, garantir número único e inserir ordenado por nome. */
    printf("Ainda não implementado: app_inserir_aluno\n");
    (void)app;
    (void)nome;
    (void)nascimento;
    (void)curso;
    (void)ano;
    (void)numero;
    return 1;
}

int app_eliminar_aluno(App* app, int numero) {
    /* TODO(aluno): procurar aluno por número, remover da lista e libertar memória. */
    printf("Ainda não implementado: app_eliminar_aluno\n");
    (void)app;
    (void)numero;
    return 1;
}

Aluno* app_procurar_aluno(App* app, int numero) {
    /* TODO(aluno): implementar busca linear por número de aluno. */
    printf("Ainda não implementado: app_procurar_aluno\n");
    (void)app;
    (void)numero;
    return NULL;
}

int app_carregar_saldo(App* app, int numero, float valor) {
    /* TODO(aluno): validar valor positivo e atualizar saldo do aluno. */
    printf("Ainda não implementado: app_carregar_saldo\n");
    (void)app;
    (void)numero;
    (void)valor;
    return 1;
}

int app_registar_despesa(App* app, int numero, float valor, const char* descricao, Data data) {
    /* TODO(aluno): validar saldo/data, criar despesa e encadear na lista de despesas. */
    printf("Ainda não implementado: app_registar_despesa\n");
    (void)app;
    (void)numero;
    (void)valor;
    (void)descricao;
    (void)data;
    return 1;
}
