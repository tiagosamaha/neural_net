#include <iostream>
#include <cstdlib>

#include "neuron.h"
#include "layer.h"

using namespace std;

int main() {
  srand((unsigned)time(NULL));
  
  Neuron *n = new Neuron(3);
  n->show_weights();
  
  Layer *input_l = new Layer(2, 3);
  input_l->info();
  cout << "\n";
  Layer *hidden_l = new Layer(3, input_l->get_size());
  hidden_l->info();
  cout << "\n";
  Layer *output_l = new Layer(1, hidden_l->get_size());
  output_l->info();
  cout << "\n";
  
  return 0;
}

