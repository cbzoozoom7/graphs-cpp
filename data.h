//data.h
//Chris Bowman
//Created Sun 7 May 2023
#ifndef DATA_STRUCT
    #define DATA_STRUCT
    #include <string>
    #include <unordered_set>
    using std::string;
    using std::unordered_set;
    struct Data {
        int id;
        string str;
    };
    struct Vertex {
        Data data;
        unordered_set<Vertex*> adjacent;
    };
#endif