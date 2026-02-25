#include <stdio.h>

int main()
{
    int a1,a2;
    float b;


    // scanf 接收键盘输入,需要传入变量地址,所以要用 &符号
    // 一定要读到 "%d %d" 这种格式,才会正确读取到 a1 和 a2 的值,否则会出现错误
    // "%d %d" 这种格式,也可以 输入第一个数字,回车,输入第二个数字,再回车,也是可以的
    scanf("%d %d", &a1, &a2);
    scanf("%f", &b);

    printf("a1=%d a2=%d\n", a1,a2);
    printf("b=%.2f\n", b);

    return 0;
}