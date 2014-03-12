#include <iostream>
#include <cstdlib>

#include "network.h"

using namespace std;

int main() {
  srand((unsigned)time(NULL));

  int input[] = {1,1};
  int num_input = 2;
  int num_hidden = 1;
  int hidden_neurons[] = {1};
  int num_output = 2;
  
  MLP *nn = new MLP(num_input, num_hidden, hidden_neurons, num_output);
  nn->feedforward(input);
  
  return 0;  
}

