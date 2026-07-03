#!/usr/bin/bash

g++ SymbolInfo.cpp SymbolTable.cpp ScopeTable.cpp test.cpp -fsanitize=address
./a.out input.txt output.txt
rm a.out