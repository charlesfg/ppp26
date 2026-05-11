#ifndef __DATA__H__
#define __DATA__H__

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

int data_valida(Data d);
int data_cria(int dia, int mes, int ano, Data* out);
int data_compara(Data a, Data b);
int data_para_string(Data d, char* out, int out_size);
int data_de_string(const char* texto, Data* out);

#endif
