#include<stdio.h>
#include<math.h>

void IsPrime(int m);

int main(){
    int m;
    scanf("%d",&m);
    IsPrime(m);
}

void IsPrime(int m){
    int i = 2;
    int t = sqrt(m);
    if(m <= 1){
        printf("%d is not a prime number",m);
    }else{
    for(i = 2;i < t;i++){
        if(m % i == 0){
            printf("%d is not a prime number",m);
            break;
        }
    }
    if(i >= t){
        printf("%d is a prime number",m);
    }
    }
}