#include <stdio.h>
#define inf 0x3f3f3f3f

struct node {
    int x, y; // 顶点的坐标
};
struct edge {
    int v, next, f; // 目标顶点、下一条边的索引、边的状态（1表示有效、0表示无效）
    double w; // 边的权重
};

int n, m; // 顶点数和边数
struct node a[205]; // 存储顶点的坐标信息
struct edge e[40005]; // 存储图的边信息
int p[205], eid, s; // 邻接表、边的计数器、起点
int vis[205], pre[205]; // 标记数组、前驱数组
int path[205], cnt; // 存储最短路径的顶点序列、路径长度计数
double d[205], min;

void insert(int u, int v, double w) {
    struct edge t = {v, p[u], 1, w};
    e[eid] = t;
    p[u] = eid++;
}
void insert2(int u, int v, double w) {
    insert(u, v, w);
    insert(v, u, w);
}

double dist(int u, int v) {
    double dx = a[u].x - a[v].x;
    double dy = a[u].y - a[v].y;
    return sqrt(dx * dx + dy * dy);
}
void getpath(int x) {
    if (x == 1) {
        path[cnt] = 1;
        return;
    }
    path[cnt++] = x;
    getpath(pre[x]);
}

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        d[i] = inf;
    }
    memset(vis, 0, sizeof(vis));
    s = 1;
    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        double mind = inf;
        int u = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && d[j] < mind) {
                mind = d[j];
                u = j;
            }
        }
        if (mind == inf) break;
        vis[u] = 1;
        for (int j = p[u]; ~j; j = e[j].next) {
            if (e[j].f) {
                int v = e[j].v;
                if (d[v] > d[u] + e[j].w) {
                    d[v] = d[u] + e[j].w;
                    pre[v] = u;
                }
            }
        }
    }
    if (d[n] < min) min = d[n];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    memset(p, -1, sizeof(p));
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        insert2(u, v, dist(u, v));
    }
    dijkstra();
    getpath(n);
    min = inf;
    for (int i = 0; i < cnt; i++) {
        int u1 = path[i], v1 = path[i + 1];
        for (int j = p[u1]; ~j; j = e[j].next) {
            if (e[j].v == v1) {
                e[j].f = 0; // 删除最短路径上的一条边
                e[j ^ 1].f = 0; // 无向图两条边序号相邻，用抑或处理
                dijkstra(); // 重新计算最短路径
                e[j].f = 1;
                e[j ^ 1].f = 1;
            }
        }
    }
    if (min == inf)
        printf("-1");
    else
        printf("%.2f", min);
    return 0;
}