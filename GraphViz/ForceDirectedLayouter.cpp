#include "ForceDirectedLayouter.h"
#include <ctime>
#include <iostream>

SimpleGraph& ForceDirectedLayouter::doLayoutProcedure(int runtimeSeconds){
    time_t startTime = time(NULL);
    double elapsedTime = 0;
    time_t lastWaitingSignDrawing = time(NULL);
    do {
        doIteration();
        elapsedTime = difftime(time(NULL), startTime);
        double timeSincelastWaitingSignDrawing = difftime(time(NULL), lastWaitingSignDrawing);
        if (timeSincelastWaitingSignDrawing>0.5){
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

}

void ForceDirectedLayouter::applyAttractiveEdgeForces(){

}
