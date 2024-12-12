#include<stdio.h>

void MonthDay(int year,int yearDay,int *pMonth,int *pDay);

int main(){
    int year,yearDay,Month,Day;
    printf("年，天\n");
    scanf("%d,%d",&year,&yearDay);
    MonthDay(year,yearDay,&Month,&Day);
    printf("这一年的第%d月第%d日",Month,Day);
}

void MonthDay(int year,int yearDay,int *Month,int *Day){
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
    *Month = 0;
    *Day = yearDay;
    int monthday[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}};
    for(int i = 0;i < 12;i++){
        if(*Day <= monthday[t][i]){
            *Month = i + 1;
            break;
        }
        *Day -= monthday[t][i];
    } 
}