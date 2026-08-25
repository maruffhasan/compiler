#pragma once

#include <iostream>
#include <string>

using namespace std;

struct SymbolInfo {
    string name;
    string type;
    string var_type;
    bool array = false;

    bool isGlobal = false;    
    int offset = 0;           
    int arraySize = 1;      

    int bucket = -1;
    int bucket_pos = -1;

    SymbolInfo* next = nullptr;

    string* extra_names = nullptr;
    string* extra_types = nullptr;
    int extra_count = 0;

    SymbolInfo(string name = "", string type = "", string var_type = "", SymbolInfo* next = nullptr);
    ~SymbolInfo();

    void set_extra(string* names, string* types, int count);
    string toString();
};