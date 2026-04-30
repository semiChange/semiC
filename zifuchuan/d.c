// main函数

#include <stdio.h>

int main(int argc, char *argv[]) {
    // int argc 表示命令行参数的个数, 包括程序本身的名字

    // char *argv[] 表示一个字符串数组,每个都是字符串常量


   printf("命令行参数的个数: %d\n", argc);
   for (int i = 0; i < argc; i++) {
       printf("参数 %d: %s\n", i, argv[i]);
   }

    return 0;
}


/* 如何测试传递参数
./d.exe hhh 222
命令行参数的个数: 3
参数 0: D:\code_c\zifuchuan\d.exe
参数 1: hhh
参数 2: 222
*/  