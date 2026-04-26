#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成随机数
int main()
{

    // time函数 返回自1970年1月1日以来的秒数，（比如 1711700000）可以用来设置随机数种子
    // srand函数 用来设置随机数种子

    srand(time(NULL)); // 设置随机数种子

    int n = 10;
    while (n--)
    {
        int random_number = rand(); // rand函数 生成伪随机数
        // 如果要获取 100以内的数, 可以使用取模运算符 %
        // int random_number = rand() % 100;  // 生成0到99
        printf("随机数是: %d 取模后%d\n", random_number, random_number % 100);
    }
    return 0;
}