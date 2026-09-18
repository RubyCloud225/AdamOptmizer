FROM ubuntu:22.04

WORKDIR /app

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
    && rm -rf /var/lib/apt/lists/*

COPY . .

RUN cmake -S . -B build \
    && cmake --build build

CMD ["./build/AdamOptmizer"]
