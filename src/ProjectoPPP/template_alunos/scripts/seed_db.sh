#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DB_DIR="${ROOT_DIR}/db"

mkdir -p "${DB_DIR}"

cat > "${DB_DIR}/alunos.txt" <<'EOF'
20241001;Aluno Exemplo;1;1;01/01/2006;0.00
20241002;Beatriz Demo;2;2;12/05/2005;10.00
EOF

cat > "${DB_DIR}/despesas.txt" <<'EOF'
20241002;2.50;Snack;10/05/2026
EOF

echo "Base de dados do template populada."
