#pragma once

#include<iostream>
using namespace std;

struct SymbolInfo {
    string name;
    string type;
    string var_type;
    bool array = false;

    int bucket = -1;
    int bucket_pos = -1;

    SymbolInfo* next = nullptr;


    string* extra_names = nullptr;
    string* extra_types = nullptr;
    int extra_count = 0;


    SymbolInfo(string name = "", string type = "", string var_type = "", SymbolInfo* next = nullptr);
    ~SymbolInfo();

    void set_extra (string* names, string* types, int count);
    
    string toString();

};
