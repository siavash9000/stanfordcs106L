#include "ForceDirectedLayouter.h"
#include <ctime>
#include <iostream>
#include "math.h"

SimpleGraph& ForceDirectedLayouter::doLayoutProcedure(int runtimeSeconds){
    time_t startTime = time(NULL);
    double elapsedTime = 0;
    time_t lastWaitingSignDrawing = time(NULL);
    do {
        doIteration();
        DrawGraph(graph);
        elapsedTime = difftime(time(NULL), startTime);
        double timeSincelastWaitingSignDrawing = difftime(time(NULL), lastWaitingSignDrawing);
        if (timeSincelastWaitingSignDrawing>WAITING_SIGNAL_INTERVALL){
            lastWaitingSignDrawing = time(NULL);
            cout << "*" << endl;
        }
    }
    while(elapsedTime < runtimeSeconds);
    return this->graph;
}

void ForceDirectedLayouter::doIteration(){
    this->applyRepulsiveNodeForces();
    this->applyAttractiveEdgeForces();
}

void ForceDirectedLayouter::applyRepulsiveNodeForces(){
    for(std::vector<int>::size_type i = 0; i != graph.nodes.size(); i++) {
        for(std::vector<int>::size_type j = i+1; j != graph.nodes.size(); j++) {
            Node& zero = graph.nodes.at(i);
            Node& one = graph.nodes.at(j);
            double diffX = one.x - zero.x;
            double diffY = one.y - zero.y;
            double repulsiveForce = REPULSION_CONSTANT / std::sqrt(diffY*diffY+diffX*diffX);
            double theta = atan2(diffY, diffX);
            zero.x -= repulsiveForce*cos(theta);
            zero.y -= repulsiveForce*sin(theta);
            one.x += repulsiveForce*cos(theta);
            one.y += repulsiveForce*cos(theta);
        }
    }
}

void ForceDirectedLayouter::applyAttractiveEdgeForces(){
    for(std::vector<int>::size_type i = 0; i != graph.edges.size(); i++) {
        Edge& currentEdge = graph.edges.at(i);
        Node& zero = graph.nodes[currentEdge.start];
        Node& one = graph.nodes[currentEdge.end];
        double diffX = one.x - zero.x;
        double diffY = one.y - zero.y;
        double repulsiveForce = ATTRACTION_CONSTANT * (diffY*diffY+diffX*diffX);
        double theta = atan2(diffY, diffX);
        zero.x += repulsiveForce*cos(theta);
        zero.y += repulsiveForce*sin(theta);
        one.x -= repulsiveForce*cos(theta);
        one.y -= repulsiveForce*cos(theta);
    }
}
