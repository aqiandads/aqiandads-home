#include<stdio.h>
#include"Linklist.cpp"

void Merge(LinkNode *L1,LinkNode *L2,LinkNode *L3)
{
	LinkNode *p,*q,*r;
	p = L1->next;
	q = L2->next;
	r = L3;
	while(p!=NULL && q!=NULL)
	{
		r->next=p;r=p;p=p->next;
		r->next=q;r=q;q=q->next;
	}
	if(q!=NULL)
	{
		p = q;
	}
	r->next=p;
}

int main()
{
	LinkNode *L1,*L2,*L3;
	L1 = (LinkNode*)malloc(sizeof(LinkNode));
	L2 = (LinkNode*)malloc(sizeof(LinkNode));
	L3 = (LinkNode*)malloc(sizeof(LinkNode));
	ElemType a[]="abcdefgh";
	int n=8;
	CreateListR(L1,a,n);
	printf("L1:");DispList(L1);
	ElemType b[]="12345";
	n = 5;
	CreateListR(L2,b,n);
	printf("L2:");DispList(L2);
	printf("L1和L2合并产生L3\n");
	Merge(L1,L2,L3);
	printf("L3:");DispList(L3);
	DestroyList(L3);
	return 1;
}
