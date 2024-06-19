#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include "Nodes.h"
#include "NodesManager.h"
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
    manager.root->outputIR();
    return 0;
}
