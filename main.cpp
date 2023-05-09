//main.cpp
//Chris Bowman
//Created Mon 8 May 2023
#include "main.h"
int main() {
    int testSize = 10;
    int ids[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string strs[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    Graph myGraph;
    isEmptyAndCount(&myGraph);
    for (int i = 0; i < testSize; i++) { //add the above vertices
        cout << "Adding vertex " << ids[i] << ": \"" << strs[i] << "\"... ";
        if (myGraph.addVertex(ids[i], &strs[i])) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    for (int i = 1; i < testSize; i++) { //line them up in numerical order (non-cyclical)
        cout << "Adding edge between " << ids[i-1] << " & " << ids[i] << "... ";
        if (myGraph.addEdge(ids[i-1], ids[i])) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    srand(time(nullptr));
    for (int i = 0; i < testSize * RANDPERCENT; i++) { //add 3 random edges
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
    for (int i = 0; i < testSize * RANDPERCENT; i++) { //remove 3 random edges between pairs of numerically adjacent ids
        int toRemove = rand() % (testSize - 1);
        int edgeStart = ids[toRemove];
        int edgeEnd = ids[toRemove + 1];
        cout << "Removing edge between " << edgeStart << " & " << edgeEnd << "... ";
        if (myGraph.removeEdge(edgeStart, edgeEnd)) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    for (int i = 0; i < testSize * RANDPERCENT; i++) { //remove 3 random vertices
        int toRemove = ids[rand() % testSize];
        cout << "Removing " << toRemove << "... ";
        if (myGraph.removeVertex(toRemove)) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    isEmptyAndCount(&myGraph);
    cout << "Clearing... ";
    myGraph.clear();
    cout << "Done." << endl;
    isEmptyAndCount(&myGraph);
    return 0;
}