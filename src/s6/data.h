#ifndef __DATA_H__
#define __DATA_H__

#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

int comparaDatas(Data t1, Data t2);
int comparaPointerDatas(Data* pt1, Data* pt2);
Data data_diff(Data t1, Data t2);
int seculoData(Data d);

#endif