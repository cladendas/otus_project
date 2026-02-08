# Используем официальный образ с поддержкой ARM64 для M1
FROM arm64v8/ubuntu:22.04

# Устанавливаем необходимые пакеты
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    curl \
    tar \
    gzip \
    && rm -rf /var/lib/apt/lists/*

# Устанавливаем Boost
RUN apt-get update && apt-get install -y \
    libboost-all-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

COPY . .

RUN mkdir -p build

# Устанавливаем стандартный способ сборки
CMD ["bash", "-c", "cd build && cmake .. && make -j$(nproc)"]