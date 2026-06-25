#include "ScopeTable.h"

static unsigned int SDBMHash(string str) {
    unsigned int hash = 0;
    unsigned int i = 0;
    unsigned int len = str.length();

    for (i = 0; i < len; i++) {
        hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}

int ScopeTable::counter = 0;

ScopeTable::ScopeTable(int n) {
    this->num_buckets = n;
    this->id = ++counter;
    buckets = new SymbolInfo*[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = nullptr;
    }
}

bool ScopeTable::Insert(SymbolInfo* si) {
    unsigned int idx = SDBMHash(si->name);
    SymbolInfo* current = buckets[idx];
    while (current) {
        if (current->name == si->name) {
            cout << "already exists in the current ScopeTable\n";
            return false;
        }
        current = current->next;
    }
    si->next = buckets[idx];
    buckets[idx] = si;
    return true;
}


SymbolInfo* ScopeTable::LookUp(string name) {
    unsigned int idx = SDBMHash(name);
    SymbolInfo* current = buckets[idx];
    while(current) {
        if (current->name == name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

bool ScopeTable::Delete(string name) {
    unsigned int idx = SDBMHash(name);
    SymbolInfo* current = buckets[idx];
    SymbolInfo* prev = nullptr;
    while (current) {
        if (current->name == name) {
            if (prev) {
                prev->next = current->next;
            } else {
                buckets[idx] = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void ScopeTable::Print() {
    cout << "\tScopeTable# " << id << "\n";
    for (int i = 0; i < num_buckets; i++) {
        if (buckets[i]) {
            cout << "\t" << i << "-->";
            SymbolInfo* current = buckets[i];
            while (current) {
                cout << "< " << current->name << " : " << current->type << " >";
                current = current->next;
            }
            cout << "\n";
        }
    }
    cout << "\n";
}

ScopeTable::~ScopeTable() {
    for (int i = 0; i < num_buckets; i++) {
        SymbolInfo* current = buckets[i];
        while (current) {
            SymbolInfo* temp = current->next;
            delete current;
            current = temp;
        }
        buckets[i] = nullptr;
    }
    delete[] buckets;
}