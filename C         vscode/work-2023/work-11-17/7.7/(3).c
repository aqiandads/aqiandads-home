#include<stdio.h>

int Gcd(int m,int n);

int main(){
    int m,n,t;
    scanf("%d %d",&m,&n);
    t = Gcd(m,n);
    printf("%d",t);
}

int Gcd(int m,int n){
    int t = m;
    if(m != n){
        if(m > n){
            t = Gcd(m - n,n);
        }else{
            t = Gcd(n - m,m);
        }
    }
    return t;
}