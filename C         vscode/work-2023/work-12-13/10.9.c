#include<stdio.h>
#include<string.h>

void paixu(char a[][20]);

int main(){
    char a[5][20];
    printf("请输入五个国家名\n");
    for(int i = 0;i < 5;i++){
        scanf("%s",a[i]);
    }
    paixu(a);
    printf("排序后:\n");
    for(int i = 0;i < 5;i++){
        puts(a[i]);
    }
}

void paixu(char a[][20]){
    int i,j;
    char temp[20];
    for(i = 0;i < 4;i++){
        for(j = i + 1;j < 5;j++){
            if(strcmp(a[j],a[i]) < 0){
                strcpy(temp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);
            }
        }
    }
}