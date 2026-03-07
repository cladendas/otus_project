FROM ubuntu:24.04

# Устанавливаем необходимые пакеты
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    curl \
    tar \
    gzip \
    libboost-all-dev \
    sqlite3 \
    libsqlite3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

COPY . .

RUN mkdir -p build

# Устанавливаем стандартный способ сборки
CMD ["bash", "-c", "cd build && cmake .. && make -j$(nproc)"]
