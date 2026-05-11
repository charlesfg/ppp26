#include "ui.h"

#include <stdio.h>

void ui_corre(App* app) {
    int opcao = -1;
    (void)app;

    while (opcao != 0) {
        printf("\n1) Inserir aluno\n2) Eliminar aluno\n3) Listar alunos\n4) Registar despesa\n5) Carregar saldo\n0) Sair\n> ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n') {
            }
            continue;
        }

        /* TODO(aluno): para cada opção, pedir dados ao utilizador e chamar funções da camada app. */
        if (opcao == 1) {
            printf("Ainda não implementado: ui_opcao_inserir_aluno\n");
        } else if (opcao == 2) {
            printf("Ainda não implementado: ui_opcao_eliminar_aluno\n");
        } else if (opcao == 3) {
            printf("Ainda não implementado: ui_opcao_listar_alunos\n");
        } else if (opcao == 4) {
            printf("Ainda não implementado: ui_opcao_registar_despesa\n");
        } else if (opcao == 5) {
            printf("Ainda não implementado: ui_opcao_carregar_saldo\n");
        }
    }
}
