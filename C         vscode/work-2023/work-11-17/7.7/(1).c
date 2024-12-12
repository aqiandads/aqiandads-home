#include<stdio.h>

int Gcd(int m,int n);

int main(){
    int m,n,t;
    scanf("%d %d",&m,&n);
    t = Gcd(m,n);
    printf("%d",t);
}

int Gcd(int m,int n){
    int t;
    for(t = m;t >= 1;t--){
        if(m % t == 0){
            if(n % t == 0){
                break;
            }
        }
    }
    return t;
}