#include <iostream>
#include <cmath>
#include "neuron.h"

using namespace std;

class NeuralNetwork  {
  public:
    NeuralNetwork() {}
  
    void feedforward(double *inputs) {
    
    }
    
    double sigmoid(double activation) {
      return 1 / (1 + exp(-activation));
    }
    
    double sigmoid_derivative(double activation) {
      return sigmoid(activation) * (1 - sigmoid(activation));
    }
};

