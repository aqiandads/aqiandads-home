#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MaxLen 9
#define Radix 27

typedef char String[MaxLen+1];
typedef struct node
{   String word;struct node *next;
//������������//�������
}LinkNode;
void DispWord(String R[],int n)
{int i;
printf(" ");
for(i=0;i<n;i++)
printf("[%s]",R[i]);
printf("\n");
}
//�Ե��ʽ���Ԥ�����ÿո����β����
void PreProcess(String R[],int n)
{int i,j;
for(i=0;i<n;i++)
{if(strlen(R[i])<MaxLen)
{for(j=strlen(R[i]);j<MaxLen;j++)
R[i][j]=' ';
R[i][j]='\0';
}
}
}
//�ָ�����ɾ��Ԥ����ʱ����β��
void EndProcess(String R[],int n)
{int i,j;
for(i=0;i<n;i++)
{for(j=MaxLen-1;R[i][j]==' ';j--);
R[i][j+1]='\0';
}
}
void Distribute(String R[],LinkNode *head[],LinkNode *tail[],int j,int n)
{int i,k;
LinkNode *p;
for(i=0;i<n;i++)
{
if(R[i][j]==' ')
k=0;
else
k=R[i][j]-'a'+1;
p=(LinkNode *)malloc(sizeof(LinkNode));
strcpy(p->word,R[i]);
p->next=NULL;
if(head[k]==NULL)
{head[k]=p;
tail[k]=p;
}
else
{tail[k]->next=p;
tail[k]=p;
}
}
}
void Collect(String R[],LinkNode*head[])
//���ν����ǿն����еĽ���ռ����������ͷŸ��ǿն����е����н��
{int k=0,i;
LinkNode*pre,*p;
for(i=0;i<Radix;i++)
{if(head[i]!=NULL)
{pre=head[i];p=pre->next;
while(p!=NULL)
{strcpy(R[k++],pre->word);
free(pre);
pre=p;
p=p->next;
}
strcpy(R[k++],pre->word);
free(pre);
}
}
}
void RadixSort(String R[],int n)
{LinkNode *head[Radix],*tail[Radix];
int i,j;
for(i=MaxLen-1;i>=0;i--)
{for(j=0;j<Radix;j++)head[j]=tail[j]=NULL;
Distribute(R,head,tail,i,n);
Collect(R,head);
}
}
int main()
{int n=6;
String R[]={"while","if","if else","do while","for","case"};
printf("����ǰ��\n");DispWord(R,n);PreProcess(R,n);
printf("Ԥ�����\n");DispWord(R,n);RadixSort(R,n);
printf("��������\n");DispWord(R,n);EndProcess(R,n);
printf("���ս����\n");DispWord(R,n);return 1;}
