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
        if (vertices.at(i)->data.id == id) {
            found = vertices.at(i);
        }
        i++;
    }
    return found;
}
bool Graph::addEdge(int fromId, int toId) {
    bool added = false;
    if (fromId != toId) {
        Vertex *from = findVertex(fromId);
        Vertex *to = findVertex(toId);
        if (from && to) {
            if (from->adjacent.insert(to).second && to->adjacent.insert(from).second) {
                added = true;
            }
        }
    }
    return added;
}
bool Graph::addVertex(int id, string *str) {
    bool added = false;
    if (!findVertex(id)) {
        Vertex *newVertex = new Vertex;
        newVertex->data.id = id;
        newVertex->data.str = *str;
        vertices.push_back(newVertex);
        added = true;
        count++;
    }
    return added;
}
void Graph::depthFirstTraversal(int startId) {
    std::cout << "\nDepth First Traversal:" << std::endl;
    Vertex *current = findVertex(startId);
    vector<Vertex*> next;
    std::unordered_set<Vertex*> visited;
    while (current) {
        if (!visited.count(current)) {
            std::cout << current->data.id << ": \"" << current->data.str << "\"" << std::endl;
            for (unordered_set<Vertex*>::iterator i = current->adjacent.begin(); i != current->adjacent.end(); i++) {
                if (!visited.count(*i)) {
                    next.push_back(*i);
                }
            }
            visited.insert(current);
        }
        current = next.back();
        next.erase(next.end()-1);
    }
}
Graph::~Graph() {
    clear();
}
void Graph::clear() {

}
int Graph::getNumVertices() {
    return count;
}
bool Graph::removeEdge(int fromId, int toId) {
    bool removed = false;
    return removed;
}
void Graph::clearDisconnected() {

}
bool Graph::removeVertex(int id) {
    bool removed = false;
    return removed;
}
void Graph::breadthFirstTraversal(int startId) {

}
bool Graph::getVertex(int id, Data *d) {
    return false;
}
int Graph::getNumEdges() {

}