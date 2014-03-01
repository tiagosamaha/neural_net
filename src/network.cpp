#include <iostream>

#include "network.h"

using namespace std;
        
MLP::MLP (int num_input, int num_hidden, int *hidden_neurons, int num_output) {
	num_layers = num_hidden + 2;
	layers = new Layer*[num_layers];
	
	layers[0] = new Layer(num_input, num_input);
	layers[1] = new Layer(hidden_neurons[0], num_input);
	for (int k=2; k<num_layers-1; k++) {
		layers[k] = new Layer(hidden_neurons[k-1], hidden_neurons[k-2]);
	}
	layers[num_hidden+1] = new Layer(num_output, hidden_neurons[num_hidden-1]);
}
    
