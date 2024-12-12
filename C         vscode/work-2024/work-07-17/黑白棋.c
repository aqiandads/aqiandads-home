/**
/**
 * @file computer.h
 * @author hanweifan@jisuanke.com
 * @copyright jisuanke.com
 * @date 2023-06-30
 */

#include <string.h>
#include "../include/playerbase.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int priority[20][20];
void set_corners(int x, int y) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            priority[x + i][y + j] = 1;
        }
    }
}
void init(struct Player *player) {
    // This function will be executed at the begin of each game, only once.
    srand(time(0));
    
    int row = player->row_cnt;
    int col = player->col_cnt;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            priority[i][j] = 4;
        }
    }
    set_corners(0, 0), set_corners(0, col - 2);
    set_corners(row - 2, 0), set_corners(row - 2, col - 2);
    priority[0][0] = priority[0][col-1] = priority[row-1][0] = priority[row-1][col-1] = 9;
    for (int i = 2; i < col - 2; i++) {
        priority[0][i] = priority[row - 1][i] = 5;
        priority[1][i] = priority[row - 2][i] = 3;
    }
    for (int i = 2; i < row - 2; i++) {
        priority[i][0] = priority[i][col - 1] = 5;
        priority[i][1] = priority[i][col - 2] = 3;
    }
}
int is_valid(struct Player *player, int posx, int posy) {
    if (posx < 0 || posx >= player->row_cnt || posy < 0 || posy >= player->col_cnt) {
        return 0;
    }
    if (player->mat[posx][posy] == 'o' || player->mat[posx][posy] == 'O') {
        return 0;
    }
    int step[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, -1, -1, 1, -1, -1, 1};
    int ans = 0;//记录翻转的棋子个数
    for (int dir = 0;  dir < 8; dir++) {
        int t_ans = ans;//暂存ans
        int x = posx + step[dir][0];
        int y = posy + step[dir][1];
        if (x < 0 || x >= player->row_cnt || y < 0 || y >= player->col_cnt) {
            continue;
        }
        if (player->mat[x][y] != 'o') {
            continue;
        }
        while (true) {
            t_ans++;
            x += step[dir][0];
            y += step[dir][1];
            if (x < 0 || x >= player->row_cnt || y < 0 || y >= player->col_cnt || (player->mat[x][y] >= '1' && player->mat[x][y] <= '9')) {
                break;
            }
            if (player->mat[x][y] == 'O') {
                ans = t_ans;
                break;
            }
        }
    }
    
    if (ans == 0) {
        return 0;
    }
    
    return ans + priority[posx][posy];
}

struct Point place(struct Player *player) {
    struct Point *ok_points = (struct Point *)malloc((player->row_cnt * player->col_cnt) * sizeof(struct Point));
    int ok_cnt = 0;
    int top = 1;//记录最大翻转棋子数
	for (int i = 0; i < player->row_cnt; i++) {
        for (int j = 0; j < player->col_cnt; j++) {
            int t_is_valid = is_valid(player, i, j);
            
            if ((i == 0 || i == player->row_cnt - 1) &&
                (j == 0 || j == player->col_cnt - 1) &&
                t_is_valid != 0) {
                struct Point point = initPoint(i, j);
                return point;
            }
            
            if (t_is_valid >= top) {
                if (t_is_valid > top) {
                    ok_cnt = 0;
                    top = t_is_valid;
                    ok_points[ok_cnt++] = initPoint(i, j);
                } else {
                    ok_points[ok_cnt++] = initPoint(i, j);
                }
            }
        }
    }
    struct Point point = initPoint(-1, -1); 
    if (ok_cnt > 0) {
        point = ok_points[rand() % ok_cnt];
    }
    free(ok_points);
	return point;
}