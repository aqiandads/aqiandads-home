#include<stdio.h>

int Gcd(int m,int n);

int main(){
    int m,n,t;
    scanf("%d %d",&m,&n);
    t = Gcd(m,n);
    printf("%d",t);
}

int Gcd(int m,int n){
    int r;
    if(m < n){
        int t = m;
        m = n;
        n = t;
    }
    r = n;
    n = m;
    do{
        m = n;
        n = r;
        r = m % n;
    }while(r != 0);
    return n;
}