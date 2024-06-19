#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cassert>
#include <map>
#include <variant>
using namespace std;

int StrToInt(const string& str);
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

static int symbol_num = 0;
static int if_else_num = 0;
static int while_num = 0;
enum class UnaryExpType { primary, unary, func_call };
enum class PrimaryExpType { exp, number, lval };
enum class StmtType { if_, ifelse, simple, while_,lval, exp, block, ret, break_, continue_ };
enum class DeclType { const_decl, var_decl };
enum class BlockItemType { decl, stmt };
static vector<map<string, MyVar>>
    symbol_tables;
static map<string, int> var_num;
static vector<int> while_stack;
static map<string, string> function_table;
static map<string, string> function_ret_type;
static map<string, int> function_param_num;
static map<string, vector<string>> function_param_idents;
static map<string, vector<string>> function_param_names;
static string present_func_type;


static MyVar look_up_symbol_tables(string l_val)
{
    for (auto it = symbol_tables.rbegin(); it != symbol_tables.rend(); it++)
        if (it->count(l_val))
            return (*it)[l_val];
    assert(false);
    return -1;
}


class BaseAST
{
public:
    virtual ~BaseAST() = default;
    virtual void dump() const = 0;
    virtual string dumpIR() const = 0;
    virtual int dumpExp() const { assert(false); return -1; }
    virtual string get_ident() const { assert(false); return ""; }
    
};


class CompUnitAST : public BaseAST
{
public:
    vector<BaseAST*> func_def_list;
    vector<BaseAST*> decl_list;
    void dump() const override
    {
        cout << "CompUnitAST { ";
        for (auto&& func_def : func_def_list)
            func_def->dump();
        cout << " } ";
    }
    string dumpIR() const override
    {
        cout << "decl @getint(): i32" << endl;
        cout << "decl @getch(): i32" << endl;
        cout << "decl @getarray(*i32): i32" << endl;
        cout << "decl @putint(i32)" << endl;
        cout << "decl @putch(i32)" << endl;
        cout << "decl @putarray(i32, *i32)" << endl;
        cout << "decl @starttime()" << endl;
        cout << "decl @stoptime()" << endl << endl;
        function_table["getint"] = "@getint";
        function_table["getch"] = "@getch";
        function_table["getarray"] = "@getarray";
        function_table["putint"] = "@putint";
        function_table["putch"] = "@putch";
        function_table["putarray"] = "@putarray";
        function_table["starttime"] = "@starttime";
        function_table["stoptime"] = "@stoptime";
        function_ret_type["getint"] = "int";
        function_ret_type["getch"] = "int";
        function_ret_type["getarray"] = "int";
        function_ret_type["putint"] = "void";
        function_ret_type["putch"] = "void";
        function_ret_type["putarray"] = "void";
        function_ret_type["starttime"] = "void";
        function_ret_type["stoptime"] = "void";
        function_param_num["getint"] = 0;
        function_param_num["getch"] = 0;
        function_param_num["getarray"] = 1;
        function_param_num["putint"] = 1;
        function_param_num["putch"] = 1;
        function_param_num["putarray"] = 2;
        function_param_num["starttime"] = 0;
        function_param_num["stoptime"] = 0;
        map<string, MyVar> global_syms;
        symbol_tables.push_back(global_syms);
        for (auto&& decl : decl_list)decl->dumpExp();
        cout << endl;
        for (auto&& func_def : func_def_list)func_def->dumpIR();
        symbol_tables.pop_back();
        return "";
    }
};


