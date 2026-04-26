// 阶乘
#include <stdio.h>

int factorial(int n) {
    // 任意数的阶乘0的阶乘是1
    if (n == 0) {
        return 1;
    }
    // 4的阶乘是4*3*2*1
    // n的阶乘是n*(n-1)的阶乘,n是变量作为参数
    return n * factorial(n - 1);
}

int main() {
    int num;
    printf("请输入一个整数: ");
    scanf("%d", &num);
    printf("%d 的阶乘是: %d\n", num, factorial(num));
    return 0;
}