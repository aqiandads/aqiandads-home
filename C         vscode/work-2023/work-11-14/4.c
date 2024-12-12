#include<stdio.h>


void swap(int *a,int *b);
int partition(int cnt[],int low,int high);
void recursion(int cnt[],int low, int high);

int main()
{
    int cnt[]={12,14,1,58,24,69,72,33,11,2,41,22,44};
    int n = sizeof(cnt)/sizeof(cnt[0]);
    recursion(cnt,0,n - 1);
    for(int i = 0;i <= n - 1;i++)
    {
        printf("%d ",cnt[i]);
    }
    return 0;
}


void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int cnt[],int low,int high){
    int i = low - 1;
    for(int j = low;j < high;j++){
        if(cnt[j] < cnt[high]){
            i++;
            swap(&cnt[i],&cnt[j]); 
        }
    }
    swap(&cnt[i + 1],&cnt[high]);
    return i + 1;
}


void recursion(int cnt[],int low, int high){
    if(low < high){
        int temp = partition(cnt,low,high);
        recursion(cnt,low,temp - 1);
        recursion(cnt,temp + 1,high);
    }
}