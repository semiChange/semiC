#include <stdio.h>

/**
 * 收款系统
 * 1. 消费多少
 * 2. 付款多少
 * 3. 找零多少
 */

int main()
{
    float cost = 0, payment = 0, change = 0;
    printf("请输入消费金额:");
    // 输入浮点型用 %f
    scanf("%f", &cost);
    printf("%.2f元\n", cost);
    printf("请输入收款金额:");
    scanf("%f", &payment);
    printf("%.2f元\n", payment);
    change = payment - cost;
    printf("找零金额:%.2f元\n", change);
    return 0; 
}