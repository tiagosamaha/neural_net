#include <iostream>

using namespace std;

class Layer {
  private:
    int size;
    Neuron *neurons;
    
  public:
    Layer(int number_of_neurons, int inputs_per_neuron) {
      size = number_of_neurons;
      neurons = new Neuron[size];
    }
    
    ~Layer() {
       delete [] neurons;
    }
    
    int get_size() {
      return size;
    }
    
    void info() {
      cout << "Neurons: " << get_size() << "\n";
    }
};

