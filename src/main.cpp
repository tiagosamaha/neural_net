#include <iostream>
#include <cstdlib>

#include "network.h"

using namespace std;

void process_xor() {
    int input[2], desired;
    int hidden_neurons[] = {1};
    
    MLP nn(2, 1, hidden_neurons, 2);

    for (int i=0; i<2; i++) {
        input[0] = (rand() % 2 == 1) ? 1.0 : 0.0;
        input[1] = (rand() % 2 == 1) ? 1.0 : 0.0;
        desired = (input[0] != input[1]) ? 1.0 : 0.0;
        
        nn.feedforward(input);
        nn.backpropagate(desired);
    }
}

int main() {
    srand((unsigned)time(NULL));
    
    process_xor(); 
    
    return 0;
}

