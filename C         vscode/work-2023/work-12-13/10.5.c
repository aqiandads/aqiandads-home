#include<stdio.h>
#include<string.h>

void huan1(char a[],char b);
void huan2(char *p,char c);

int main(){
    char a[20],b;
    int choice;
    printf("�������ַ���\n");
    gets(a);
    printf("������ɾ���ַ�\n");
    b = getchar();
    printf("����һ�ַ�����1/2\n");
    scanf("%d",&choice);
    if(choice == 1){
        huan1(a,b);
    }
    if(choice == 2){
        huan2(a,b);
    }
    printf("%s",a);
}


void huan1(char a[],char b){
    int i,j;
    for(i = j = 0;a[i] != '\0';i++){
        if (a[i] != b){
            a[j] = a[i];
            j++;
        }
    }
    a[j] = '\0';
}

void huan2(char *p,char c){
    char a[20];
    char *m = a;
    strcpy(m,p);
    while(*m != '\0'){
        if(*m != c){
            *p = *m;
            p++;
        }
        m++;
    }
    *p = '\0';
}