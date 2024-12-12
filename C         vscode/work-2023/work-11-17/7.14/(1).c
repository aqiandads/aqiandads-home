#include<stdio.h>
#include<stdlib.h>

void inspect(int reply,int m,int n);

int main(){
    while(2 > 1){
        int m = rand(),n = rand(),reply;
        m = m % 10;
        n = n % 10;
        m = m + 1;
        n = n + 1;
        printf("%d*%d = ? ",m,n);
        scanf("%d",&reply);
        inspect(reply,m,n);
    }
}

void inspect(int reply,int m,int n){
    if(reply == m * n){
        printf("Right!\n");
    }else{
        printf("Wrong!Please try again.\n");
        scanf("%d",&reply);
        inspect(reply,m,n);
    }
}