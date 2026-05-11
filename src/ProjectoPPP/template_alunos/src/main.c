#include "app.h"
#include "conf.h"
#include "ui.h"

int main(void) {
    App app;
    app_init(&app);
    (void)app_carregar(&app, DB_ALUNOS_PATH, DB_DESPESAS_PATH);
    ui_corre(&app);
    (void)app_guardar(&app, DB_ALUNOS_PATH, DB_DESPESAS_PATH);
    app_destroy(&app);
    return 0;
}
