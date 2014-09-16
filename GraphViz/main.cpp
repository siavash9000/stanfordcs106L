#include <iostream>
#include <sstream>
#include "SimpleGraph.h"
using namespace std;

void Welcome();

int main() {
    Welcome();
    //TODO: Implement the program
    return 0;
}

/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}

