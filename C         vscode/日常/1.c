#include <stdio.h>
#include <string.h>
#include <math.h>

struct node {
    int v;
    double w;
    int next;
    int f;
} e[100000];
struct node1 {
    int x, y;
} point[201];

int n, m;
int eid = 1;
int h[201];
double d[201];
int in_q[201];
int q[100000];
int pre[201][2];

void insert(int u, int v) {
    double tx = point[u].x - point[v].x;
    double ty = point[u].y - point[v].y;
    double sum = tx * tx + ty * ty;
    sum = pow(sum, 0.5);
    e[eid].v = v;
    e[eid].w = sum;
    e[eid].next = h[u];
    e[eid].f = 1;
    h[u] = eid++;
}
void Insert(int u, int v) {
    insert(u, v);
    insert(v, u);
}
double spfa() {
    for (int i = 0; i <= 201; i++) {
        d[i] = 1000000000.00;
    }
    int l, r;
    l = r = 0;
    q[r++] = 1;
    d[1] = 0;
    in_q[1] = 1;
    while (l < r) {
        int u = q[l++];
        in_q[u] = 0;
        for (int i = h[u]; i; i = e[i].next) {
            if (e[i].f == 0) {
                continue;
            }
            int v = e[i].v;
            double w = e[i].w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pre[v][0] = u;
                pre[v][1] = i;
                if (!in_q[v]) {
                    q[r++] = v;
                    in_q[v] = 1;
                }
            }
        }
    }
    if (d[n] < 1000000000.00) {
        return d[n];
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &point[i].x, &point[i].y);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        Insert(u, v);
    }
    //spfa();
    printf("%.2f\n", spfa());
    double min = 1000000000.00;
    for (int i = n; i != 1; i = pre[i][0]) {
        int j = pre[i][1];
        e[j].f = 0;
        double mm = spfa();
        if (mm < min) {
            min = mm;
        }
        e[j].f = 1;
    }
    printf("%.2f", spfa());
    
    return 0;
}