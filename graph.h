//graphs.h
//Chris Bowman
//Created Sun 7 May 2023
#ifndef GRAPH
    #define GRAPH
    #include <iostream>
    #include <unordered_set>
    #include <vector>
    #include "data.h"
    using std::vector;
    class Graph {
        public:
            Graph();
            ~Graph();
            void clear();
            int getNumVertices();
            int getNumEdges();
            bool addEdge(int, int);
            bool removeEdge(int, int);
            void clearDisconnected();
            bool addVertex(int, string*);
            bool removeVertex(int);
            void depthFirstTraversal(int);
            void breadthFirstTraversal(int);
            bool getVertex(int, Data*);
        protected:
            int count;
            vector<Vertex*> vertices;
            Vertex *findVertex(int);
    };
#endif //GRAPH