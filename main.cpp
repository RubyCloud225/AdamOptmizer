#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>
#include "AdamOptimizer.hpp"

namespace {
    struct Sample {
        double x1;
        double x2;
        double target;
    };
}

int main() {
    auto start_total = std::chrono::high_resolution_clock::now();

    std::vector<Sample> data = {
        {0.0, 0.0, 0.0},
        {1.0, 0.0, 1.0},
        {0.0, 1.0, 1.0},
        {1.0, 1.0, 2.0}
    };

    std::vector<double> params = {0.1, -0.2, 0.05};
    AdamOptimizer optimizer(params, 0.05, std::make_tuple(0.9, 0.999), 1e-8, 1e-4, true);

    constexpr int epochs = 200;

    for (int epoch = 1; epoch <= epochs; ++epoch) {
        std::vector<double> grads(params.size(), 0.0);
        double loss = 0.0;

        for (const auto&[x1, x2, target] : data) {
            const double prediction = params[0] * x1 + params[1] * x2 + params[2];
            const double error = prediction - target;
            loss += error * error;

            const double inv_n = 1.0 / static_cast<double>(data.size());
            grads[0] += 2.0 * inv_n * error * x1;
            grads[1] += 2.0 * inv_n * error * x2;
            grads[2] += 2.0 * inv_n * error;
        }

        optimizer.step(grads);

        /*if (epoch % 25 == 0 || epoch == 1) {
            std::cout << "Epoch " << epoch << " | loss = " << std::fixed << std::setprecision(6) << (loss / data.size())
                      << " | params = [" << params[0] << ", " << params[1] << ", " << params[2] << "]" << std::endl;
        }*/
    }

    auto end_total = std::chrono::high_resolution_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_total - start_total).count();

    if (elapsed_ns > 1'000'000) {
        std::cout << "Training complete in " << elapsed_ns / 1000 << " ms" << std::endl;
    } else if (elapsed_ns > 1'000) {
        std::cout << "Training complete in " << elapsed_ns / 1000 << " microseconds" << std::endl;
    } else {
        std::cout << "Training complete in " << elapsed_ns << " ns" << std::endl;
    }
    std::cout << "Final parameters: [" << params[0] << ", " << params[1] << ", " << params[2] << "]" << std::endl;

    return 0;
}