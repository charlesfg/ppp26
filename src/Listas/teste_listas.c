#include <stdio.h>

#if defined(TESTE_SIMPLES)
#include "lista_simples.h"
typedef lista_simples lista_t;
typedef ls_no no_t;
#define IMPLEMENTACAO_NOME "Lista Simples (ponteiro de inicio)"
#define criar ls_criar
#define vazia ls_vazia
#define inserir_inicio ls_inserir_inicio
#define inserir_fim ls_inserir_fim
#define inserir_ordenado ls_inserir_ordenado
#define remover_inicio ls_remover_inicio
#define buscar ls_buscar
#define op_tamanho ls_tamanho
#define imprimir ls_imprimir
#define limpar ls_limpar
#define PRIMEIRO_NO(L) ((L)->inicio)
#elif defined(TESTE_CABECA)
#include "lista_cabeca.h"
typedef lista_cabeca lista_t;
typedef lc_no no_t;
#define IMPLEMENTACAO_NOME "Lista com No Cabecalho"
#define criar lc_criar
#define vazia lc_vazia
#define inserir_inicio lc_inserir_inicio
#define inserir_fim lc_inserir_fim
#define inserir_ordenado lc_inserir_ordenado
#define remover_inicio lc_remover_inicio
#define buscar lc_buscar
#define op_tamanho lc_tamanho
#define imprimir lc_imprimir
#define limpar lc_limpar
#define PRIMEIRO_NO(L) ((L)->cabeca.prox)
#elif defined(TESTE_DESCRITOR)
#include "lista_descritor.h"
typedef lista_descritor lista_t;
typedef ld_no no_t;
#define IMPLEMENTACAO_NOME "Lista com Descritor (inicio/fim/tamanho)"
#define criar ld_criar
#define vazia ld_vazia
#define inserir_inicio ld_inserir_inicio
#define inserir_fim ld_inserir_fim
#define inserir_ordenado ld_inserir_ordenado
#define remover_inicio ld_remover_inicio
#define buscar ld_buscar
#define op_tamanho ld_tamanho
#define imprimir ld_imprimir
#define limpar ld_limpar
#define PRIMEIRO_NO(L) ((L)->inicio)
#else
#error "Defina TESTE_SIMPLES, TESTE_CABECA ou TESTE_DESCRITOR"
#endif

#define NO_VALOR(N) ((N)->valor)
#define NO_PROX(N) ((N)->prox)
#define MAX_STEPS_TRAVERSAL 1000

static int g_total_testes = 0;
static int g_testes_ok = 0;

static void reportar_resultado(int ok,
                               const char *titulo,
                               const char *operacao,
                               const char *esperado,
                               const char *obtido,
                               const char *dica) {
    g_total_testes++;
    if (ok) {
        g_testes_ok++;
        printf("[PASS] %s\n", titulo);
        return;
    }

    printf("[FAIL] %s\n", titulo);
    printf("  Operacao: %s\n", operacao);
    printf("  Esperado: %s\n", esperado);
    printf("  Obtido  : %s\n", obtido);
    printf("  Dica    : %s\n", dica);
}

static int contar_nos_com_guarda(const lista_t *lista) {
    const no_t *atual = PRIMEIRO_NO(lista);
    int count = 0;

    while (atual != NULL) {
        count++;
        if (count > MAX_STEPS_TRAVERSAL) {
            return -1;
        }
        atual = NO_PROX(atual);
    }

    return count;
}

static void texto_array(const int *v, int n, char *out, size_t out_size) {
    size_t usado = 0;
    int i;

    if (out_size == 0) {
        return;
    }

    usado += (size_t)snprintf(out + usado, out_size - usado, "[ ");
    for (i = 0; i < n && usado < out_size; i++) {
        usado += (size_t)snprintf(out + usado, out_size - usado, "%d ", v[i]);
    }
    if (usado < out_size) {
        (void)snprintf(out + usado, out_size - usado, "]");
    }
}

