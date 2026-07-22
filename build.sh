#!/usr/bin/bash

flex parser.l

g++ SymbolInfo.cpp SymbolTable.cpp ScopeTable.cpp lex.yy.c -fsanitize=address

mkdir -p out
./a.out inputs/input1.txt
rm lex.yy.c 
rm a.out