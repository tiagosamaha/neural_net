#include <iostream>

using namespace std;

class Layer {
  private:
    int size;
    Neuron **neurons;
    
  public:
    Layer(int number_of_neurons, int inputs_per_neuron) {
      size = number_of_neurons;
      neurons = new Neuron*[size];
      for (int i=0; i<size; i++) {
        neurons[i] = new Neuron(inputs_per_neuron);
      }
    }
    
    ~Layer() {
       delete [] neurons;
    }
    
    int get_size() {
      return size;
    }
    
    Neuron* get_neuron(int i) {
      return neurons[i];
    }

    
    void info() {
      cout << "Neurons: " << get_size() << "\n";
    }
};