static void texto_lista(const lista_t *lista, char *out, size_t out_size) {
    const no_t *atual = PRIMEIRO_NO(lista);
    size_t usado = 0;
    int passos = 0;

    if (out_size == 0) {
        return;
    }

    usado += (size_t)snprintf(out + usado, out_size - usado, "[ ");
    while (atual != NULL && usado < out_size) {
        usado += (size_t)snprintf(out + usado, out_size - usado, "%d ", NO_VALOR(atual));
        atual = NO_PROX(atual);
        passos++;
        if (passos > MAX_STEPS_TRAVERSAL) {
            usado += (size_t)snprintf(out + usado, out_size - usado, "... possivel ciclo ");
            break;
        }
    }
    if (usado < out_size) {
        (void)snprintf(out + usado, out_size - usado, "]");
    }
}

static int lista_igual_array(const lista_t *lista, const int *esperado, int n_esperado) {
    const no_t *atual = PRIMEIRO_NO(lista);
    int i = 0;
    int passos = 0;

    while (atual != NULL && i < n_esperado) {
        if (NO_VALOR(atual) != esperado[i]) {
            return 0;
        }
        atual = NO_PROX(atual);
        i++;
        passos++;
        if (passos > MAX_STEPS_TRAVERSAL) {
            return 0;
        }
    }

    if (i != n_esperado) {
        return 0;
    }

    if (atual != NULL) {
        return 0;
    }

    return 1;
}

static void validar_estado_lista(const char *titulo,
                                 const lista_t *lista,
                                 const int *esperado,
                                 int n_esperado,
                                 const char *dica) {
    char txt_esperado[256];
    char txt_obtido[256];
    int ok = lista_igual_array(lista, esperado, n_esperado);

    texto_array(esperado, n_esperado, txt_esperado, sizeof(txt_esperado));
    texto_lista(lista, txt_obtido, sizeof(txt_obtido));

    reportar_resultado(ok, titulo, "verificacao da sequencia de valores", txt_esperado, txt_obtido, dica);
}

static void teste_criacao_e_estado_inicial(void) {
    lista_t lista;
    int removido = -1;

    criar(&lista);

    reportar_resultado(vazia(&lista) == 1,
                       "Criacao: lista inicia vazia",
                       "vazia() apos criar()",
                       "1 (verdadeiro)",
                       vazia(&lista) ? "1" : "0",
                       "A funcao criar() deve configurar a estrutura para estado vazio.");

    reportar_resultado(op_tamanho(&lista) == 0,
                       "Criacao: tamanho inicia em 0",
                       "tamanho() apos criar()",
                       "0",
                       op_tamanho(&lista) == 0 ? "0" : "nao-zero",
                       "Confirme inicializacao dos campos e retorno correto de tamanho().");

    reportar_resultado(remover_inicio(&lista, &removido) == 0,
                       "Remocao em lista vazia nao deve funcionar",
                       "remover_inicio() com lista vazia",
                       "0 (falha controlada)",
                       "1 (removeu indevidamente)",
                       "Antes de remover, verifique se a lista esta vazia.");

    reportar_resultado(buscar(&lista, 42) == 0,
                       "Busca em lista vazia deve retornar falso",
                       "buscar(42) em lista vazia",
                       "0",
                       buscar(&lista, 42) ? "1" : "0",
                       "Percurso de busca deve terminar em NULL sem encontrar valor.");

    limpar(&lista);
}

static void teste_insercao_inicio_fim_ordem(void) {
    lista_t lista;
    int esperado[] = {10, 20, 30};

    criar(&lista);

    reportar_resultado(inserir_inicio(&lista, 20) == 1,
                       "Inserir no inicio (primeiro elemento)",
                       "inserir_inicio(20)",
                       "1",
                       "0",
                       "Verifique alocacao de no e ajuste de ponteiro inicial.");

    reportar_resultado(inserir_inicio(&lista, 10) == 1,
                       "Inserir no inicio (novo primeiro)",
                       "inserir_inicio(10)",
                       "1",
                       "0",
                       "Novo no deve apontar para antigo inicio.");

    reportar_resultado(inserir_fim(&lista, 30) == 1,
                       "Inserir no fim",
                       "inserir_fim(30)",
                       "1",
                       "0",
                       "No fim, o ultimo no atual deve passar a apontar para o novo no.");

    validar_estado_lista("Ordem apos insercoes no inicio/fim",
                         &lista,
                         esperado,
                         3,
                         "Se a ordem falhou, revise encadeamento de ponteiros nas insercoes.");

    reportar_resultado(op_tamanho(&lista) == 3,
                       "Tamanho apos 3 insercoes",
                       "tamanho()",
                       "3",
                       op_tamanho(&lista) == 3 ? "3" : "valor incorreto",
                       "Conte corretamente os nos de dados da lista.");

    limpar(&lista);
}

