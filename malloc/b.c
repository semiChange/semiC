// 不停申请空间,知道返回NULL为止
#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *p;
    // 也可以 每次循环申请100M的空间,直到返回NULL为止
    // while (p = malloc(1024*1024*100) )
    while (1)
    {
        p = malloc(1024);
        if (p == NULL)
        {
            printf("内存分配失败\n");
            break;
        }
    }
    return 0;
}

// 注意: free释放内存,只能使用原始指针 
// free(p);
// 不能使用修改后的指针 p++; free(p);报错

// 注意: free只能释放 malloc申请的内存
// int i; int *p = &i; free(p); // 错误,不能释放非malloc申请的内存

// 所以初始化指针时 可以先 void *p = NULL; 以免误用未初始化的指针, free(NULL); 是安全的,不会报错