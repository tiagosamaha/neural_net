#include <iostream>
#include <cstdlib>

using namespace std;

class Neuron {
    private:
        int input_size;
        double *weights;
        double bias; // bias weight
        double activation;
        double output;
        double delta;

    public:
        Neuron() {};

        Neuron(int number_of_inputs) {
            input_size = number_of_inputs;
            weights = new double[input_size];
            for (int i=0; i<input_size; i++) {
                weights[i] = ((double) rand() / (RAND_MAX));
            }
            bias = ((double) rand() / (RAND_MAX));
        }

        ~Neuron() {
            delete [] weights;
        }

        void update_weight(int index, double value) {
            weights[index] += value;
        }

        void update_bias(double value) {
            bias += value;
        }

        int get_size() {
            return input_size;
        }

        double get_activation() {
            return activation;
        }

        double get_bias() {
            return bias;
        }

        double get_output() {
            return output;
        }

        double get_delta() {
            return delta;
        }

        double get_weight(int index) {
            return weights[index];
        }

        void set_activation(double value) {
            activation = value;
        }

        void set_output(double value) {
            output = value;
        }

        void set_delta(double value) {
            delta = value;
        }
        
        void show_weights() {
            for (int i=0; i<input_size; i++)
                cout << weights[i] << "\n";
        }
};

