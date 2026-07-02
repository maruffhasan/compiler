#include <bits/stdc++.h>
#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "ScopeTable.h"

using namespace std;


// ---------------- manual tokenizer (no STL containers) ----------------
// Splits line into up to maxTokens whitespace-separated tokens.
// Returns actual token count. tokens[] must be pre-allocated array of strings.
int splitTokens(const string& line, string tokens[], int maxTokens) {
    int count = 0;
    int i = 0;
    int len = (int)line.length();
    while (i < len && count < maxTokens) {
        while (i < len && isspace((unsigned char)line[i])) i++;
        if (i >= len) break;
        int start = i;
        while (i < len && !isspace((unsigned char)line[i])) i++;
        tokens[count++] = line.substr(start, i - start);
    }
    return count;
}
 
int main(int argc, char* argv[]) {
    freopen("output.txt", "w", stdout);

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file> [output_file]\n";
        return 1;
    }
    ifstream in(argv[1]);
    streambuf* coutBuf = nullptr;
    ofstream out;
    if (argc >= 3) {
        out.open(argv[2]);
        coutBuf = cout.rdbuf();
        cout.rdbuf(out.rdbuf());
    }

    string firstLine;
    getline(in, firstLine);
    int num_buckets = atoi(firstLine.c_str());
 
    SymbolTable* symTab = new SymbolTable(num_buckets); // ScopeTable# 1 created
 
    const int MAX_TOKENS = 64;
    string tokens[MAX_TOKENS];
 
    string line;
    int cmdNo = 0;
    bool quit = false;
 
    while (!quit && getline(in, line)) {
        bool blank = true;
        for (size_t k = 0; k < line.length(); k++) {
            if (!isspace((unsigned char)line[k])) { blank = false; break; }
        }
        if (blank) continue;
 
        int tokenCount = splitTokens(line, tokens, MAX_TOKENS);
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
 
        // trim trailing whitespace for echo
        string echoLine = line;
        while (!echoLine.empty() && isspace((unsigned char)echoLine.back())) echoLine.pop_back();
 
        cmdNo++;
        cout << "Cmd " << cmdNo << ": " << echoLine << "\n";
 
        if (code == "I") {
            if (tokenCount < 3) {
                cout << "\tNumber of parameters mismatch for the command I\n";
                continue;
            }
            string name = tokens[1];
            string type = tokens[2];
            SymbolInfo* sym = new SymbolInfo(name, type);
 
            if (type == "FUNCTION") {
                int extraCount = tokenCount - 3;
                if (extraCount > 0) {
                    string* extraTypes = new string[extraCount];
                    for (int i = 0; i < extraCount; i++) extraTypes[i] = tokens[3 + i];
                    sym->set_extra(nullptr, extraTypes, extraCount);
                    delete[] extraTypes;
                }
            } else if (type == "STRUCT" || type == "UNION") {
                int remaining = tokenCount - 3;
                int pairCount = remaining / 2;
                if (pairCount > 0) {
                    string* types = new string[pairCount];
                    string* names = new string[pairCount];
                    for (int i = 0; i < pairCount; i++) {
                        types[i] = tokens[3 + 2 * i];
                        names[i] = tokens[3 + 2 * i + 1];
                    }
                    sym->set_extra(names, types, pairCount);
                    delete[] types;
                    delete[] names;
                }
            }
            bool inserted = symTab->Insert(sym);
            delete sym;
 
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
            if (tokens[1] == "C") {
                symTab->PrintCurrentScope();
            } else {
                symTab->PrintAllScopes();
            }
 
        } else if (code == "S") {
            symTab->EnterScope();
 
        } else if (code == "E") {
            symTab->ExitScope();
 
        } else if (code == "Q") {
            while (symTab->current) {
                bool hadParent = symTab->current->HasParent();
                int rootId = symTab->current->id;
                if (!hadParent) {
                    // manually report removal of the root scope, then delete it
                    cout << "\tScopeTable# " << rootId << " removed\n";
                    delete symTab->current;
                    symTab->current = nullptr;
                    break;
                }
                symTab->ExitScope();
            }
            quit = true;
        }
    }
 
    delete symTab;
    in.close();
    if (coutBuf) {
        cout.rdbuf(coutBuf);
        out.close();
    }
    return 0;
}