
#include "SymbolTable.h"
#include <fstream>

// SymbolTable::SymbolTable(int n, ofstream &logout) {
//     this->num_buckets = n;
//     this->current = nullptr;
//     this->logout = logout;
//     EnterScope();
// }

SymbolTable::SymbolTable(int n, std::ofstream& logout)
    : num_buckets(n),
      current(nullptr),
      logout(logout)
{
    EnterScope();
}

SymbolTable::~SymbolTable() {
    while (current) {
        ScopeTable* tmp = current->parent_scope;
        delete current;
        current = tmp;
    }
}

void SymbolTable::EnterScope() {
    ScopeTable* newScope = new ScopeTable(num_buckets, this->current);
    this->current = newScope;
    // cout << "\tScopeTable# " << this->current->id << " created\n";
}

void SymbolTable::ExitScope() {
    if (!current) {
        // cout << "\tNo scope to exit\n";
        return;
    }
    if (!current->parent_scope) {
        // cout << "\tCannot remove root ScopeTable\n";
        return;
    }
    ScopeTable* tmp = current->parent_scope;
    // cout << "\tScopeTable# " << current->id << " removed\n";

    delete current;
    current = tmp;
}

bool SymbolTable::Insert(SymbolInfo &si) {
    if (!current) return false;
    SymbolInfo* new_si = current->Insert(si);
    if (new_si) {
        // cout << "\tInserted in ScopeTable# " << current->id << " at position " << new_si->bucket << ", " << new_si->bucket_pos << "\n";
        return true;
    } else {
        new_si = LookUp(si.name);
        logout << new_si->toString() << " already exists in ScopeTable# " << current->id << " at position " << new_si->bucket << ", " << new_si->bucket_pos << "\n\n";;
        return false;
    }
}

bool SymbolTable::Remove(string name) {
    if (!current) return false;

    SymbolInfo* si = current->LookUp(name);
    if (si) {
        // cout << "\tDeleted \'" << name << "\'" << " from ScopeTable# " << current->id << " at position " << si->bucket << ", " << si->bucket_pos << "\n";
        return current->Delete(name);
    } else {
        // cout << "\tNot found in the current ScopeTable\n";
        return false;
    }

    return current->Delete(name);
}

SymbolInfo* SymbolTable::LookUp(string name) {
    ScopeTable* scope = current;
    while (scope) {
        SymbolInfo* found = scope->LookUp(name);
        if (found) {
            // cout << "\t\'" << name << "\'" << " found in ScopeTable# " << scope->id << " at position " << found->bucket << ", " << found->bucket_pos << "\n";
            return found;
        }
        scope = scope->parent_scope;
    }
    // cout << "\t\'" << name << "\'" << " not found in any of the ScopeTables\n";
    return nullptr;
}

void SymbolTable::PrintCurrentScope() {
    if (current) {
        current->Print(logout);
    }
    logout << "\n";
}

void SymbolTable::PrintAllScopes() {
    ScopeTable* scope = current;
    while (scope) {
        scope->Print(logout);
        scope = scope->parent_scope;
    }
    logout << "\n";
}


void SymbolTable::Quit() {
    while (current) {
        bool hasParent = current->HasParent();
        string rootId = current->id;
        if (!hasParent) {
            // manually report removal of the root scope, then delete it
            cout << "ScopeTable# " << rootId << " removed\n";
            delete current;
            current = nullptr;
            break;
        }
        ExitScope();
    }
}
