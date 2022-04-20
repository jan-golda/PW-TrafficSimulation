#ifndef PW_TRAFFICSIMULATION_ONEWAYJOINDISPATCHER_H
#define PW_TRAFFICSIMULATION_ONEWAYJOINDISPATCHER_H


#include "MatrixDispatcher.h"

namespace sim {
    class OneWayJoinDispatcher : public MatrixDispatcher<2,1> {
    public:
        OneWayJoinDispatcher() {
            edges[0][0] = true;
            edges[1][0] = true;

            edgesDependencies[{0,0}] = {{1,0}};
            edgesDependencies[{1,0}] = {{0,0}};
        }
    };
}


#endif //PW_TRAFFICSIMULATION_ONEWAYJOINDISPATCHER_H
