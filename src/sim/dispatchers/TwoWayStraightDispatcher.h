#ifndef PW_TRAFFICSIMULATION_TWOWAYSTRAIGHTDISPATCHER_H
#define PW_TRAFFICSIMULATION_TWOWAYSTRAIGHTDISPATCHER_H

#include "MatrixDispatcher.h"

namespace sim {
    /**
     * The simplest possible dispatcher that has two input nodes and two output node arranged to form two separate connections.
     */
    class TwoWayStraightDispatcher : public MatrixDispatcher<2,2> {
    public:
        TwoWayStraightDispatcher() {
            edges[0][0] = true;
            edges[1][1] = true;
        }
    };
}


#endif //PW_TRAFFICSIMULATION_TWOWAYSTRAIGHTDISPATCHER_H
