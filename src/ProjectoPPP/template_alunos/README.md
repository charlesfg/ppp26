# Template Didático PPP

Este diretório contém um **esqueleto funcional** do projeto para os alunos implementarem.

## Objetivo pedagógico

- Manter contrato (headers, structs e assinaturas) já definido.
- Deixar toda lógica em stubs com mensagem: `Ainda não implementado: <funcao>`.
- Permitir compilação, execução e smoke tests desde o início.

## Estrutura

- `src/`: módulos da arquitetura (`ui`, `app`, `db`, `aluno`, `despesa`, `data`, `lista`, `main`).
- `db/`: ficheiros de persistência em texto.
- `scripts/`: reset, seed, simulação e validação.
- `test/`: testes smoke.

## Ordem sugerida para implementação pelos alunos

1. `data.c` (validação/comparação de datas).
2. `aluno.c` e `lista.c` (listas ligadas).
3. `despesa.c`.
4. `app.c` (regras de negócio).
5. `db.c` (carregar/guardar).
6. `ui.c` (interação completa com utilizador).

## Comandos

```bash
make -C template_alunos all
make -C template_alunos test
template_alunos/scripts/reset_db.sh
template_alunos/scripts/seed_db.sh
template_alunos/scripts/simular_utilizacao.sh
template_alunos/scripts/validar_cenario.sh
```
