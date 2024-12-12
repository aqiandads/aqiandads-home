#include<stdio.h>

int main(){
    int t = 2,pig[12] = {1,2};
    while(t <= 11){
        pig[t] = pig[t - 1] + pig[t - 2];
        t++;
    }
    for(int i = 0;i < 12;i++){
        printf("%d ",pig[i]);
    }
    printf("\n");
    printf("一年以后有%d对兔子",pig[11]);
}