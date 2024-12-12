#include<stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType;
typedef struct
{
    KeyType key;
InfoType data;
}RecType;
int FindElem(RecType R[],int n,KeyType k)
{int i=4,j;
if(k<R[1].key ||  k>R[4*n].key)return 0;
while(i<=4*n)
{if(R[i].key==k)
//查找成功返回
return i;
else if(R[i].key<k)
i+=4;
else
break;
}
j=i-3;
while(j<i&&R[j].key!=k)
    j++;
if(j<i)return j;
else return 0;
}
int ImproveFindElem(RecType R[],int n,KeyType k)
{int low,high,mid;
int i,j;
if(k<R[1].key || k>R[4*n].key)
    return 0;
low=4;high=4*n;
while(low<=high)
{   mid=(low+high)/2;
if(k<R[mid].key)
high=mid-4;
else if(k>R[mid].key)
low=mid+4;
else return mid;
}
i=high+4;
j=high+1;
while(j<i&&R[j].key!=k)
    j++;
if(j<i)return j;
else return 0;
}
int main()
{int i,m=13,n=3;
KeyType keys[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
RecType R[MAXL];
for(i=0;i<m;i++)R[i].key=keys[i];
printf("R:");
for(i=0;i<m;i++)
printf("%3d",R[i].key);
printf("\n");
KeyType k=8;
printf("用算法(1)查找关键字%d:\n",k);
i=FindElem(R,n,k);
if(i>=1)printf("结果：R[%d]=%d\n",i,k);
else printf("未找到号%d\n",k);
k=20;
printf("用算法(2)查找关键字%d:\n",k);
i=ImproveFindElem(R,n,k);
if(i>=1)printf("结果：R[%d]=%d\n",i,k);
else printf("未找到%d\n",k);
return 1;
}
