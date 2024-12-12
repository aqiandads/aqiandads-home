#include<stdio.h>

unsigned long Fact(unsigned int n);

int main(){
    int n,m;
    scanf("%d",&n);
    m = Fact(n);
    printf("%d",m);
}

unsigned long Fact(unsigned int n){
    unsigned int i,j;
    unsigned long result = 1,sum = 0;
    for(i = 1;i <= n;i++){
        for(j = 1;j <= i;j++){
            result *= j;
        }
        sum += result;
        result = 1;
    }
    return sum;
}