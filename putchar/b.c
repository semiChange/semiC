// getchar 返回读取的字符
#include <stdio.h>

int main() {
    char c;
    // 循环从键盘读取字符，直到输入结束 
    // ctrl+c 是结束程序, 不是输入了 EOF
    while ((c = getchar()) != EOF) { 
        // EOF表示输入结束，通常是Ctrl+D或Ctrl+Z
        putchar(c); // 输出读取的字符
    }
    return 0;
}