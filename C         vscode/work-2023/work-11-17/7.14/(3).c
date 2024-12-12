#include<stdio.h>
#include<stdlib.h>

int main(){
    int t = 1,j = 0;
    while(t <= 10){
        int m = rand(),n = rand(),reply;
        m = m % 10;
        n = n % 10;
        m = m + 1;
        n = n + 1;
        printf("%d*%d = ? ",m,n);
        scanf("%d",&reply);
        if(reply == m * n){
            printf("Right!\n");
            j++;
        }else{
            printf("Wrong!\n");
        }
        t++;
    }
    printf("%d分  正确率为%d%%",j,10 * j);
}