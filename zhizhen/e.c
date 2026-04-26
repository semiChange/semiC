// 指针循环数组
#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5,-1};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("arr[i]=%d \n", arr[i]);
    }

    int *p = arr; // 指针指向数组的第一个元素
    // (第一个地址;取值不为-1;地址递增)
    for (p = arr; *p != -1; p++)
    {
        printf("*p= %d\n", *p);
    }
    
    // 也可以用 while 循环
    p = arr;
    while (*p != -1)
    {
        printf("*p= %d\n", *p);
        p++;
    }
    
    return 0;
}

// 内存中虽然有0地址,但指针不应该设为0值
// NULL表示0地址
// 程序启动时,32位系统会分配最大4G的内存空间,起始地址0x00000000,结束地址0xffffffff
// 0地址是系统保留的,不能访问,所以指针不应该设为0值,否则会导致程序崩溃

// void* 表示不确定指向类型的指针