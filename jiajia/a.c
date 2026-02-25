// a++ 和 ++a 的区别
#include <stdio.h>

int main() {
    int a = 5;
    printf("a++: %d\n", a++); // 此时a先输出 5，后++  变为 6
    printf("a: %d\n", a); // 输出 6

    int b = 5;
    printf("++b: %d\n", ++b); // b 先变为 6，然后输出 6
    printf("b: %d\n", b); // 输出 6
    return 0;
}