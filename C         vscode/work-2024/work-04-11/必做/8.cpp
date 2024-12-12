#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 100
typedef struct
{
    int col[MaxSize];
    int top;
}StackType;

void dispasolution(StackType St)
{
    static int count=0;
    printf("第%d个解:",++count);
    for(int i=1;i<=St.top;i++)
    {
        printf("(%d,%d)",i,St.col[i]);
    }
    printf("\n");
}

bool place(StackType St,int k,int j)
{
    int i=1;
    if(k==1)
    {
        return true;
    }
    while(i<=k-1)
    {
        if((St.col[i]==j) || (abs(j-St.col[i])==abs(i-k)))
        {
            return false;
        }
        i++;
    }
    return true;
}

void queen(int n)
{
    int k;
    bool find;
    StackType St;
    St.top=0;
    St.top++;
    St.col[St.top]=0;
    while(St.top!=0)
    {
        k=St.top;
        find=false;
        for(int j=St.col[k]+1;j<=n;j++)
        {
            if(place(St,k,j))
            {
                St.col[St.top]=j;
                find=true;
                break;
            }
        }
        if(find)
        {
            if(k==n)
            {
                dispasolution(St);
            }else{
                St.top++;
                St.col[St.top]=0;
            }
        }else{
            St.top--;
        }
    }
}
 
int main()
{
    int n;
    printf("皇后问题(n<20) n=");
    scanf("%d",&n);
    if(n>20)
    {
        printf("n值太大\n");
    }else{
        printf("%d皇后问题求解如下:\n",n);
        queen(n);
    }
    return 1;
}