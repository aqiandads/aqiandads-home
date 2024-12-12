#include<stdio.h>

int main()
{
    char temp[100];
    int cnt = 0,n = 0;
    do{
        scanf("%c",&temp[cnt]);
        if(temp[cnt]!=' '&&temp[cnt]!='.'){
            n = n + 1;
        }else{
            if(temp[cnt]=='.'){
                printf("%d",n);
                break;
            }else{
                if(temp[cnt-1]!=' '){
                    printf("%d ",n);
                    n = 0;
                }
            }
        }
        cnt++;
        
        
    }while(temp[cnt]!='.');
    return 0;
}