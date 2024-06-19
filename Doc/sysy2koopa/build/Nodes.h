#pragma once
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
using namespace std;
static int StrToInt(const string& str){
    int x=0;
    bool flag=0;
    size_t i=0;
    if(str[0]=='-'){
        flag=1;
        i++;
    }else if(str[0]=='+'){
        i++;
    }
    for(;i<str.size();i++){
        char c=str[i];
        assert(isdigit(c));
        x=x*10+(c-'0');
    }
    if(flag)x=-x;
    return x;
}
class MyVar {
public:
    enum class Type { INT, STRING };
    MyVar(): type(Type::INT), intValue(0), stringValue(""){}
    MyVar(int value) : type(Type::INT), intValue(value) {}
    MyVar(const std::string& value) : type(Type::STRING), stringValue(value) {}
    Type getType() const { return type; }
    int index() const {
        if (type == Type::INT) return 0;
        if (type == Type::STRING) return 1;
        assert(0);
        return 2;
    }
    bool operator <(const MyVar&b)const{
        if(type==b.type){
            if (type == Type::INT)return intValue<b.intValue;
            return stringValue<b.stringValue;
        }
        return type<b.type;
    }
    int getIntValue() const {
        if (type == Type::INT)
            return intValue;
        assert(0);
        return 0;
    }
    const std::string getStringValue() const {
        if (type == Type::STRING)
            return stringValue;
        assert(0);
        return "";
    }
private:
    Type type;
    int intValue;
    std::string stringValue;
};

enum class UnaryExpType { primary, unary, func_call };
enum class PrimaryExpType { exp, number, lval };
enum class StmtType { if_, ifelse, simple, while_,lval, exp, block, ret, break_, continue_ };
enum class BlockItemType { decl, stmt };



static int symbol_num = 0;
static int if_else_num = 0;
static int while_num = 0;



static map<string, int> var_num;
static vector<int> while_stack;


static vector<map<string, MyVar>>symbol_tables;
static MyVar get_val_in_symbol_tables(string iden)
{
    for (auto it = symbol_tables.rbegin(); it != symbol_tables.rend(); it++)
        if (it->find(iden)!=it->end())
            return (*it)[iden];
    assert(0);
    return -1;
}


static map<string, string> function_table;
static map<string, string> function_ret_type;
static map<string, int> function_param_num;
static void set_function(string func_table,string func_ret_type,int func_param_num){
    function_table[func_table] = "@" + func_table;
    function_ret_type[func_table] = func_ret_type;
    function_param_num[func_table] = func_param_num;
}
static map<string, vector<string>> function_param_idents;
static map<string, vector<string>> function_param_names;
static string present_func_type;


class BaseAST
{
public:
    virtual ~BaseAST() = default;
    virtual string outputIR() const = 0;
    virtual int caculateExp() const { assert(0); return -1; }
    virtual string get_ident() const { assert(0); return ""; }
};

class CompUnitAST : public BaseAST
{
public:
    vector<BaseAST*> func_def_list;//FuncDefAST
    vector<BaseAST*> decl_list;//DeclAST
    string outputIR() const override
    {
        cout << "decl @getint(): i32" << endl;
        set_function("getint", "int", 0);
        cout << "decl @getch(): i32" << endl;
        set_function("getch", "int", 0);
        cout << "decl @getarray(*i32): i32" << endl;
        set_function("getarray", "int", 1);
        cout << "decl @putint(i32)" << endl;
        set_function("putint", "void", 1);
        cout << "decl @putch(i32)" << endl;
        set_function("putch", "void", 1);
        cout << "decl @putarray(i32, *i32)" << endl;
        set_function("putarray", "void", 2);
        cout << "decl @starttime()" << endl;
        set_function("starttime", "void", 0);
        cout << "decl @stoptime()" << endl << endl;
        set_function("stoptime", "void", 0);
        map<string, MyVar> global_syms;
        symbol_tables.push_back(global_syms);
        for (auto decl : decl_list)decl->caculateExp();
        cout << endl;
        for (auto func_def : func_def_list)func_def->outputIR();
        symbol_tables.pop_back();
        return "";
    }
};

class DeclAST : public BaseAST
{
public:
    string type;
    BaseAST* decl;//ConstDeclAST 或 VarDeclAST
    string outputIR() const override { return decl->outputIR(); }
    int caculateExp() const override { return decl->caculateExp(); }
};


