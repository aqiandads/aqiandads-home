#include<stdio.h>
#include<math.h>

int main()
{
    int a,b;
    char c;
    scanf("%d %c %d",&a,&c,&b);
    if(c=='+'){
        printf("%d",a+b);
    }else{
        if(c=='-'){
            printf("%d",a - b);
        }else{
            if(c=='*'){
                printf("%d",a * b);
            }else{
                if(c=='/'){
                    printf("%d",a / b);
                }else{
                    if(c=='%'){
                        printf("%d",a % b);
                    }else{
                        if(c=='<'){
                            printf("%.0f",a * pow(2,b));
                        }else{
                            if(c=='>'){
                                printf("%.0f",a / pow(2,b));
                            }else{
                                printf("ERROR");
                            }
                        }
                    }
                }
            }
        }
    }
}