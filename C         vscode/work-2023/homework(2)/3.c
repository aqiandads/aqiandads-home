#include<stdio.h>

int main()
{
    int hour,minute,past,t;
    scanf("%d %d",&hour,&past);
    minute = hour % 100;
    hour = hour / 100;
    minute = minute + past;
    hour = hour + minute / 60;
    minute = minute % 60;
    if(minute<0){
        minute = 60 + minute;
        hour = hour - 1;
    }
    if(hour<24){
    t = 100 * hour + minute;
    printf("%d",t);}
    else{
        printf("Input Error");
    }
}