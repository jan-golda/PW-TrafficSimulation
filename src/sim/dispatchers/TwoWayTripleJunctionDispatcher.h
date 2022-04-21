#ifndef PW_TRAFFICSIMULATION_TWOWAYTRIPLEJUNCTIONDISPATCHER_H
#define PW_TRAFFICSIMULATION_TWOWAYTRIPLEJUNCTIONDISPATCHER_H

#include "MatrixDispatcher.h"

namespace sim {
    /**
     * Dispatcher for fully-connected junctions with three two-way connections.
     */
    class TwoWayTripleJunctionDispatcher : public MatrixDispatcher<3,3> {
    public:
        TwoWayTripleJunctionDispatcher() {
            edges[0][1] = true;
            edges[0][2] = true;
            edges[1][0] = true;
            edges[1][2] = true;
            edges[2][0] = true;
            edges[2][1] = true;

            edgesDependencies[{0,1}] = {{2,1}};
            edgesDependencies[{1,2}] = {{0,2}};
            edgesDependencies[{2,0}] = {{1,0}};
            edgesDependencies[{0,2}] = {{1,0}, {2,1}, {1,2}};
            edgesDependencies[{1,0}] = {{0,2}, {2,1}, {2,0}};
            edgesDependencies[{2,1}] = {{0,2}, {1,0}, {0,1}};
        }
    };
}


#endif //PW_TRAFFICSIMULATION_TWOWAYTRIPLEJUNCTIONDISPATCHER_H
