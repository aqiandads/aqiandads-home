#include<stdio.h>

int DayofYear(int year,int month,int day);
void MonthDay(int year,int yearDay,int *pMonth,int *pDay);

int main(){
    int choice;
    printf("1.year/month/day -> yearDay\n");
    printf("2.yearDay -> year/month/day\n");
    printf("3.Exit\n");
    printf("Please enter your choice:");
    scanf("%d",&choice);
    int year,yearDay,Month,Day,month,day;
    switch(choice){
        case 1:
        printf("年，月，日\n");
        scanf("%d,%d,%d",&year,&month,&day);
        int sum;
        sum = DayofYear(year,month,day);
        printf("这一年的第%d天\n",sum);
        break;
        case 2:
        printf("年，天\n");
        scanf("%d,%d",&year,&yearDay);
        MonthDay(year,yearDay,&Month,&Day);
        printf("这一年的第%d月第%d日",Month,Day);
        break;
        case 3:
        break;
    }
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