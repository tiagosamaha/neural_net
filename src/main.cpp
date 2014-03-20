#include <iostream>
#include <cstdlib>

#include "network.h"

using namespace std;

void process_xor() {
    int input[2], desired[1];
    int hidden_neurons[] = {2};
    
    MLP nn(2, 1, hidden_neurons, 1);

    for (int i=0; i<1000; i++) {
        input[0] = (rand() % 2 == 1) ? 1.0 : 0.0;
        input[1] = (rand() % 2 == 1) ? 1.0 : 0.0;
        desired[0] = (input[0] != input[1]) ? 1.0 : 0.0;

        cout << "STEP " << i << "\n\n";
        cout << "INPUT " << input[0] << " " << input[1] << "\n";
        cout << "DESIRED " << desired[0]  << "\n\n";
        nn.feedforward(input);
        nn.backpropagate(desired);
        cout << "\n";
    }
}

int main() {
    srand((unsigned)time(NULL));
    
    process_xor(); 
    
    return 0;
}

