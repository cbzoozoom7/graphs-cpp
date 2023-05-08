//main.cpp
//Chris Bowman
//Created Mon 8 May 2023
#include "main.h"
int main() {
    int testSize = 10;
    int ids[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string strs[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    Graph myGraph;
    for (int i = 1; i < testSize; i++) {
        cout << "Adding edge between " << ids[i-1] << " & " << ids[i] << "... ";
        myGraph.addEdge(ids[i-1], ids[i]);
        cout << "Done.\nAdding vertex " << ids[i-1] << ": \"" << strs[i-1] << "\"... ";
        myGraph.addVertex(ids[i-1], &strs[i-1]);
        cout << "Done.\nAdding vertex " << ids[i] << ": \"" << strs[i] << "\"... ";
        myGraph.addVertex(ids[i], &strs[i]);
        cout << "Done." << endl;
    }
    myGraph.depthFirstTraversal(1);
    return 0;
}