// 指针的应用场景1
// 同时改变多个外部变量的值
#include <stdio.h>

void f(int *a, int *b);

int main(void)
{
    int x = 10;
    int y = 20;
    f(&x, &y);
    printf("x: %d, y: %d\n", x, y);
    return 0;
}

// 同时改变2个值 
void f(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}