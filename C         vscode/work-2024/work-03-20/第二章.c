#include<stdio.h>

void fun8(SqList *&L)

int main()
{
    int i;
    fun();
}

void fun8(SqList *&L)
{
    int i = 0,j = L->length - 1;
    while(i < j)
    {
        while(L->data[i] < 0)
        {
            i++;
        }
        while(L->data[j] > 0)
        {
            j--;
        }
        if(i < j)
        {
            int t;
            t = L->data[i];
            L->data[j] = L->data[i];
            L->data[i] = t;
        }
    }
}


void fun14(LinkNode *&L,ElemType x)
{
    LinkNode *p = L->next,*pre = L,*maxp = p,*maxpre = pre,*s;
    while(p != NULL){
        if(maxp->data < p->data){
            maxp = p;
            maxpre = pre;
        }
        pre = p;
        p = p->next;
    }
    s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = maxpre->next;
    maxpre->next = s;
}


void fun16(DLinkNode *L,ElemType x)
{
    DLinkNode *p = L->next,*pre;
    while(p!=NULL && p->data!=x)
    {
        p = p->next;
    }
    if(p == NULL){
        return false;
    }
    else{
        p->freq++;
        pre = p->prior;
        while(pre!= h && pre->freq < p->freq){
            p->prior = pre->prior;
            p->prior->next = p;
            pre->next = p->next;
            if(pre->next != NULL){
                pre->next->prior = pre;
            }
            p->next = pre;
            pre->prior = p;
            pre = p->prior;
        }
        return true;
    }
}



void fun201(LinkNode *A,LinkNode *B,LinkNode *&C)
{
    LinkNode *prea = A,*pa = A->next,*pb,*p,*t;
    C = A;
    while(pa != NULL)
    {
        pb = B->next;
        while(pb!=NULL && pb->data != pa->data){
            pb = pb->next;
        }
        if(pb != NULL)
        {
            prea ->next = pa->next;
            free(pa);
            pa = prea->next;
        }else{
            prea = pa;
            pa = pa->next;
        }
    }
    p = B;
    t = B->next;
    while(t != NULL)
    {
        free(p);
        p = t;
        t = t->next;
    }
    free(p);
}


void fun202(LinkNode *A,LinkNode *B,LinkNode *&C)
{
    LinkNode *prea = A,*pa = A->next;
    LinkNode *preb = B,*pb = B->next;
    LinkNode *pc = C;
    C = A;
    pc = C;
    while(pa != NULL && pb != NULL)
    {
        if(pa->data < pb->data){
            pc->next = pa;
            pc = pa;
            prea = pa;
            pa = pa->next;
        }
        else{
            if(pa->data>pb->data){
                preb->next = pb->next;
                free(pb);
                pb = preb->next;
            }else{
                prea->next = pa->next;
                free(pa);
                pa = prea->next;
                preb->next = pb->next;
                free(pb);
                pb = preb->next;
            }
        }
        while(pb != NULL)
        {
            preb->next = pb ->next;
            free(pb);
            pb = preb->next;
        }
        free(B);
        pc->next = NULL;
    }
}