class FuncFParamAST : public BaseAST
{
public:
    string b_type;
    string ident;
    void dump() const override { cout << b_type << " " << ident; }
    string dumpIR() const override
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
    void dump() const override
    {
        cout << "FuncDefAST { " << func_type << ", " << ident << ", ";
        for (int i = 0; i < params.size(); i++)
        {
            params[i]->dump();
            if (i != params.size() - 1)cout << ", ";
        }
        block->dump();
        cout << " } ";
    }
    string dumpIR() const override
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
            names.push_back(params[i]->dumpIR());
            cout << ": i32";
            if (i != params.size() - 1)cout << ", ";
        }
        function_param_idents[ident] = move(idents);
        function_param_names[ident] = move(names);
        cout << ")";
        if (func_type == "int")cout << ": i32";
        else if (func_type != "void")assert(false);
        cout << " {" << endl << "\%entry_" << ident << ":" <<
            endl;
        string block_type = block->dumpIR();
        if (block_type != "ret")
        {
            if (func_type == "int")cout << "\tret 0" << endl;
            else if (func_type == "void")cout << "\tret" << endl;
            else assert(false);
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
    void dump() const override
    {
        cout << "BlockAST { ";
        for (auto&& block_item : block_item_list)block_item->dump();
        cout << " } ";
    }
    string dumpIR() const override
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
        for (auto&& block_item : block_item_list)
        {
            block_type = block_item->dumpIR();
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
    void dump() const override
    {
        if (type == StmtType::ret)
        {
            cout << "RETURN { ";
            block_exp->dump();
            cout << " } ";
        }
        else if (type == StmtType::lval)
        {
            cout << "LVAL { " << lval << " = ";
            block_exp->dump();
            cout << " } ";
        }
        else if (type == StmtType::exp)
        {
            if (block_exp != nullptr)
            {
                cout << "EXP { ";
                block_exp->dump();
                cout << " } ";
            }
        }
        else if (type == StmtType::block)
        {
            cout << "BLOCK { ";
            block_exp->dump();
            cout << " } ";
        }
        else if (type == StmtType::break_)cout << "BREAK ";
        else if (type == StmtType::continue_)cout << "CONTINUE ";
        else if (type == StmtType::if_)
        {
            cout << "IF { ";
            exp_simple->dump();
            cout << " } THEN { ";
            if_stmt->dump();
            cout << " } ";
        }
        else if (type == StmtType::ifelse)
        {
            cout << "IF { ";
            exp_simple->dump();
            cout << " } THEN { ";
            if_stmt->dump();
            cout << " } ELSE { ";
            else_stmt->dump();
            cout << " } ";
        }
        else if (type == StmtType::while_)
        {
            cout << "WHILE { ";
            exp_simple->dump();
            cout << " } DO { ";
            while_stmt->dump();
            cout << " } ";
        }
        else assert(false);
    }
    string dumpIR() const override
    {
        if (type == StmtType::simple)return exp_simple->dumpIR();
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
                string result_var = block_exp->dumpIR();
                cout << "\tret " << result_var << endl;
            }
            return "ret";
        }
        else if (type == StmtType::lval)
        {
            string result_var = block_exp->dumpIR();
            MyVar value = look_up_symbol_tables(lval);
            assert(value.index() == 1);
            cout << "\tstore " << result_var << ", " <<
                value.getStringValue() << endl;
        }
        else if (type == StmtType::exp)
        {
            if (block_exp != nullptr)block_exp->dumpIR();
        }
        else if (type == StmtType::block)return block_exp->dumpIR();
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
            string if_result = exp_simple->dumpIR();
            string then_label = "\%then_" + to_string(if_else_num);
            string end_label = "\%end_" + to_string(if_else_num++);
            cout << "\tbr " << if_result << ", " << then_label << ", " <<
                end_label << endl;
            cout << then_label << ":" << endl;
            string if_stmt_type = if_stmt->dumpIR();
            if (if_stmt_type != "ret" && if_stmt_type != "break" &&
                if_stmt_type != "cont")
                cout << "\tjump " << end_label << endl;
            cout << end_label << ":" << endl;
        }
        else if (type == StmtType::ifelse)
        {
            string if_result = exp_simple->dumpIR();
            string then_label = "\%then_" + to_string(if_else_num);
            string else_label = "\%else_" + to_string(if_else_num);
            string end_label = "\%end_" + to_string(if_else_num++);
            cout << "\tbr " << if_result << ", " << then_label << ", " <<
                else_label << endl;
            cout << then_label << ":" << endl;
            string if_stmt_type = if_stmt->dumpIR();
            if (if_stmt_type != "ret" && if_stmt_type != "break" &&
                if_stmt_type != "cont")
                cout << "\tjump " << end_label << endl;
            cout << else_label << ":" << endl;
            string else_stmt_type = else_stmt->dumpIR();
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
            string while_result = exp_simple->dumpIR();
            cout << "\tbr " << while_result << ", " << body_label << ", "
                << end_label << endl;
            cout << body_label << ":" << endl;
            string while_stmt_type = while_stmt->dumpIR();
            if (while_stmt_type != "ret" && while_stmt_type != "break" &&
                while_stmt_type != "cont")
                cout << "\tjump " << entry_label << endl;
            cout << end_label << ":" << endl;
            while_stack.pop_back();
        }
        else assert(false);
        return "";
    }
};




class ExpAST : public BaseAST
{
public:
    BaseAST* l_or_exp;
    void dump() const override
    {
        cout << "ExpAST { ";
        l_or_exp->dump();
        cout << " } ";
    }
    string dumpIR() const override
    {
        return l_or_exp->dumpIR();
    }
    virtual int dumpExp() const override
    {
        return l_or_exp->dumpExp();
    }
};


