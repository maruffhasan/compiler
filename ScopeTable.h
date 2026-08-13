#pragma once

#include<iostream>
#include<string>
#include"SymbolInfo.h"
#include <fstream>


using namespace std;


struct ScopeTable {
    int num_buckets;
    SymbolInfo** buckets;

    string id;
    int child;
    static int counter;
    
    ScopeTable* parent_scope;

    ScopeTable(int n, ScopeTable* parent_scope);
    ~ScopeTable();

    SymbolInfo* Insert(SymbolInfo &si);
    SymbolInfo* LookUp(string name);
    bool Delete(string name);
    bool HasParent();

    void Print(ofstream &logout);

};
