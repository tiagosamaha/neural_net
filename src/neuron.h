#include <iostream>
#include <cstdlib>

using namespace std;

class Neuron {
  private:
    int input_size;
    double *weights;
    double net;
    double output;

  public:
    Neuron() {};
    
    Neuron(int number_of_inputs) {
      input_size = number_of_inputs + 1;
      weights = new double[input_size];
      for (int i=0; i<input_size; i++) {
        weights[i] = ((double) rand() / (RAND_MAX));
      }
    }
    
    ~Neuron() {
      delete [] weights;
    }
    
    double get_weight(int index) {
      return weights[index];
    }
    
    void set_net(double value) {
      net = value;
    }
    
    void set_output(double value) {
      output = value;
    }
    
    void show_weights() {
      for (int i=0; i<input_size; i++)
        cout << weights[i] << "\n";
    }
};

