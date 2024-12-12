#include<stdio.h>
#include<stdlib.h>
const int N = 20;
int q[N];
int count=0;

void print(int n)
{
    count++;
    int i;
    printf(" 第%d个解:",count);
    for(i=1;i<=n;i++)
    {
        printf("(%d,%d)",i,q[i]);
    }
    printf("\n");
}

bool place(int k,int j)
{
    int i=1;
    while(i<k)
    {
        if((q[i]==j) || (abs(q[i]-j)==abs(i-k)))
        {
            return false;
        }
        i++;
    }
    return true;
    
}

void queen(int k,int n)
{
    int j;
    if(k>n)
    {
        print(n);
    }else{
        for(j=1;j<=n;j++)
        {
            if(place(k,j))
            {
                q[k]=j;
                queen(k+1,n);
            }
        }
    }
}

int main()
{
    int n;
    printf("皇后问题(n<20)n:");
    scanf("%d",&n);
    if(n>20)
    {
        printf("n值太大,不能求解\n");
    }else{
        printf("%d皇后问题求解如下:\n",n);
        queen(1,n);
        printf("\n");
    }
    return 1;
}