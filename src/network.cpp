#include <iostream>
#include <cmath>

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
 
void MLP::feedforward (int *input) {
    cout << "Fase FeedForward\n\n";
    for (int i=0; i<layers[0]->get_size(); i++) {
        Neuron *current_neuron = layers[0]->get_neuron(i);
        double sum = 0;
        for (int j=0; j<current_neuron->get_size(); j++) {
            sum += input[j] * current_neuron->get_weight(j);
        }
        current_neuron->set_activation(sum);
        current_neuron->set_output(sigmoid(sum));
        cout << "layer 0 | " << "neuron " << i << " | y = " << sigmoid(sum) << "\n";
    }
    
    for (int k=1; k<num_layers; k++) {
        Layer *current_layer = layers[k];
        Layer *previous_layer = layers[k-1];
        for (int i=0; i<current_layer->get_size(); i++) {
            Neuron *current_neuron = current_layer->get_neuron(i);
            double sum = 0;
            for (int j=0; j<current_neuron->get_size(); j++) {
                sum += previous_layer->get_neuron(j)->get_output() * current_neuron->get_weight(j);
            }
            current_neuron->set_activation(sum);
            current_neuron->set_output(sigmoid(sum));
            cout << "layer " << k << " | " << "neuron " << i << " | y = " << sigmoid(sum) << "\n";
        }
    }
}

double MLP::sigmoid(double activation) {
    return 1 / (1 + exp(-activation));
}

double MLP::sigmoid_derivative(double activation) {
    return sigmoid(activation) * (1 - sigmoid(activation));
}