class ConstDeclAST : public BaseAST
{
public:
    string b_type;
    vector<BaseAST*> const_def_list;//ConstDefAST
    string outputIR() const override
    {
        assert(b_type == "int");
        for (auto const_def : const_def_list)const_def->outputIR();
        return "";
    }
    int caculateExp() const override { outputIR(); return 0; }
};


class ConstDefAST : public BaseAST
{
public:
    string ident;
    BaseAST* const_init_val;//ConstInitValAST
    string outputIR() const override
    {
        symbol_tables.back()[ident] = StrToInt(const_init_val->outputIR());
        return "";
    }
};


class ConstInitValAST : public BaseAST
{
public:
    BaseAST* const_exp;//ConstExpAST
    string outputIR() const override
    {
        return to_string(const_exp->caculateExp());
    }
};


class ConstExpAST : public BaseAST
{
public:
    BaseAST* exp;//ExpAST
    string outputIR() const override {return to_string(exp->caculateExp());}
    virtual int caculateExp() const override { return exp->caculateExp(); }
};


class ExpAST : public BaseAST
{
public:
    BaseAST* l_or_exp;//LOrExpAST
    string outputIR() const override
    {
        return l_or_exp->outputIR();
    }
    virtual int caculateExp() const override
    {
        return l_or_exp->caculateExp();
    }
};


class LOrExpAST : public BaseAST
{
public:
    string op;
    BaseAST* l_and_exp;
    BaseAST* l_or_exp;
    string outputIR() const override
    {
        string result_var = "";
        if (op == "")result_var = l_and_exp->outputIR();
        else if (op == "||")
        {
            string left_result = l_or_exp->outputIR();
            string then_label = "\%then_" + to_string(if_else_num);
            string else_label = "\%else_" + to_string(if_else_num);
            string end_label = "\%end_" + to_string(if_else_num++);
            string result_var_ptr = "%" + to_string(symbol_num++);
            cout << '\t' << result_var_ptr << " = alloc i32" << endl;
            cout << "\tbr " << left_result << ", " << then_label << ", "
                << else_label << endl;
            cout << then_label << ":" << endl;
            cout << "\tstore 1, " << result_var_ptr << endl;
            cout << "\tjump " << end_label << endl;
            cout << else_label << ":" << endl;
            string tmp_result_var = "%" + to_string(symbol_num++);
            string right_result = l_and_exp->outputIR();
            cout << '\t' << tmp_result_var << " = ne " << right_result
                << ", 0" << endl;
            cout << "\tstore " << tmp_result_var << ", " << result_var_ptr
                << endl;
            cout << "\tjump " << end_label << endl;
            cout << end_label << ":" << endl;
            result_var = "%" + to_string(symbol_num++);
            cout << '\t' << result_var << " = load " << result_var_ptr
                << endl;
        }
        else assert(0);
        return result_var;
    }
    virtual int caculateExp() const override
    {
        int result = 1;
        if (op == "")result = l_and_exp->caculateExp();
        else if (op == "||")
        {
            int left_result = l_or_exp->caculateExp();
            if (left_result)return 1;
            result = l_and_exp->caculateExp() != 0;
        }
        else assert(0);
        return result;
    }
};


class LAndExpAST : public BaseAST
{
public:
    string op;
    BaseAST* eq_exp;//EqExpAST
    BaseAST* l_and_exp;
    string outputIR() const override
    {
        string result_var = "";
        if (op == "")result_var = eq_exp->outputIR();
        else if (op == "&&")
        {
            string left_result = l_and_exp->outputIR();
            string then_label = "\%then_" + to_string(if_else_num);
            string else_label = "\%else_" + to_string(if_else_num);
            string end_label = "\%end_" + to_string(if_else_num++);
            string result_var_ptr = "%" + to_string(symbol_num++);
            cout << '\t' << result_var_ptr << " = alloc i32" << endl;
            cout << "\tbr " << left_result << ", " << then_label << ", "
                << else_label << endl;
            cout << then_label << ":" << endl;
            string tmp_result_var = "%" + to_string(symbol_num++);
            string right_result = eq_exp->outputIR();
            cout << '\t' << tmp_result_var << " = ne " << right_result
                << ", 0" << endl;
            cout << "\tstore " << tmp_result_var << ", " << result_var_ptr
                << endl;
            cout << "\tjump " << end_label << endl;
            cout << else_label << ":" << endl;
            cout << "\tstore 0, " << result_var_ptr << endl;
            cout << "\tjump " << end_label << endl;
            cout << end_label << ":" << endl;
            result_var = "%" + to_string(symbol_num++);
            cout << '\t' << result_var << " = load " << result_var_ptr
                << endl;
        }
        else assert(0);
        return result_var;
    }
    virtual int caculateExp() const override
    {
        int result = 0;
        if (op == "")result = eq_exp->caculateExp();
        else if (op == "&&")
        {
            int left_result = l_and_exp->caculateExp();
            if (left_result == 0)return 0;
            result = eq_exp->caculateExp() != 0;
        }
        else assert(0);
        return result;
    }
};


