#include<stdio.h>

void exchange(int cnt[],int n);
void insert(int cnt[],int n);
void choose(int cnt[],int n);

void swap(int *a,int *b);
int partition(int cnt[],int low,int high);
void recursion(int cnt[],int low, int high);




int main(){
    int m = 4,n = 5,t = 0;
    int A[4]={1,4,7,3},B[6] = {7,5,3,6,4,2},cnt[100];
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(A[i - 1] == B[j - 1]){
                cnt[t] = A[i - 1];
                t++;
            }
        }
    }
    exchange(cnt,t);
    for(int i = 0;i <= t - 1;i++){
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