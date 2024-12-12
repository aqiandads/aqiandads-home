#include<stdio.h>

void choose(int cnt[],int n);

int main()
{
    int cnt[]={12,14,1,58,24,69,72,33,11,2,41,22,44};
    int n = sizeof(cnt)/sizeof(cnt[0]);
    choose(cnt,n);
    for(int i = 0;i <= n - 1;i++)
    {
        printf("%d ",cnt[i]);
    }
    return 0;
}


void choose(int cnt[],int n){
    for(int i = 0;i < n;i++){
        int min = i;
        for(int j = i;j <= n - 1;j++){
            if(cnt[min] > cnt[j]){
                min = j;
            }
        }
        int temp = cnt[min];
        cnt[min] = cnt[i];
        cnt[i] = temp;
    }
}