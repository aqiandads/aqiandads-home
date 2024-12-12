#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAXWORD 100
typedef struct tnode
//�ַ�
{char ch;
//���ִ���
int count;
//����ָ��
struct tnode *lchild,*rchild;
//�������
}BSTNode;
void CreateBST(BSTNode *&bt,char c)
//btΪNULL,����һ
{if(bt==NULL)
{   bt=(BSTNode *)malloc(sizeof(BSTNode));
bt->ch=c;
bt->count =1;
bt->lchild=bt->rchild=NULL;
}
else if(c==bt->ch)
bt->count++;
else if(c<bt->ch)
CreateBST(bt->lchild,c);
else
CreateBST(bt->rchild,c);
}
void InOrder(BSTNode *bt)
{if(bt!=NULL)
{InOrder(bt->lchild);
printf(" %c(%d)\n",bt->ch,bt->count);
InOrder(bt->rchild);
}
}
void DestroyBST(BSTNode *bt)
{if(bt!=NULL)
{
DestroyBST(bt->lchild);
DestroyBST(bt->rchild);
free(bt);
}
}
int main()
{BSTNode *bt =NULL;
int i=0;
char str[MAXWORD];
printf("�����ַ�����");
gets(str);
while(str[i]!='\0')
{  CreateBST(bt,str[i]);
i++;
}
printf("�ַ������ִ�����\n");
InOrder(bt);
printf("\n");
DestroyBST(bt);
return 1;
}