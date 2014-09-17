#ifndef LAYOUTPROCEDURE_H
#define LAYOUTPROCEDURE_H

#include "SimpleGraph.h"

#define WAITING_SIGNAL_INTERVALL 0.5
#define REPULSION_CONSTANT 0.001
#define ATTRACTION_CONSTANT 0.001

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
