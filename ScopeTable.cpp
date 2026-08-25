#include "ScopeTable.h"

// static unsigned int SDBMHash(string str, unsigned int num_buckets) {
//     unsigned int hash = 0;
//     unsigned int len = str.length();

//     for (unsigned int i = 0; i < len; i++) {
//         hash = ((str[i]) + (hash << 6) + (hash << 16) - hash) % num_buckets;
//     }
//     return hash;
// }


unsigned int sdbmHash(const char *p, unsigned int num_buckets ) {
    unsigned int hash = 0;
    auto *str = (unsigned char *) p;
    int c{};
    while ((c = *str++)) {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash % num_buckets;
}

int ScopeTable::counter = 0;

ScopeTable::ScopeTable(int n, ScopeTable* parent_scope) {
    this->num_buckets = n;
    this->child = 0;
    this->parent_scope = parent_scope;
    if (this->parent_scope) {
        this->parent_scope->child++;
        this->id = this->parent_scope->id + "." + to_string(this->parent_scope->child);
    } else {
        this->id = to_string(++counter);
    }
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

SymbolInfo* ScopeTable::Insert(SymbolInfo &si) {
    unsigned int idx = sdbmHash(si.name.c_str(), num_buckets);
    SymbolInfo* current = buckets[idx];
    SymbolInfo* prev = nullptr;
    int cnt = 0;
    while (current) {
        if (current->name == si.name) {
            return nullptr;
        }
        prev = current;
        current = current->next;
        cnt++;
    }

    SymbolInfo* new_si = new SymbolInfo(si.name, si.type, si.var_type, si.next);
    new_si->set_extra(si.extra_names, si.extra_types, si.extra_count);
    new_si->bucket = idx;
    new_si->bucket_pos = cnt;
    new_si->array = si.array;
    new_si->var_type = si.var_type;

    new_si->isGlobal = si.isGlobal;
    new_si->offset = si.offset;
    new_si->arraySize = si.arraySize;

    if (prev == nullptr) {
        buckets[idx] = new_si;
    } else {
        prev->next = new_si;
    }

    return new_si;
}


SymbolInfo* ScopeTable::LookUp(string name) {
    unsigned int idx = sdbmHash(name.c_str(), num_buckets);
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
    unsigned int idx = sdbmHash(name.c_str(), num_buckets);
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
            delete current;
            return true;
        }
        prev = current;
        cnt++;
        current = current->next;
    }
    return false;
}

// void ScopeTable::Print(int round) {
//     for (int i = 0; i < round; i++) cout << "\t";
//     cout << "ScopeTable# " << id << "\n";
//     for (int i = 0; i < num_buckets; i++) {
//         for (int i = 0; i < round; i++) cout << "\t";
//         cout << i + 1 << "--> ";
//         SymbolInfo* current = buckets[i];
//         while (current) {
//             cout << current->toString() << " ";
//             current = current->next;
//         }
//         cout << "\n";
//     }
// }

void ScopeTable::Print(ofstream &logout) {
    logout << "ScopeTable# " << id << "\n";
    for (int i = 0; i < num_buckets; i++) {
        
        SymbolInfo* current = buckets[i];
        if (!current) continue;

        logout << i << " --> ";
        while (current) {
            if (current->toString() != "")
                logout << current->toString();
            current = current->next;
        }
        logout << "\n";
    }
}

bool ScopeTable::HasParent() {
    return !(parent_scope == nullptr);
}
