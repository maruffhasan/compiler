#include <bits/stdc++.h>
#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"

using namespace std;


int split_tokens(const string& line, string tokens[], int maxTokens) {
    int count = 0;
    int i = 0;
    int len = line.length();
    while (i < len && count < maxTokens) {
        while (i < len && line[i] == ' ') i++;
        if (i >= len) break;
        int start = i;
        while (i < len && line[i] != ' ') i++;
        tokens[count++] = line.substr(start, i - start);
    }
    return count;
}
 
int main(int argc, char* argv[]) {
    

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file> [output_file]\n";
        return 1;
    }
    ifstream in(argv[1]);
    if (argc >= 3) {
        freopen(argv[2], "w", stdout);
    }

    string firstLine;
    getline(in, firstLine);
    int num_buckets = (int) firstLine[0] - '0';
 
    SymbolTable* symTab = new SymbolTable(num_buckets); // ScopeTable# 1 created
 
    const int MAX_TOKENS = 64;
    string tokens[MAX_TOKENS];
 
    string line;
    int cmdNo = 0;
 
    while (getline(in, line)) {
 
        int tokenCount = split_tokens(line, tokens, MAX_TOKENS);
        if (tokenCount == 0) continue;
        string code = tokens[0];
 
        if (code != "I" && code != "L" && code != "D" && code != "P" &&
            code != "S" && code != "E" && code != "Q") {
            continue; // unrecognized command letter, ignore entirely
        }
        if (code == "P" && (tokenCount != 2 || (tokens[1] != "A" && tokens[1] != "C"))) {
            continue; // invalid P argument, ignore entirely
        }
        if (code == "E" && !symTab->current->HasParent()) {
            continue; // cannot exit root scope; ignore entirely
        }
 
        cmdNo++;
        cout << "Cmd " << cmdNo << ":";
        for (int i = 0; i < tokenCount; i++) {
            cout << " " << tokens[i];
        } cout << "\n";
 
        if (code == "I") {
            if (tokenCount < 3) {
                cout << "\tNumber of parameters mismatch for the command I\n";
                continue;
            }
            string name = tokens[1];
            string type = tokens[2];
            SymbolInfo sym = SymbolInfo(name, type);
 
            if (type == "FUNCTION") {
                int extraCount = tokenCount - 3;
                if (extraCount > 0) {
                    string extraTypes[extraCount];
                    for (int i = 0; i < extraCount; i++) extraTypes[i] = tokens[3 + i];
                    sym.set_extra(nullptr, extraTypes, extraCount);
                }
            } else if (type == "STRUCT" || type == "UNION") {
                int remaining = tokenCount - 3;
                int pairCount = remaining / 2;
                if (pairCount > 0) {
                    string types[pairCount];
                    string names[pairCount];
                    for (int i = 0; i < pairCount; i++) {
                        types[i] = tokens[3 + 2 * i];
                        names[i] = tokens[3 + 2 * i + 1];
                    }
                    sym.set_extra(names, types, pairCount);
                }
            }
            bool inserted = symTab->Insert(sym);
 
        } else if (code == "L") {
            if (tokenCount != 2) {
                cout << "\tNumber of parameters mismatch for the command L\n";
                continue;
            }
            symTab->LookUp(tokens[1]);
 
        } else if (code == "D") {
            if (tokenCount != 2) {
                cout << "\tNumber of parameters mismatch for the command D\n";
                continue;
            }
            symTab->Remove(tokens[1]);
 
        } else if (code == "P") {
            if (tokens[1] == "C") symTab->PrintCurrentScope();
            else symTab->PrintAllScopes();
 
        } else if (code == "S") {
            symTab->EnterScope();
 
        } else if (code == "E") {
            symTab->ExitScope();
 
        } else if (code == "Q") {
            symTab->Quit();
            break;
        }
    }
 
    delete symTab;
    in.close();
    return 0;
}
