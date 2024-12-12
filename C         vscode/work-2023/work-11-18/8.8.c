#include<stdio.h>

void exchange(int cnt[],int n);

int main(){
    int student[40] = {0},count[10] = {0};
    for(int i = 0;i < 40;i++){
        scanf("%d",&student[i]);
    }
    for(int i = 0;i < 40;i++){
        switch(student[i]){
            case 1:count[0]++;break;
            case 2:count[1]++;break;
            case 3:count[2]++;break;
            case 4:count[3]++;break;
            case 5:count[4]++;break;
            case 6:count[5]++;break;
            case 7:count[6]++;break;
            case 8:count[7]++;break;
            case 9:count[8]++;break;
            case 10:count[9]++;break;
            default:printf("input error!\n");
        }
    }
    printf("Grade\tCount\tHistogram\n");
    for(int j = 0;j < 10;j++){
        printf("%3d\t%3d\t",j + 1,count[j]);
        for(int t = 0;t < count[j];t++){
            printf("*");
        }
        printf("\n");
    }
    


    int sum = 0;
    double pingjun;
    for(int i = 0;i < 40;i++){
        sum += student[i];
    }
    sum = sum * 1.0;
    pingjun = sum / 40;
    printf("平均值为%.0f\n",pingjun);


    exchange(student,40);
    sum = student[19] + student[20];
    sum = sum * 1.0;
    double zhongwei = sum / 2.0;
    printf("中位数为%.0f\n",zhongwei);


    int max = 0,t = 0;
    for(int i = 0;i < 10;i++){
        if(max < count[i]){
            max = count[i];
            t = i;
        }
    }
    printf("众数为%d\n",t + 1);
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