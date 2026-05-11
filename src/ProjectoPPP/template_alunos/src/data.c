#include "data.h"

#include <stdio.h>

int data_valida(Data d) {
    /* TODO(aluno): validar dia/mês/ano e regras de ano bissexto. */
    printf("Ainda não implementado: data_valida\n");
    (void)d;
    return 1;
}

int data_cria(int dia, int mes, int ano, Data* out) {
    /* TODO(aluno): construir Data válida e escrever no ponteiro de saída. */
    printf("Ainda não implementado: data_cria\n");
    (void)dia;
    (void)mes;
    (void)ano;
    if (out != NULL) {
        out->dia = 1;
        out->mes = 1;
        out->ano = 2000;
    }
    return 1;
}

int data_compara(Data a, Data b) {
    /* TODO(aluno): comparar datas para suportar ordenação de despesas. */
    printf("Ainda não implementado: data_compara\n");
    (void)a;
    (void)b;
    return 0;
}

int data_para_string(Data d, char* out, int out_size) {
    /* TODO(aluno): formatar data como dd/mm/aaaa com validação de buffer. */
    printf("Ainda não implementado: data_para_string\n");
    (void)d;
    (void)out;
    (void)out_size;
    return 1;
}

int data_de_string(const char* texto, Data* out) {
    /* TODO(aluno): converter string para Data, tratando erros de parsing. */
    printf("Ainda não implementado: data_de_string\n");
    (void)texto;
    (void)out;
    return 1;
}
