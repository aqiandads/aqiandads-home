#include<stdio.h>
#include"sqstring.cpp"

SqString A,B;

SqString EnCrypt(SqString p)
{
    int i=0,j;
    SqString q;
    while(i<p.length)
    {
        for(j=0;p.data[i]!=A.data[j];j++);
        if(j>=p.length)
        {
            q.data[i]=p.data[i];
        }else{
            q.data[i]=B.data[j];
        }
        i++;
    }
    q.length=p.length;
    return q;
}

SqString UnEncrypt(SqString q)
{
    int i=0,j;
    SqString p;
    while(i<q.length)
    {
        for(j=0;q.data[i]!=B.data[j];j++);
        if(j>=q.length)
        {
            p.data[i]=q.data[i];
        }else{
            p.data[i]=A.data[j];
        }
        i++;
    }
    p.length=q.length;
    return p;
}

int main()
{
    SqString p,q;
    int ok=1;
    StrAssign(A,"abcdefjhijklmnopqrstuvwxyz");
    StrAssign(B,"ngzqtcobmuhelkpdawxfyivrsj");
    char str[MaxSize];
    printf("\n");
    printf("����ԭ�Ĵ�:");
    gets(str);
    StrAssign(p,str);
    printf("���ܽ�������:\n");
    printf("ԭ�Ĵ�:");DispStr(p);
    q=EnCrypt(p);
    printf("���ܴ�:");DispStr(q);
    p=UnEncrypt(q);
    printf("���ܴ�:");DispStr(p);
    printf("\n");
    DestroyStr(p);
    DestroyStr(q);
    return 1;
}