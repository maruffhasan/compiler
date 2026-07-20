#ifndef SCOPETABLE_H
#define SCOPETABLE_H

#include<iostream>
#include<string>
#include"SymbolInfo.h"

using namespace std;


struct ScopeTable {
    string id;
    int child;
    static int counter;
    int num_buckets;
    SymbolInfo** buckets;
    ScopeTable* parent_scope;

    ScopeTable(int n, ScopeTable* parent_scope);

    SymbolInfo* Insert(SymbolInfo &si);
    SymbolInfo* LookUp(string name);
    bool Delete(string name);
    void Print(int round = 1);
    bool HasParent();
    
    ~ScopeTable();

};

#endif