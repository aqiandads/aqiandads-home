#include<stdio.h>

void insert(int cnt[],int n);

int main()
{
    int cnt[]={12,14,11,1,58,24,69,72,33,2,41,22,};
    int n = sizeof(cnt)/sizeof(cnt[0]);
    insert(cnt,n);
    for(int i = 0;i <= n - 1;i++)
    {
        printf("%d ",cnt[i]);
    }
    return 0;
}


void insert(int cnt[],int n){
    for(int i = 1;i <= n - 1;i++){
        int a = cnt[i];
        int j = i - 1;
        while(j >= 0&&cnt[j] > a){
            cnt[j + 1] = cnt[j];
            cnt[j] = a;
            j--;
        }
    }
}