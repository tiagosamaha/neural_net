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
      input_size = number_of_inputs; // somar mais um devido ao bias?
      weights = new double[input_size];
      for (int i=0; i<input_size; i++) {
        weights[i] = ((double) rand() / (RAND_MAX));
      }
    }
    
    ~Neuron() {
      delete [] weights;
    }
    
    void set_net(double value) {
      net = value;
    }
    
    void show_weights() {
      for (int i=0; i<input_size; i++)
        cout << weights[i] << "\n";
    }
};

