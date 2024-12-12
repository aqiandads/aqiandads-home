#include<stdio.h>

int main()
{
    char a;
    scanf("%c",&a);
    if(a == ' '){
        printf("空格");
    }else{
        if(a>'0'&&a<'9'){
            printf("数字字符");
        }else{
        if(a>'A'&&a<'Z'){
            printf("大写字符");
        }else{
            if(a>'a'&&a<'z'){
                printf("小写字符");
            }else{
                printf("其它字符");
            }
        }
        }
    }
}