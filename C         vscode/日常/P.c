#include <stdio.h>
#include <math.h>

int n;
int ans;
int q[100000];
int visa[7][7];
int num;
int example[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y, int step, int sum) {
    if (x == n - 1 && y == 0) {
        if (step != n * n) {
            return;
        }
        for (int i = 0; i < ans; i++) {
            if (q[i] == sum) {
                return;
            }
        }
        if (ans == 100000) {
            printf("No");
            return;
        }
        q[ans++] = sum;
    }
    for (int i = 0; i < 4; i++) {
        int tx = x + example[i][0];
        int ty = y + example[i][1];
        if (in(x, y) && !visa[tx][ty]) {
            visa[tx][ty] = 1;
            dfs(tx, ty, step + 1, sum + (step * (x + 1) * (y + 1)) * (step * (x + 700) * (y + 1000)));
            visa[tx][ty] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    visa[0][0] = 1;
    dfs(0, 0, 1, 0);
    
    printf("%d", ans);
    
    return 0;
}