#include <stdio.h>
#define inf 0x3f3f3f3f

struct node {
    int x, y; // ���������
};
struct edge {
    int v, next, f; // Ŀ�궥�㡢��һ���ߵ��������ߵ�״̬��1��ʾ��Ч��0��ʾ��Ч��
    double w; // �ߵ�Ȩ��
};

int n, m; // �������ͱ���
struct node a[205]; // �洢�����������Ϣ
struct edge e[40005]; // �洢ͼ�ı���Ϣ
int p[205], eid, s; // �ڽӱ��ߵļ����������
int vis[205], pre[205]; // ������顢ǰ������
int path[205], cnt; // �洢���·���Ķ������С�·�����ȼ���
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
                e[j].f = 0; // ɾ�����·���ϵ�һ����
                e[j ^ 1].f = 0; // ����ͼ������������ڣ����ֻ���
                dijkstra(); // ���¼������·��
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