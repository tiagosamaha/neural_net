#include <iostream>
#include <cstdlib>

#include "network.h"

using namespace std;

int main() {
  srand((unsigned)time(NULL));
  
  int num_input = 9;
  int num_hidden = 2;
  int hidden_neurons[] = {5,4};
  int num_output = 2;
  
  MLP *nn = new MLP(num_input, num_hidden, hidden_neurons, num_output);
  
  return 0;
}

