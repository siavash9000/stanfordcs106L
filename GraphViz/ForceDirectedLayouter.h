#ifndef LAYOUTPROCEDURE_H
#define LAYOUTPROCEDURE_H
using namespace std;
class ForceDirectedLayouter {
public:
    ForceDirectedLayouter(SimpleGraph& graph);
    SimpleGraph& doLayoutProcedure(int runtimeSeconds);
private:
    SimpleGraph& doIteration(int runtimeSeconds);
    SimpleGraph& applyRepulsiveNodeForces();
    SimpleGraph& applyAttractiveEdgeForces();
};

#endif // LAYOUTPROCEDURE_H