static void teste_remocao_inicio_transicoes(void) {
    lista_t lista;
    int v = -1;

    criar(&lista);
    inserir_fim(&lista, 100);
    inserir_fim(&lista, 200);

    reportar_resultado(remover_inicio(&lista, &v) == 1 && v == 100,
                       "Remover inicio: primeiro valor correto",
                       "remover_inicio() em [100, 200]",
                       "sucesso e valor 100",
                       "falha ou valor diferente",
                       "A remocao deve retirar o no apontado pelo inicio da lista.");

    reportar_resultado(remover_inicio(&lista, &v) == 1 && v == 200,
                       "Remover inicio: segundo valor correto",
                       "remover_inicio() em [200]",
                       "sucesso e valor 200",
                       "falha ou valor diferente",
                       "Apos remover o penultimo, o ultimo tambem deve ser removivel sem erros.");

    reportar_resultado(vazia(&lista) == 1,
                       "Apos remover todos, lista volta a ficar vazia",
                       "vazia() apos duas remocoes",
                       "1",
                       vazia(&lista) ? "1" : "0",
                       "Confirme ajuste de ponteiros apos remover o ultimo elemento.");

    reportar_resultado(remover_inicio(&lista, &v) == 0,
                       "Remocao extra em lista vazia permanece controlada",
                       "remover_inicio() novamente",
                       "0",
                       "1",
                       "Nao remova quando inicio for NULL (ou cabeca->prox for NULL).");

    limpar(&lista);
}

static void teste_busca(void) {
    lista_t lista;

    criar(&lista);
    inserir_fim(&lista, 4);
    inserir_fim(&lista, 8);
    inserir_fim(&lista, 15);

    reportar_resultado(buscar(&lista, 8) == 1,
                       "Busca de elemento existente",
                       "buscar(8)",
                       "1",
                       buscar(&lista, 8) ? "1" : "0",
                       "A busca deve percorrer todos os nos ate encontrar o valor.");

    reportar_resultado(buscar(&lista, 16) == 0,
                       "Busca de elemento inexistente",
                       "buscar(16)",
                       "0",
                       buscar(&lista, 16) ? "1" : "0",
                       "Se nao encontrou, o retorno deve ser 0 ao chegar em NULL.");

    limpar(&lista);
}

static void teste_limpar(void) {
    lista_t lista;

    criar(&lista);
    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    limpar(&lista);

    reportar_resultado(vazia(&lista) == 1 && op_tamanho(&lista) == 0,
                       "Limpar zera a lista",
                       "limpar()",
                       "lista vazia e tamanho 0",
                       "estado diferente do vazio",
                       "Limpe todos os nos e restaure estado inicial da estrutura.");

    reportar_resultado(buscar(&lista, 2) == 0,
                       "Busca apos limpar nao encontra elementos antigos",
                       "buscar(2) depois de limpar",
                       "0",
                       buscar(&lista, 2) ? "1" : "0",
                       "Se ainda encontra elementos, pode haver no nao liberado ou ponteiro incorreto.");

    limpar(&lista);
}

