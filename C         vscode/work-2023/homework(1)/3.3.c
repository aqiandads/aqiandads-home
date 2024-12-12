#include<stdio.h>

int main()
{
    const double rate = 0.0225;
    int n;
    double deposit,capital;
    printf("请输入存款期:\n请输入本金:\n");
    scanf("%d %lf",&n,&capital);
    deposit = capital*(1 + n * rate);
    printf("%d年之后本利之和为%f",n,deposit);
}