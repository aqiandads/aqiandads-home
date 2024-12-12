#include<stdio.h>
#include"Linklist.cpp"

void Splist(LinkNode *L,ElemType x){
	LinkNode *p = L->next,*q,*r;
	L->next = NULL;
	r=L;
	while(p!=NULL)
	{
		if(p->data<x)
		{
			q = p->next;
			p->next = L->next;
			L->next = p;
			if(p->next==NULL)
			{
				r = p;
			}
			p = q;
		}else{
			r->next = p;
			r = p;
			p = p->next;
		}
	}
	r->next = NULL;
}

int main(){
	LinkNode *L;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	ElemType a[8]="abcdefgh";
	int n = 8;
	CreateListR(L,a,n);
	printf("L:");  DispList(L);
	ElemType x='d';
	printf("以%c进行划分\n",x);
	Splist(L,x);
	printf("L:");  DispList(L);
	DestroyList(L);
	return 0;
}
