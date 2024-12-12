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

int main () {
	char e,str[1000];
	int count1=0,count11=0,count2=0,count22=0,count3=0,count33=0;
	int countL,countR;
	int i=0;
	LinkStNode*p;
	p=(LinkStNode*)malloc(sizeof(LinkStNode));
	gets(str);
	while(str[i]!='\0')
	{
		e=str[i];
		Push(p,e);
		switch(e)
		{
			case '(':count1++;break;
			case ')':count11++;break;
			case '[':count2++;break;
			case ']':count22++;break;
			case '{':count3++;break;
			case '}':count33++;break;
		}
		i++;
	}
	countL=count1+count2+count3;
	countR=count11+count22+count33;
	printf("%d %d\n",countL,countR);
	if(count1==count11 && count2==count22 && count3==count33)
	{
		printf("yes");
	}else{
		printf("no");
	}
	return 0;
}