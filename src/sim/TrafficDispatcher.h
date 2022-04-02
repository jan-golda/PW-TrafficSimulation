#ifndef PW_TRAFFICSIMULATION_TRAFFICDISPATCHER_H
#define PW_TRAFFICSIMULATION_TRAFFICDISPATCHER_H

namespace sim {
    class TrafficDispatcher {
    public:
        virtual void update(float elapsed) = 0;
    };
}


#endif //PW_TRAFFICSIMULATION_TRAFFICDISPATCHER_H
