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


## 学习记录

- 5.23: 加入了块注释，补充了readme

## 学习指南

- [北京大学编译实践课程在线文档](https://pku-minic.github.io/online-doc/#/lv1-main/parsing-main)

## 参考材料

- [llvm](https://llvm.org/docs/)
