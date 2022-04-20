#ifndef PW_TRAFFICSIMULATION_MATRIXDISPATCHER_H
#define PW_TRAFFICSIMULATION_MATRIXDISPATCHER_H

#include <array>
#include <memory>
#include <map>
#include <list>
#include "../TrafficDispatcher.h"
#include "../TrafficNode.h"

namespace sim {

    /**
     * Alias for graph edge represented as indices (within this dispatcher) of an input node and an output node.
     */
    using Edge = std::pair<std::size_t, std::size_t>;

    /**
     * Abstract, generic implementation of traffic dispatcher which logic is based on edges and dependencies matrices.
     * @tparam NInputs Number of input nodes.
     * @tparam NOutputs Number of output nodes.
     */
    template<std::size_t NInputs, std::size_t NOutputs>
    class MatrixDispatcher : public TrafficDispatcher {
    public:
        /**
         * Updates the dispatcher by applying logic based on edges and dependencies matrices.
         * @param elapsed Time (in seconds) from the last logic update.
         */
        void update(float elapsed) override;

        /**
         * Sets the input node from which the entities will be picked up.
         * @param i Id of the input node position within the dispatcher.
         * @param node Input node.
         */
        void setInputNode(std::size_t i, const std::shared_ptr<TrafficNode>& node);

        /**
         * Sets the output node to which the entities will be redirected.
         * @param i Id of the output node position within the dispatcher.
         * @param node Output node.
         */
        void setOutputNode(std::size_t i, const std::shared_ptr<TrafficNode>& node);

        /**
         * Returns the requested input node.
         * @param i Id of the input node position within the dispatcher.
         */
        std::shared_ptr<TrafficNode> getInputNode(std::size_t i);

        /**
         * Returns the requested output node.
         * @param i Id of the output node position within the dispatcher.
         */
        std::shared_ptr<TrafficNode> getOutputNode(std::size_t i);

    protected:
        /**
         * Incidence matrix that defines possible edges within the dispatcher area of responsibility.
         * Should be modified by subclass constructor in order to define dispatcher specific rules.
         */
        std::array<std::array<bool, NOutputs>, NInputs> edges = {};

        /**
         * Mapping that for an edge defines other edges that have to be checked to avoid collisions.
         * Should be modified by subclass constructor in order to define dispatcher specific rules.
         */
        std::map<Edge, std::vector<Edge>> edgesDependencies;

    private:
        /**
         * Nodes from which the dispatcher will pickup new entities.
         */
        std::array<std::shared_ptr<TrafficNode>, NInputs> inputNodes;

        /**
         * Nodes to which the dispatcher will redirect entities.
         */
        std::array<std::shared_ptr<TrafficNode>, NOutputs> outputNodes;

        /**
         * List of entities (and their corresponding edges) that are currently under supervision of this dispatcher.
         */
        std::list<std::pair<TrafficEntity *, Edge>> entities;

        /**
         * Counting semaphore that keeps track how many entities are traversing between given input and output nodes.
         */
        std::array<std::array<unsigned int, NOutputs>, NInputs> edgesSemaphore = {};

        /**
         * Perform dispatcher simulation logic for an entity that is on the given edge.
         * @param entity Entity to update the logic for.
         * @param edge Edge assigned to the entity.
         * @param elapsed Time (in seconds) from the last logic update.
         * @return if entity was deposited in the target node and should be removed.
         */
        bool checkEntity(TrafficEntity* entity, Edge edge, float elapsed);

        /**
         * Perform dispatcher simulation logic for an input node.
         * @param nodeId Id (within this dispatcher) of an input node.
         */
        void checkInputNode(std::size_t nodeId);

    };
}

#include "MatrixDispatcher.cpp"


#endif //PW_TRAFFICSIMULATION_MATRIXDISPATCHER_H
