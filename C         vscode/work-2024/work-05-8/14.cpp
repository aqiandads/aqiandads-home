#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#define M 4
#define N 4
typedef struct ANode
//边的结点结构类型
{ int i,j;
//该边的终点位置(i,j)
struct ANode * nextarc;
}//指向下一条边的指针
ArcNode;
typedef struct Vnode
//邻接表头结点的类型
{ArcNode *firstarc;
//指向第一个相邻点
}VNode;

typedef struct
{
    VNode adjlist[M+2][N+2];
//邻接表头结点数组
}ALGraph;
typedef struct
{
 int i;
//当前方块的行号
int j;
//当前方块的列号
}
Box;
typedef struct
{
Box data[MaxSize];
//路径长度
int length;
//定义路径类型
}
PathType;
int visited[M+2][N+2]={0};
int count=0;
//建立迷宫数组对应的邻接表G
void CreateAdj(ALGraph *&G,int mg[][N+2])
{
int i,j,i1,j1,di;
ArcNode *p;
G=(ALGraph *)malloc(sizeof(ALGraph));
for(i=0;i<M+2;i++)
{   for(j=0;j<N+2;j++)
    {   G->adjlist[i][j].firstarc=NULL;
        
    }
}

for(i=1;i<=M;i++)
{
    for(j=1;j<=N;j++)
{
    
if(mg[i][j]==0)
{di=0;
while(di<4)
{  switch(di)
    {   case 0:i1=i-1;j1=j;break;
        case 1:i1=i;j1=j+1;break;
        case 2:i1=i+1;j1=j;break;
        case 3:i1=i,j1=j-1;break;
    }
if(mg[i1][j1]==0)
{
p=(ArcNode*)malloc(sizeof(ArcNode));
p->i=i1;p->j=j1;
p->nextarc=G->adjlist[i][j].firstarc;//将p结点链到链表后
G->adjlist[i][j].firstarc=p;
}
di++;
}
}
}
}
}
void DispAdj(ALGraph *G)
{  int i,j;
ArcNode *p;
for(i=0;i<M+2;i++)
{for(j=0;j<N+2;j++)
{
printf("[%d,%d]:",i,j);
p=G->adjlist[i][j].firstarc;
while(p!=NULL)
{printf("(%d,%d)",p->i,p->j);
p=p->nextarc;
}
printf("\n");
}
}
}


void DestroyAdj(ALGraph *&G)
//销毁邻接表
{  int i,j;
ArcNode *pre,*p;
for(i=0;i<M+2;i++)
{for(j=0;j<N+2;j++)
{pre=G->adjlist[i][j].firstarc;
if(pre!=NULL)
{p=pre->nextarc;
while(p!=NULL)
{free(pre);
pre=p;p=p->nextarc;
}
free(pre);
}
}

free(G);}
}
void FindPath(ALGraph*G,int xi,int yi,int xe,int ye,PathType path)
{
ArcNode *p;
//置已访问标记
visited[xi][yi]=1;
path.data[path.length].i=xi;path.data[path.length].j=yi;path.length++;
if(xi==xe&&yi==ye)
{printf("迷宫路径%d:",++count);
for(int k=0;k<path.length;k++)
{printf("(%d,%d)",path.data[k].i,path.data[k].j);}
printf("\n");
}
p=G->adjlist[xi][yi].firstarc;
//p指向顶点v的第一条边顶点
while(p!=NULL)
{if(visited[p->i][p->j]==0)
//若(p->i,p->j)方块未访问，递归访问它
{FindPath(G,p->i,p->j,xe,ye,path);}
p=p->nextarc;
}
//p指向顶点v的下一条边顶点
visited[xi][yi]=0;
}
int main()
{  ALGraph *G;

int mg[M+2][N+2]={
//图3.9的迷宫数组
{1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},
{1,0,0,0,1,1},{1,1,0,0,0,1},{1,1,1,1,1,1}};

CreateAdj(G,mg);

printf("迷宫对应的邻接表：\n");DispAdj(G);PathType path;path.length=0;
//输出邻接表
printf("所有的迷宫路径：\n");FindPath(G,1,1,M,N,path);DestroyAdj(G);
return 1;
}