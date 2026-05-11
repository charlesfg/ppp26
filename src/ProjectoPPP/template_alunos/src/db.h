#ifndef DB_H
#define DB_H

#include "aluno.h"

int db_carregar(AlunoLista* lista, const char* alunos_path, const char* despesas_path);
int db_guardar(const AlunoLista* lista, const char* alunos_path, const char* despesas_path);

#endif