class EqExpAST : public BaseAST
{
public:
    string op;
    BaseAST* rel_exp;//RelExpAST
    BaseAST* eq_exp;
    string outputIR() const override
    {
        string result_var = "";
        if (op == "")result_var = rel_exp->outputIR();
        else
        {
            string left_result = eq_exp->outputIR();
            string right_result = rel_exp->outputIR();
            result_var = "%" + to_string(symbol_num++);
            if (op == "==")
                cout << '\t' << result_var << " = eq " << left_result <<
                    ", " << right_result << endl;
            else if (op == "!=")
                cout << '\t' << result_var << " = ne " << left_result <<
                    ", " << right_result << endl;
            else assert(0);
        }
        return result_var;
    }
    virtual int caculateExp() const override
    {
        int result = 0;
        if (op == "")result = rel_exp->caculateExp();
        else
        {
            int left_result = eq_exp->caculateExp();
            int right_result = rel_exp->caculateExp();
            if (op == "==")result = left_result == right_result;
            else if (op == "!=")result = left_result != right_result;
            else assert(0);
        }
        return result;
    }
};


class RelExpAST : public BaseAST
{
public:
    string op;
    BaseAST* add_exp;//AddExpAST
    BaseAST* rel_exp;
    string outputIR() const override
    {
        string result_var = "";
        if (op == "")result_var = add_exp->outputIR();
        else
        {
            string left_result = rel_exp->outputIR();
            string right_result = add_exp->outputIR();
            result_var = "%" + to_string(symbol_num++);
            if (op == "<")
                cout << '\t' << result_var << " = lt " << left_result <<
                    ", " << right_result << endl;
            else if (op == ">")
                cout << '\t' << result_var << " = gt " << left_result <<
                    ", " << right_result << endl;
            else if (op == "<=")
                cout << '\t' << result_var << " = le " << left_result <<
                    ", " << right_result << endl;
            else if (op == ">=")
                cout << '\t' << result_var << " = ge " << left_result <<
                    ", " << right_result << endl;
            else assert(0);
        }
        return result_var;
    }
    virtual int caculateExp() const override
    {
        int result = 0;
        if (op == "")result = add_exp->caculateExp();
        else
        {
            int left_result = rel_exp->caculateExp();
            int right_result = add_exp->caculateExp();
            if (op == ">")result = left_result > right_result;
            else if (op == ">=")result = left_result >= right_result;
            else if (op == "<")result = left_result < right_result;
            else if (op == "<=")result = left_result <= right_result;
            else assert(0);
        }
        return result;
    }
};


class AddExpAST : public BaseAST
{
public:
    string op;
    BaseAST* mul_exp;//MulExpAST
    BaseAST* add_exp;
    string outputIR() const override
    {
        string result_var = "";
        if (op == "")result_var = mul_exp->outputIR();
        else
        {
            string left_result = add_exp->outputIR();
            string right_result = mul_exp->outputIR();
            result_var = "%" + to_string(symbol_num++);
            if (op == "+")
                cout << '\t' << result_var << " = add " << left_result <<
                    ", " << right_result << endl;
            else if (op == "-")
                cout << '\t' << result_var << " = sub " << left_result <<
                    ", " << right_result << endl;
            else assert(0);
        }
        return result_var;
    }
    virtual int caculateExp() const override
    {
        int result = 0;
        if (op == "")result = mul_exp->caculateExp();
        else
        {
            int left_result = add_exp->caculateExp();
            int right_result = mul_exp->caculateExp();
            if (op == "+")result = left_result + right_result;
            else if (op == "-")result = left_result - right_result;
            else assert(0);
        }
        return result;
    }
};


