#include "graph.cpp"
int visited[MAXV];
int V1[MAXV],V2[MAXV],n,m;
int count=0;

bool Cond(int path[],int d)
{
    int flag1=0,f1,flag2=0,f2,i,j;
    for(i=0;i<n;i++)
    {
        f1=1;
        for(j=0;j<=d;j++)
            if(path[j]==V1[i])
            {
                f1=0;break;
            }
        flag1+=f1;
    }
    for(i=0;i<m;i++)
    {
        f2=0;
        for(j=0;j<=d;j++)
            if(path[j]==V2[i])
            {
                f2=1;break;
            }
        flag2+=f2;
    }
    if(flag1==0 &&flag2==0)
        return true;
    else
        return false;
}
void TravPath(AdjGraph *G,int vi,int vj,int path[],int d)
{
    int v,i;
    ArcNode *p;
    visited[vi]=1;
    d++;path[d]=vi;
    if(vi==vj &&Cond(path,d))
    {
        printf("路径%d:",++count);
        for(i=0;i<d;i++)
            printf("%d->",path[i]);
        printf("%d\n",path[i]);
    }
    p=G->adjlist[vi].firstarc;
    while(p!=NULL)
    {
        v=p->adjvex;
        if(visited[v]==0)
            TravPath(G,v,vj,path,d);
        p=p->nextarc;
    }
    visited[vi]=0;
    d--;
}

int main()
{
    int i,u,v;
    int path[MAXV];
    AdjGraph *G;
    int A[MAXV][MAXV]={
    {0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
    {0,1,0,1,0,0,0,1,0,1,0,0,0,0,0},{0,0,0,0,1,0,1,0,0,0,1,1,0,0,0},
    {0,1,0,0,0,1,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,1,1,0,0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0,1,0,1,0,0,0,1,0},{0,0,0,0,0,0,0,1,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,1,1,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,1,1,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0}};
    CreateAdj(G,A,15,21);
    printf("图G的邻接表：\n");DispAdj(G);
    for(i=0;i<n;i++)visited[i]=0;
    printf("输入起点和终点：");
    scanf("%d %d",&u,&v);
    printf("输入必经点个数：");
    scanf("%d",&n);
    printf("输入必经点集合：");
    for(i=0;i<n;i++)
        scanf("%d",&V1[i]);
    printf("输入必避点个数：");
    scanf("%d",&m);
    printf("输入必避点集合：");
    for(i=0;i<m;i++)
        scanf("%d",&V2[i]);
    printf("\n所有的探宝路径如下：\n");
    TravPath(G,u,v,path,-1);
    DestroyAdj(G);
    return 1;
}