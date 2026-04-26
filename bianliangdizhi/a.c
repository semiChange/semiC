// 变量地址
#include <stdio.h>

int main() {

    int a;
    // &a表示变量a的地址，scanf函数需要传入变量的地址来存储输入的值
    printf("a的地址0x%x\n", &a);
    // 地址甚至可以赋值给一个整型变量
    int address = (int)&a;
    printf("a的地址0x%x\n", address);
    // 相当于取得变量a的地址，并将输入的值存储在该地址中
    scanf("%d", &a);

    // 指针变量, 可以保存地址
    // 注意: 虽然 int* p 也是可以的,但是不推荐 
    int *p = &a;  // 指针p指向变量a的地址
    // %p格式会自动添加0x 
    printf("a的地址是：%p\n", (void*)&a);
    printf("p的值是：%p\n", (void*)p);
    printf("p指向的值是：%d\n", *p);
    return 0;
}

// void * 是一种特殊的指针类型，称为“无类型指针”或“通用指针”。
// 它可以指向任何类型的数据，但不能直接解引用。
// 要使用 void* 指针，需要先将其转换为正确的类型。