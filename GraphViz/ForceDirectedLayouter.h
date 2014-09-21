#ifndef LAYOUTPROCEDURE_H
#define LAYOUTPROCEDURE_H

#include "SimpleGraph.h"

using namespace std;
class ForceDirectedLayouter {
public:
    ForceDirectedLayouter(SimpleGraph& inputGraph):graph(inputGraph){}
    SimpleGraph& doLayoutProcedure(int runtimeSeconds);
private:
    SimpleGraph& graph;
    void doIteration();
    void applyRepulsiveNodeForces();
    void applyAttractiveEdgeForces();
    void applyPerturbation(float raangeStart,float rangeEnd);
    float repulsionForceConstant = 0.001;
    float attractionForceConstant = 0.001;
};

#endif // LAYOUTPROCEDURE_H
