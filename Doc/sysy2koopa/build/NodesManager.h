#pragma once

#include <string>
#include <vector>
#include "Nodes.h"


class NodesManager
{
public:
    NodesManager(){}
    ~NodesManager(){
        for (auto node : nodes){
            delete(node);
        }
        for (auto vec: vectors){
            delete (vec);
        }
    }
    BaseAST* root;
    vector <BaseAST*> nodes; 
    vector <vector<BaseAST*>*> vectors;

    CompUnitAST* create_CompUnitAST(){
        auto node = new CompUnitAST();
        nodes.push_back(node);
        return node;
    }

    FuncFParamAST* create_FuncFParamAST(){
        auto node = new FuncFParamAST();
        nodes.push_back(node);
        return node;
    }

    FuncDefAST* create_FuncDefAST(){
        auto node = new FuncDefAST();
        nodes.push_back(node);
        return node;
    }

    BlockAST* create_BlockAST(){
        auto node = new BlockAST();
        nodes.push_back(node);
        return node;
    }

    StmtAST* create_StmtAST(){
        auto node = new StmtAST();
        nodes.push_back(node);
        return node;
    }

    ExpAST* create_ExpAST(){
        auto node = new ExpAST();
        nodes.push_back(node);
        return node;
    }

    LOrExpAST* create_LOrExpAST(){
        auto node = new LOrExpAST();
        nodes.push_back(node);
        return node;
    }

    LAndExpAST* create_LAndExpAST(){
        auto node = new LAndExpAST();
        nodes.push_back(node);
        return node;
    }

    EqExpAST* create_EqExpAST(){
        auto node = new EqExpAST();
        nodes.push_back(node);
        return node;
    }

    RelExpAST* create_RelExpAST(){
        auto node = new RelExpAST();
        nodes.push_back(node);
        return node;
    }

    AddExpAST* create_AddExpAST(){
        auto node = new AddExpAST();
        nodes.push_back(node);
        return node;
    }

    MulExpAST* create_MulExpAST(){
        auto node = new MulExpAST();
        nodes.push_back(node);
        return node;
    }

    UnaryExpAST* create_UnaryExpAST(){
        auto node = new UnaryExpAST();
        nodes.push_back(node);
        return node;
    }

    PrimaryExpAST* create_PrimaryExpAST(){
        auto node = new PrimaryExpAST();
        nodes.push_back(node);
        return node;
    }

    DeclAST* create_DeclAST(){
        auto node = new DeclAST();
        nodes.push_back(node);
        return node;
    }

    ConstDeclAST* create_ConstDeclAST(){
        auto node = new ConstDeclAST();
        nodes.push_back(node);
        return node;
    }

    ConstDefAST* create_ConstDefAST(){
        auto node = new ConstDefAST();
        nodes.push_back(node);
        return node;
    }

    ConstInitValAST* create_ConstInitValAST(){
        auto node = new ConstInitValAST();
        nodes.push_back(node);
        return node;
    }

    BlockItemAST* create_BlockItemAST(){
        auto node = new BlockItemAST();
        nodes.push_back(node);
        return node;
    }

    ConstExpAST* create_ConstExpAST(){
        auto node = new ConstExpAST();
        nodes.push_back(node);
        return node;
    }

    VarDeclAST* create_VarDeclAST(){
        auto node = new VarDeclAST();
        nodes.push_back(node);
        return node;
    }

    VarDefAST* create_VarDefAST(){
        auto node = new VarDefAST();
        nodes.push_back(node);
        return node;
    }

    InitValAST* create_InitValAST(){
        auto node = new InitValAST();
        nodes.push_back(node);
        return node;
    }

    vector<BaseAST*>* create_vector(){
        auto vec = new vector<BaseAST*> ;
        vectors.push_back(vec);
        return vec;
    }


};
