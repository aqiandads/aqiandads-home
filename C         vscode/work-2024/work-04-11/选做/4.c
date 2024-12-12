//链栈运算算法
#include <stdio.h>
#include <malloc.h>
#include<stdbool.h>
typedef char ElemType;
typedef struct linknode
{	
	ElemType data;				
	struct linknode *next;		
} LinkStNode;					

void Push(LinkStNode *s,ElemType e)	
{	LinkStNode *p;
	p=(LinkStNode *)malloc(sizeof(LinkStNode));
	p->data=e;				
	p->next=s->next;		
	s->next=p;
}
bool Pop(LinkStNode *s,ElemType *e)	
{	LinkStNode *p;
	if (s->next==NULL)		
		return false;
	p=s->next;				
	*e=p->data;
	s->next=p->next;		
	free(p);				
	return true;
}

int main () {
	char e,x,str[1000];
	int i=0;
	LinkStNode *p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	gets(str);
	while(str[i]!='\0')
	{
		e=str[i];
		Push(p,e);
		i++;
	}
	i=0;
	while(str[i]!='\0')
	{
		x=str[i];
		Pop(p,&e);
		if(x!=e)
		{
			break;
		}
		i++;
	}
	if(x!=e)
	{
		printf("no");
	}else{
		printf("yes");
	}
	return 0;
}