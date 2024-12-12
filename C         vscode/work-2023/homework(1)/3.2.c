#include<stdio.h>

int main()
{
    int a,b,c,t;
    scanf("%d",&a);
    if(a<0)
    {
        a = -a;
    }
    b = a % 100;
    c = a % 10;
    b = b - c;
    a = a / 100;
    t = 100 * c + b + a;
    printf("%d",t);
}