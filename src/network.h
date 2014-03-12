#include "neuron.h"
#include "layer.h"

class MLP {
    public:
        
        MLP (int, int, int*, int);
        void feedforward (int*);
        double sigmoid(double);
        double sigmoid_derivative(double);
    
    private:
        
        Layer **layers;
        int num_layers;
};

