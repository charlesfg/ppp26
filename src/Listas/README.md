# Listas Dinamicas em C (Material Didatico)

Este modulo foi criado para treinar tres formas classicas de implementar a abstracao de lista dinamica simplesmente encadeada.

## O que existe nesta pasta

- `lista_simples.h/.c`: lista com apenas ponteiro para o inicio.
- `lista_cabeca.h/.c`: lista com no cabecalho (no auxiliar).
- `lista_descritor.h/.c`: lista com descritor (`inicio`, `fim`, `tamanho`).
- `teste_listas.c`: programa de testes didaticos com mensagens de ajuda.
- `Makefile`: compila e executa testes de cada implementacao.

## Operacoes implementadas (nas 3 versoes)

- `criar`
- `vazia`
- `inserir_inicio`
- `inserir_fim`
- `inserir_ordenado` (ordem crescente)
- `remover_inicio`
- `buscar`
- `tamanho`
- `imprimir`
- `limpar`

## Regra da insercao ordenada

A operacao `inserir_ordenado` sempre mantem a lista em ordem crescente.

Regra para valores repetidos: o novo valor e inserido **depois** dos valores menores e tambem depois dos iguais ja existentes (estavel para iguais).

Exemplo:

- Se a lista for `[ 10 20 20 30 ]` e inserir `20`, o resultado esperado e `[ 10 20 20 20 30 ]`.

## Como compilar e testar

Dentro de `src/Listas`:

```bash
make
make test
```

Executar um teste especifico:

```bash
make test_simples
make test_cabeca
make test_descritor
```

Limpar binarios:

```bash
make clean
```

## Como usar os testes para aprender

Quando um teste falha, ele mostra:

- operacao testada,
- valor esperado,
- valor obtido,
- dica de onde investigar no codigo.

Objetivo pedagogico: ajudar voce a encontrar erros comuns de ponteiros, encadeamento de nos e atualizacao de tamanho/logica da lista.
