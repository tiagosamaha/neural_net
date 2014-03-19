#include "neuron.h"
#include "layer.h"

class MLP {
    public:
        
        MLP (int, int, int*, int);
        void feedforward (int*);
        void backpropagate(int*);
        double sigmoid(double);
        double sigmoid_derivative(double);
    
    private:
        
        Layer **layers;
        double rate;
        int num_layers;
        int num_hidden_layers;
};

