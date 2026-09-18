FROM debian:bookworm-slim

WORKDIR /app

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
    && rm -rf /var/lib/apt/lists/*

COPY . .

RUN cmake -S . -B build \
    && cmake --build build

CMD ["./build/AdamOptmizer"]
