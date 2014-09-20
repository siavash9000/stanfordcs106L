#include "GraphReader.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <boost/math/constants/constants.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;
SimpleGraph GraphReader::parseFile(const string& fileName){
    ifstream fileStream(fileName.c_str());
    if(!fileStream.is_open())
        cerr << "Couldn't open the file " << fileName << endl;
    char str[255];
    int lines = 0;
    std::vector<Node> nodes;
    std::vector<Edge> edges;
    while(fileStream) {
        int numberOfNodes;
        fileStream.getline(str, 255);
        if(lines==0){
            numberOfNodes = atoi(str);
            nodes = this->createNodesOnCircle(numberOfNodes);
            cout << "Number of nodes:" << numberOfNodes << endl;
        }
        else {
            if(fileStream){
                vector <string> fields;
                split( fields, str, is_any_of( " " ) );
                size_t start = lexical_cast<size_t>(fields.at(0).c_str());
                size_t end = lexical_cast<size_t>(fields.at(1).c_str());
                Edge edge;
                edge.start = start;
                edge.end = end;
                edges.push_back(edge);
            }
        }
        lines++;
    }
    fileStream.close();
    SimpleGraph loadedGraph;
    loadedGraph.nodes = nodes;
    loadedGraph.edges = edges;
    return loadedGraph;
}

std::vector<Node> GraphReader::createNodesOnCircle(int numberOfNodes){
    std::vector<Node> result;
    for(int i=0;i<numberOfNodes;i++){
        result.push_back(this->createSingleNodeOnCircle(numberOfNodes,i));
    }
    return result;
}

Node GraphReader::createSingleNodeOnCircle(int numberOfNodes,int nodeIndex){
    double pi = boost::math::constants::pi<double>();
    double x = cos((2*pi*nodeIndex)/numberOfNodes);
    double y = sin((2*pi*nodeIndex)/numberOfNodes);
    Node node;
    node.x = x;
    node.y = y;
    return node;
}
