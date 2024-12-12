#include "graph.cpp"
int visited[MAXV];
void PathAll1(AdjGraph *G,int u,int v,int path[],int d)
{ArcNode*p;
int j,w;
d++;
path[d]=u;
visited[u]=1;
if(u==v &&d>0)
{for(j=0;j<=d;j++)printf("%3d",path[j]);printf("\n");
}
p=G->adjlist[u].firstarc;
while(p!=NULL)
{w=p->adjvex;
if(visited[w]==0)PathAll1(G,w,v,path,d);
p=p->nextarc;
}
visited[u]=0;
}
void PathAll2(AdjGraph *G,int u,int v,int l,int path[],int d)
{
int w,i;
ArcNode *p;
visited[u]=1;
d++;
path[d]=u;
if(u==v &&d==l)
{for(i=0;i<=d;i++)printf("%3d",path[i]);printf("\n");
}
p=G->adjlist[u].firstarc;
while(p!=NULL)
{  w=p->adjvex;
if(visited[w]==0)PathAll2(G,w,v,l,path,d);
p=p->nextarc;
}
visited[u]=0;
//取消访问标记，以使该顶点可重新使用
}
int ShortPath(AdjGraph *G,int u,int v,int path[])
{struct
{int vno;
int level;
int parent;}qu[MAXV];
int front=-1,rear =-1,k,lev,i,j;
ArcNode *p;
visited[u]=1;
rear++;
qu[rear].vno=u;
qu[rear].level=0;
qu[rear].parent=-1;
while(front<rear)
{front++;
k=qu[front].vno;
lev=qu[front].level;
if(k==v)
{i=0;
j=front;
while(j!=-1)
{path[lev-i]=qu[j].vno;
j=qu[j].parent;
i++;
}
return lev;
}
p=G->adjlist[k].firstarc;
while(p!=NULL)
{if(visited[p->adjvex]==0)
{visited[p->adjvex]=1;
rear++;
qu[rear].vno=p->adjvex;
qu[rear].level=lev+1;
qu[rear].parent =front;
}
p=p->nextarc;
}
}
return -1;
}
int main()
{int i,j;
int u=5,v=2,l=3;
int path[MAXV];
AdjGraph*G;
int A[MAXV][MAXV]={
{0,1,0,1,0,0},{0,0,1,0,0,0},{1,0,0,0,0,1},
{0,0,1,0,0,1},{0,0,0,1,0,0},{1,1,0,1,1,0}};
int n=6,e=10;
CreateAdj(G,A,n,e);
printf("图G的邻接表：\n");
DispAdj(G);
printf("(1)从顶点%d到%d的所有路径：\n",u,v);
for(i=0;i<n;i++)visited[i]=0;
PathAll1(G,u,v,path,-1);
printf("(2)从顶点%d到%d的所有长度为%d路径：\n",u,v,l);
PathAll2(G,u,v,l,path,-1);
printf("(3)从顶点%d到%d的最短路径：\n",u,v);
for(i=0;i<n;i++)visited[i]=0;
j=ShortPath(G,u,v,path);
for(i=0;i<=j;i++)printf("%3d",path[i]);
printf("\n");
DestroyAdj(G);
return 1;
}