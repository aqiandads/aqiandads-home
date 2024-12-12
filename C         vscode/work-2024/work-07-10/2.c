#include <stdio.h>

int n;
int p[21];
int sum;
int flag;

void dfs(int i, int x1, int x2, int x3, int x4) {
    if (flag == 1) {
        return;
    }
    if (x1 == sum && x2 == sum && x3 == sum && x4 == sum) {
        flag = 1;
        return;
    }
    if (x1 > sum || x2 > sum || x3 > sum || x4 > sum) {
        return;
    }
    dfs(i + 1, x1 + p[i], x2, x3, x4);
    dfs(i + 1, x1, x2 + p[i], x3, x4);
    dfs(i + 1, x1, x2, x3 + p[i], x4);
    dfs(i + 1, x1, x2, x3, x4 + p[i]);
}

void dfs1(int i, int x) {
    if (flag == 2) {
        return;
    }
    if (x == sum) {
        flag = 2;
        return;
    }
    if (x > sum) {
        return;
    }
    dfs1(i + 1, x);
    dfs1(i + 1, x + p[i]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        sum += p[i];
    }
    sum = sum / 4;
    dfs(0, 0, 0, 0, 0);
    if (flag == 1) {
        printf("Yes");
    } else {
        printf("No");
    }
    
    
    return 0;
}