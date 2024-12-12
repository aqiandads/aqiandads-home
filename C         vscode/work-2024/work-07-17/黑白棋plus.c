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

void init(struct Player *player) {
    // This function will be executed at the begin of each game, only once.
    srand(time(0));
    
    for (int i = 0; i < player->row_cnt; i++) {
        for (int j = 0; j < player->col_cnt; j++) {
            if (player->mat[i][j] == 'o' || 
                player->mat[i][j] == 'O') {
                priority[i][j] = 0;
                continue;
            }
            char _mat = player->mat[i][j];
            priority[i][j] = (int)_mat - 48;
        }
    }
}

int is_valid(struct Player *player, int posx, int posy, int status) {
    char M, N;
    if (status == 0) {
        M = 'O';
        N = 'o';
    } else if (status == 1) {
        M = 'o';
        N = 'O';
    }
    
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
        if (player->mat[x][y] != N) {
            continue;
        }
        while (true) {
            t_ans++;
            x += step[dir][0];
            y += step[dir][1];
            if (x < 0 || x >= player->row_cnt || y < 0 || y >= player->col_cnt || (player->mat[x][y] >= '1' && player->mat[x][y] <= '9')) {
                break;
            }
            if (player->mat[x][y] == M) {
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

int sec_is_valid(struct Player *player) {
    int top = 0;
    for (int i = 0; i < player->row_cnt; i++) {
        for (int j = 0; j < player->col_cnt; j++) {
            int t_is_valid = is_valid(player, i, j, 1);
            
            if ((i == 0 || i == player->row_cnt - 1) &&
                (j == 0 || j == player->col_cnt - 1) &&
                t_is_valid != 0) {
                return 100;
            }
            
            if (t_is_valid > top) {         
                top = t_is_valid;
            }
        }
    }
    return top;
}

struct Point place(struct Player *player) {
    struct Point *ok_points = (struct Point *)malloc((player->row_cnt * player->col_cnt) * sizeof(struct Point));
    int ok_t_is_valid[20];
    int ok_cnt = 0;
    int top = -0x3f3f3f3f;//记录最大翻转棋子数
	for (int i = 0; i < player->row_cnt; i++) {
        for (int j = 0; j < player->col_cnt; j++) {
            int t_is_valid = is_valid(player, i, j, 0);
            
            if ((i == 0 || i == player->row_cnt - 1) &&
                (j == 0 || j == player->col_cnt - 1) &&
                t_is_valid != 0) {
                struct Point point = initPoint(i, j);
                return point;
            }
            
            if (t_is_valid != 0) {
                char mm = player->mat[i][j];//暂存数据
                player->mat[i][j] = 'O';
                t_is_valid -= sec_is_valid(player);
                player->mat[i][j] = mm;
                if (t_is_valid < top) {
                    continue;
                }
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