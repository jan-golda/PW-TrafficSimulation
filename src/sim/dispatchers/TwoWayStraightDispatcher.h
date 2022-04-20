#ifndef PW_TRAFFICSIMULATION_TWOWAYSTRAIGHTDISPATCHER_H
#define PW_TRAFFICSIMULATION_TWOWAYSTRAIGHTDISPATCHER_H

#include "MatrixDispatcher.h"

namespace sim {
    class TwoWayStraightDispatcher : public MatrixDispatcher<2,2> {
    public:
        TwoWayStraightDispatcher() {
            edges[0][0] = true;
            edges[1][1] = true;
        }
    };
}


#endif //PW_TRAFFICSIMULATION_TWOWAYSTRAIGHTDISPATCHER_H
