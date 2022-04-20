#ifndef PW_TRAFFICSIMULATION_TWOONECROSSINGDISPATCHER_H
#define PW_TRAFFICSIMULATION_TWOONECROSSINGDISPATCHER_H


#include "MatrixDispatcher.h"

namespace sim {
    class TwoOneCrossingDispatcher : public MatrixDispatcher<3,3> {
    public:
        TwoOneCrossingDispatcher() {
            edges[0][0] = true;
            edges[1][1] = true;
            edges[2][2] = true;

            edgesDependencies[{0,0}] = {{1,1}, {2,2}};
            edgesDependencies[{1,1}] = {{0,0}};
            edgesDependencies[{2,2}] = {{0,0}};
        }
    };
}


#endif //PW_TRAFFICSIMULATION_TWOONECROSSINGDISPATCHER_H
