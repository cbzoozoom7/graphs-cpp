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
            if (from->adjacent.insert(to).second && to->adjacent.insert(from).second) { //second is a bool incidating success.
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
    next.push_back(current);
    while (current && !next.empty()) {
        next.erase(next.end()-1);
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
    }
    std::cout << std::endl;
}
void Graph::breadthFirstTraversal(int startId) {
    std::cout << "\nBreadth First Traversal:" << std::endl;
    Vertex *current = findVertex(startId);
    vector<Vertex*> next;
    std::unordered_set<Vertex*> visited;
    next.push_back(current);
    while (current && !next.empty()) {
        next.erase(next.begin());
        if (!visited.count(current)) {
            std::cout << current->data.id << ": \"" << current->data.str << "\"" << std::endl;
            for (unordered_set<Vertex*>::iterator i = current->adjacent.begin(); i != current->adjacent.end(); i++) {
                if (!visited.count(*i)) 
                    next.push_back(*i);
                }
            
            visited.insert(current);
        }
        current = next.front();
    }
    std::cout << std::endl;
}
bool Graph::isEmpty() {
    return vertices.empty();
}
void Graph::clear() {
    for (vector<Vertex*>::iterator i = vertices.begin(); i < vertices.end(); i++) {
        delete *i;
    }
    vertices.clear();
    count = 0;
}
int Graph::getCount() {
    return count;
}
Graph::~Graph() {
    clear();
}
bool Graph::removeVertex(int id) {
    bool removed = false;
    Vertex *target = nullptr;
    vector<Vertex*>::iterator i = vertices.begin();
    while (!target && i < vertices.end()) {
        if ((*i)->data.id == id) {
            target = *i;
            vertices.erase(i);
        }
        i++;
    }
    if (target) {
        for (unordered_set<Vertex*>::iterator i = target->adjacent.begin(); i != target->adjacent.end(); i++) {
            (*i)->adjacent.erase(target);
        }
        delete target;
        removed = true;
        count--;
    }
    return removed;
}
bool Graph::removeEdge(int fromId, int toId) {
    bool removed = false;
    Vertex *from = findVertex(fromId);
    Vertex *to = findVertex(toId);
    if (from && to) {
        removed = (from->adjacent.erase(to) && to->adjacent.erase(from));
    }
    return removed;
}
bool Graph::getVertex(int id, Data *d) {
    Vertex *v = findVertex(id);
        if (v) {
            d->id = v->data.id;
            d->str = v->data.str;
        } else {
            d->id = -1;
            d->str = "";
        }
    return v;
}
void Graph::clearDisconnected() {
    for (vector<Vertex*>::iterator i = vertices.begin(); i < vertices.end(); i++) {
        if ((*i)->adjacent.empty()) {
            delete *i;
            vertices.erase(i);
        }
    }
}