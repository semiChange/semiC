// 取余
#include <stdio.h>

// 根据分钟数计算小时数和剩余分钟数
int main() {
    int total_minutes = 130;  // 总分钟数
    int hours = total_minutes / 60;  // 计算小时数
    int minutes = total_minutes % 60;  // 计算剩余分钟数
    printf("总分钟数：%d\n转换时分：%d小时%d分钟\n", total_minutes, hours, minutes);
    return 0;
}


// 如果 有 712 三个数字, 如何分别获取 7,1,2
// 712/100 = 7
// 712%10 = 2
// 712/10%10 = 1

// 任意3位数 / 100 就是百位数
// 任意3位数 / 10 就是十位数
// 任意3位数 % 10 就是gz个位数