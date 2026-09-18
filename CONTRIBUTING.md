# Contributing

Thanks for your interest in contributing to this project.

## How to contribute

1. Fork the repository.
2. Create a feature branch from `main`.
3. Make your changes and keep them focused.
4. Run the project locally or in Docker to validate the change.
5. Submit a pull request with a clear description of the update.

## Development workflow

### Local build

```bash
mkdir -p build
cmake -S . -B build
cmake --build build
./build/AdamOptmizer
```

### Docker build

```bash
docker-compose up --build
```

or

```bash
docker compose up --build
```

## Coding guidelines

- Keep changes minimal and easy to review.
- Prefer clear names and readable C++ code.
- Document behavior changes in the README or changelog when relevant.
- Ensure the project still builds after your change.

## Pull request checklist

- The change is tested locally or in Docker.
- The code follows the existing style of the project.
- The README and changelog are updated if needed.
- The change is explained clearly in the PR description.
