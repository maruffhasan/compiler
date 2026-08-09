#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include<iostream>
using namespace std;

struct SymbolInfo {
    string name;
    string type;
    SymbolInfo* next;
    string var_type;

    bool array;

    int bucket;
    int bucket_pos;

    string* extra_types;
    string* extra_names;
    int extra_count;

    SymbolInfo();
    SymbolInfo(string name, string type, string var_type = "INT", SymbolInfo* next = nullptr);
    void set_extra (string* names, string* types, int count);
    string toString();
    ~SymbolInfo();
};

#endif