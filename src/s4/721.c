#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

// Compara duas datas t1 e t2
int comparaDatas(Data t1, Data t2) {
    if (t1.ano == t2.ano) {
        if (t1.mes == t2.mes) {
            if (t1.dia == t2.dia) {
                return 0;
            } else if (t1.dia > t2.dia) {
                return 1;
            } else {
                return -1;
            }
        } else if (t1.mes > t2.mes) {
            return 1;
        } else {
            return -1;
        }
    } else if (t1.ano > t2.ano) {
        return 1;
    } else {
        return -1;
    }
}

// gera vetor do tipo Data que deve estar alocado previamente
void generate_datas(Data* vec, int s) {
    int i;

    for (i = 0; i < s; i++) {
        vec[i].ano = rand() % 2000 + 1000;
        vec[i].mes = rand() % 11 + 1;
        vec[i].dia = rand() % 27 + 1;
    }
}

void print_data(Data d) {
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}
void print_data_vec(Data vec[], int s) {
    int i;

    for (i = 0; i < s; i++) {
        print_data(vec[i]);
    }
}

// Ordena o vetor in plance
void ordena_datas(Data v[], int s) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (comparaDatas(v[i], v[j]) == -1) {
                Data tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}

// função que retorna o menor

Data menor_data(Data v[], int s) {
    ordena_datas(v, s);
    return v[0];
}

#define VEC_SIZE 10

int main() {
    Data v[10];

    generate_datas(v, VEC_SIZE);

    printf("Antes: \n");
    print_data_vec(v, VEC_SIZE);
    ordena_datas(v, VEC_SIZE);
    printf("Depois: \n");
    print_data_vec(v, VEC_SIZE);
    printf("Menor data é a ");
    print_data(menor_data(v, VEC_SIZE));
}