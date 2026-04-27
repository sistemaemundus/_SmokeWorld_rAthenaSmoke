# Etapa 1: Compilação
FROM debian:bullseye-slim AS builder

WORKDIR /workspace

# Instala dependências de compilação
RUN apt-get update && apt-get install -y \
    gcc g++ make git libmysqlclient-dev \
    zlib1g-dev libpcre3-dev \
    && rm -rf /var/lib/apt/lists/*

# Copia o código do rAthena da sua pasta
COPY _SmokeWorld_rAthena/ /workspace/

# Compila para ARM64
RUN cd src && ./configure && make clean && make sql

# Etapa 2: Imagem final
FROM debian:bullseye-slim

# Instala libs necessárias para rodar
RUN apt-get update && apt-get install -y \
    libmysqlclient21 libpcre3 netcat-openbsd \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /rathena

# Copia o binário compilado e arquivos necessários
COPY --from=builder /workspace /rathena

# Copia script de entrypoint
COPY _SmokeWorld_rAthena/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# Expõe portas do servidor
EXPOSE 5121 6121 6900 6901

ENTRYPOINT ["/entrypoint.sh"]