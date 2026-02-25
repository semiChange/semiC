#include <stdio.h>

// 常量：在程序运行过程中值不能改变的量
// 变量：在程序运行过程中值可以改变的量
// 直接量：就是指在程序中直接使用的值，如：3.14、100、'a'等

int main()
{
    // 常量通常大写
    const float PI = 3.14;
    float r;

    printf("请输入半径:");
    scanf("%f", &r);

    printf("圆周长:%.2f\n", 2 * PI * r);
    printf("圆面积:%.2f\n", PI * r * r);

    return 0;
}