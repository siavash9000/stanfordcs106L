#include <iostream>
#include <sstream>
#include <string>
#include "SimpleGraph.h"
#include "GraphReader.h"
using namespace std;

void Welcome();
string askForFileName();

void recursiveMenu()
{
    GraphReader graphReader;
    SimpleGraph graph = graphReader.parseFile(askForFileName());
    InitGraphVisualizer(graph);
    DrawGraph(graph);
    recursiveMenu();
}

int main() {
    Welcome();
    recursiveMenu();
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

/* Asks user which file to open. All example files has been copied
 * to the executable folder. So only filename is required by the user.
 */
string askForFileName() {
    cout << "Which file do you want open?" << endl;
    cout << "The files can be found in GraphViz/resources. Just type the filename without path." << endl;
    cout << endl;
    string fileName;
    cin >> fileName;
    return fileName;
}

