#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include<iostream>
#include "ScopeTable.h"

using namespace std;

struct SymbolTable {
    ScopeTable* current;
    int num_buckets;
    ofstream &logout;

    SymbolTable();
    SymbolTable(int n, ofstream &logout);

    void EnterScope(); //Create a new scope table and make it the current one. Also, make the previous “current” scope table as its parent_scope table.
    void ExitScope(); // Remove the current scope table.
    bool Insert(SymbolInfo &si); // Insert a symbol in the current scope table.
    bool Remove(string name); // Remove a symbol from the current scope table.
    SymbolInfo* LookUp(string name); // Search a symbol in the symbol table. First, search the current scope table. If the symbol is not in the current one, then search its parent scope table and so on.
    void PrintCurrentScope(); // Print the current scope table.
    void PrintAllScopes(); // Print all the scope tables currently in the symbol table.
    void Quit();

    ~SymbolTable();

};


#endif