%code requires 
{
    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <vector>
    #include <map>
    #include <set>
    #include <cmath>
    #include <cstdlib>
    #include "Nodes.h"
    #include "NodesManager.h"
    using namespace std;
}

%{
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "Nodes.h"
#include "NodesManager.h"
using namespace std;
void yyerror(NodesManager &manager, const char *s);
int yylex();
%}

%parse-param {NodesManager &manager}

%union 
{
    string *stringPointer;
    int integer32;
    BaseAST *astPointer;
    vector<BaseAST *> *vectorPointer;
}

%type <stringPointer> UNARYOP LVal BType VoidType
%type <astPointer> FuncDef Block Stmt Exp PrimaryExp UnaryExp AddExp MulExp RelExp EqExp LAndExp LOrExp Decl ConstDecl ConstDef ConstInitVal BlockItem ConstExp VarDecl VarDef InitVal OpenStmt ClosedStmt CompUnit FuncFParam
%type <vectorPointer> BlockItemList ConstDefList VarDefList FuncFParams FuncRParams
%type <integer32> Number
%token INT VOID RETURN CONST IF ELSE WHILE BREAK CONTINUE
%token <stringPointer> IDENT
%token <integer32> INT_CONST
%token <stringPointer> LE GE EQ NE AND OR


%%

Start:
	CompUnit 
	{
        manager.root = (BaseAST*)($1);
    }
    ;

CompUnit:
	FuncDef 
	{
        auto comp_unit = manager.create_CompUnitAST();
        auto func_def = $1;
        comp_unit->func_def_list.push_back(func_def);
        $$ = comp_unit;
    }|

	Decl 
	{
        auto comp_unit = manager.create_CompUnitAST();
        auto decl = (BaseAST*)($1);
        comp_unit->decl_list.push_back(decl);
        $$ = comp_unit;
    }|

	CompUnit FuncDef 
	{
        auto comp_unit = (CompUnitAST*)($1);
        auto func_def = (BaseAST*)($2);
        comp_unit->func_def_list.push_back(func_def);
        $$ = comp_unit;
    }|

	CompUnit Decl 
	{
        auto comp_unit = (CompUnitAST*)($1);
        auto decl = (BaseAST*)($2);
        comp_unit->decl_list.push_back(decl);
        $$ = comp_unit;
    }
    ;

FuncDef:
	VoidType IDENT '(' ')' Block 
	{
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *($1);
        delete $1;
        func_def->ident = *($2);
        delete $2;
        func_def->block = (BaseAST*)($5);
        $$ = func_def;
    }|

	VoidType IDENT '(' FuncFParams ')' Block 
	{
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *($1);
        delete $1;
        func_def->ident = *($2);
        delete $2;
        vector<BaseAST*> *v_ptr = ($4);
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            func_def->params.push_back(*it);
        func_def->block = (BaseAST*)($6);
        ((BlockAST*)(func_def->block))->func = func_def->ident;
        $$ = func_def;
    }|

	BType IDENT '(' ')' Block 
	{
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *($1);
        delete $1;
        func_def->ident = *($2);
        delete $2;
        func_def->block = (BaseAST*)($5);
        $$ = func_def;
    }|

	BType IDENT '(' FuncFParams ')' Block 
	{
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *($1);
        delete $1;
        func_def->ident = *($2);
        delete $2;
        vector<BaseAST*> *v_ptr = ($4);
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            func_def->params.push_back(*it);
        func_def->block = (BaseAST*)($6);
        ((BlockAST*)(func_def->block))->func = func_def->ident;
        $$ = func_def;
    }
    ;
    ;

FuncFParams:
	FuncFParam 
	{
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)($1));
        $$ = v;
    }|

	FuncFParams ',' FuncFParam 
	{
        vector<BaseAST*> *v = ($1);
        v->push_back((BaseAST*)($3));
        $$ = v;
    }
    ;

FuncFParam:
	BType IDENT 
	{
        auto param = manager.create_FuncFParamAST();
        param->b_type = *($1);
        delete $1;
        param->ident = *($2);
        delete $2;
        $$ = param;
    }
    ;

FuncRParams:
	Exp 
	{
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)($1));
        $$ = v;
    }|

	FuncRParams ',' Exp 
	{
        vector<BaseAST*> *v = ($1);
        v->push_back((BaseAST*)($3));
        $$ = v;
    }
    ;

Block:
	'{' BlockItemList '}' 
	{
        auto block = manager.create_BlockAST();
        vector<BaseAST*> *v_ptr = ($2);
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            block->block_item_list.push_back(*it);
        $$ = block;
    }
    ;

