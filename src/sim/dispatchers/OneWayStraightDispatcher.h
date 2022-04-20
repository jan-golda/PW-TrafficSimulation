#ifndef PW_TRAFFICSIMULATION_ONEWAYSTRAIGHTDISPATCHER_H
#define PW_TRAFFICSIMULATION_ONEWAYSTRAIGHTDISPATCHER_H


#include "MatrixDispatcher.h"

namespace sim {
    /**
     * The simplest possible dispatcher that has one input node and one output node.
     */
    class OneWayStraightDispatcher : public MatrixDispatcher<1,1> {
    public:
        OneWayStraightDispatcher() {
            edges[0][0] = true;
        }
    };
}


#endif //PW_TRAFFICSIMULATION_ONEWAYSTRAIGHTDISPATCHER_H
