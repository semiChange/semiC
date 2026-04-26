// 字符串
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // 这是字符数组,不是字符串
    // char str[] = {'H', 'e', 'l', 'l', 'o'}; 
    // 结尾加'\0'或0表示字符串, '\0'表示整数0,但是不能 '0'
    // char str[] = {'H', 'e', 'l', 'l', 'o', '\0'}; 
    char str[] = {'H', 'e', 'l', 'l', 'o', 0}; 
    // 字符串必须以'\0'结尾,否则尾部会出现乱码输出

    // printf("%s\n", str);
    // printf("%c\n", str[1]);
    // printf("%c\n", *(str+1)); // str是数组名, 不能使用++
    char *p = str; 
    printf("%c\n", *(++p)); // p是指针, 可以使用++
    return 0;
}


// 字符串变量定义,等同 字符数组, 结尾自动加'\0'
// char str[] = "Hello"; // 字符数组, 字面量,结尾自动加'\0'
// char str[10] = "Hello"; // 字符数组, 结尾自动加'\0'
// char *str = "Hello"; // 字符指针, 指向字符串常量

// 字符串 字面量, 字符串 常量
// "Hello" 结尾自动添加0