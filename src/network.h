#include "neuron.h"
#include "layer.h"
#include "functions.h"

class MLP {
    public:
        
        MLP (int, int, int*, int) {}
    
    private:
        
        Layer **layers;
        int num_layers;
};

