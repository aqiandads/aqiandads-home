#include<stdio.h>
#define M 4
#define N 4
void MinMax(int A[M][N])
{
    int i,j;
    bool have=false;
    int min[M],max[N];
    for(i=0;i<M;i++)
    {  
        min[i]=A[i][0];
        for(j=1;j<N;j++)
            if(A[i][j]<min[i])
                min[i]=A[i][j];
    }
    for(j=0;j<N;j++)
    {
        max[j]=A[0][j];
        for(i=1;i<M;i++)
            if(A[i][j]>max[j])
                max[j]=A[i][j];
    }
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            if(min[i]==max[j])
            {
                printf("A[%d][%d]=%d\n",i,j,A[i][j]);have=true;
            }
    if(!have)
        printf("没有马鞍点\n");
}
int main()
{
    int i,j;
    int A[M][N]={{9,7,6,8},{20,26,22,25},{28,36,25,30},{12,4,2,6}};
    printf("A矩阵：\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            printf("%4d",A[i][j]);
        printf("\n");
    }
    printf("A矩阵中的马鞍点：\n");
    MinMax(A);
    return 1;
}