class MulExpAST : public BaseAST
{
public:
    string op;
    BaseAST* unary_exp;//UnaryExpAST
    BaseAST* mul_exp;
    string outputIR() const override
    {
        string result_var = "";
        if (op == "")result_var = unary_exp->outputIR();
        else
        {
            string left_result = mul_exp->outputIR();
            string right_result = unary_exp->outputIR();
            result_var = "%" + to_string(symbol_num++);
            if (op == "*")
                cout << '\t' << result_var << " = mul " << left_result <<
                    ", " << right_result << endl;
            else if (op == "/")
                cout << '\t' << result_var << " = div " << left_result <<
                    ", " << right_result << endl;
            else if (op == "%")
                cout << '\t' << result_var << " = mod " << left_result <<
                    ", " << right_result << endl;
            else assert(0);
        }
        return result_var;
    }
    virtual int caculateExp() const override
    {
        int result = 0;
        if (op == "")result = unary_exp->caculateExp();
        else
        {
            int left_result = mul_exp->caculateExp();
            int right_result = unary_exp->caculateExp();
            if (op == "*")result = left_result * right_result;
            else if (op == "/")result = left_result / right_result;
            else if (op == "%")result = left_result % right_result;
            else assert(0);
        }
        return result;
    }
};


class UnaryExpAST : public BaseAST
{
public:
    UnaryExpType type;
    string op;
    BaseAST* exp;//PrimaryExpAST 或 本身
    string ident;
    vector<BaseAST*> params;
    string outputIR() const override
    {
        if (type == UnaryExpType::primary)return exp->outputIR();
        else if (type == UnaryExpType::unary)
        {
            string result_var = exp->outputIR();
            string next_var = "%" + to_string(symbol_num);
            if (op == "+")return result_var;
            else if (op == "-")cout << '\t' << next_var << " = sub 0, " <<
                result_var << endl;
            else if (op == "!")cout << '\t' << next_var << " = eq " <<
                result_var << ", 0" << endl;
            else assert(0);
            symbol_num++;
            return next_var;
        }
        else if (type == UnaryExpType::func_call)
        {
            vector<string> param_vars;
            for (auto param : params)
                param_vars.push_back(param->outputIR());
            assert(function_table.count(ident));
            assert(function_param_num[ident] == params.size());
            string result_var = "";
            if (function_ret_type[ident] == "int")
                result_var = "%" + to_string(symbol_num++);
            string name = function_table[ident];
            cout << '\t';
            if (function_ret_type[ident] == "int")
                cout << result_var << " = ";
            cout << "call " << name << "(";
            for (int i = 0; i < param_vars.size(); i++)
            {
                cout << param_vars[i];
                if (i != param_vars.size() - 1)cout << ", ";
            }
            cout << ")" << endl;
            return result_var;
        }
        else assert(0);
        return "";
    }
    virtual int caculateExp() const override
    {
        int result = 0;
        if (type == UnaryExpType::primary)result = exp->caculateExp();
        else if (type == UnaryExpType::unary)
        {
            int tmp = exp->caculateExp();
            if (op == "+")result = tmp;
            else if (op == "-")result = -tmp;
            else if (op == "!")result = !tmp;
            else assert(0);
        }
        else assert(0);
        return result;
    }
};


class PrimaryExpAST : public BaseAST
{
public:
    PrimaryExpType type;
    BaseAST* exp;//ExpAST
    string lval;
    int number;

    string outputIR() const override
    {
        string result_var = "";
        if (type == PrimaryExpType::exp)result_var = exp->outputIR();
        else if (type == PrimaryExpType::number)result_var = to_string(number);
        else if (type == PrimaryExpType::lval)
        {
            MyVar value = get_val_in_symbol_tables(lval);
            if (value.index() == 0)result_var = to_string(value.getIntValue());
            else
            {
                result_var = "%" + to_string(symbol_num++);
                cout << '\t' << result_var << " = load " << value.getStringValue() << endl;
            }
        }
        else assert(0);
        return result_var;
    }
    virtual int caculateExp() const override
    {
        int result = 0;
        if (type == PrimaryExpType::exp)result = exp->caculateExp();
        else if (type == PrimaryExpType::number)result = number;
        else if (type == PrimaryExpType::lval)
        {
            MyVar value = get_val_in_symbol_tables(lval);
            assert(value.index() == 0);
            result = value.getIntValue();
        }
        else assert(0);
        return result;
    }
};





