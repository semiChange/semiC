// 计算平均数
#include <stdio.h>

int main() {
    int n,m;
    printf("请输入2个数字: ");
    scanf("%d %d", &n, &m);

    // 因为是浮点数,所以要除以2.0而不是2,否则会得到整数结果
    double average = (n + m) / 2.0;
    printf("平均数是: %.2lf\n", average);

    return 0;
}

// 如果是多个数
// printf("平均数: %f\n", (sum)*1.0 / n);