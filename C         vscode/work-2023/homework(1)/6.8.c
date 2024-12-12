#include<stdio.h>

int main()
{
    int n = 1;
    double a = 1,b = 1,t = 1;
    while(t>=0.0001){
        b = 1/(2 * n + 1);
        b = -b;
        a += b;
        n++;
        if(b<0){
            t = -b;
        }
    }
    printf("%lf,%d",4*a,n+1);
}