Stmt:
	OpenStmt 
	{
        auto stmt = ($1);
        $$ = stmt;
    }|

	ClosedStmt 
	{
        auto stmt = ($1);
        $$ = stmt;
    }
    ;

ClosedStmt:
	
    //////////////////////////////////////////////////////////////////////
    RETURN Exp ';' 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ret;
        stmt->block_exp = (BaseAST*)($2);
        $$ = stmt;
    }|

	RETURN ';' 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ret;
        stmt->block_exp = nullptr;
        $$ = stmt;
    }|

	LVal '=' Exp ';' 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::lval;
        stmt->lval = *($1);
        delete $1;
        stmt->block_exp = (BaseAST*)($3);
        $$ = stmt;
    }|

	Block 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::block;
        stmt->block_exp = (BaseAST*)($1);
        $$ = stmt;
    }|

	Exp ';' 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::exp;
        stmt->block_exp = (BaseAST*)($1);
        $$ = stmt;
    }|

	';' 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::exp;
        stmt->block_exp = nullptr;
        $$ = stmt;
    }|

	BREAK ';' 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::break_;
        $$ = stmt;
    }|

	CONTINUE ';' 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::continue_;
        $$ = stmt;
    }|

    ///////////////////////////////////////////////////////////////////////

	IF '(' Exp ')' ClosedStmt ELSE ClosedStmt 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ifelse;
        stmt->exp_simple = (BaseAST*)($3);
        stmt->if_stmt = (BaseAST*)($5);
        stmt->else_stmt = (BaseAST*)($7);
        $$ = stmt;
    }|

	WHILE '(' Exp ')' ClosedStmt 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::while_;
        stmt->exp_simple = (BaseAST*)($3);
        stmt->while_stmt = (BaseAST*)($5);
        $$ = stmt;
    }
    ;

OpenStmt:
	IF '(' Exp ')' Stmt 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::if_;
        stmt->exp_simple = (BaseAST*)($3);
        stmt->if_stmt = (BaseAST*)($5);
        $$ = stmt;
    }|

	IF '(' Exp ')' ClosedStmt ELSE OpenStmt 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ifelse;
        stmt->exp_simple = (BaseAST*)($3);
        stmt->if_stmt = (BaseAST*)($5);
        stmt->else_stmt = (BaseAST*)($7);
        $$ = stmt;
    }|

	WHILE '(' Exp ')' OpenStmt 
	{
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::while_;
        stmt->exp_simple = (BaseAST*)($3);
        stmt->while_stmt = (BaseAST*)($5);
        $$ = stmt;
    }
    ;


Exp:
	LOrExp 
	{
        auto exp = manager.create_ExpAST();
        exp->l_or_exp = (BaseAST*)($1);
        $$ = exp;
    }
    ;

LOrExp:
	LAndExp 
	{
        auto l_or_exp = manager.create_LOrExpAST();
        l_or_exp->op = "";
        l_or_exp->l_and_exp = (BaseAST*)($1);
        $$ = l_or_exp;
    }|

	LOrExp OR LAndExp 
	{
        auto l_or_exp = manager.create_LOrExpAST();
        l_or_exp->l_or_exp = (BaseAST*)($1);

        l_or_exp->op = "||";
        l_or_exp->l_and_exp = (BaseAST*)($3);
        $$ = l_or_exp;
    }
    ;

LAndExp:
	EqExp 
	{
        auto l_and_exp = manager.create_LAndExpAST();
        l_and_exp->op = "";
        l_and_exp->eq_exp = (BaseAST*)($1);
        $$ = l_and_exp;
    }|

	LAndExp AND EqExp 
	{
        auto l_and_exp = manager.create_LAndExpAST();
        l_and_exp->l_and_exp = (BaseAST*)($1);
        l_and_exp->op = "&&";
        l_and_exp->eq_exp = (BaseAST*)($3);
        $$ = l_and_exp;
    }
    ;

EqExp:
	RelExp 
	{
        auto eq_exp = manager.create_EqExpAST();
        eq_exp->op = "";
        eq_exp->rel_exp = (BaseAST*)($1);
        $$ = eq_exp;
    }|

	EqExp EQ RelExp 
	{
        auto eq_exp = manager.create_EqExpAST();
        eq_exp->eq_exp = (BaseAST*)($1);
        eq_exp->op = "==";
        eq_exp->rel_exp = (BaseAST*)($3);
        $$ = eq_exp;
    }|

	EqExp NE RelExp 
	{
        auto eq_exp = manager.create_EqExpAST();
        eq_exp->eq_exp = (BaseAST*)($1);
        eq_exp->op = "!=";
        eq_exp->rel_exp = (BaseAST*)($3);
        $$ = eq_exp;
    }
    ;

