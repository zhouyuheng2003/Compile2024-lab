# Compile2024-lab

## 使用方式

- 打开Docker Desktop

- 在工作目录（这个readme所在的目录）下打开cmd，并运行如下指令加载环境

  ```cmd
  docker run -it --rm -v K:\Document\Compile2024-lab:/root/compiler maxxing/compiler-dev bash
  ```

  如果正常运行，应当能看到终端出现如下显示：

  ```
  root@473cc8b4e3a5:~#
  ```

- 然后进入compiler文件夹并进行编译

  ```
  cd compiler
  make
  ```

- 最后一步就能测试自己的编译器能否正确运行了

  ```
  build/compiler -koopa hello.c -o hello.koopa
  ```

## 学习指南

- [北京大学编译实践课程在线文档](https://pku-minic.github.io/online-doc/#/lv1-main/parsing-main)

## 参考材料

- [llvm](https://llvm.org/docs/)
- [北京大学编译原理课程实践报告](https://zhuanlan.zhihu.com/p/640953686)
- [2021Spring北京大学编译实践lab报告](https://zhuanlan.zhihu.com/p/584830038)

- [衣然，胡剑峥，郭冠男Compiler_Koopa_RISCV](https://github.com/HocRiser01/Compiler_Koopa_RISCV)

- [koopa - Rust](https://docs.rs/koopa/latest/koopa/)



## Middle End

### 语法树结构

每个节点的信息包含UUID，子节点的UUID构成的vector，种类，和节点信息。所有的节点通过一个类**ObjManager**统一管理，并以UUID为唯一标识符。

### 上承Frontend

首先切换到K:\RefDocument\Compiler_Koopa_RISCV\FrontEnd的目录

运行

```
g++ YaccLex/src/YaccLex.cpp YaccLex/build/sysy.tab.cpp YaccLex/StrDump.cpp YaccLex/build/sysy.lex.cpp -DTEST_YACC_LEX -std=c++11
```

接下来在当前目录放好test.sy

之后运行

```
a
```

就可以得到语法树

### 跑通

```
g++ compiler.cpp -g -L./Lib -lkoopa -o compiler
```



### 关键文件

[编译文件](K:\RefDocument\Compiler_Koopa_RISCV\compiler.cpp)

[语法树的定义，ObjManager.h](K:\RefDocument\Compiler_Koopa_RISCV\ObjTree\ObjManager.h)

[中间层IrGenerator.h](K:\RefDocument\Compiler_Koopa_RISCV\MiddleEnd\IrGenerator.h)

### 可能的问题

arm和risc-V

note.txt提到的问题



不支持const a=3,b=2这样的类型



### 几点疑问

生成节点的顺序是什么样的（理论来说最后一个生成的应该是根）

### 操作历史

#### 语法树生成

```
K:\RefDocument\Compiler_Koopa_RISCV\FrontEnd>g++ YaccLex/src/YaccLex.cpp YaccLex/build/sysy.tab.cpp YaccLex/StrDump.cpp YaccLex/build/sysy.lex.cpp -DTEST_YACC_LEX -std=c++11

K:\RefDocument\Compiler_Koopa_RISCV\FrontEnd>a
16(CompUnitAst)[]{15(CompUnitDefAst)[]{14(FuncDefAst)[main]{1(FuncTypeAst)[int]{},13(BlockAst)[]{12(BlockItemListAst)[]{2(BlockItemListAst)[]{},11(BlockItemAst)[]{10(StmtAst)[ReturnExp]{9(ExpAst)[]{8(AddExpAst)[]{7(MulExpAst)[]{6(UnaryExpAst)[]{5(PrimaryExpAst)[]{4(NumberAst)[]{3(IntConstAst)[3]{}}}}}}}}}}}}}}
```

#### koopaIR2risc-V test

```
K:\Document\Compile2024-lab>docker run -it --rm -v K:\Document\Compile2024-lab:/root/compiler maxxing/compiler-dev bash
root@45d8e6ae1ca7:~# cd compiler
root@45d8e6ae1ca7:~/compiler# cd Henry-test
root@45d8e6ae1ca7:~/compiler# apt update
root@45d8e6ae1ca7:~/compiler# apt install g++
root@fd72f92d5a39:~/compiler/Henry-test# g++ RiscGenerator.cpp koopa.h -o a.exe -L./Lib -lkoopa -ldl -lpthread
```



