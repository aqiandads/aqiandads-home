#include<stdio.h>

int IsPrime(int m);

int main(){
    int m;
    scanf("%d",&m);
    if(IsPrime(m)){
        printf("It is a prime number");
    }else{
        printf("%d=",m);
        do{
            for(int i = 2;i <= m;i++){
                if(m % i == 0){
                    printf("%d",i);
                    m = m / i;
                    break;
                }
            }
            if(m != 1){
                printf("¡Á ");
            }
        }while(m != 1);
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