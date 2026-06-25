#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include<iostream>
using namespace std;

struct SymbolInfo {
    string name;
    string type;
    SymbolInfo* next;

    SymbolInfo();
    SymbolInfo(string name, string type);
    SymbolInfo(string name, string type, SymbolInfo* next);
};

#endif