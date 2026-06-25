#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include<iostream>
#include "ScopeTable.h"

using namespace std;

struct SymbolTable {
    ScopeTable* current;
    int num_buckets;

    SymbolTable(int n);

    void EnterScope();
    void ExitScope();
    bool Insert(SymbolInfo* si);
    bool Remove(string name);
    SymbolInfo* LookUp(string name);
    void PrintCurrentScope();
    void PrintAllScopes();

    ~SymbolTable();

};


#endif