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
};

#endif // LAYOUTPROCEDURE_H
