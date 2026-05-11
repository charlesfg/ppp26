#include <assert.h>
#include <stdio.h>

#include "app.h"
#include "data.h"
#include "lista.h"

static void testa_smoke_app(void) {
    App app;
    Data d = {1, 1, 2000};
    app_init(&app);
    assert(app_carregar(&app, "db/alunos.txt", "db/despesas.txt") == 0);
    assert(app_guardar(&app, "db/alunos.txt", "db/despesas.txt") == 0);
    assert(app_inserir_aluno(&app, "Teste", d, 1, 1, 1) == 1);
    assert(app_eliminar_aluno(&app, 1) == 1);
    assert(app_procurar_aluno(&app, 1) == NULL);
    assert(app_carregar_saldo(&app, 1, 10.0f) == 1);
    assert(app_registar_despesa(&app, 1, 2.5f, "X", d) == 1);
    app_destroy(&app);
}

static void testa_smoke_lista(void) {
    struct person p = {"Aluno", 20};
    assert(create() == NULL);
    assert(empty(NULL) == 1);
    assert(clean(NULL) == NULL);
    insert(NULL, p);
    delete(NULL, "Aluno");
    print_person(p);
    print(NULL);
}

int main(void) {
    testa_smoke_app();
    testa_smoke_lista();
    printf("Testes smoke do template executados.\n");
    return 0;
}
