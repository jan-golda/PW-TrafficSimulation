#include "MatrixDispatcher.h"


using namespace sim;

template<std::size_t NInputs, std::size_t NOutputs>
void MatrixDispatcher<NInputs, NOutputs>::updateEntity(TrafficEntity* entity, Edge edge, float elapsed) {
    entity->update(elapsed);

    // if the entity is not near the output node let it drive
    auto outputNode = outputNodes[edge.second];
    if (!entity->isNear(outputNode.get())) return;

    // deposit the entity into the output node
    entities.remove(std::make_pair(entity, edge));
    outputNode->push(entity);
    edgesSemaphore[edge.first][edge.second]--;
}

template<std::size_t NInputs, std::size_t NOutputs>
void MatrixDispatcher<NInputs, NOutputs>::updateInputNode(std::size_t nodeId) {
    auto node = inputNodes[nodeId];

    // check if there is an entity waiting
    if (node->empty()) return;
    auto entity = node->front();

    // get the target node
    // FIXME: apply routing
    std::size_t target = -1;
    for (int i = 0; i < NOutputs; i++) {
        if (edges[nodeId][i]) {
            target = i;
            break;
        }
    }
    if (target == -1) return;

    // edge for this entity
    Edge edge = std::make_pair(nodeId, target);

    // check if the path is clear
    if (edgesDependencies.count(edge))
        for (const auto& dependentEdge : edgesDependencies[edge])
            if (edgesSemaphore[dependentEdge.first][dependentEdge.second])
                return;

    // accept the entity into this dispatcher
    node->pop();
    entities.push_back(std::make_pair(entity, edge));
    edgesSemaphore[edge.first][edge.second]++;
}

template<std::size_t NInputs, std::size_t NOutputs>
void MatrixDispatcher<NInputs, NOutputs>::update(float elapsed) {
    for (const auto& [entity, edge] : entities)
        updateEntity(entity, edge, elapsed);
    for (int i = 0; i < NInputs; i++)
        updateInputNode(i);
}

template<std::size_t NInputs, std::size_t NOutputs>
void MatrixDispatcher<NInputs, NOutputs>::setInputNode(std::size_t i, const std::shared_ptr<TrafficNode>& node) {
    inputNodes[i] = node;
}

template<std::size_t NInputs, std::size_t NOutputs>
void MatrixDispatcher<NInputs, NOutputs>::setOutputNode(std::size_t i, const std::shared_ptr<TrafficNode>& node) {
    outputNodes[i] = node;
}

template<std::size_t NInputs, std::size_t NOutputs>
std::shared_ptr<TrafficNode> MatrixDispatcher<NInputs, NOutputs>::getInputNode(std::size_t i) {
    return inputNodes[i];
}

template<std::size_t NInputs, std::size_t NOutputs>
std::shared_ptr<TrafficNode> MatrixDispatcher<NInputs, NOutputs>::getOutputNode(std::size_t i) {
    return outputNodes[i];
}
