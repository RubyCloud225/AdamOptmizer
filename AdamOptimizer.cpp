#include "AdamOptimizer.hpp"
#include <cmath>

AdamOptimizer::AdamOptimizer(std::vector<double>& params, double learning_rate, const std::tuple<double, double> &beta, double eps, double weight_decay, bool amsgrad) : params(params), learning_rate(learning_rate), beta1(std::get<0>(beta)), beta2(std::get<1>(beta)), eps(eps), weight_decay(weight_decay), amsgrad(amsgrad), t(0) {
    m = std::vector<double>(params.size(), 0.0);
    v = std::vector<double>(params.size(), 0.0);
    if (amsgrad) {
        v_hat.resize(params.size(), 0.0); // maximum of v
    }
}

void AdamOptimizer::step(const std::vector<double>& grads) {
    t++;
    for (size_t i = 0; i < params.size(); i++) {
        // Apply L2 regularization
        double grad = grads[i] + weight_decay * params[i];
        // Update biased first moment estimate
        m[i] = beta1 * m[i] + (1 - beta1) * grad;
        // Update biased second raw moment estimate using squared gradient
        v[i] = beta2 * v[i] + (1 - beta2) * grad * grad;
        // compute bias-corrected moment estimates
        double m_hat = m[i] / (1 - pow(beta1, t));
        double v_hat_value = v[i] / (1 - pow(beta2, t));
        if (amsgrad) {
            // add a lower cap to v_t (AMSGrad)
            if (v_hat[i] < v[i]) {
                v_hat[i] = v[i];
            }
            v_hat_value = v_hat[i] / (1 - pow(beta2, t));
        }
        // update parameters
        params[i] -= learning_rate * m_hat / (std::sqrt(v_hat_value) + eps);
    }
}
