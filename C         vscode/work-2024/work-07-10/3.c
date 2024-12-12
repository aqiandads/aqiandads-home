#include <stdio.h>

char g[9][9];
int row[10][9];
int col[10][9];
int block[10][9];
int num[9][9];
int flag;

int charTonum(char a) {
    int n;
    n = (int)(a - '0');
    return n;
}
void initEvery() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (g[i][j] != '*') {
                num[i][j] = charTonum(g[i][j]);
                row[num[i][j]][i] = 1;
                col[num[i][j]][j] = 1;
                int n = i / 3 * 3 + j / 3;
                block[num[i][j]][n] = 1;
            }
        }
    }
}
int isOk() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (num[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}
void dfs() {
    if (flag == 1) {
        return;
    }
    if (isOk() == 1) {
        flag = 1;
        return;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (num[i][j] == 0) {
                for (int n = 1; n < 10; n++) {
                    if (row[n][i] == 0 && col[n][j] == 0 && block[n][i / 3 * 3 + j / 3] == 0) {
                        num[i][j] = n; row[n][i] = 1; col[n][j] = 1;
                        block[n][i / 3 * 3 + j / 3] = 1;
                        dfs();
                        num[i][j] = 0; row[n][i] = 0; col[n][j] = 0;
                        block[n][i / 3 * 3 + j / 3] = 0;
                    }
                }
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        scanf("%s", g[i]);
    }
    initEvery();
    dfs();
    if (flag) {
        printf("Yes");
    } else {
        printf("No");
    }
    
    /*for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }*/
    
    
    return 0;
}