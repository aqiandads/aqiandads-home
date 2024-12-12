#include<stdio.h>
#include<stdlib.h>

int inspect(int reply,int m,int n,int t);

int main(){
    int i = 1;
    while(i != 0){
        int m = rand(),n = rand(),reply,t = 1;
        m = m % 10;
        n = n % 10;
        m = m + 1;
        n = n + 1;
        printf("%d*%d = ? ",m,n);
        scanf("%d",&reply);
        i = inspect(reply,m,n,t);
    }
}

int inspect(int reply,int m,int n,int t){
    int i = 1;
    if(t <= 2){
    if(reply == m * n){
        printf("Right!\n");
        i = 1;
    }else{
        printf("Wrong!Please try again.\n");
        t++;
        scanf("%d",&reply);
        i = inspect(reply,m,n,t);
    }
    }else{
        if(reply == m * n){
            printf("Right!\n");
        }else{
            printf("Wrong! You have tried three times! Test over!");
            i = 0;
        }
    }
    return i;
}