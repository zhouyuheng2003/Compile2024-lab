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



```
CompUnit      ::= [CompUnit] (Decl | FuncDef);   
// 编译单元：可以是自身递归（即多个编译单元），也可以是声明或函数定义。

Decl          ::= ConstDecl | VarDecl;  
// 声明：可以是常量声明或变量声明。

ConstDecl     ::= "const" BType ConstDef {"," ConstDef} ";";  
// 常量声明：以 "const" 开头，后跟基本类型、一个或多个常量定义，用逗号分隔，最后以分号结尾。

BType         ::= "int";  
// 基本类型：仅支持 "int" 类型。

ConstDef      ::= IDENT "=" ConstInitVal;  
// 常量定义：标识符后跟等号和常量初始值。

ConstInitVal  ::= ConstExp;  
// 常量初始值：常量表达式。

VarDecl       ::= BType VarDef {"," VarDef} ";";  
// 变量声明：基本类型后跟一个或多个变量定义，用逗号分隔，最后以分号结尾。

VarDef        ::= IDENT | IDENT "=" InitVal;  
// 变量定义：可以是标识符，或标识符后跟等号和初始值。

InitVal       ::= Exp;  
// 初始值：表达式。

FuncDef       ::= FuncType IDENT "(" [FuncFParams] ")" Block;  
// 函数定义：函数类型、标识符、参数列表（可选）和函数体。

FuncType      ::= "void" | "int";  
// 函数类型：可以是 "void" 或 "int"。

FuncFParams   ::= FuncFParam {"," FuncFParam};  
// 函数参数列表：一个或多个函数参数，用逗号分隔。

FuncFParam    ::= BType IDENT;  
// 函数参数：基本类型后跟标识符。

Block         ::= "{" {BlockItem} "}";  
// 代码块：由大括号括起来的零个或多个代码块项。

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

