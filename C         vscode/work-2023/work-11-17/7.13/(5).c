#include<stdio.h>

void IsPerfect(int m);

int main(){
    int m;
    scanf("%d",&m);
    IsPerfect(m);
}

void IsPerfect(int m){
    int sum = 0;
    for(int i = 1;i < m;i++){
        if(m % i == 0){
            sum += i;
        }
    }
    if(sum == m){
        printf("%d����ȫ��",m);
    }else{
        printf("%d������ȫ��",m);
    }
}