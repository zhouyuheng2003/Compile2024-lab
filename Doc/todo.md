一个任务：完成编译原理大作业

三个资料：北大文档（思路），知乎解释（实现），yjl的markdown（展示）

三个工作：功能检验，代码混淆，检验代码，拆分出中间代码到目标代码



核心问题：

需要实现的功能有哪些？我们用什么样的方法来实现这些功能？

有哪些可以代码改进的方向？有哪些可以混淆的方法？



1.删除个性化的内容

2.增加一些个性化内容

3.增加一个半成品

4.格式化乱改





### 改进方向

CompUnit（疑问，如果函数，变量，函数这样的顺序定义，会不会出现未声明就使用的情况）

vardec(疑问，未声明就使用会怎么样)

**VarDefAST**全局变量如果相互赋值会怎么样

考虑使用float(注意函数funcdef那边有i32的硬编码)

疑问，fundef的dumpIR的返回值是干什么的

### 独特点

使用stoi，也就是string to int

## 问问shyshy

能不能有多个函数，有相同的函数名？

## 语法

```
CompUnit      ::= [CompUnit] (Decl | FuncDef);   
// 编译单元：可以是自身递归（即多个编译单元），也可以是声明或函数定义。
-语法树里存一个声明list和定义list
-先输出函数内置声明，更新函数表（名字，返回值，参数数量）
-再初始化符号表
-输出声明的中间表示
-输出函数定义的中间表示
Decl          ::= ConstDecl | VarDecl;  
// 声明：可以是常量声明或变量声明。

ConstDecl     ::= "const" BType ConstDef {"," ConstDef} ";";  
// 常量声明：以 "const" 开头，后跟基本类型、一个或多个常量定义，用逗号分隔，最后以分号结尾。
//遍历const_def_list，分别调用constDef即可


BType         ::= "int";  
// 基本类型：仅支持 "int" 类型。

ConstDef      ::= IDENT "=" ConstInitVal;  
// 常量定义：标识符后跟等号和常量初始值。
//做的内容是加入符号表
//常量的时候不需要中间代码，可以直接替换

ConstInitVal  ::= ConstExp;  
// 常量初始值：常量表达式。
//计算表达式的值并返回

VarDecl       ::= BType VarDef {"," VarDef} ";";  
// 变量声明：基本类型后跟一个或多个变量定义，用逗号分隔，最后以分号结尾。
//var_def_list

VarDef        ::= IDENT | IDENT "=" InitVal;  
// 变量定义：可以是标识符，或标识符后跟等号和初始值。
//用一个bool判断有没有初始化
//

InitVal       ::= Exp;  
// 初始值：表达式。
//dumpExp使用于全局变量
//实现的时候分成constinit或者普通init
//constinit是dumpExp，直接计算结果
//普通init输出表达式的koopa

FuncDef       ::= FuncType IDENT "(" [FuncFParams] ")" Block;  
// 函数定义：函数类型、标识符、参数列表（可选）和函数体。
//不能有同名的（在全局符号表里找，函数表里也找）
//function_table存函数标识符（索引是内部表示）
//function_ret_type存返回值的类型
//function_param_num存参数数量
//present_func_type存当前函数的返回值
//function_param_idents存函数参数标识符
//function_param_names存函数参数标识符内部表示
//dumpIR返回块类型


FuncType      ::= "void" | "int";  
// 函数类型：可以是 "void" 或 "int"。

FuncFParams   ::= FuncFParam {"," FuncFParam};  
// 函数参数列表：一个或多个函数参数，用逗号分隔。

FuncFParam    ::= BType IDENT;  
// 函数参数：基本类型后跟标识符。

Block         ::= "{" {BlockItem} "}";  
// 代码块：由大括号括起来的零个或多个代码块项。
//dumpIR的返回值是块类型
//func表示如果是函数直接的块，那就需要它的标识符

BlockItem     ::= Decl | Stmt;  
// 代码块项：可以是声明或语句。

Stmt          ::= LVal "=" Exp ";"  
                | [Exp] ";"  
                | Block  
                | "if" "(" Exp ")" Stmt ["else" Stmt]  
                | "while" "(" Exp ")" Stmt  
                | "break" ";"  
                | "continue" ";"  
                | "return" [Exp] ";";  
// 语句：可以是赋值语句、表达式语句、代码块、条件语句、循环语句、break 语句、continue 语句或返回语句。

Exp           ::= LOrExp;  
// 表达式：逻辑或表达式。

LVal          ::= IDENT;  
// 左值：标识符。

PrimaryExp    ::= "(" Exp ")" | LVal | Number;  
// 基本表达式：可以是括号内的表达式、左值或数字。

Number        ::= INT_CONST;  
// 数字：整数常量。

UnaryExp      ::= PrimaryExp | IDENT "(" [FuncRParams] ")" | UnaryOp UnaryExp;  
// 一元表达式：可以是基本表达式、标识符后跟参数列表（可选），或一元操作符后跟一元表达式。

UnaryOp       ::= "+" | "-" | "!";  
// 一元操作符：可以是加号、减号或逻辑非。

FuncRParams   ::= Exp {"," Exp};  
// 函数实参列表：一个或多个表达式，用逗号分隔。

MulExp        ::= UnaryExp | MulExp ("*" | "/" | "%") UnaryExp;  
// 乘法表达式：可以是一个一元表达式，或两个乘法表达式通过乘法、除法或取模运算符连接。

AddExp        ::= MulExp | AddExp ("+" | "-") MulExp;  
// 加法表达式：可以是一个乘法表达式，或两个加法表达式通过加号或减号连接。

RelExp        ::= AddExp | RelExp ("<" | ">" | "<=" | ">=") AddExp;  
// 关系表达式：可以是一个加法表达式，或两个关系表达式通过关系运算符连接。

EqExp         ::= RelExp | EqExp ("==" | "!=") RelExp;  
// 相等表达式：可以是一个关系表达式，或两个相等表达式通过相等或不等运算符连接。

LAndExp       ::= EqExp | LAndExp "&&" EqExp;  
// 逻辑与表达式：可以是一个相等表达式，或两个逻辑与表达式通过逻辑与运算符连接。

LOrExp        ::= LAndExp | LOrExp "||" LAndExp;  
// 逻辑或表达式：可以是一个逻辑与表达式，或两个逻辑或表达式通过逻辑或运算符连接。

ConstExp      ::= Exp;  
// 常量表达式：表达式。


```

## 指令

#### 中间代码生成修改方案

enum

表

库函数

assert

cout用define进行简化

从逻辑上简化中间代码输出







### windows化

```
g++ main.cpp -o compiler.exe -std=c++17
```

