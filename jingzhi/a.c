// 16进制
#include <stdio.h>

int main() {
    int num = 31;
    printf("十进制: %d\n", num);
    // 要想添加0x前缀，使用#标志
    printf("十六进制: %X   %#x\n", num,num);
    return 0;
}