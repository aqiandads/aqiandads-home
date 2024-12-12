#include<stdio.h>
#include"Linklist.cpp"

void Sort(LinkNode *);
void Union(LinkNode*,LinkNode*,LinkNode*);
void InterSect(LinkNode*,LinkNode*,LinkNode*);
void Subs(LinkNode*,LinkNode*,LinkNode*);

int main()
{
    LinkNode *ha,*hb,*hc;
    ha = (LinkNode*)malloc(sizeof(LinkNode));
    hb = (LinkNode*)malloc(sizeof(LinkNode));
    hc = (LinkNode*)malloc(sizeof(LinkNode));
    ElemType a[]="caeh",b[]="fhbgda";
    printf("集合的运算如下:\n");
    CreateListR(ha,a,4);
    CreateListR(hb,b,6);
    printf("原集合A:");DispList(ha);
    printf("原集合B:");DispList(hb);
    Sort(ha);Sort(hb);
    printf("有序集合A:");DispList(ha);
    printf("有序集合B:");DispList(hb);
    Union(ha,hb,hc);
    printf("集合的并集C:");DispList(hc);
    InterSect(ha,hb,hc);
    printf("集合的交集C:");DispList(hc);
    Subs(ha,hb,hc);
    printf("集合的差集C:");DispList(hc);
    DestroyList(ha);DestroyList(hb);DestroyList(hc);
    return 1;
}


void Sort(LinkNode *L)
{
    LinkNode *p,*pre,*q;
    p = L->next->next;
    L->next->next = NULL;
    while(p!=NULL)
    {
        q = p->next;
        pre = L;
        while(pre->next!=NULL && pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}


void Union(LinkNode*ha,LinkNode*hb,LinkNode*hc)
{
    LinkNode *pa = ha->next,*pb = hb->next,*s,*tc;
    tc = hc;
    while(pa!=NULL && pb!=NULL)
    {
        if(pa->data < pb->data)
        {
            s = (LinkNode*)malloc(sizeof(LinkNode));
            s->data = pa->data;
            tc->next = s;
            tc = s;
            pa = pa->next;
        }else{
            if(pa->data > pb->data)
            {
                s = (LinkNode*)malloc(sizeof(LinkNode));
                s->data = pb->data;
                tc->next = s;
                tc = s;
                pb = pb->next;
            }else{
                s = (LinkNode*)malloc(sizeof(LinkNode));
                s->data = pa->data;
                tc->next = s;
                tc = s;
                pa = pa->next;
                pb = pb->next;
            }
        }
    }
    if(pb!=NULL)
    {
        pa = pa;
    }
    tc->next = pa;
}


void InterSect(LinkNode*ha,LinkNode*hb,LinkNode*hc)
{
    LinkNode *pa = ha->next,*pb,*s,*tc;
    tc = hc;
    while(pa!=NULL)
    {
        pb = hb->next;
        while(pb!=NULL && pb->data <pa->data)
        {
            pb = pb->next;
        }
        if(pb!=NULL && pb->data == pa->data)
        {
            s = (LinkNode*)malloc(sizeof(LinkNode));
            s->data = pa->data;
            tc->next = s; tc = s;
        }
        pa = pa->next;
    }
    tc->next = NULL;
}


void Subs(LinkNode*ha,LinkNode*hb,LinkNode*hc)
{
    LinkNode *pa = ha->next,*pb,*s,*tc;
    tc = hc;
    while(pa!=NULL)
    {
        pb = hb->next;
        while(pb!=NULL && pb->data <pa->data)
        {
            pb = pb->next;
        }
        if(pb==NULL || pb->data != pa->data)
        {
            s = (LinkNode*)malloc(sizeof(LinkNode));
            s->data = pa->data;
            tc->next = s; tc = s;
        }
        pa = pa->next;
    }
    tc->next = NULL;
}
