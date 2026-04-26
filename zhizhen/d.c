// 注意事项

#include <stdio.h>
int main() {
    
    int n = 10;
    int *p = NULL;     // 没有指向任何有效地址的指针  例如 int *p = NULL或者 int *p = 0; 都是合法的，但更推荐使用NULL来表示空指针。 
    // 将指针初始化为NULL，表示它不指向任何有效地址

    *p = 100;   // *p指向未知地址的变量,会报错
    printf("*p = %d\n", *p);
    return 0;
}

// 附: 当参数是数组时  arr[] 和 arr* 是等价的
// void func(int arr[]) 和 void func(int *arr) 是等价的
// 赋值时也可以直接用数组名  int *p = arr

// 数组变量是一个特殊的指针, 
// int * const arr; 不能改变arr的值

// const int *p; 不能通过p修改指向的值, 如: *p=20, 但可以改变p指向其他地址


/* const说明 
int i = 10;

当const在*前面时, 表示指针指向的内容不能修改,所以下面2种一样
const int *p = &i;
int const *p = &i;

当const在*后面, 表示指针本身不能修改, 但指向的内容可以修改
int * const p = &i;










*/



