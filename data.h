//data.h
//Chris Bowman
//Created Sun 7 May 2023
#ifndef DATA_STRUCT
    #define DATA_STRUCT
    #include <string>
    using std::string;
    struct Data {
        int id;
        string str;
    };
    struct Vertex {
        Data data;
        vector<int> adjacent;
    };
#endif