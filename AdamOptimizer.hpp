#ifndef ADAMOPTIMIZER_HPP
#define ADAMOPTIMIZER_HPP

#include <vector>
#include <tuple>

class AdamOptimizer {
    public:
    explicit AdamOptimizer(std::vector<double>& params, double learning_rate = 1e-3, const std::tuple<double, double> &beta = std::make_tuple(0.9, 0.999), double eps = 1e-8, double weight_decay = 0.0, bool amsgrad = false);
        void step(const std::vector<double>& grads);
    private:
        std::vector<double>& params; // Parameters to Optimize
        double learning_rate = 1e-3; // Learning Rate
        double beta1; // Coefficient for first moment
        double beta2; // Coefficient for second moment
        double eps = 1e-8; // Small term to prevent division by zero
        double weight_decay = 0.0; // L2 penalty
        bool amsgrad = false; // Use AMSGrad variant
        std::vector<double> m; // First moment
        std::vector<double> v; // Second moment
        std::vector<double> v_hat; // First moment for AMSGrad
        int t;
        // Time step
};

#endif // ADAMOPTIMIZER_HPP