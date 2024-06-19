# Windows下代码使用指南

- 在setup中找到安装包，安装flex和bison。

- 配置环境变量。

- 新建build文件夹

- 运行如下指令：

  ```
  flex -l sysy.l
  bison -d sysy.y
  g++ main.cpp lex.yy.c sysy.tab.c -o sys2koopa.exe -std=c++11
  sys2koopa input.sy output.koopa
  ```


### 生成目标代码

如果需要生成目标代码，可以运行setup中提供的koopa2riscv，比如要讲output.koopa转化为output.riscv，需要在unix环境下执行

```
./koopa2riscv output.koopa output.riscv
```

unix环境可以在在ubuntu操作系统中运行，也可以在有WSL的windows下运行。

