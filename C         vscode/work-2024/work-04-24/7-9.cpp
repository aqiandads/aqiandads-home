#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxSize 30
#define NAMEWIDTH 10
typedef struct fnode
{
    char father[NAMEWIDTH];
    char wife[NAMEWIDTH];
    char son[NAMEWIDTH];
}FamType;
typedef struct tnode
{
    char name[NAMEWIDTH];
    struct tnode*lchild,*rchild;
}BTree;
int n;
FamType fam[MaxSize];
BTree *CreateBTree(char *root)
{
    int i=0,j;
    BTree *b,*p;
    b=(BTree *)malloc(sizeof(BTree));
    strcpy(b->name,root);
    b->lchild=b->rchild=NULL;
    while(i<n &&strcmp(fam[i].father,root)!=0)
        i++;
    if(i<n)
    {
        p=(BTree *)malloc(sizeof(BTree));
        p->lchild=p->rchild=NULL;
        strcpy(p->name,fam[i].wife);
        b->lchild=p;
        for(j=0;j<n;j++)
            if(strcmp(fam[j].father,root)==0)//找到一个儿子
            {
                p->rchild=CreateBTree(fam[j].son);
                p=p->rchild;
            }
    }
    return(b);
}
void DispTree(BTree *b)
{
    if(b!=NULL)
    {
        printf("%s",b->name);
        if(b->lchild!=NULL || b->rchild!=NULL)
        {
            printf("(");
            DispTree(b->lchild);
            if(b->rchild!=NULL)
                printf(",");
            DispTree(b->rchild);
            printf(")");
        }
    }
}
BTree *FindNode(BTree *b,char xm[])
{
    BTree *p;
    if(b==NULL)
        return(NULL);
    else
    {
        if(strcmp(b->name,xm)==0)
            return(b);
        else
        {
            p=FindNode(b->lchild,xm);
            if(p!=NULL)
                return(p);
            else
                return(FindNode(b->rchild,xm));
        }
    }
}
void FindSon(BTree *b)
{
    char xm[NAMEWIDTH];
    BTree *p;
    printf(">>父亲姓名：");
    scanf("%s",xm);
    p=FindNode(b,xm);
    if(p==NULL)
        printf(">>不存在%s的父亲!\n",xm);
    else
    {
        p=p->lchild;
        if(p==NULL)
            printf(">>%s没有妻子\n",xm);
        else
        {
            p=p->rchild;
            if(p==NULL)
                printf(">>%s没有儿子!\n",xm);
            else
            {
                printf(">>%s的儿子：",xm);
                while(p!=NULL)
                {
                    printf("%10s",p->name);
                    p=p->rchild;
                }
                printf("\n");
            }
        }
    }
}
int Path(BTree *b,BTree *s)
{
    BTree *St[MaxSize];
    BTree *p;
    int i,top=-1;
    bool flag;
    do
    {
        while(b)
        {
            top++;
            St[top]=b;
            b=b->lchild;
        }
        p=NULL;
        flag=true;
        while(top!=-1&&flag)
        {
            b=St[top];
            if(b->rchild==p)
            {
                if(b==s)
                {
                    printf(">>所有祖先：");
                    for(i=0;i<top;i++)
                        printf(" %s",St[i]->name);
                    printf("\n");
                    return 1;
                }
                else
                {
                    top--;
                    p=b;
                }
            }
            else
            {
                b=b->rchild;
                flag =false;
            }
        }
    }while(top!=-1);
    return 0;
}
void Ancestor(BTree *b)
{
    BTree *p;
    char xm[NAMEWIDTH];
    printf(">>输入姓名：");
    scanf("%s",xm);
    p=FindNode(b,xm);
    if(p!=NULL)
        Path(b,p);
    else
        printf(">>不存在%s\n",xm);
}
void DestroyBTree(BTree*b)
{
    if(b!=NULL)
    {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

void DelAll()
{
    FILE *fp;
    if((fp=fopen("fam.dat","wb"))==NULL)
    {
        printf(">>不能打开家谱文件\n");
        return;
    }
    n=0;
    fclose(fp);
}
void ReadFile()
{
    FILE *fp;
    long len;
    int i;
    if((fp=fopen("fam.dat","rb"))==NULL)
    {
        n=0;
        return;
    }
    fseek(fp,0,2);
    len=ftell(fp);
    rewind(fp);
    n=len/sizeof(FamType);
    for(i=0;i<n;i++)
        fread(&fam[i],sizeof(FamType),1,fp);
    fclose(fp);
}
void SaveFile()
{
    int i;
    FILE *fp;
    if((fp=fopen("fam.dat","wb"))==NULL)
    {
        printf(">>数据家谱文件不能打开\n");
        return;
    }
    for(i=0;i<n;i++)
        fwrite(&fam[i],sizeof(FamType),1,fp);
    fclose(fp);
}
void InputFam()
{
    printf(">>输入父亲、母亲和儿子姓名：");
    scanf("%s%s%s",fam[n].father,fam[n].wife,fam[n].son);
    n++;
}
void OutputFile()
{
    int i;
    if(n<=0)
    {
        printf("    >>没有任何记录\n");
        return;
    }
    printf("          父亲       母亲       儿子\n");
    printf("    --------------------------------\n");
    for(i=0;i<n;i++)
        printf("    %10s%10s%10s\n",fam[i].father,fam[i].wife,fam[i].son);
    printf("    --------------------------------\n");
}
void Fileop()
{
    int sel;
    do
    {
        printf(">1:输入 2:输出 9:全清 0:存盘返回 请选择：");
        scanf("%d",&sel);
        switch(sel)
        {
            case 9:
                DelAll();break;
            case 1:
                InputFam();break;
            case 2:
                OutputFile();break;
            case 0:
                SaveFile();break;
        }
    }while(sel!=0);
}
void BTreeop()
{
    BTree *b;
    int sel;
    if(n==0)return;
    b=CreateBTree(fam[0].father);
    do
    {
        printf(">1:括号表示法2.找某人所有儿子3.找某人所有祖先0:返回请选择：");
        scanf("%d",&sel);
        switch(sel)
        {
            case 1:
                printf(">>");DispTree(b);printf("\n");break;
            case 2:
                FindSon(b);break;
            case 3:
                printf(">>");Ancestor(b);break;
        }
    }while(sel!=0);
    DestroyBTree(b);
}

int main()
{
    BTree *b;
    int sel;
    ReadFile();
    do
    {
        printf("*1.文件操作 2:家谱操作 0:退出 请选择：");
        scanf("%d",&sel);
        switch(sel)
        {
            case 1:
                Fileop();
                break;
            case 2:
                BTreeop();
                break;
        }
    }while(sel!=0);
    return 1;
}