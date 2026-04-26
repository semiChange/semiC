// 数组
#include <stdio.h>

int number[5];  // 声明一个包含5个整数的数组
int i = 0;
int main() {
    while (i < 5)
    {
        scanf("%d", &number[i]);  // 输入第一个元素
        i++;
    }

    for (; i > 0; i--) {
        printf("%d ", number[i - 1]);
    }
    return 0;
    // 数组初始化
    // int number[5] = {1, 2, 3, 4, 5};  // 声明并初始化一个包含5个整数的数组
    // 统计个数
    // sizeof(number) / sizeof(number[0]);
    // 查看类型的大小
    // printf("%ld", sizeof(int));


}