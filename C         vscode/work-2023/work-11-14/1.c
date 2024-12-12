#include<stdio.h>

void exchange(int cnt[],int n);

int main()
{
    int cnt[]={12,14,11,1,58,24,69,72,33,2,41,22,};
    int n = sizeof(cnt)/sizeof(cnt[0]);
    exchange(cnt,n);
    for(int i = 0;i <= n - 1;i++)
    {
        printf("%d ",cnt[i]);
    }
    return 0;
}

void exchange(int cnt[],int n){
    int i = 1;
    while(i != 0){
        i = 0;
        for(int j = 0;j < n - 1;j++){
            if(cnt[j] > cnt[j + 1]){
                int a = cnt[j];
                cnt[j] = cnt[j + 1];
                cnt[j + 1] = a;
                i = 1;  
            }
        }
    }
}