static void teste_insercao_ordenada_casos_classicos(void) {
    lista_t lista;
    int esperado[] = {10, 20, 30, 30, 40, 50};

    criar(&lista);

    inserir_ordenado(&lista, 40);
    inserir_ordenado(&lista, 10);
    inserir_ordenado(&lista, 50);
    inserir_ordenado(&lista, 30);
    inserir_ordenado(&lista, 30);
    inserir_ordenado(&lista, 20);

    validar_estado_lista("Insercao ordenada: vazio, inicio, meio, fim e duplicados",
                         &lista,
                         esperado,
                         6,
                         "Revise condicao do while em inserir_ordenado() e onde ligar o novo no.");

    reportar_resultado(op_tamanho(&lista) == 6,
                       "Insercao ordenada: tamanho consistente",
                       "tamanho() apos 6 insercoes ordenadas",
                       "6",
                       op_tamanho(&lista) == 6 ? "6" : "valor incorreto",
                       "Toda insercao bem-sucedida deve incrementar o tamanho logico da lista.");

    limpar(&lista);
}

static void teste_insercao_ordenada_sequencia_aleatoria(void) {
    lista_t lista;
    int entrada[] = {7, 1, 9, 2, 8, 3, 3, 0, 10, -1};
    int esperado[] = {-1, 0, 1, 2, 3, 3, 7, 8, 9, 10};
    int i;

    criar(&lista);

    for (i = 0; i < (int)(sizeof(entrada) / sizeof(entrada[0])); i++) {
        reportar_resultado(inserir_ordenado(&lista, entrada[i]) == 1,
                           "Insercao ordenada: insercao individual",
                           "inserir_ordenado(valor)",
                           "1",
                           "0",
                           "Falha aqui indica problema de alocacao ou encadeamento.");
    }

    validar_estado_lista("Insercao ordenada: entrada fora de ordem gera lista crescente",
                         &lista,
                         esperado,
                         10,
                         "A lista final deve ficar em ordem crescente independente da ordem de entrada.");

    limpar(&lista);
}

static void teste_alternancia_operacoes(void) {
    lista_t lista;
    int v = -1;
    int esperado[] = {4, 5};

    criar(&lista);

    inserir_fim(&lista, 1);
    remover_inicio(&lista, &v);
    inserir_inicio(&lista, 3);
    inserir_fim(&lista, 4);
    remover_inicio(&lista, &v);
    inserir_fim(&lista, 5);

    validar_estado_lista("Alternancia de operacoes nao deve quebrar encadeamento",
                         &lista,
                         esperado,
                         2,
                         "Erros aqui geralmente indicam ponteiro nao atualizado em insercao/remocao.");

    limpar(&lista);
}

static void teste_consistencia_tamanho_vs_percurso(void) {
    lista_t lista;
    int declarada;
    int percorrida;
    char obtido[64];

    criar(&lista);
    inserir_fim(&lista, 11);
    inserir_fim(&lista, 22);
    inserir_fim(&lista, 33);
    remover_inicio(&lista, NULL);
    inserir_ordenado(&lista, 15);

    declarada = op_tamanho(&lista);
    percorrida = contar_nos_com_guarda(&lista);

    if (percorrida < 0) {
        reportar_resultado(0,
                           "Consistencia de percurso: possivel ciclo",
                           "percorrer lista para conferir tamanho",
                           "percurso finito",
                           "mais de 1000 passos",
                           "Verifique se algum no ficou apontando para um no anterior (ciclo). ");
    } else {
        (void)snprintf(obtido, sizeof(obtido), "tamanho()=%d e percurso=%d", declarada, percorrida);
        reportar_resultado(declarada == percorrida,
                           "Consistencia: tamanho logico x nos encadeados",
                           "comparar tamanho() com percurso real",
                           "mesmo valor",
                           obtido,
                           "Se diferir, revise atualizacao de tamanho (ou encadeamento).");
    }

    limpar(&lista);
}

static void teste_especifico_simples(void) {
#if defined(TESTE_SIMPLES)
    lista_t lista;
    int esperado[] = {0, 1, 2, 3, 4};

    criar(&lista);
    inserir_inicio(&lista, 3);
    inserir_inicio(&lista, 2);
    inserir_inicio(&lista, 1);
    inserir_fim(&lista, 4);
    inserir_inicio(&lista, 0);

    validar_estado_lista("[Simples] Detectar perda de referencia ao inicio",
                         &lista,
                         esperado,
                         5,
                         "Se faltarem valores antigos, voce pode estar sobrescrevendo o ponteiro inicio incorretamente.");

    limpar(&lista);
#else
    (void)0;
#endif
}

