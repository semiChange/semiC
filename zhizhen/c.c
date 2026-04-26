// 指针应用场景2
// 返回函数运行结果, 通常用-1或0表示出错或失败
#include <stdio.h>

// 既返回结果又返回出错信息 
float devide(int a, int b, int *result)
{
    if (b == 0) {
        *result = -1; // 出错
        return 0;
    }
    return (float)a / b;
}

int main(void)
{
    int error_code;
    float result = devide(10, 0, &error_code);
    if (error_code == -1) {
        printf("出错了%d\n", error_code);
    } else {
        printf("结果是: %.2f\n", result);
    }
    return 0;
}
