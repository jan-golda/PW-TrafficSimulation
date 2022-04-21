#ifndef PW_TRAFFICSIMULATION_ONEWAYSPLITDISPATCHER_H
#define PW_TRAFFICSIMULATION_ONEWAYSPLITDISPATCHER_H


#include "MatrixDispatcher.h"

namespace sim {
    /**
     * Dispatcher for fully-connected junctions with one input node and two output nodes.
     */
    class OneWaySplitDispatcher : public MatrixDispatcher<1,2> {
    public:
        OneWaySplitDispatcher() {
            edges[0][0] = true;
            edges[0][1] = true;
        }
    };
}


#endif //PW_TRAFFICSIMULATION_ONEWAYSPLITDISPATCHER_H
