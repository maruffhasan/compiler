#include "ScopeTable.h"

static unsigned int SDBMHash(string str, unsigned int num_buckets) {
    unsigned int hash = 0;
    unsigned int len = str.length();

    for (unsigned int i = 0; i < len; i++) {
        hash = ((str[i]) + (hash << 6) + (hash << 16) - hash) % num_buckets;
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

bool ScopeTable::Insert(SymbolInfo* si) {
    unsigned int idx = SDBMHash(si->name, num_buckets);
    SymbolInfo* current = buckets[idx];
    SymbolInfo* prev = nullptr;
    int cnt = 1;
    while (current) {
        if (current->name == si->name) {
            cout << "\t\'" << si->name << "\'" << " already exists in the current ScopeTable\n";
            return false;
        }
        prev = current;
        current = current->next;
        cnt++;
    }

    SymbolInfo* new_si = new SymbolInfo(si->name, si->type, si->next);
    new_si->set_extra(si->extra_names, si->extra_types, si->extra_count);

    if (prev == nullptr) {
        buckets[idx] = new_si;
    } else {
        prev->next = new_si;
    }

    cout << "\tInserted in ScopeTable# " << id << " at position " << idx + 1<< ", " << cnt << "\n";

    return true;
}


SymbolInfo* ScopeTable::LookUp(string name) {
    unsigned int idx = SDBMHash(name, num_buckets);
    SymbolInfo* current = buckets[idx];
    int cnt = 1;
    while(current) {
        if (current->name == name) {
            cout << "\t\'" << name << "\'" << " found in ScopeTable# " << id << " at position " << idx + 1 << ", " << cnt << "\n";
            return current;
        }
        cnt++;
        current = current->next;
    }
    return nullptr;
}

bool ScopeTable::Delete(string name) {
    unsigned int idx = SDBMHash(name, num_buckets);
    SymbolInfo* current = buckets[idx];
    SymbolInfo* prev = nullptr;
    int cnt = 1;
    while (current) {
        if (current->name == name) {
            if (prev) {
                prev->next = current->next;
            } else {
                buckets[idx] = current->next;
            }
            cout << "\tDeleted \'" << name << "\'" << " from ScopeTable# " << id << " at position " << idx + 1 << ", " << cnt << "\n";
            delete current;
            return true;
        }
        prev = current;
        cnt++;
        current = current->next;
    }
    cout << "\tNot found in the current ScopeTable\n";
    return false;
}

void ScopeTable::Print(int round) {
    for (int i = 0; i < round; i++) cout << "\t";
    cout << "ScopeTable# " << id << "\n";
    for (int i = 0; i < num_buckets; i++) {
        for (int i = 0; i < round; i++) cout << "\t";
        cout << i + 1 << "--> ";
        SymbolInfo* current = buckets[i];
        while (current) {
            cout << current->toString() << " ";
            current = current->next;
        }
        cout << "\n";
    }
}

bool ScopeTable::HasParent() {
    return !(parent_scope == nullptr);
}
