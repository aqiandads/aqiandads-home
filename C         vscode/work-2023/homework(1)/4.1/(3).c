#include<stdio.h>

int main()
{
    int a,b;
    scanf("%2d%*2s%2d",&a,&b);
    printf("%d,%d\n",a,b);
    return 0;
}