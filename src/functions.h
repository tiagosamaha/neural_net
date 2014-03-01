#include <cmath>

double sigmoid(double activation) {
  return 1 / (1 + exp(-activation));
}

double sigmoid_derivative(double activation) {
  return sigmoid(activation) * (1 - sigmoid(activation));
}
