#include "SymbolInfo.h"

SymbolInfo::SymbolInfo(string name, string type, SymbolInfo* next) {
    this->name = name;
    this->type = type;
    this->next = next;
    this->extra_names = nullptr;
    this->extra_types = nullptr;
    this->extra_count = 0;
}

SymbolInfo::~SymbolInfo() {
    if (extra_types) 
        delete[] extra_types;
    if (extra_names) 
        delete[] extra_names;
}

void SymbolInfo::set_extra(string* names, string* types, int count) {
    if (extra_types)
        delete[] extra_types;
    if (extra_names)
        delete[] extra_names;
    extra_count = count;
    extra_types = (count > 0) ? new string[count] : nullptr;
    extra_names = (count > 0 && names != nullptr) ? new string[count] : nullptr;
    for (int i = 0; i < count; i++) {
        extra_types[i] = types[i];
        if (extra_names) extra_names[i] = names[i];
    }
}

string SymbolInfo::toString() {
    string out = "<" + name + "," + type;
    if (type == "FUNCTION") {
        out += "," + extra_types[0] + "<==(";
        for (int i = 1; i < extra_count; i++) {
            out += extra_types[i];
            if (i + 1 < extra_count) out += ",";
        }
        out += ")";
    } else if (type == "STRUCT" || type == "UNION") {
        out += ",{";
        for (int i = 0; i < extra_count; i++) {
            out += "(" + extra_types[i] + "," + extra_names[i] + ")";
            if (i + 1 < extra_count) out += ",";
        }
        out += "}";
    }

    out += ">";
    return out;
}



