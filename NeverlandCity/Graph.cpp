//
// Created by Dor Shukrun on 18/01/2023.
//

#include "Graph.h"

Graph::Graph() {
    // matGraph is initialized as an empty vector
    this->size = 0;
    this->nextVertex = 0;


}

Graph::~Graph() = default;

int Graph::addVertex() {
    std::vector<int> temp;

    for (int j = 0; j < nextVertex; j++) {
        temp.push_back(-1);
    }
    matGraph.push_back(temp);

    for (auto & i : matGraph) {
        i.push_back(-1);

    }
    nextVertex++;
    size++;

    return nextVertex - 1;


}

bool Graph::delVertex(int vertex) {
    if (vertex > nextVertex) return false;
    if (vertex < 0) return false;
    for (int i = 0; i < nextVertex; i++) {
        matGraph[i][vertex] = -2;
        matGraph[vertex][i] = -2;
    }
    size--;
    return true;
}

bool Graph::updateWeight(int source, int dest, int weight) {
    if (source > nextVertex || dest > nextVertex) return false;
    if (source < 0 || dest < 0) return false;
    matGraph[source][dest] = weight;
    return true;
}

bool Graph::isVertexExist(int vertex) {
    return (matGraph[vertex][vertex] == -2);
}

std::vector<int> Graph::getNeighbors(int vertex) {
    std::vector<int> neighbors;
    for (int i = 0; i < nextVertex; i++) {
        if (matGraph[vertex][i] > 0) neighbors.push_back(i);
    }
    return neighbors;
}

int Graph::getWeight(int source, int dest) {
    return matGraph[source][dest];
}

std::set<int> Graph::getConnections(int vertex) {
    this->connect.clear();
    std::vector<int> allIn = getNeighbors(vertex);
    for (int i: allIn) {
        connect.insert(i);
        helper(i);
    }
    connect.erase(vertex);
    return connect;

}

void Graph::helper(int vertex) {
    std::vector<int> neighbors = getNeighbors(vertex);
    if (neighbors.empty()) return;

    for (int &neighbor: neighbors) {
        if (connect.find(neighbor) != connect.end()) continue;

        connect.insert(neighbor);
        helper(neighbor);
    }
}

void Graph::addEdge(int source, int dest) {
    updateWeight(source, dest, 10);

};

void Graph::delEdge(int source, int dest) {
    updateWeight(source, dest, -1);
};



std::ostream &operator<<(std::ostream &stream, Graph &mg) {
    std::vector<int> temp;
    for (int i = 0; i < mg.nextVertex; ++i) {
        temp = mg.getNeighbors(i);
        if (mg.matGraph[i][i] == -2) continue;
        stream << i;
        for (int j : temp) stream << " " << j;
        stream << std::endl;
    }

    return stream;

}





