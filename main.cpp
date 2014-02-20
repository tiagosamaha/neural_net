#include <iostream>
#include <cstdlib>

#include "neuron.h"
#include "layer.h"

using namespace std;

int main() {
  /* Now this is only to test some features */
  srand((unsigned)time(NULL));
  
  Layer *input_l = new Layer(2, 3);
  
  Neuron *x1 = input_l->get_neuron(0);
  x1->show_weights();
  
  cout << "\n";
  
  Neuron *x2 = input_l->get_neuron(1);
  x2->show_weights();
  
  return 0;
}

