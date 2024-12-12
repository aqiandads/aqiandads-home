#include<stdio.h>

int IsPrime(int m);

int main(){
    int m;
    scanf("%d",&m);
    if(IsPrime(m)){
        printf("No divisor! It is a prime number");
    }else{
        int j;
        for(int i = 2;i < m;i++){
            if(m % i == 0){
                j = i;
                break;
            }
        }
        for(int i = 2;i < m;i++){
            if(m % i == 0){
                printf("%d",i);
                if(i != m / j){
                    printf("¡¢");
                }
            }
        }
    }
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