#include "graph.cpp"
#define MAXE 100
typedef struct
{
int u;
int v;
int w;
}Edge;
int visited[MAXV];
void MDFS(MatGraph g,int v)
//�����ڽӾ����ͼ������ȱ���
{int w;
visited[v]=1;
//�÷��ʱ��
for(w=0;w<g.n;w++)
//�Ҷ���v�������ڽӵ�
if(g.edges[v][w]!=0 &&g.edges[v][w]!=INF &&visited[w]==0)
MDFS(g,w);
}
bool connect(MatGraph g)
//�ж�ͼg����ͨ��
{bool flag =true;
int k;
for(k=0;k<g.n;k++)visited[k]=0;
MDFS(g,0);
for(k=0;k<g.n;k++)
if(visited[k]==0)
flag=false;
return flag;
}

void spantree(MatGraph &g)
{int i,j,k,e;
k=0;
Edge tmp;
//��ȡͼ�����б���Ϣ
Edge edges[MAXE];
for(i=0;i<g.n;i++)
{for(j=0;j<i;j++)
{
    if(g.edges[i][j]!=0&&g.edges[i][j]!=INF)
{edges[k].u=i;edges[k].v=j;
edges[k].w=g.edges[i][j];k++;}
}
}
for(i=1;i<g.e;i++)
{if(edges[i].w>edges[i-1].w)
{tmp=edges[i];
j=i-1;
do
{edges[j+1]=edges[j];
j--;
}while(j>=0 &&edges[j].w<tmp.w);
edges[j+1]=tmp;
}
}
k=0;e=g.e;
while(e>=g.n)
{g.edges[edges[k].u][edges[k].v]=INF;
g.edges[edges[k].v][edges[k].u]=INF;
if(connect(g))
{e--;
printf("(%d)ɾ����(%d,%d):%d\n",
g.e-e,edges[k].u,edges[k].v,edges[k].w);
}
else
{
g.edges[edges[k].u][edges[k].v]=edges[k].w;
g.edges[edges[k].v][edges[k].u]=edges[k].w;}
k++;
}
g.e-=e;
}
int main()
{MatGraph g;
int A[MAXV][MAXV]={
{0,28,INF,INF,INF,10,INF},{28,0,16,INF,INF,INF,14},
{INF,16,0,12,INF,INF,INF},{INF,INF,12,0,22,INF,18},{INF,INF,INF,22,0,25,24},{10,INF,INF,INF,25,0,INF},
{INF,14,INF,18,24,INF,0}};
int n=7,e=9;
CreateMat(g,A,n,e);
printf("ͼG���ڽӾ���\n");DispMat(g);
printf("������С�������Ĺ��̣�\n");spantree(g);
printf("��С���������£�\n");DispMat(g);
//����ڽӾ���
return 1;
}
