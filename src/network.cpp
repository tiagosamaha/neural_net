#include <iostream>
#include <cmath>

#include "network.h"

using namespace std;
        
MLP::MLP (int num_input, int num_hidden, int *hidden_neurons, int num_output) {
    rate = 0.1; // learning rate
    num_layers = num_hidden + 2;
    num_hidden_layers = num_hidden;
    layers = new Layer*[num_layers];

    layers[0] = new Layer(num_input, num_input);
    layers[1] = new Layer(hidden_neurons[0], num_input);
    for (int k=2; k<num_layers-1; k++) {
        layers[k] = new Layer(hidden_neurons[k-1], hidden_neurons[k-2]);
    }
    layers[num_hidden+1] = new Layer(num_output, hidden_neurons[num_hidden-1]);
}
 
void MLP::feedforward (int *input) {
    for (int i=0; i<layers[0]->get_size(); i++) {
        Neuron *current_neuron = layers[0]->get_neuron(i);
        double sum = 0;
        for (int j=0; j<current_neuron->get_size(); j++) {
            sum += input[j] * current_neuron->get_weight(j);
        }
        sum += current_neuron->get_bias();
        current_neuron->set_activation(sum);
        current_neuron->set_output(sigmoid(sum));
        cout << "layer 0 | "
             << "neuron " << i 
             << " | net " << sum
             << " | y = "
             << current_neuron->get_output() << "\n";
        current_neuron->show_weights();
        cout << "bias "<< current_neuron->get_bias() << "\n\n";
    }

    for (int k=1; k<num_layers; k++) {
        Layer *current_layer = layers[k], *previous_layer = layers[k-1];
        for (int i=0; i<current_layer->get_size(); i++) {
            Neuron *current_neuron = current_layer->get_neuron(i);
            double sum = 0;
            for (int j=0; j<current_neuron->get_size(); j++) {
                sum += previous_layer->get_neuron(j)->get_output()
                    * current_neuron->get_weight(j);
            }
            sum += current_neuron->get_bias();
            current_neuron->set_activation(sum);
            current_neuron->set_output(sigmoid(sum));
            cout << "layer " << k
                 << " | " << "neuron " << i
                 << " | net " << sum
                 << " | y = "
                 << current_neuron->get_output() << "\n";
            current_neuron->show_weights();
            cout << "bias " << current_neuron->get_bias() << "\n\n";
        }
    }
}

void MLP::backpropagate(int *desired) {
    for (int i=0; i<layers[num_hidden_layers+1]->get_size(); i++) {
        Neuron *current_neuron = layers[num_hidden_layers+1]->get_neuron(i);
        double delta = (desired[i] - current_neuron->get_output())
                     * sigmoid_derivative(current_neuron->get_activation());
        current_neuron->set_delta(delta);
    }

    for (int k=num_hidden_layers; k>=0; k--) {
        Layer *current_layer = layers[k], *previous_layer = layers[k+1];

        for (int i=0; i<current_layer->get_size(); i++) {
            double sum = 0;
            Neuron *current_neuron = current_layer->get_neuron(i);
            for (int j=0; j<previous_layer->get_size(); j++) {
                sum += previous_layer->get_neuron(j)->get_delta()
                    * previous_layer->get_neuron(j)->get_weight(i);
            }
            current_neuron->set_delta(
               sigmoid_derivative(current_neuron->get_activation()) * sum
            );
            for (int j=0; j<previous_layer->get_size(); j++) {
                previous_layer->get_neuron(j)->update_weight(i,
                    rate * current_neuron->get_output()
                    * previous_layer->get_neuron(j)->get_delta());
                previous_layer->get_neuron(j)->update_bias(
                    rate * previous_layer->get_neuron(j)->get_delta());
            }
        }
    }
}

double MLP::sigmoid(double activation) {
    return 1 / (1 + exp(-activation));
}

double MLP::sigmoid_derivative(double activation) {
    return sigmoid(activation) * (1 - sigmoid(activation));
}
