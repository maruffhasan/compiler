
#include "SymbolTable.h"

SymbolTable::SymbolTable(int n) {
    this->num_buckets = n;
    this->current = nullptr;
    EnterScope();
}

void SymbolTable::EnterScope() {
    ScopeTable* newScope = new ScopeTable(num_buckets);
    newScope->parent_scope = this->current;
    this->current = newScope;
}

void SymbolTable::ExitScope() {
    if (!current) {
        cout << "No scope to exit\n";
        return;
    }
    if (!current->parent_scope) {
        cout << "Cannot remove root ScopeTable\n";
        return;
    }
    ScopeTable* tmp = current->parent_scope;
    delete current;
    current = tmp;
}

bool SymbolTable::Insert(SymbolInfo* si) {
    if (!current) return false;
    return current->Insert(si);
}

bool SymbolTable::Remove(string name) {
    if (!current) return false;
    return current->Delete(name);
}

SymbolInfo* SymbolTable::LookUp(string name) {
    ScopeTable* scope = current;
    while (scope) {
        SymbolInfo* found = scope->LookUp(name);
        if (found) return found;
        scope = scope->parent_scope;
    }
    return nullptr;
}

void SymbolTable::PrintCurrentScope() {
    if (current) {
        current->Print();
    }
}

void SymbolTable::PrintAllScopes() {
    ScopeTable* scope = current;
    while (scope) {
        scope->Print();
        scope = scope->parent_scope;
    }
}

SymbolTable::~SymbolTable() {
    while (current) {
        ScopeTable* tmp = current->parent_scope;
        delete current;
        current = tmp;
    }
}