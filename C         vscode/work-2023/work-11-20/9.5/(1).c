#include<stdio.h>

int DayofYear(int year,int month,int day);

int main(){
    int year,month,day;
    printf("年，月，日\n");
    scanf("%d,%d,%d",&year,&month,&day);
    int sum;
    sum = DayofYear(year,month,day);
    printf("这一年的第%d天\n",sum);
}

int DayofYear(int year,int month,int day){
    int monthday[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}};
    int t = 0;
    if(year % 100 == 0){
        if(year % 400 == 0){
            t = 1;
        }
    }else{
        if(year % 4 == 0){
            t = 1;
        }
    }
    int sum = 0;
    for(int i = 0;i < month - 1;i++){
        sum += monthday[t][i];
    }
    sum += day;
    return sum;
}