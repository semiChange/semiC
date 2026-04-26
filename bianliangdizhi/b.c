// 数组的地址
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("arr的地址是：%p\n", (void*)&arr);
    printf("arr的地址是：%p\n", (void*)arr);
    printf("arr[0]的地址是：%p\n", (void*)&arr[0]);
    printf("arr[1]的地址是：%p\n", (void*)&arr[1]);
    return 0;
}
