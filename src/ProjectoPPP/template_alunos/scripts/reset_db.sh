#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DB_DIR="${ROOT_DIR}/db"

mkdir -p "${DB_DIR}"
: > "${DB_DIR}/alunos.txt"
: > "${DB_DIR}/despesas.txt"

echo "Base de dados do template reiniciada."
