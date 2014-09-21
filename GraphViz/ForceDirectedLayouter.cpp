#include "ForceDirectedLayouter.h"
#include <ctime>
#include <iostream>
#include "math.h"
#include <stdlib.h>
#include <random>

SimpleGraph& ForceDirectedLayouter::doLayoutProcedure(int runtimeSeconds){
    time_t startTime = time(NULL);
    double elapsedTime = 0;
    do {
        doIteration();
        DrawGraph(graph);
        elapsedTime = difftime(time(NULL), startTime);
    }
    while(elapsedTime < runtimeSeconds);
    return this->graph;
}

void ForceDirectedLayouter::doIteration(){
    //applyPerturbation(-0.01,0.01);
    applyRepulsiveNodeForces();
    applyAttractiveEdgeForces();
}

void ForceDirectedLayouter::applyRepulsiveNodeForces(){
    for(std::vector<int>::size_type i = 0; i != graph.nodes.size(); i++) {
        for(std::vector<int>::size_type j = i+1; j != graph.nodes.size(); j++) {
            Node& zero = graph.nodes.at(i);
            Node& one = graph.nodes.at(j);
            double diffX = one.x - zero.x;
            double diffY = one.y - zero.y;
            double repulsiveForce = repulsionForceConstant / sqrt(diffY*diffY+diffX*diffX);
            double theta = atan2(diffY, diffX);
            zero.x -= repulsiveForce*cos(theta);
            zero.y -= repulsiveForce*sin(theta);
            one.x += repulsiveForce*cos(theta);
            one.y += repulsiveForce*sin(theta);
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
        double attractionForce = attractionForceConstant * (diffY*diffY+diffX*diffX);
        double theta = atan2(diffY, diffX);
        zero.x += attractionForce*cos(theta);
        zero.y += attractionForce*sin(theta);
        one.x -= attractionForce*cos(theta);
        one.y -= attractionForce*sin(theta);
    }
}

void ForceDirectedLayouter::applyPerturbation(float raangeStart,float rangeEnd){
    for(std::vector<int>::size_type i = 0; i != graph.nodes.size(); i++) {
        random_device rd;
        default_random_engine e(rd());
        uniform_real_distribution<> d(-raangeStart, rangeEnd);
        Node& node = graph.nodes.at(i);
        node.x += d(e);
        node.y += d(e);
    }
}
