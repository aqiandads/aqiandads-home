#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAXR 10
#define MaxSize 10
typedef struct node
{char xm[10];char xb;char bh[6];
struct node *next;
}StudNode;
typedef struct
//姓名
{char xm[10];
char xb;
char bh[6];
}StudType;


void CreateLink(StudNode*&p,StudType A[],int n)//创建单链表
{int i;
StudNode*s,*t;
p=NULL;
for(i=0;i<n;i++)
{s=(StudNode *)malloc(sizeof(StudNode));
strcpy(s->xm,A[i].xm);
s->xb=A[i].xb;
strcpy(s->bh,A[i].bh);
if(p==NULL)
{p=s;
t=s;
}
else
{t->next=s;
t=s;
}
}
t->next =NULL;
}


void DispLink(StudNode *p)
//输出单链表
{int i=0;
while(p!=NULL)
{printf("%s(%s,%c)",p->xm,p->bh,p->xb);
p=p->next;
if((i+1)%5==0)printf("\n");
i++;
}
printf("\n");
}
void DestroyLink(StudNode *p)
//销毁单链表
{StudNode *pre=p,*q=pre->next;
while(q!=NULL)
{free(pre);
pre=q;
q=q->next;
}
free(pre);
}


void RadixSort1(StudNode *&p,int r,int d)
{    StudNode *head[MAXR],*tail[MAXR],*t;
//定义各链队的首尾指针
int j,k;
printf("按性别进行排序\n");
for(j=0;j<r;j++)head[j]=tail[j]=NULL;
while(p!=NULL)
{
if(p->xb=='f')k=0;
else k=1;
if(head[k]==NULL)
{head[k]=p;
tail[k]=p;
}
else
{tail[k]->next =p;
tail[k]=p;
}
p=p->next;
//取下一个待排序的元素
}
p=NULL;
for(j=0;j<r;j++)
//对于每一个链队循环//进行收集
if(head[j]!=NULL)
{if(p==NULL)
{p=head[j];
t=tail[j];
}
else
{t->next =head[j];
t=tail[j];
}
}
//最后一个结点的next域置NULL//输出单键表
t->next=NULL;
DispLink(p);
}


void RadixSort2(StudNode *p,int r,int d)
{StudNode *head[MAXR],*tail[MAXR],*t;
int i,j,k;
printf("按班号进行排序\n");
//从低位到高位做d趟排序
for(i=3;i>=2;i--)
//初始化各链队首、尾指针
{for(j=0;j<r;j++)
head[j]=tail[j]=NULL;
while(p!=NULL)
{k=p->bh[i]-'0';
if(head[k]==NULL)
{head[k]=p;
tail[k]=p;
}
else
{tail[k]->next =p;
tail[k]=p;
}
//取下一个待排序的元素
p=p->next;
}
p=NULL;
//对于每一个链队循环//进行收集
for(j=0;j<r;j++)
if(head[j]!=NULL)
{if(p==NULL)
{   p=head[j];
t=tail[j];
}
else
{t->next=head[j];
t=tail[j];
}
}t->next =NULL;
printf("第%d趟：\n",d-i+2);
DispLink(p);
if(d-i+2==2)
{
    printf("排序后：\n");DispLink(p);
}
}
}


void Sort(StudType A[],int n)
{
StudNode *p;
CreateLink(p,A,n);
printf("排序前：\n");DispLink(p);RadixSort1(p,2,1);RadixSort2(p,10,2);
//对性别进行排序//对班号的后两位进行排序
DestroyLink(p);
}
int main()
{
int n=10;
StudType A[MaxSize]={{"王华",'m',"1003"},
{"陈兵",'m',"1020"},{"许可",'f',"1022"},
{"李英",'f',"1003"},{"张冠",'m',"1021"},
{"陈强",'m',"1002"},{"李真",'f',"1002"},
{"章华",'m',"1001"},{"刘丽",'f',"1021"},
{"王强",'m',"1022"}};
Sort(A,n);
return 1;
}