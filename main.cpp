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
    isEmptyAndCount(&myGraph);
    for (int i = 1; i < testSize; i++) { //line them up in numerical order (non-cyclical)
        cout << "Adding edge between " << ids[i-1] << " & " << ids[i] << "... ";
        if (myGraph.addEdge(ids[i-1], ids[i])) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    isEmptyAndCount(&myGraph);
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
    isEmptyAndCount(&myGraph);
    myGraph.depthFirstTraversal(ids[rand() % testSize]);
    myGraph.breadthFirstTraversal(ids[rand() % testSize]);
    for (int i = 0; i < testSize * RANDPERCENT; i++) { //get a few vertices
        int getId = rand() % testSize;
        cout << "Getting " << getId << "... ";
        Data *myData = new Data;
        if (myGraph.getVertex(getId, myData)) {
            cout << "Success: ";
        } else {
            cout << "Fail: ";
        }
        cout << myData->id << ": \"" << myData->str << "\"" << endl;
    }
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
    isEmptyAndCount(&myGraph);
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
    myGraph.breadthFirstTraversal(ids[rand() % testSize]);
    myGraph.depthFirstTraversal(ids[rand() % testSize]);
    cout << "Clearing... ";
    myGraph.clear();
    cout << "Done." << endl;
    isEmptyAndCount(&myGraph);
    int randTestSize = testSize * testSize;
    int randTestIds[randTestSize];
    string randTestStrs[randTestSize];
    for (int outer = 0; outer < testSize; outer++) { //make more test data
        for (int inner = 0; inner < testSize; inner++) {
            int i = (outer * 10) + inner;
            randTestIds[i] = (outer * 10) + ids[inner];
            randTestStrs[i] = std::to_string(outer) + strs[inner];
        }
    }
    for (int i = 0; i < randTestSize * RANDPERCENT; i++) { //add part of the new test data
        cout << "Adding vertex " << randTestIds[i] << ": \"" << randTestStrs[i] << "\"... ";
        if (myGraph.addVertex(randTestIds[i], &randTestStrs[i])) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    for (int i = 1; i < randTestSize * RANDPERCENT; i++) { //line them up in numerical order (non-cyclical)
        cout << "Adding edge between " << randTestIds[i-1] << " & " << randTestIds[i] << "... ";
        if (myGraph.addEdge(randTestIds[i-1], randTestIds[i])) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    for (int i = 0; i < randTestSize * RANDPERCENT; i++) { //add random edges
        int edgeStart = randTestIds[rand() % int(randTestSize * RANDPERCENT)];
        int edgeEnd = randTestIds[rand() % int(randTestSize * RANDPERCENT)];
        cout << "Adding edge between " << edgeStart << " & " << edgeEnd << "... ";
        if (myGraph.addEdge(edgeStart, edgeEnd)) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    for (int i = 0; i < randTestSize * RANDPERCENT; i++) { //remove some random edges between pairs of numerically adjacent ids
        int toRemove = rand() % (int(randTestSize * RANDPERCENT) - 1);
        int edgeStart = randTestIds[toRemove];
        int edgeEnd = randTestIds[toRemove + 1];
        cout << "Removing edge between " << edgeStart << " & " << edgeEnd << "... ";
        if (myGraph.removeEdge(edgeStart, edgeEnd)) {
            cout << "Success." << endl;
        } else {
            cout << "Fail." << endl;
        }
    }
    isEmptyAndCount(&myGraph);
    myGraph.depthFirstTraversal(ids[rand() % int(randTestSize * RANDPERCENT)]);
    myGraph.breadthFirstTraversal(ids[rand() % int(randTestSize * RANDPERCENT)]);
    for (int i = 0; i < RANDTESTSCALE; i++) {
        switch (rand() % CHOICES) {
            case 1: { //addVertex()
                int i = rand() % randTestSize;
                int id = randTestIds[i];
                string str = randTestStrs[i];
                cout << "Adding vertex " << id << ": \"" << str << "\"... ";
                if (myGraph.addVertex(id, &str)) {
                    cout << "Success." << endl;
                } else {
                    cout << "Fail." << endl;
                }
            break;}
            case 2: { //removeVertex()
                int toRemove = randTestIds[rand() % randTestSize];
                cout << "Removing " << toRemove << "... ";
                if (myGraph.removeVertex(toRemove)) {
                    cout << "Success." << endl;
                } else {
                    cout << "Fail." << endl;
                }
            break;}
            case 3: { //addEdge()
                int edgeStart = randTestIds[rand() % randTestSize];
                int edgeEnd = randTestIds[rand() % randTestSize];
                cout << "Adding edge between " << edgeStart << " & " << edgeEnd << "... ";
                if (myGraph.addEdge(edgeStart, edgeEnd)) {
                    cout << "Success." << endl;
                } else {
                    cout << "Fail." << endl;
                }
            break;}
            case 4: { //removeEdge()
                int edgeStart = randTestIds[rand() % randTestSize];
                int edgeEnd = randTestIds[rand() % randTestSize];
                cout << "Removing edge between " << edgeStart << " & " << edgeEnd << "... ";
                if (myGraph.removeEdge(edgeStart, edgeEnd)) {
                    cout << "Success." << endl;
                } else {
                    cout << "Fail." << endl;
                }
                //removing numerically adjacent as well because the above is unlikely to succeed.
                int toRemove = rand() % (randTestSize - 1);
                edgeStart = randTestIds[toRemove];
                edgeEnd = randTestIds[toRemove + 1];
                cout << "Removing edge between " << edgeStart << " & " << edgeEnd << "... ";
                if (myGraph.removeEdge(edgeStart, edgeEnd)) {
                    cout << "Success." << endl;
                } else {
                    cout << "Fail." << endl;
                }
            break;}
            case 5: { //getVertex()
                int getId = rand() % randTestSize;
                cout << "Getting " << getId << "... ";
                Data *myData = new Data;
                if (myGraph.getVertex(getId, myData)) {
                    cout << "Success: ";
                } else {
                    cout << "Fail: ";
                }
                cout << myData->id << ": \"" << myData->str << "\"" << endl;
            break;}
            default: { //isEmptyAndCount() (functions.cpp)
                isEmptyAndCount(&myGraph);
            break;}
        }
    }
    cout << "Didn't crash!" << endl;
    return 0;
}