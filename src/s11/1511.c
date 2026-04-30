/*
 *   Crie um programa para escrever num ficheiro binário uma lista ordenada
 * por ordem alfabética do nome de pessoas, sendo o nome guardado num campo
 * com 50 bytes e o ano de nascimento no espaço necessário para um int
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

/*
 * Remove o '\n' que pode ficar no fim da string lida com fgets.
 */
void remover_enter(char s[]) {
    size_t tam = strlen(s);

    if (tam > 0 && s[tam - 1] == '\n') {
        s[tam - 1] = '\0';
    }
}

/*
 * Escreve a lista num ficheiro binário.
 * Cada registo escrito terá:
 * - 50 bytes para o nome;
 * - sizeof(int) bytes para o ano de nascimento.
 */
int escrever_binario(const char* nome_ficheiro, struct list_node* lista) {
    FILE* f = fopen(nome_ficheiro, "wb");

    if (f == NULL) {
        perror("Erro ao abrir o ficheiro");
        return 0;
    }

    struct list_node* atual = lista;

    while (atual != NULL) {
        size_t escritos = fwrite(&atual->per, sizeof(struct person), 1, f);

        if (escritos != 1) {
            perror("Erro ao escrever no ficheiro");
            fclose(f);
            return 0;
        }

        atual = atual->next;
    }

    fclose(f);
    return 1;
}

int main(void) {
    struct list_node* lista = create();
    int n;

    printf("Quantas pessoas pretende inserir? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Número inválido.\n");
        return 1;
    }

    /*
     * Limpar o '\n' deixado pelo scanf,
     * antes de usar fgets para ler nomes.
     */
    getchar();

    for (int i = 0; i < n; i++) {
        struct person p;

        printf("\nPessoa %d\n", i + 1);

        printf("Nome: ");
        fgets(p.name, MAX, stdin);
        remover_enter(p.name);

        printf("Ano de nascimento: ");
        if (scanf("%d", &p.age) != 1) {
            printf("Ano inválido.\n");
            empty(lista);
            return 1;
        }

        getchar();
        insert(lista, p);
    }

    printf("\nLista ordenada alfabeticamente:\n");
    print(lista);

    if (escrever_binario("pessoas.bin", lista)) {
        printf("\nFicheiro pessoas.bin escrito com sucesso.\n");
    } else {
        printf("\nErro ao escrever o ficheiro.\n");
    }

    empty(lista);

    return 0;
}