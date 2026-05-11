#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
APP_BIN="${ROOT_DIR}/bin/projectoppp_template"
LOG_DIR="${ROOT_DIR}/test/logs"
LOG_FILE="${LOG_DIR}/simulacao_template.log"

mkdir -p "${LOG_DIR}"

"${ROOT_DIR}/scripts/seed_db.sh" > /dev/null
make -C "${ROOT_DIR}" all > /dev/null

cat <<'EOF' | "${APP_BIN}" > "${LOG_FILE}"
3
1
2
4
5
0
EOF

echo "Simulação do template concluída."
echo "Log: ${LOG_FILE}"
