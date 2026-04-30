// string.h 常用函数

// strlen 计算字符串长度, 不包含结尾 \0
// strcmp 比较两个字符串
// strcpy 复制字符串
// strcat 连接字符串
// strchr 查找字符
// strstr 查找子字符串
#include <string.h>

#include <stdio.h>

int main()
{
    printf("长度:%d",strlen("hello"));  // sizeof结果是6
    printf("比较:%d",strcmp("hello","world"));
    
    char dest[] = {0}; // 等同于 char dest[] = ""或{\0}; 
    // 不写长度, 编译器自动计算长度为1, dest[0] = '\0'
    // char* dest = (char *)malloc(20);
    strcpy(dest,"hello");
    printf("复制:%s",dest);
   
    strcat(dest," world");
    printf("连接:%s",dest);
    
    printf("查找:%s",strchr("hello world",'o'));
    printf("查找:%s",strstr("hello world","world"));

    // free(dest);
    return 0;
}