static void teste_especifico_cabecalho(void) {
#if defined(TESTE_CABECA)
    lista_t lista;
    int contagem;

    criar(&lista);
    contagem = contar_nos_com_guarda(&lista);

    reportar_resultado(contagem == 0,
                       "[Cabecalho] No cabecalho nao conta como dado",
                       "contagem de nos de dados apos criar()",
                       "0",
                       contagem == 0 ? "0" : "nao-zero",
                       "O no cabecalho e auxiliar; ele nao deve entrar na logica de dados.");

    inserir_inicio(&lista, 42);
    reportar_resultado(op_tamanho(&lista) == 1,
                       "[Cabecalho] Tamanho apos 1 insercao",
                       "tamanho() apos inserir_inicio(42)",
                       "1",
                       op_tamanho(&lista) == 1 ? "1" : "valor incorreto",
                       "Se tamanho for 2, voce provavelmente contou o cabecalho por engano.");

    limpar(&lista);
#else
    (void)0;
#endif
}

static void teste_especifico_descritor(void) {
#if defined(TESTE_DESCRITOR)
    lista_t lista;

    criar(&lista);

    reportar_resultado(lista.inicio == NULL && lista.fim == NULL && lista.tamanho == 0,
                       "[Descritor] Estado inicial coerente",
                       "inicio/fim/tamanho apos criar()",
                       "inicio=NULL, fim=NULL, tamanho=0",
                       "algum campo incoerente",
                       "No descritor, os tres campos devem representar o mesmo estado logico.");

    inserir_fim(&lista, 9);
    reportar_resultado(lista.inicio == lista.fim && lista.tamanho == 1,
                       "[Descritor] Um unico no: inicio e fim iguais",
                       "inserir_fim(9) na lista vazia",
                       "inicio==fim e tamanho=1",
                       "estado diferente",
                       "Ao inserir o primeiro no, inicio e fim devem apontar para ele.");

    inserir_fim(&lista, 12);
    reportar_resultado(lista.fim != NULL && lista.fim->valor == 12 && lista.tamanho == 2,
                       "[Descritor] Inserir no fim atualiza ponteiro fim",
                       "inserir_fim(12)",
                       "fim->valor=12 e tamanho=2",
                       "fim/tamanho incorretos",
                       "Se fim nao mudou, a operacao no fim nao esta consistente.");

    limpar(&lista);
    reportar_resultado(lista.inicio == NULL && lista.fim == NULL && lista.tamanho == 0,
                       "[Descritor] Limpar restaura descritor",
                       "limpar()",
                       "inicio=NULL, fim=NULL, tamanho=0",
                       "algum campo nao foi resetado",
                       "Depois de limpar, todos os campos do descritor devem voltar ao estado inicial.");
#else
    (void)0;
#endif
}

int main(void) {
    printf("============================================================\n");
    printf("TESTES DIDATICOS - %s\n", IMPLEMENTACAO_NOME);
    printf("Objetivo: ajudar a detectar erros de ponteiro e de logica.\n");
    printf("============================================================\n\n");

    teste_criacao_e_estado_inicial();
    teste_insercao_inicio_fim_ordem();
    teste_remocao_inicio_transicoes();
    teste_busca();
    teste_limpar();
    teste_insercao_ordenada_casos_classicos();
    teste_insercao_ordenada_sequencia_aleatoria();
    teste_alternancia_operacoes();
    teste_consistencia_tamanho_vs_percurso();
    teste_especifico_simples();
    teste_especifico_cabecalho();
    teste_especifico_descritor();

    printf("\n------------------------------------------------------------\n");
    printf("Resumo: %d/%d testes passaram.\n", g_testes_ok, g_total_testes);
    if (g_testes_ok == g_total_testes) {
        printf("Status final: IMPLEMENTACAO CORRETA para os cenarios avaliados.\n");
        return 0;
    }

    printf("Status final: EXISTEM FALHAS. Revise as dicas acima.\n");
    return 1;
}
