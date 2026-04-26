// malloc使用
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // malloc返回的是void*类型的指针，需要进行类型转换
    int *p = (int *)malloc(sizeof(int) * 5);
    printf("内存空间初始地址p：%p\n", p);
    printf("内存空间初始地址里面的值*p：%d\n", *p);
    if (p == NULL)
    {
        printf("内存分配失败\n");
        return -1;
    }
    // 往分配的内存空间中写入数据
    for (int i = 0; i < 5; i++)
    {
        // 指针当数组使用，p[i]等价于*(p + i)
        p[i] = i + 1;
        // 也可以
        //        *(p + i) = i + 1;
        // scanf("%d", &p[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    // 释放内存
    free(p);
    return 0;
}