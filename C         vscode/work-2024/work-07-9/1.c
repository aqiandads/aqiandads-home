#include <stdio.h>

int r, c;
int cnt;
int visa[1000][1000];
char g[1000][1000];
int example[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int in(int x, int y) {
    return (x >= 0 && x < r && y >= 0 && y < c);
}

void fds(int x, int y) {
    visa[x][y] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int tx = x + example[i][0];
        int ty = y + example[i][1];
        if (in(tx, ty) && g[tx][ty] == '#' && visa[tx][ty] == 0) {
            fds(tx, ty);
        }
    }
}

int main() {
    
    scanf("%d %d", &r, &c);
    int max = 0;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%c", &g[i][j]);
        }
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visa[i][j] == 0 && g[i][j] == '#') {
                cnt = 0;
                fds(i, j);
                if (cnt > max) {
                    max = cnt;
                }
            }
        }
    }
    printf("%d", max);
    
    return 0;
}