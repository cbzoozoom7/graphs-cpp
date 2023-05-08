//data.h
//Chris Bowman
//Created Sun 7 May 2023
#ifndef DATA_STRUCT
    #define DATA_STRUCT
    #include <string>
    #include <vector>
    using std::string;
    using std::vector;
    struct Data {
        int id;
        string str;
    };
    struct Vertex {
        Data data;
        vector<Vertex*> adjacent;
    };
#endif