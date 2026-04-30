// 字符串连接



#include <stdio.h>
#include <string.h>

int main() {
    // 第3部分: int i=0 和char *s = "hello"(存放在只读区[比较近的内存地址],方便快速读取)
    char *s1 = "hello"; // 所以其实是  const char *s1
    char *s2 = "hello"; // 是一个指针(栈空间), 指向(堆空间)
    printf("%p\n", s1); // 输出字符串字面量的地址
    printf("%p\n", s2); // 输出字符串字面量的地址，s1和s2可能指向同一地址，因为编译器可能会合并相同的字符串字面量
    // 总结:  指针字符串常用于定义只读字符串
    return 0;



    // 第2部分:
    // 注意: 字符串字面量 和 字符数组的区别
    // char *str = "hello"; // 字符串字面量, 存储在只读内存中, 不能修改内容
    // str[0] = 'H'; // 错误，修改字符串字面

    char str[] = "hello"; // 字符数组, 可以修改内容, 它直接存放在栈上,内存地址比较大的位置
    str[0] = 'H'; // 正确，修改字符数组的内容

    printf("%s\n", str); // 输出 hello
    return 0;

    // 第1部分:
    // 字符串可以连续写
    printf("abc" "def\n"); // 输出 abcdef
    printf("abc" 
        "def\n"); // 输出 abcdef
    // 结尾的反斜杠表示续行
    printf("abc\
def\n"); // 输出 abcdef
    return 0;
}


// c语言字符串赋值,只是指针的赋值
// char *s1 = "hello";
// char *s2;
// s2 = s1; // 只是指针的赋值, s2和s1指向同一地址
