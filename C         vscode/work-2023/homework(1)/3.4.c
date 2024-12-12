#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c;
    double t,x1,x2;
    scanf("%d %d %d",&a,&b,&c);
    t = sqrt(b * b - 4 * a * c);
    x1 = (-b + t) / (2*a);
    x2 = (-b - t) / (2*a);
    printf("%f %f",x1,x2);
}