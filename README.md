# Adam Optimizer in C++

[![Build](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com)
[![Docker](https://img.shields.io/badge/docker-supported-blue)](https://www.docker.com/)
[![License](https://img.shields.io/badge/license-MIT-green)](LICENSE)

This project implements the Adam optimization algorithm in C++. The Adam optimizer is widely used in machine learning and deep learning for training models due to its adaptive learning rate capabilities.

## Features

- Implements the Adam optimization algorithm.
- Supports AMSGrad variant.
- Allows for weight decay (L2 regularization).
- Provides a simple interface for parameter updates.

## Requirements

- Docker and Docker Compose installed
- Or a local C++ toolchain with CMake

## Files

- `main.cpp`: Contains the main function demonstrating the usage of the Adam optimizer.
- `AdamOptimizer.hpp`: Header file declaring the `AdamOptimizer` class.
- `AdamOptimizer.cpp`: Implementation of the `AdamOptimizer` class.
- `Dockerfile`: Builds the project inside a container.
- `docker-compose.yml`: Runs the project with Docker Compose.

## Local compilation

To build the project on your machine without Docker:

```bash
mkdir -p build
cmake -S . -B build
cmake --build build
./build/AdamOptmizer
```

## Docker Compose

To build and run the project in a container:

```bash
docker-compose up --build
```

Or, with the newer Compose plugin:

```bash
docker compose up --build
```

This will compile the code inside the container and run the optimizer demo automatically.

## Adam optimizer math

Adam maintains two exponentially weighted moving averages:

- first moment: $m_t = \beta_1 m_{t-1} + (1 - \beta_1) g_t$
- second moment: $v_t = \beta_2 v_{t-1} + (1 - \beta_2) g_t^2$

Because these estimates are biased toward zero early in training, Adam applies bias correction:

- $\hat{m}_t = \frac{m_t}{1 - \beta_1^t}$
- $\hat{v}_t = \frac{v_t}{1 - \beta_2^t}$

The parameter update is then:

- $\theta_t = \theta_{t-1} - \alpha \frac{\hat{m}_t}{\sqrt{\hat{v}_t} + \epsilon}$

where:

- $\theta_t$ is the parameter value
- $g_t$ is the gradient at time $t$
- $\alpha$ is the learning rate
- $\beta_1, \beta_2$ are the exponential decay rates
- $\epsilon$ prevents division by zero

This project also supports the AMSGrad variant, which keeps the maximum of the past squared gradients when computing the denominator.

 