class VarDeclAST : public BaseAST
{
public:
    string b_type;
    vector<BaseAST*> var_def_list;
    string outputIR() const override
    {
        assert(b_type == "int");
        for (auto var_def : var_def_list)var_def->outputIR();
        return "";
    }
    int caculateExp() const override
    {
        assert(b_type == "int");
        for (auto var_def : var_def_list)var_def->caculateExp();
        return 0;
    }
};


class VarDefAST : public BaseAST
{
public:
    string ident;
    bool has_init_val;
    BaseAST* init_val;
    string outputIR() const override
    {
        string var_name = "@" + ident;
        string name = var_name + "_" +
            to_string(var_num[var_name]++);
        cout << '\t' << name << " = alloc i32" << endl;
        symbol_tables.back()[ident] = name;
        if (has_init_val)
        {
            string val_var = init_val->outputIR();
            cout << "\tstore " << val_var << ", " << name << endl;
        }
        return "";
    }
    int caculateExp() const override
    {
        string var_name = "@" + ident;
        string name = var_name + "_" +
            to_string(var_num[var_name]++);
        symbol_tables.back()[ident] = name;
        if (has_init_val)
        {
            string val_var = init_val->outputIR();
            cout << "global " << name << " = alloc i32, ";
            if (val_var[0] == '@' || val_var[0] == '%')assert(0);
            else if (val_var != "0")cout << val_var << endl;
            else cout << "zeroinit" << endl;
        }
        else
            cout << "global " << name << " = alloc i32, zeroinit" <<
                endl;
        return 0;
    }
};


class InitValAST : public BaseAST
{
public:
    BaseAST* exp;
    string outputIR() const override { return exp->outputIR(); }
};


class FuncFParamAST : public BaseAST
{
public:
    string b_type;
    string ident;
    string outputIR() const override
    {
        assert(b_type == "int");
        string param_name = "@" + ident;
        string name = param_name + "_" +
            to_string(var_num[param_name]++);
        cout << name;
        return name;
    }
    string get_ident() const override { return ident; }
};


class FuncDefAST : public BaseAST
{
public:
    string func_type;
    string ident;
    vector<BaseAST*> params;
    BaseAST* block;
    string outputIR() const override
    {
        string name = "@" + ident;
        assert(!symbol_tables[0].count(ident));
        assert(!function_table.count(ident));
        function_table[ident] = name;
        function_ret_type[ident] = func_type;
        function_param_num[ident] = params.size();
        present_func_type = func_type;
        vector<string> idents, names;
        cout << "fun " << name << "(";
        for (int i = 0; i < params.size(); i++)
        {
            idents.push_back(params[i]->get_ident());
            names.push_back(params[i]->outputIR());
            cout << ": i32";
            if (i != params.size() - 1)cout << ", ";
        }
        function_param_idents[ident] = move(idents);
        function_param_names[ident] = move(names);
        cout << ")";
        if (func_type == "int")cout << ": i32";
        else if (func_type != "void")assert(0);
        cout << " {" << endl << "\%entry_" << ident << ":" <<
            endl;
        string block_type = block->outputIR();
        if (block_type != "ret")
        {
            if (func_type == "int")cout << "\tret 0" << endl;
            else if (func_type == "void")cout << "\tret" << endl;
            else assert(0);
        }
        cout << "}" << endl << endl;
        return block_type;
    }
};


class BlockAST : public BaseAST
{
public:
    vector<BaseAST*> block_item_list;
    string func = "";
    string outputIR() const override
    {
        string block_type = "";
        map<string, MyVar> symbol_table;
        if (func != "")
        {
            vector<string> idents = function_param_idents[func];
            vector<string> names = function_param_names[func];
            for (int i = 0; i < names.size(); i++)
            {
                string ident = idents[i];
                string name = names[i]; name[0] = '%';
                symbol_table[ident] = name;
                cout << '\t' << name << " = alloc i32" << endl;
                cout << "\tstore " << names[i] << ", " << name <<
                    endl;
            }
        }
        symbol_tables.push_back(symbol_table);
        for (auto block_item : block_item_list)
        {
            block_type = block_item->outputIR();
            if (block_type == "ret" || block_type == "break" ||
                block_type == "cont")break;
        }
        symbol_tables.pop_back();
        return block_type;
    }
};


