#include<stdio.h>

int main()
{
    int hour,minute,t;
    scanf("%d%*c%d",&hour,&minute);
    t = hour / 12;
    if(t==1){
        if(hour%12==0&&minute==0){
            printf("12:0 PM");
        }else{
            printf("%d:%d PM",hour%12,minute);
        }
    }else{
        printf("%d:%d AM",hour,minute);
    }
}