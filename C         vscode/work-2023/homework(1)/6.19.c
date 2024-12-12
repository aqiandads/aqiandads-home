#include<stdio.h>

int main()
{
    int n = 1;
    double a = 0.01,sum = 0,b = 100000.0;
    while(n<=30){
        sum += a;
        a = 2*a;
        n++;
    }
    b = 30*b;
    printf("%lf\n%lf",b,a);
}