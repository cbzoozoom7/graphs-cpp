//graph.cpp
//Chris Bowman
//Created Mon 8 May 2023
#include "graph.h"
Graph::Graph() {
    vertices;
    count = 0;
}
Vertex *Graph::findVertex(int id) {
    Vertex *found = nullptr;
    int i = 0;
    while (!found && i < count) {
        if (vertices.at(i).data.id == id) {
            found = &vertices.at(i);
        }
        i++;
    }
    return found;
}
bool Graph::addEdge(int start, int end) {
    return false;
}