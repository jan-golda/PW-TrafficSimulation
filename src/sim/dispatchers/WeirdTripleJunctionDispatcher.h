#ifndef PW_TRAFFICSIMULATION_WEIRDTRIPLEJUNCTIONDISPATCHER_H
#define PW_TRAFFICSIMULATION_WEIRDTRIPLEJUNCTIONDISPATCHER_H

#include "MatrixDispatcher.h"

namespace sim {
    /**
     * Dispatcher for a junction that has a two-way connection joining a one-way to form a one-way output.
     */
    class WeirdTripleJunctionDispatcher : public MatrixDispatcher<2,2> {
    public:
        WeirdTripleJunctionDispatcher() {
            edges[0][0] = true;
            edges[0][1] = true;
            edges[1][0] = true;

            edgesDependencies[{0,0}] = {{1,0}};
            edgesDependencies[{1,0}] = {{0,0}};
        }
    };
}


#endif //PW_TRAFFICSIMULATION_WEIRDTRIPLEJUNCTIONDISPATCHER_H
