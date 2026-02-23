#include <stdio.h>

/**
 * 收款系统
 * 1. 消费多少
 * 2. 付款多少
 * 3. 找零多少
 */

int main()
{
    int cost, payment, change;
    printf("请输入消费金额:");
    scanf("%d",&cost);
    printf("%d元\n",cost);
    printf("请输入收款金额:");
    scanf("%d",&payment);
    printf("%d元\n",payment);
    printf("找零金额:%d元\n",payment-cost);
    return 0; 
}