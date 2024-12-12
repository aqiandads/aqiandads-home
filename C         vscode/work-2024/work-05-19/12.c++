#include<stdio.h>
#include<malloc.h>
#define MAXV 201

typedef struct ANode
{int no;
struct ANode *nextarc;}
ArcNode;

typedef struct Vnode
{ArcNode *firstarc;}VNode;
typedef struct
{int n;
int m;
VNode adjlist[MAXV];
}ALGraph;

int BFS(ALGraph*G,int s,int e)
{int visited[MAXV];
struct
{int no;
int level;
}qu[MAXV];

int front=0,rear=0,i,w,l;
ArcNode *p;
if(s==e)return 0;
for(i=0;i<G->n;i++)visited[i]=0;
visited[s]=1;
rear =(rear+1)%MAXV;
qu[rear].no=s;
qu[rear].level=0;

while(front!=rear)
{  front=(front+1)%MAXV;
w=qu[front].no;
l=qu[front].level;
p=G->adjlist[w].firstarc;
while(p!=NULL)
{if(visited[p->no]==0)
{if(p->no ==e)return qu[rear].level;
visited[p->no]=1;
rear=(rear+1)%MAXV;
qu[rear].no=p->no;
qu[rear].level=l+1;
}
p=p->nextarc;
}
}
return -1;
}
//初始化邻接表
void InitGraph(ALGraph *&G,int n)
{int i;
G=(ALGraph *)malloc(sizeof(ALGraph));
for(i=0;i<n;i++)G->adjlist[i].firstarc=NULL;
G->n=n;
G->m=0;
}
void Add(ALGraph *&G,int a,int b)
{ArcNode*p;
p=(ArcNode*)malloc(sizeof(ArcNode));
p->no=b;
p->nextarc=G->adjlist[a].firstarc;
G->adjlist[a].firstarc=p;
p=(ArcNode *)malloc(sizeof(ArcNode));
p->no =a;
p->nextarc=G->adjlist[b].firstarc;
G->adjlist[b].firstarc=p;
G->m++;
}
void DestroyGraph(ALGraph *&G)
{ArcNode *pre,*p;
for(int i=0;i<G->n;i++)
{pre=G->adjlist[i].firstarc;
if(pre!=NULL)
{p=pre->nextarc;
while(p!=NULL)
{free(pre);
pre=p;p=p->nextarc;
}
free(pre);
}
}
free(G);
}
void DispGraph(ALGraph *G)
{int i;
ArcNode *p;
printf("n=%d,e=%d\n",G->n,G->m);
for(i=0;i<G->n;i++)
{printf("[%3d]:",i);
p=G->adjlist[i].firstarc;
while(p!=NULL)
{printf("→(%d)",p->no);
p=p->nextarc;
}
printf("→A\n");
}
}
int main()
{ALGraph *G;
int m,n,k,a,b,s,e,i;
FILE *fp;
fp=fopen("test.txt","r");
if(fp==NULL)
{ printf("不能打开 test. txt文件\n");
return 0;}
fscanf(fp,"%d%d", &n, &m);
InitGraph( G, n);
for( i=0; i< m; i++)
{ fscanf( fp,"%d%d",&a,&b);
Add(G, a, b);}
printf("邻接表:\n");
DispGraph(G);
printf("求解结果:\n");
fscanf(fp,"%d", &k);
for( i=0; i< k; i++)
{ fscanf( fp,"%d%d",&s,&e);
printf(" case%d至少需要%d个翻泽\n",i+1, BFS(G, s, e));}
DestroyGraph(G);
fclose(fp);
return 1;
}