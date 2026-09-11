#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "CSubsetLexer.h"
#include "CSubsetParser.h"
#include "BuildCodeVisitor.h"

using namespace antlr4;
using namespace std;

ofstream lexLogFile("out/log.txt");

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    ANTLRInputStream input(inputFile);
    CSubsetLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CSubsetParser parser(&tokens);

    CSubsetParser::StartContext* tree = parser.start();

    // Run Assembly Code Generator
    BuildCodeVisitor visitor("out/code.asm", "out/optCode.asm", lexLogFile);
    visitor.visit(tree);

    cout << "Intermediate Code Generation Completed." << endl;

    inputFile.close();
    return 0;
}