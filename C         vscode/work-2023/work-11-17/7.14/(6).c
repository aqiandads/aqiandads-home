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
            switch(a[i]){
                case'+':
                printf("Very good!\n");
                break;
                case'-':
                printf("Excellent!\n");
                break;
                case'*':
                printf("Nice work!\n");
                break;
                case'/':
                printf("Keep up the good work!\n");
                break;
            }
            j++;
        }else{
            switch(a[i]){
                case'+':
                printf("No.Please try again.\n");
                break;
                case'-':
                printf("Wrong.Try once more.\n");
                break;
                case'*':
                printf("Don't give up!\n");
                break;
                case'/':
                printf("Not correct.Keep trying.\n");
                break;
            }
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