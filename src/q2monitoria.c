

char v[10] = "duvida";
char b[10] = "demais";

// funcao
strcpy(v, b)
    // for
    v[i] = b[i]

    v = b;
printf("%s", v);

char* s = {'A', 'B', 'C'};
char* s = {'A', 'B', '\0'};
char* s = {'A', 'B', 0};
char* s = "ABC";

int transforma(
    char mat[][20],
    int n,
    char resultado[][100]) {
    char tmp[20] = {0};
    char cat[100] = {0};
    int str_sz = 0;
    int res_sz = 0;

    for (int i = 0; i < n; i++) {
        str_sz = 0;
        for (int j = 0; j < 20; j++) {
            if (mat[i][j] != '\0') {
                tmp[str_sz] = mat[i][j];
                str_sz++;
            }
        }
        tmp[str_sz] = '\0';

        if (str_sz >= 5) {
            strcpy(resultado[res_sz], tmp);
            res_sz++;
        } else {
            strcat(cat, tmp);
        }
    }
    if (res_sz < n) {
        strcpy(resultado[res_sz], cat);
    }
    return res_sz;
}
