//functions.cpp
//Chris Bowman
//Created Tue 9 May 2023
#include "functions.h"
void isEmptyAndCount(Graph *g) {
    if (g->isEmpty()) {
        cout << "Graph is empty." << endl;
    } else {
        cout << "Graph is not empty." << endl;
    }
    cout << "Number of vertices: " << g->getCount() << endl; //Decided against sentence-style to avoid having to form the plural.
}