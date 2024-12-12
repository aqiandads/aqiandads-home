#include<stdio.h>
#include<stdlib.h>

void inspect();

int main(){
    inspect();
}

void inspect(){
    int t = 1,j = 0;
    char a[] = {'+','-','*','/'};
    while(t <= 10){
        int m = rand(),n = rand(),reply,i,answer;
        m = m % 10 * 1.0;
        n = n % 10 * 1.0;
        i = rand() % 4;
        m = m + 1;
        n = n + 1;
        printf("%d%c%d = ? ",m,a[i],n);
        switch(a[i]){
            case'+':
            answer = m + n;
            break;
            case'-':
            answer = m - n;
            break;
            case'*':
            answer = m * n;
            break;
            case'/':
            answer = m / n;
            break;
        }
        scanf("%d",&reply);
        if(reply == answer){
            printf("Right!\n");
            j++;
        }else{
            printf("Wrong!\n");
        }
        t++;
    }
    if(j >= 8){
        printf("%d分  正确率为%d%%",j,10 * j);
    }else{
        printf("pig! try again.\n");
        inspect();
    }
}