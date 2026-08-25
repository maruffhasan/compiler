ANTLR_VERSION = 4.13.2
ANTLR4 = antlr4
CXX = g++
CXXFLAGS = -std=c++17 -w -I/usr/local/include/antlr4-runtime
LDFLAGS = -L/usr/local/lib
LDLIBS = -lantlr4-runtime -pthread

GRAMMAR = CSubset.g4
TARGET = compiler.out

GENERATED = $(GRAMMAR:.g4=.cpp) \
            CSubsetLexer.cpp \
            CSubsetParser.cpp \
            CSubsetBaseVisitor.cpp \
            CSubsetVisitor.cpp

SOURCES = $(filter-out main.cpp,$(wildcard *.cpp))

.PHONY: all generate clean run

all: generate $(TARGET)

generate: $(GRAMMAR)
	$(ANTLR4) -v $(ANTLR_VERSION) -Dlanguage=Cpp -visitor -no-listener $<

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) $(LDFLAGS) $(LDLIBS) -o $@

run: $(TARGET)
	LD_LIBRARY_PATH=/usr/local/lib ./$(TARGET) $(ARGS)

clean:
	rm -f $(TARGET) *.o
	rm -f CSubsetLexer.cpp CSubsetLexer.h
	rm -f CSubsetParser.cpp CSubsetParser.h
	rm -f CSubsetBaseVisitor.cpp CSubsetBaseVisitor.h
	rm -f CSubsetVisitor.cpp CSubsetVisitor.h
	rm -f CSubset.interp CSubset.tokens