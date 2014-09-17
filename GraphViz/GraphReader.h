#ifndef GRAPHREADER_H
#define GRAPHREADER_H

#include <string>
#include "SimpleGraph.h"

using namespace std;
class GraphReader {
    public:
        SimpleGraph parseFile(const string& fileName);
    private:
        std::vector<Node> createNodesOnCircle(int numberOfNodes);
        Node createSingleNodeOnCircle(int numberOfNodes,int nodeIndex);
};

#endif // GRAPHREADER_H
