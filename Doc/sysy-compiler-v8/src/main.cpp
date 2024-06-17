#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include "Nodes.h"
#include "RISCV.h"
#include "koopa.h"
#include "NodesManager.h"
#define _SUB_MODE
using namespace std;
extern FILE *yyin;
auto manager = NodesManager();
extern int yyparse(NodesManager &);
int main(int argc, const char *argv[])
{
    auto input = argv[1];
    auto output = argv[2];
    yyin = fopen(input, "r");
    freopen(output, "w", stdout); 
    yyparse(manager);
    // cerr << "Parsing finished" << endl;
    manager.root->dumpIR();
    return 0;
}
