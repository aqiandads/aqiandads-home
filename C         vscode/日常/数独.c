#include <stdio.h>
#include <stdlib.h>

struct node {
    int x, y, n;
} q[100];

int r;
int rid;
char g[9][9];
int row[10][9];
int col[10][9];
int block[10][9];
int num[9][9];
int flag;

int cmp(const void* a, const void* b) {
    return (*(struct node*)b).n - (*(struct node*)a).n;
}
void initEvery() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (g[i][j] != '*') {
                char a = g[i][j];
                int k;
                k = (int)(a - '0');
                num[i][j] = k;
                row[num[i][j]][i] = 1;
                col[num[i][j]][j] = 1;
                int n = i / 3 * 3 + j / 3;
                block[num[i][j]][n] = 1;
            }
        }
    }
}
void initQ() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (num[i][j] == 0) {
                int better = 0;
                for (int n = 1; n < 10; n++) {
                    better += row[n][i];
                    better += col[n][j];
                    better += block[n][i / 3 * 3 + j / 3];
                }
                struct node t = {i, j, better};
                q[r++] = t;
            }
        }
    }
}
void dfs() {
    if (flag == 1) {
        return;
    }
    if (rid == r) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", num[i][j]);
            }
            printf("\n");
        }
        flag = 1;
        return;
    }
    int i = q[rid].x;
    int j = q[rid].y;
    for (int n = 1; n < 10; n++) {
        if (row[n][i] == 0 && col[n][j] == 0 && block[n][i / 3 * 3 + j / 3] == 0) {
            num[i][j] = n; row[n][i] = 1; col[n][j] = 1;
            block[n][i / 3 * 3 + j / 3] = 1;
            rid++;
            dfs();
            rid--;
            num[i][j] = 0; row[n][i] = 0; col[n][j] = 0;
            block[n][i / 3 * 3 + j / 3] = 0;
        }
    }
    return;
}

int main() {
    printf("这是一个计算数独的程序(空的数字用\" * \"表示，按行输入的数字之间不要有空格)\n");
    for (int i = 0; i < 9; i++) {
        printf("请输入第%d行 :\n", i + 1);
        scanf("%s", g[i]);
    }
    initEvery();
    initQ();
    qsort(q, r, sizeof(struct node), cmp);
    dfs();
    
    return 0;
}