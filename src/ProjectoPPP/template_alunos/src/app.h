#ifndef APP_H
#define APP_H

#include "aluno.h"

typedef struct {
    AlunoLista alunos;
} App;

void app_init(App* app);
void app_destroy(App* app);
int app_carregar(App* app, const char* alunos_path, const char* despesas_path);
int app_guardar(App* app, const char* alunos_path, const char* despesas_path);

int app_inserir_aluno(App* app, const char* nome, Data nascimento, int curso, int ano, int numero);
int app_eliminar_aluno(App* app, int numero);
Aluno* app_procurar_aluno(App* app, int numero);
int app_carregar_saldo(App* app, int numero, float valor);
int app_registar_despesa(App* app, int numero, float valor, const char* descricao, Data data);

#endif
