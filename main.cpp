//main.cpp
//Chris Bowman
//Created Mon 8 May 2023
#include "main.h"
int main() {
    int testSize = 10;
    int ids[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string strs[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    Graph myGraph;
    for (int i = 0; i < testSize; i++) {
        cout << "Adding vertex " << ids[i] << ": \"" << strs[i] << "\"... ";
        if (myGraph.addVertex(ids[i], &strs[i])) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    for (int i = 1; i < testSize; i++) {
        cout << "Adding edge between " << ids[i-1] << " & " << ids[i] << "... ";
        if (myGraph.addEdge(ids[i-1], ids[i])) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    srand(time(nullptr));
    for (int i = 0; i < testSize * RANDPERCENT; i++) {
        int edgeStart = ids[rand() % testSize];
        int edgeEnd = ids[rand() % testSize];
        cout << "Adding edge between " << edgeStart << " & " << edgeEnd << "... ";
        if (myGraph.addEdge(edgeStart, edgeEnd)) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    myGraph.depthFirstTraversal(ids[rand() % testSize]);
    myGraph.breadthFirstTraversal(ids[rand() % testSize]);
    return 0;
}