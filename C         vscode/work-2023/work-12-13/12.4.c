#include<stdio.h>
#include<string.h>

struct candidate{
    char name[20];
    int count;
}candidate[3] = {{"li",0},{"zhang",0},{"wang",0}};
int main(){
    int i,j,flag = 1,wrong = 0;
    for(i = 1;i < 11;i++){
        char name[20];
        printf("你支持的是:");
        scanf("%s",name);
        strlwr(name);
        flag = 1;
        for(j = 0;j < 3;j++){
            if(strcmp(name,candidate[j].name) == 0){
                candidate[j].count++;
                flag = 0;
            }
        }
        if(flag){
            wrong++;
            flag = 0;
        }
    }
    printf("结果是:\n");
    for(i = 0;i < 3;i++){
        printf("%s:%d票\n",candidate[i].name,candidate[i].count);
    }
    printf("%d张废票",wrong);
}