RelExp:
	AddExp 
	{
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->op = "";
        rel_exp->add_exp = (BaseAST*)($1);
        $$ = rel_exp;
    }|

	RelExp LE AddExp 
	{
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)($1);
        rel_exp->op = "<=";
        rel_exp->add_exp = (BaseAST*)($3);
        $$ = rel_exp;
    }|

	RelExp GE AddExp 
	{
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)($1);
        rel_exp->op = ">=";
        rel_exp->add_exp = (BaseAST*)($3);
        $$ = rel_exp;
    }|

	RelExp '<' AddExp 
	{
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)($1);
        rel_exp->op = "<";
        rel_exp->add_exp = (BaseAST*)($3);
        $$ = rel_exp;
    }|

	RelExp '>' AddExp 
	{
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)($1);
        rel_exp->op = ">";
        rel_exp->add_exp = (BaseAST*)($3);
        $$ = rel_exp;
    }
    ;

AddExp:
	MulExp 
	{
        auto add_exp = manager.create_AddExpAST();
        add_exp->op = "";
        add_exp->mul_exp = (BaseAST*)($1);
        $$ = add_exp;
    }|

	AddExp '+' MulExp 
	{
        auto add_exp = manager.create_AddExpAST();
        add_exp->add_exp = (BaseAST*)($1);
        add_exp->op = "+";
        add_exp->mul_exp = (BaseAST*)($3);
        $$ = add_exp;
    }|

	AddExp '-' MulExp 
	{
        auto add_exp = manager.create_AddExpAST();
        add_exp->add_exp = (BaseAST*)($1);
        add_exp->op = "-";
        add_exp->mul_exp = (BaseAST*)($3);
        $$ = add_exp;
    }
    ;

MulExp:
	UnaryExp 
	{
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->op = "";
        mul_exp->unary_exp = (BaseAST*)($1);
        $$ = mul_exp;
    }|

	MulExp '*' UnaryExp 
	{
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->mul_exp = (BaseAST*)($1);
        mul_exp->op = "*";
        mul_exp->unary_exp = (BaseAST*)($3);
        $$ = mul_exp;
    }|

	MulExp '/' UnaryExp 
	{
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->mul_exp = (BaseAST*)($1);
        mul_exp->op = "/";
        mul_exp->unary_exp = (BaseAST*)($3);
        $$ = mul_exp;
    }|

	MulExp '%' UnaryExp 
	{
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->mul_exp = (BaseAST*)($1);
        mul_exp->op = "%";
        mul_exp->unary_exp = (BaseAST*)($3);
        $$ = mul_exp;
    }
    ;

UnaryExp:
	PrimaryExp 
	{
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::primary;
        unary_exp->exp = (BaseAST*)($1);
        $$ = unary_exp;
    }|

	UNARYOP UnaryExp 
	{
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::unary;
        unary_exp->op = *($1);
        delete $1;
        unary_exp->exp = (BaseAST*)($2);
        $$ = unary_exp;
    }|

	IDENT '(' ')' 
	{
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::func_call;
        unary_exp->ident = *($1);
        delete $1;
        $$ = unary_exp;
    }|

	IDENT '(' FuncRParams ')' 
	{
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::func_call;
        unary_exp->ident = *($1);
        delete $1;
        vector<BaseAST*> *v_ptr = ($3);
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            unary_exp->params.push_back(*it);
        $$ = unary_exp;
    }
    ;

PrimaryExp:
	'(' Exp ')' 
	{
        auto primary_exp = manager.create_PrimaryExpAST();
        primary_exp->type = PrimaryExpType::exp;
        primary_exp->exp = (BaseAST*)($2);
        $$ = primary_exp;
    }|

	Number 
	{
        auto primary_exp = manager.create_PrimaryExpAST();
        primary_exp->type = PrimaryExpType::number;
        primary_exp->number = ($1);
        $$ = primary_exp;
    }|

	LVal 
	{
        auto primary_exp = manager.create_PrimaryExpAST();
        primary_exp->type = PrimaryExpType::lval;
        primary_exp->lval = *($1);
        delete $1;
        $$ = primary_exp;
    }
    ;

