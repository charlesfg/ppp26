#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
LOG_FILE="${ROOT_DIR}/test/logs/simulacao_template.log"

falha() {
  echo "ERRO: $1" >&2
  exit 1
}

[[ -f "${LOG_FILE}" ]] || falha "Log de simulação não encontrado."

grep -q "Ainda não implementado: ui_opcao_listar_alunos" "${LOG_FILE}" || falha "Falta mensagem da opção listar."
grep -q "Ainda não implementado: ui_opcao_inserir_aluno" "${LOG_FILE}" || falha "Falta mensagem da opção inserir."
grep -q "Ainda não implementado: ui_opcao_eliminar_aluno" "${LOG_FILE}" || falha "Falta mensagem da opção eliminar."
grep -q "Ainda não implementado: ui_opcao_registar_despesa" "${LOG_FILE}" || falha "Falta mensagem da opção despesa."
grep -q "Ainda não implementado: ui_opcao_carregar_saldo" "${LOG_FILE}" || falha "Falta mensagem da opção saldo."

echo "Validação smoke do template concluída com sucesso."
