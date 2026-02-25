#include <stdio.h>

/**
 * 收款系统
 * 1. 消费多少
 * 2. 付款多少
 * 3. 找零多少
 */

int main()
{
    // 注意变量初始化,否则出现随机值
    float cost = 0, payment = 0, change = 0;
    printf("请输入消费金额:");
    // 输入浮点型用 %f
    // scanf 接收键盘输入,需要传入变量地址,所以要用 &符号
    scanf("%f", &cost);
    printf("%.2f元\n", cost);
    printf("请输入收款金额:");
    scanf("%f", &payment);
    printf("%.2f元\n", payment);
    change = payment - cost;
    printf("找零金额:%.2f元\n", change);
    return 0; 
}