#include<stdio.h>

int IsPrime(int m);

int main(){
    int m,sum = 0;
    scanf("%d",&m);
    for(int i = 2;i <= m;i++){
        if(IsPrime(i)){
            sum += i;
        }
    }
    printf("%d",sum);
}

int IsPrime(int m){
    int i = 2,t = 0;
    if(m <= 1){
        t = 0;
    }else{
    for(i = 2;i < m;i++){
        if(m % i == 0){
            t = 0;
            break;
        }
    }
    if(i == m){
        t = 1;
    }
    }
    return t;
}