class StmtAST : public BaseAST
{
public:
    StmtType type;
    BaseAST* exp_simple;
    BaseAST* if_stmt;
    BaseAST* else_stmt;
    BaseAST* while_stmt;
    string lval;
    BaseAST* block_exp;
    string outputIR() const override
    {
        if (type == StmtType::simple)return exp_simple->outputIR();
        if (type == StmtType::ret)
        {
            if (block_exp == nullptr)
            {
                if (present_func_type == "int")
                    cout << "\tret 0" << endl;
                else cout << "\tret" << endl;
            }
            else
            {
                string result_var = block_exp->outputIR();
                cout << "\tret " << result_var << endl;
            }
            return "ret";
        }
        else if (type == StmtType::lval)
        {
            string result_var = block_exp->outputIR();
            MyVar value = get_val_in_symbol_tables(lval);
            assert(value.index() == 1);
            cout << "\tstore " << result_var << ", " <<
                value.getStringValue() << endl;
        }
        else if (type == StmtType::exp)
        {
            if (block_exp != nullptr)block_exp->outputIR();
        }
        else if (type == StmtType::block)return block_exp->outputIR();
        else if (type == StmtType::break_)
        {
            assert(!while_stack.empty());
            int while_no = while_stack.back();
            string end_label = "\%while_end_" + to_string(while_no);
            cout << "\tjump " << end_label << endl;
            return "break";
        }
        else if (type == StmtType::continue_)
        {
            assert(!while_stack.empty());
            int while_no = while_stack.back();
            string entry_label = "\%while_" + to_string(while_no);
            cout << "\tjump " << entry_label << endl;
            return "cont";
        }
        else if (type == StmtType::if_)
        {
            string if_result = exp_simple->outputIR();
            string then_label = "\%then_" + to_string(if_else_num);
            string end_label = "\%end_" + to_string(if_else_num++);
            cout << "\tbr " << if_result << ", " << then_label << ", " <<
                end_label << endl;
            cout << then_label << ":" << endl;
            string if_stmt_type = if_stmt->outputIR();
            if (if_stmt_type != "ret" && if_stmt_type != "break" &&
                if_stmt_type != "cont")
                cout << "\tjump " << end_label << endl;
            cout << end_label << ":" << endl;
        }
        else if (type == StmtType::ifelse)
        {
            string if_result = exp_simple->outputIR();
            string then_label = "\%then_" + to_string(if_else_num);
            string else_label = "\%else_" + to_string(if_else_num);
            string end_label = "\%end_" + to_string(if_else_num++);
            cout << "\tbr " << if_result << ", " << then_label << ", " <<
                else_label << endl;
            cout << then_label << ":" << endl;
            string if_stmt_type = if_stmt->outputIR();
            if (if_stmt_type != "ret" && if_stmt_type != "break" &&
                if_stmt_type != "cont")
                cout << "\tjump " << end_label << endl;
            cout << else_label << ":" << endl;
            string else_stmt_type = else_stmt->outputIR();
            if (else_stmt_type != "ret" && else_stmt_type != "break" &&
                else_stmt_type != "cont")
                cout << "\tjump " << end_label << endl;
            if ((if_stmt_type == "ret" || if_stmt_type == "break" ||
                if_stmt_type == "cont") && (else_stmt_type == "ret" ||
                else_stmt_type == "break" || else_stmt_type == "cont"))
                return "ret";
            else cout << end_label << ":" << endl;
        }
        else if (type == StmtType::while_)
        {
            string entry_label = "\%while_" + to_string(while_num);
            string body_label = "\%do_" + to_string(while_num);
            string end_label = "\%while_end_" + to_string(while_num);
            while_stack.push_back(while_num++);
            cout << "\tjump " << entry_label << endl;
            cout << entry_label << ":" << endl;
            string while_result = exp_simple->outputIR();
            cout << "\tbr " << while_result << ", " << body_label << ", "
                << end_label << endl;
            cout << body_label << ":" << endl;
            string while_stmt_type = while_stmt->outputIR();
            if (while_stmt_type != "ret" && while_stmt_type != "break" &&
                while_stmt_type != "cont")
                cout << "\tjump " << entry_label << endl;
            cout << end_label << ":" << endl;
            while_stack.pop_back();
        }
        else assert(0);
        return "";
    }
};

class BlockItemAST : public BaseAST
{
public:
    BlockItemType type;
    BaseAST* content;
    string outputIR() const override { return content->outputIR(); }
};