class LOrExpAST : public BaseAST
{
public:
    string op;
    BaseAST* l_and_exp;
    BaseAST* l_or_exp;
    void dump() const override
    {
        if (op == "")l_and_exp->dump();
        else
        {
            l_or_exp->dump();
            cout << op;
            l_and_exp->dump();
        }
    }
    string dumpIR() const override
    {
        string result_var = "";
        if (op == "")result_var = l_and_exp->dumpIR();
        else if (op == "||")
        {
            string left_result = l_or_exp->dumpIR();
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
            string right_result = l_and_exp->dumpIR();
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
        else assert(false);
        return result_var;
    }
    virtual int dumpExp() const override
    {
        int result = 1;
        if (op == "")result = l_and_exp->dumpExp();
        else if (op == "||")
        {
            int left_result = l_or_exp->dumpExp();
            if (left_result)return 1;
            result = l_and_exp->dumpExp() != 0;
        }
        else assert(false);
        return result;
    }
};


class LAndExpAST : public BaseAST
{
public:
    string op;
    BaseAST* eq_exp;
    BaseAST* l_and_exp;
    void dump() const override
    {
        if (op == "")eq_exp->dump();
        else
        {
            l_and_exp->dump();
            cout << op;
            eq_exp->dump();
        }
    }
    string dumpIR() const override
    {
        string result_var = "";
        if (op == "")result_var = eq_exp->dumpIR();
        else if (op == "&&")
        {
            string left_result = l_and_exp->dumpIR();
            string then_label = "\%then_" + to_string(if_else_num);
            string else_label = "\%else_" + to_string(if_else_num);
            string end_label = "\%end_" + to_string(if_else_num++);
            string result_var_ptr = "%" + to_string(symbol_num++);
            cout << '\t' << result_var_ptr << " = alloc i32" << endl;
            cout << "\tbr " << left_result << ", " << then_label << ", "
                << else_label << endl;
            cout << then_label << ":" << endl;
            string tmp_result_var = "%" + to_string(symbol_num++);
            string right_result = eq_exp->dumpIR();
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
        else assert(false);
        return result_var;
    }
    virtual int dumpExp() const override
    {
        int result = 0;
        if (op == "")result = eq_exp->dumpExp();
        else if (op == "&&")
        {
            int left_result = l_and_exp->dumpExp();
            if (left_result == 0)return 0;
            result = eq_exp->dumpExp() != 0;
        }
        else assert(false);
        return result;
    }
};


class EqExpAST : public BaseAST
{
public:
    string op;
    BaseAST* rel_exp;
    BaseAST* eq_exp;
    void dump() const override
    {
        if (op == "")rel_exp->dump();
        else
        {
            eq_exp->dump();
            cout << op;
            rel_exp->dump();
        }
    }
    string dumpIR() const override
    {
        string result_var = "";
        if (op == "")result_var = rel_exp->dumpIR();
        else
        {
            string left_result = eq_exp->dumpIR();
            string right_result = rel_exp->dumpIR();
            result_var = "%" + to_string(symbol_num++);
            if (op == "==")
                cout << '\t' << result_var << " = eq " << left_result <<
                    ", " << right_result << endl;
            else if (op == "!=")
                cout << '\t' << result_var << " = ne " << left_result <<
                    ", " << right_result << endl;
            else assert(false);
        }
        return result_var;
    }
    virtual int dumpExp() const override
    {
        int result = 0;
        if (op == "")result = rel_exp->dumpExp();
        else
        {
            int left_result = eq_exp->dumpExp();
            int right_result = rel_exp->dumpExp();
            if (op == "==")result = left_result == right_result;
            else if (op == "!=")result = left_result != right_result;
            else assert(false);
        }
        return result;
    }
};


class RelExpAST : public BaseAST
{
public:
    string op;
    BaseAST* add_exp;
    BaseAST* rel_exp;
    void dump() const override
    {
        if (op == "")add_exp->dump();
        else
        {
            rel_exp->dump();
            cout << op;
            add_exp->dump();
        }
    }
    string dumpIR() const override
    {
        string result_var = "";
        if (op == "")result_var = add_exp->dumpIR();
        else
        {
            string left_result = rel_exp->dumpIR();
            string right_result = add_exp->dumpIR();
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
            else assert(false);
        }
        return result_var;
    }
    virtual int dumpExp() const override
    {
        int result = 0;
        if (op == "")result = add_exp->dumpExp();
        else
        {
            int left_result = rel_exp->dumpExp();
            int right_result = add_exp->dumpExp();
            if (op == ">")result = left_result > right_result;
            else if (op == ">=")result = left_result >= right_result;
            else if (op == "<")result = left_result < right_result;
            else if (op == "<=")result = left_result <= right_result;
            else assert(false);
        }
        return result;
    }
};


class AddExpAST : public BaseAST
{
public:
    string op;
    BaseAST* mul_exp;
    BaseAST* add_exp;
    void dump() const override
    {
        if (op == "")mul_exp->dump();
        else
        {
            add_exp->dump();
            cout << op;
            mul_exp->dump();
        }
    }
    string dumpIR() const override
    {
        string result_var = "";
        if (op == "")result_var = mul_exp->dumpIR();
        else
        {
            string left_result = add_exp->dumpIR();
            string right_result = mul_exp->dumpIR();
            result_var = "%" + to_string(symbol_num++);
            if (op == "+")
                cout << '\t' << result_var << " = add " << left_result <<
                    ", " << right_result << endl;
            else if (op == "-")
                cout << '\t' << result_var << " = sub " << left_result <<
                    ", " << right_result << endl;
            else assert(false);
        }
        return result_var;
    }
    virtual int dumpExp() const override
    {
        int result = 0;
        if (op == "")result = mul_exp->dumpExp();
        else
        {
            int left_result = add_exp->dumpExp();
            int right_result = mul_exp->dumpExp();
            if (op == "+")result = left_result + right_result;
            else if (op == "-")result = left_result - right_result;
            else assert(false);
        }
        return result;
    }
};


class MulExpAST : public BaseAST
{
public:
    string op;
    BaseAST* unary_exp;
    BaseAST* mul_exp;
    void dump() const override
    {
        if (op == "")unary_exp->dump();
        else
        {
            mul_exp->dump();
            cout << op;
            unary_exp->dump();
        }
    }
    string dumpIR() const override
    {
        string result_var = "";
        if (op == "")result_var = unary_exp->dumpIR();
        else
        {
            string left_result = mul_exp->dumpIR();
            string right_result = unary_exp->dumpIR();
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
            else assert(false);
        }
        return result_var;
    }
    virtual int dumpExp() const override
    {
        int result = 0;
        if (op == "")result = unary_exp->dumpExp();
        else
        {
            int left_result = mul_exp->dumpExp();
            int right_result = unary_exp->dumpExp();
            if (op == "*")result = left_result * right_result;
            else if (op == "/")result = left_result / right_result;
            else if (op == "%")result = left_result % right_result;
            else assert(false);
        }
        return result;
    }
};


class UnaryExpAST : public BaseAST
{
public:
    UnaryExpType type;
    string op;
    BaseAST* exp;
    string ident;
    vector<BaseAST*> params;
    void dump() const override
    {
        if (type == UnaryExpType::func_call)
        {
            cout << ident << "(";
            for (int i = 0; i < params.size(); i++)
            {
                params[i]->dump();
                if (i != params.size() - 1)cout << ", ";
            }
            return;
        }
        if (type == UnaryExpType::unary)cout << op;
        exp->dump();
    }
    string dumpIR() const override
    {
        if (type == UnaryExpType::primary)return exp->dumpIR();
        else if (type == UnaryExpType::unary)
        {
            string result_var = exp->dumpIR();
            string next_var = "%" + to_string(symbol_num);
            if (op == "+")return result_var;
            else if (op == "-")cout << '\t' << next_var << " = sub 0, " <<
                result_var << endl;
            else if (op == "!")cout << '\t' << next_var << " = eq " <<
                result_var << ", 0" << endl;
            else assert(false);
            symbol_num++;
            return next_var;
        }
        else if (type == UnaryExpType::func_call)
        {
            vector<string> param_vars;
            for (auto&& param : params)
                param_vars.push_back(param->dumpIR());
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
        else assert(false);
        return "";
    }
    virtual int dumpExp() const override
    {
        int result = 0;
        if (type == UnaryExpType::primary)result = exp->dumpExp();
        else if (type == UnaryExpType::unary)
        {
            int tmp = exp->dumpExp();
            if (op == "+")result = tmp;
            else if (op == "-")result = -tmp;
            else if (op == "!")result = !tmp;
            else assert(false);
        }
        else assert(false);
        return result;
    }
};


class PrimaryExpAST : public BaseAST
{
public:
    PrimaryExpType type;
    BaseAST* exp;
    string lval;
    int number;
    void dump() const override
    {
        if (type == PrimaryExpType::exp)exp->dump();
        else if (type == PrimaryExpType::number)cout << number;
        else if (type == PrimaryExpType::lval)cout << lval;
        else assert(false);
    }
    string dumpIR() const override
    {
        string result_var = "";
        if (type == PrimaryExpType::exp)result_var = exp->dumpIR();
        else if (type == PrimaryExpType::number)
            result_var = to_string(number);
        else if (type == PrimaryExpType::lval)
        {
            MyVar value = look_up_symbol_tables(lval);
            if (value.index() == 0)
                result_var = to_string(value.getIntValue());
            else
            {
                result_var = "%" + to_string(symbol_num++);
                cout << '\t' << result_var << " = load " <<
                    value.getStringValue() << endl;
            }
        }
        else assert(false);
        return result_var;
    }
    virtual int dumpExp() const override
    {
        int result = 0;
        if (type == PrimaryExpType::exp)result = exp->dumpExp();
        else if (type == PrimaryExpType::number)result = number;
        else if (type == PrimaryExpType::lval)
        {
            MyVar value = look_up_symbol_tables(lval);
            assert(value.index() == 0);
            result = value.getIntValue();
        }
        else assert(false);
        return result;
    }
};


class DeclAST : public BaseAST
{
public:
    DeclType type;
    BaseAST* decl;
    void dump() const override { decl->dump(); }
    string dumpIR() const override { return decl->dumpIR(); }
    int dumpExp() const override { return decl->dumpExp(); }
};


class ConstDeclAST : public BaseAST
{
public:
    string b_type;
    vector<BaseAST*> const_def_list;
    void dump() const override
    {
        assert(b_type == "int");
        for (auto&& const_def : const_def_list)const_def->dump();
    }
    string dumpIR() const override
    {
        assert(b_type == "int");
        for (auto&& const_def : const_def_list)const_def->dumpIR();
        return "";
    }
    int dumpExp() const override { dumpIR(); return 0; }
};


class ConstDefAST : public BaseAST
{
public:
    string ident;
    BaseAST* const_init_val;
    void dump() const override
    {
        cout << "ConstDefAST{" << ident << "=";
        const_init_val->dump();
        cout << "} ";
    }
    string dumpIR() const override
    {
        symbol_tables.back()[ident] = StrToInt(const_init_val->dumpIR());
        return "";
    }
};


class ConstInitValAST : public BaseAST
{
public:
    BaseAST* const_exp;
    void dump() const override { cout << const_exp->dumpExp(); }
    string dumpIR() const override
    {
        return to_string(const_exp->dumpExp());
    }
};


class BlockItemAST : public BaseAST
{
public:
    BlockItemType type;
    BaseAST* content;
    void dump() const override { content->dump(); }
    string dumpIR() const override { return content->dumpIR(); }
};


class ConstExpAST : public BaseAST
{
public:
    BaseAST* exp;
    void dump() const override { cout << exp->dumpExp(); }
    string dumpIR() const override
    {
        return to_string(exp->dumpExp());
    }
    virtual int dumpExp() const override { return exp->dumpExp(); }
};


class VarDeclAST : public BaseAST
{
public:
    string b_type;
    vector<BaseAST*> var_def_list;
    void dump() const override
    {
        assert(b_type == "int");
        for (auto&& var_def : var_def_list)var_def->dump();
    }
    string dumpIR() const override
    {
        assert(b_type == "int");
        for (auto&& var_def : var_def_list)var_def->dumpIR();
        return "";
    }
    int dumpExp() const override
    {
        assert(b_type == "int");
        for (auto&& var_def : var_def_list)var_def->dumpExp();
        return 0;
    }
};


class VarDefAST : public BaseAST
{
public:
    string ident;
    bool has_init_val;
    BaseAST* init_val;
    void dump() const override
    {
        cout << "VarDefAST{" << ident;
        if (has_init_val)
        {
            cout << "=";
            init_val->dump();
        }
        cout << "} ";
    }
    string dumpIR() const override
    {
        string var_name = "@" + ident;
        string name = var_name + "_" +
            to_string(var_num[var_name]++);
        cout << '\t' << name << " = alloc i32" << endl;
        symbol_tables.back()[ident] = name;
        if (has_init_val)
        {
            string val_var = init_val->dumpIR();
            cout << "\tstore " << val_var << ", " << name << endl;
        }
        return "";
    }
    int dumpExp() const override
    {
        string var_name = "@" + ident;
        string name = var_name + "_" +
            to_string(var_num[var_name]++);
        symbol_tables.back()[ident] = name;
        if (has_init_val)
        {
            string val_var = init_val->dumpIR();
            cout << "global " << name << " = alloc i32, ";
            if (val_var[0] == '@' || val_var[0] == '%')assert(false);
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
    void dump() const override { exp->dump(); }
    string dumpIR() const override { return exp->dumpIR(); }
};