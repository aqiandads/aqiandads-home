#include<stdio.h>
#include<string.h>

void ni1(char a[],char b[]);
void ni2(char *m,char *n);

int main(){
    char a[40],b[40];
    printf("请输入字符串\n");
    gets(a);
    printf("用哪一种方法？1/2\n");
    int choice;
    scanf("%d",&choice);
    if(choice == 1){
        ni1(a,b);
    }
    if(choice == 2){
        ni2(a,b);
    }
    puts(b);
}

void ni1(char a[],char b[]){
    int len;
    len = strlen(a);
    for(int i = 0,j = len - 1;a[i] != '\0';i++,j--){
        b[j] = a[i];
    }
}

void ni2(char *m,char *n){
    char a[40];
    int i;
    for( i = 0;*m != '\0';m++,i++)
    {
        a[i] = *m;
    }
    a[i] = '\0';
    i = i - 1;
    for(;i >= 0;i--,n++){
        *n = a[i];
    }
    *n = '\0';
}