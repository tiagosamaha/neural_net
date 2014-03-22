#include <iostream>
#include <cstdlib>

#include "network.h"

using namespace std;

void process_person() {
    int input[4][2], desired[4][2];
    int hidden_neurons[] = {2};
    
    input[0][0] = 1, input[0][1] = 1;
    input[1][0] = 1, input[1][1] = 0;
    input[2][0] = 0, input[2][1] = 0;
    input[3][0] = 0, input[3][1] = 1;
    
    desired[0][0] = 0, desired[0][1] = 1;
    desired[1][0] = 0, desired[1][1] = 0;
    desired[2][0] = 1, desired[2][1] = 0;
    desired[3][0] = 1, desired[3][1] = 1;
    
    MLP nn(2, 1, hidden_neurons, 1);

    for (int i=0; i<10000; i++) {
        for (int j=0; j<4; j++) {
			cout << "STEP " << i << "\n\n";
			cout << "INPUT " << input[j][0] << " " << input[j][1] << "\n";
			cout << "DESIRED " << desired[j][0] << " " << desired[j][1]  << "\n\n";
			nn.feedforward(input[j]);
			nn.backpropagate(desired[j]);
			cout << "\n";
        }
    }
}

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
    
    // process_xor(); 
    process_person();
    
    return 0;
}

