#include<SymbolInfo.h>

SymbolInfo::SymbolInfo(string name, string type) {
    this->name = name;
    this->type = type;
    this->next = nullptr;
}

SymbolInfo::SymbolInfo(string name, string type, SymbolInfo* next) {
    this->name = name;
    this->type = type;
    this->next = next;
}

