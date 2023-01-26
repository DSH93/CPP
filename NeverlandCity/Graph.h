//
// Created by Dor Shukrun on 18/01/2023.
//

#ifndef NEVERLANDCITY_GRAPH_H
#define NEVERLANDCITY_GRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <map>

class Graph {
private:
    std::vector<std::vector<int>> matGraph;
    std::set<int> connect;
    int nextVertex;
    int size;

public:
    Graph();

    ~Graph();

    int addVertex();

    void addEdge(int source, int dest);

    void delEdge(int source, int dest);

    bool delVertex(int vertrex);

    bool updateWeight(int source, int dest, int weight);

    bool isVertexExist(int vertex);

    std::vector<int> getNeighbors(int vertex);

    int getWeight(int source, int dest);

    std::set<int> getConnections(int vertex);

    void helper(int vertex);

    friend std::ostream &operator<<(std::ostream &stream, Graph &mg);

    std::set<int> getLastVertexConnections() {
        return this->connect;
    }

};


#endif //NEVERLANDCITY_GRAPH_H
