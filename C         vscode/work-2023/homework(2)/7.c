#include<stdio.h>
#include<stdlib.h>

int main()
{
    char rely;

    do{

        int a = rand(),b,n = 1;
        a = a % 100;
        do{
        scanf("%d",&b);
        if(b == a){
            printf("��ϲ�㣬�ɹ������Ϸ��");
        }
        if(b>a){
            printf("too big\n");
        }
        if(b<a){
            printf("too small\n");
        }
        n++;
    }while(b!=a&&n<=5);
    if(b!=a&&n == 6){
        printf("ʧ���ˣ����´���ս��\n");
    }
    printf("�Ƿ�ʼ��һ����Ϸ����y/n��\n");
    scanf("%c",&rely);
    }while(rely!='n');
}
