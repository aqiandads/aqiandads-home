#include "state.h"

struct node {
    int x, y;
}pre[600][2100];

int max = 0;
int min = 0x3f3f3f3f;
int min1;
int f[600][2100];
int industry[600][2100];
int len, height;
int vis[600][2100];
int example0[6][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, -1}};
int example1[6][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {1, 1}};

void init_State(struct State *s) {
    // TODO
    
}
void delete_State(struct State *s) {
    // TODO
}
void parse(struct State *s, struct PNG *p) {
    // TODO 
    for (int i = 0; ; i++) {
        int x = 4 + 8 * i;
        int y;
        if (i % 2 == 0) {
            y = 4;
        } else {
            y = 8;
        }
        int j = 0;
        for (; ; j++) {
            struct PXL *image = get_PXL(p, x, y);
            if (image == NULL) {
                break;
            }
            int r = image->red;
            int g = image->green;
            int b = image->blue;
            industry[i][j] = 255 * 255 * 3 - r * r - g * g - b * b;
            f[i][j] = 1;
        }
        if (j == 0) {
            height = i - 1;
            break;
        } else {
            len = j - 1;
        }
    }
    for (int i = 0; i <= height; i++) {
        if (i % 2 == 1) {
            f[i][len] = -1;
        }
    }
    delete_PNG(p);
    for (int i = 0; i <= height; i++) {
        max += industry[i][0];
    }
    for (int j = 0; j <= len - 1; j++) {
        max += industry[height][j];
    }
    
}

int in(int x, int y) {
    if (y % 2 == 0) {
        return (x >= 0 && x <= height && y >= 0 && y <= len);
    } else {
        return (x >= 0 && x <= height && y >= 0 && y <= len - 1);
    }
}

int h(int x, int y) {
    int sum = 0;
    for (int i = x; i <= height; i++) {
        sum += industry[i][y];
    }
    for (int i = y; i <= len - 1; i++) {
        sum += industry[height][i];
    }
    sum -= industry[x][y];
    return sum; 
}

void dfs(int x, int y, int sum) {
    if (sum + h(x, y) > max) return;
    if (sum >= min) {
        return;
    }
    if (x == height && y == len - 1) {
        min = sum;
        return;
    }
    vis[x][y] = 1;
    if (x % 2 == 0) {
        for (int i = 0; i < 6; i++) {
            int tx = x + example0[i][0];
            int ty = y + example0[i][1];
            if (f[tx][ty] == -1) {
                continue;
            }
            if (in(tx, ty) && !vis[tx][ty]) {
                vis[tx][ty] = 1;
                pre[tx][ty].x = x;
                pre[tx][ty].y = y;
                dfs(tx, ty, sum + industry[tx][ty]);
                vis[tx][ty] = 0;
                pre[tx][ty].x = 0;
                pre[tx][ty].y = 0;
            }
        }
    } else {
        for (int i = 0; i < 6; i++) {
            int tx = x + example1[i][0];
            int ty = y + example1[i][1];
            if (f[tx][ty] == -1) {
                continue;
            }
            if (in(tx, ty) && !vis[tx][ty]) {
                vis[tx][ty] = 1;
                dfs(tx, ty, sum + industry[tx][ty]);
                vis[tx][ty] = 0;
            }
        }
    }
}

int solve1(struct State *s) {
    // TODO
    dfs(0, 0, industry[0][0]);
    return min;
}
int solve2(struct State *s) {
    // TODO
    min = min1 = 0x3f3f3f3f;
    for (int x = pre[height][len - 1].x, y = pre[height][len - 1].y; 
        x != 0 || y != 0; x = pre[x][y].x, y = pre[x][y].y) {
        f[x][y] = -1;
        dfs(0, 0, industry[0][0]);
        f[x][y] = 1;
        if (min1 > min) {
            min1 = min;
        }
    }
    return min1;
}