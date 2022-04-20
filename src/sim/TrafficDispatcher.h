#ifndef PW_TRAFFICSIMULATION_TRAFFICDISPATCHER_H
#define PW_TRAFFICSIMULATION_TRAFFICDISPATCHER_H


namespace sim {

    /**
     * Abstract base class for traffic dispatchers that manage entities within their area of responsibility.
     */
    class TrafficDispatcher {
    public:
        /**
         * Updates the dispatcher by performing one step of its logic.
         * @param elapsed Time (in seconds) from the last logic update.
         */
        virtual void update(float elapsed) = 0;

    };
}


#endif //PW_TRAFFICSIMULATION_TRAFFICDISPATCHER_H
