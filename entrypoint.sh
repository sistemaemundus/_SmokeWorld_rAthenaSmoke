#!/bin/bash
set -e

echo "========================================="
echo "Iniciando entrypoint do rAthena SmokeWorld"
echo "========================================="

# Função para aguardar banco de dados
wait_for_db() {
    echo "Aguardando banco de dados em $DB_HOST:$DB_PORT..."
    until nc -z $DB_HOST $DB_PORT; do
        echo "Banco de dados não disponível ainda - aguardando 2 segundos..."
        sleep 2
    done
    echo "? Banco de dados disponível!"
}

# Executa wait_for_db
wait_for_db

# Configura inter_athena.conf com as variáveis de ambiente
echo "Configurando inter_athena.conf..."
cat > /rathena/conf/import/inter_athena.conf << EOF
// Configuração gerada automaticamente pelo entrypoint - SmokeWorld
// Data: $(date)

sql_connection: {
    db_hostname: "$DB_HOST"
    db_port: $DB_PORT
    db_username: "$DB_USER"
    db_password: "$DB_PASS"
    db_database: "$DB_NAME"
    codepage: ""
    case_sensitive: false
}
EOF

echo "? inter_athena.conf configurado com:"
echo "  - Host: $DB_HOST"
echo "  - Porta: $DB_PORT"
echo "  - Database: $DB_NAME"
echo "  - Usuário: $DB_USER"

# Verifica se os arquivos dos servidores existem
cd /rathena

echo "Verificando executáveis do servidor..."
for server in login-server char-server map-server; do
    if [ -f "./$server" ]; then
        echo "  ? $server encontrado"
        chmod +x "./$server"
    else
        echo "  ?? $server não encontrado - verificando se foi compilado corretamente"
    fi
done

echo ""
echo "========================================="
echo "Iniciando servidores SmokeWorld..."
echo "========================================="

# Função para iniciar um servidor e verificar se subiu
start_server() {
    local server=$1
    local port=$2
    
    echo "Iniciando $server na porta $port..."
    ./$server &
    local pid=$!
    
    # Aguarda um pouco e verifica se o processo ainda está rodando
    sleep 2
    if kill -0 $pid 2>/dev/null; then
        echo "  ? $server iniciado com PID $pid"
        return 0
    else
        echo "  ? $server falhou ao iniciar"
        return 1
    fi
}

# Inicia cada servidor (ajuste as portas conforme necessário)
start_server "login-server" "6900"
start_server "char-server" "6121"
start_server "map-server" "5121"

echo ""
echo "? Todos os servidores iniciados!"
echo "Monitorando processos..."

# Mantém container rodando e monitora os processos
while true; do
    sleep 30
    
    # Verifica se os processos ainda estão rodando
    if ! pgrep -f "login-server" > /dev/null; then
        echo "?? login-server não está rodando! Reiniciando..."
        ./login-server &
    fi
    
    if ! pgrep -f "char-server" > /dev/null; then
        echo "?? char-server não está rodando! Reiniciando..."
        ./char-server &
    fi
    
    if ! pgrep -f "map-server" > /dev/null; then
        echo "?? map-server não está rodando! Reiniciando..."
        ./map-server &
    fi
done