Decl:
	ConstDecl 
	{
        auto decl = manager.create_DeclAST();
        decl->type = "const_decl";
        decl->decl = (BaseAST*)($1);
        $$ = decl;
    }|

	VarDecl 
	{
        auto decl = manager.create_DeclAST();
        decl->type = "var_decl";
        decl->decl = (BaseAST*)($1);
        $$ = decl;
    }
    ;

ConstDecl:
	CONST BType ConstDefList ';' 
	{
        auto const_decl = manager.create_ConstDeclAST();
        const_decl->b_type = *($2);
        delete $2;
        vector<BaseAST*> *v_ptr = ($3);
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            const_decl->const_def_list.push_back(*it);
        $$ = const_decl;
    }
    ;

ConstDef:
	IDENT '=' ConstInitVal 
	{
        auto const_def = manager.create_ConstDefAST();
        const_def->ident = *($1);
        delete $1;
        const_def->const_init_val = (BaseAST*)($3);
        $$ = const_def;
    }
    ;

ConstInitVal:
	ConstExp 
	{
        auto const_init_val = manager.create_ConstInitValAST();
        const_init_val->const_exp = (BaseAST*)($1);
        $$ = const_init_val;
    }
    ;

BlockItem:
	Decl 
	{
        auto block_item = manager.create_BlockItemAST();
        block_item->type = BlockItemType::decl;
        block_item->content = (BaseAST*)($1);
        $$ = block_item;
    }|

	Stmt 
	{
        auto block_item = manager.create_BlockItemAST();
        block_item->type = BlockItemType::stmt;
        block_item->content = (BaseAST*)($1);
        $$ = block_item;
    }
    ;

ConstExp:
	Exp 
	{
        auto const_exp = manager.create_ConstExpAST();
        const_exp->exp = (BaseAST*)($1);
        $$ = const_exp;
    }
    ;

VarDecl:
	BType VarDefList ';' 
	{
        auto var_decl = manager.create_VarDeclAST();
        var_decl->b_type = *($1);
        delete $1;
        vector<BaseAST*> *v_ptr = ($2);
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            var_decl->var_def_list.push_back(*it);
        $$ = var_decl;
    }
    ;

VarDef:
	IDENT 
	{
        auto var_def = manager.create_VarDefAST();
        var_def->ident = *($1);
        delete $1;
        var_def->has_init_val = false;
        $$ = var_def;
    }|

	IDENT '=' InitVal 
	{
        auto var_def = manager.create_VarDefAST();
        var_def->ident = *($1);
        delete $1;
        var_def->has_init_val = true;
        var_def->init_val = (BaseAST*)($3);
        $$ = var_def;
    }
    ;

InitVal:
	Exp 
	{
        auto init_val = manager.create_InitValAST();
        init_val->exp = (BaseAST*)($1);
        $$ = init_val;
    }
    ;

BlockItemList:
	
	{
        vector<BaseAST*> *v = manager.create_vector();
        $$ = v;
    }|

	BlockItemList BlockItem 
	{
        vector<BaseAST*> *v = ($1);
        v->push_back((BaseAST*)($2));
        $$ = v;
    }
    ;

ConstDefList:
	ConstDef 
	{
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)($1));
        $$ = v;
    }|

	ConstDefList ',' ConstDef 
	{
        vector<BaseAST*> *v = ($1);
        v->push_back((BaseAST*)($3));
        $$ = v;
    }
    ;

VarDefList:
	VarDef 
	{
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)($1));
        $$ = v;
    }|

	VarDefList ',' VarDef 
	{
        vector<BaseAST*> *v = ($1);
        v->push_back((BaseAST*)($3));
        $$ = v;
    }
    ;


Number:
	INT_CONST 
	{
        $$ = ($1);
    }
    ;

LVal:
	IDENT 
	{
        string *lval = new string(*($1));
        delete $1;
        $$ = lval;
    }
    ;

BType:
	INT 
	{
        string *type = new string("int");
        $$ = type;
    }
    // | VOID {
    //     string *type = new string("void");
    //     $$ = type;
    // }
    ;
VoidType:
	VOID 
	{
        string *type = new string("void");
        $$ = type;
    }


UNARYOP:
	'+' 
	{
        string *op = new string("+");
        $$ = op;
    }|

	'-' 
	{
        string *op = new string("-");
        $$ = op;
    }|

	'!' 
	{
        string *op = new string("!");
        $$ = op;
    }
    ;







%%

void yyerror(NodesManager &manager, const char *s)
{
    extern int yylineno;
    extern char *yytext;
    cerr << "ERROR: " << s << " at symbol '" << yytext << "' on line " << yylineno << endl;
}