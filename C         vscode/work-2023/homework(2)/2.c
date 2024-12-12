#include<stdio.h>

int main()
{
    int a,b;
    scanf("%d",&a);
    if(a>=0&&a<=153){
    b = a % 16;
    a = a / 16;
    printf("%d",10*a + b);}
    else{
        printf("Input Error");
    }
}