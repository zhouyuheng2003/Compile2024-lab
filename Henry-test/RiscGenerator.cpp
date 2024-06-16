//
// Created by yyi on 2023/6/12.
//
#include "koopa.h"
#include <fstream>
#include <iostream>
int main() {
    // 读入字符形式的 Koopa IR 文件

    koopa_program_t program;
    koopa_error_code_t  ret = koopa_parse_from_file("input1.sy.koopa", &program);
    if(ret==0){
        std::cout<<"koopa parse file error"<<std::endl;
    }
    return 0;
}
