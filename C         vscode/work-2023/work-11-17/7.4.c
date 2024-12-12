#include<stdio.h>

int AWM (int m,int n);

int main(){
    int m,n,a;
    scanf("%d %d",&m,&n);
    a = AWM(m,n);
    printf("%d",a);
}

int AWM (int m,int n){
    int i;
    for(i = m;i <= m * n;i++){
        if(i % m == 0){
            if(i % n == 0){
                break;
            }
        }
    }
    return i;
}