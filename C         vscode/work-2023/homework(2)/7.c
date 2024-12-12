#include<stdio.h>
#include<stdlib.h>

int main()
{
    char rely;

    do{

        int a = rand(),b,n = 1;
        a = a % 100;
        do{
        scanf("%d",&b);
        if(b == a){
            printf("恭喜你，成功完成游戏！");
        }
        if(b>a){
            printf("too big\n");
        }
        if(b<a){
            printf("too small\n");
        }
        n++;
    }while(b!=a&&n<=5);
    if(b!=a&&n == 6){
        printf("失败了，请下次再战！\n");
    }
    printf("是否开始下一轮游戏？（y/n）\n");
    scanf("%c",&rely);
    }while(rely!='n');
}
