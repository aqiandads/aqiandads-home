#include<stdio.h>

int main()
{
    long a,b;
    float x,y;
    scanf("%ld,%ld",&a,&b);
    scanf("%f,%f",&x,&y);
    printf("a = %ld,b = %ld\n",a,b);
    printf("x = %5.2f,y = %5.2f\n",x,y);
    return 0;
}