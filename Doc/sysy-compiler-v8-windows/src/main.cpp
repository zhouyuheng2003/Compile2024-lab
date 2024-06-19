#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include "Nodes.h"
// #include "RISCV.h"
// #include "koopa.h"
#include "NodesManager.h"
#define _SUB_MODE
using namespace std;
extern FILE *yyin;
auto manager = NodesManager();
extern int yyparse(NodesManager &);
int StrToInt(const string& str) {
    int x = 0;
    bool flag = 0;
    size_t i = 0;
    if (str[0] == '-') {
        flag = 1;
        i++;
    } else if (str[0] == '+') {
        i++;
    }
    for (; i < str.size(); ++i) {
        char c = str[i];
        assert(isdigit(c));
        x = x * 10 + (c - '0');
    }
    if (flag) x = -x;
    return x;
}
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
