#include<stdio.h>
#define MAXN 20
int maxv,maxw,x[MAXN],W=7,n=4;
int w[]={5,3,2,1},v[]={4,4,3,1};
void knap(int i,int tw,int tv,int op[])
{
    int j;
    if(i>=n)
    {
        if(tw<=W && tv>maxv)
        {
            maxv = tv;
            maxw = tw;
            for(j=1;j<=n;j++)
            {
                x[j]=op[j];
            }
        }
    }else{
        op[i]=1;
        knap(i+1,tw+w[i],tv+v[i],op);
        op[i]=0;
        knap(i+1,tw,tv,op);
    }
}

void dispasolution(int x[],int n)
{
    int i;
    printf("���װ�����:\n");
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
            printf("ѡȡ��%d����Ʒ\n",i);
        }
    }
    printf("������=%d,�ܼ�ֵ=%d\n",maxw,maxv);
}

int main()
{
    int op[MAXN];
    knap(0,0,0,op);
    dispasolution(x,n);
    return 1;
}