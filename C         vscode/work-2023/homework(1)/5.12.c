#include<stdio.h>

int main()
{
    double w,h,t;
    scanf("%lf %lf",&w,&h);
    t = w / (h * h);
    if(t<18){
        printf("低体重");
    }
    if(t>=18&&t<=25){
        printf("正常体重");
    }
    if(t>25&&t<27){
        printf("超重体重");
    }
    if(t>=27){
        printf("肥胖");
    }
}