/**
 * @file player.h
 * @author yangboyang@jisuanke.com
 * @copyright jisuanke.com
 * @date 2021-07-01
 */

#include <string.h>
#include "../include/playerbase.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int _time = 0;
int _time_ans = 0;
int _time_change;
char player_mat[20][20];
int example[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void init(struct Player *player) {
    // This function will be executed at the begin of each game, only once.
    if (player->row_cnt > player->col_cnt) {
        _time_change = 4 * player->row_cnt;
    } else {
        _time_change = 4 * player->col_cnt;
    }
   
    srand(time(0));
}

int step_isok(struct Player *player, int posx, int posy, int step) {
    if (step == 6) {
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        int dx = posx + example[i][0];
        int dy = posy + example[i][1];
        if (dx >= _time_ans && dx < (player->row_cnt - _time_ans) && 
            dy >= _time_ans && dy < (player->col_cnt - _time_ans) &&
            (player->mat[dx][dy] == '.' || 
             player->mat[dx][dy] == 'o' || 
             player->mat[dx][dy] == 'O')) {
            char mm = player->mat[dx][dy];
            player->mat[dx][dy] = '1';
            if (step_isok(player, dx, dy, step + 1) == 1) {
                player->mat[dx][dy] = mm;
                return 1;
            }
            player->mat[dx][dy] = mm;
		}
    }
    return 0;
}

struct Point walk(struct Player *player) {
	for (int i = 0; i < player->row_cnt; i++) {
		for (int j = 0; j < player->col_cnt; j++) {
            printf("%c", player->mat[i][j]);
            player_mat[i][j] = player->mat[i][j];
		}
		printf("\n");
    }
    // This function will be executed in each round.
    
    _time++;
    if (_time >= _time_change - 5) {
        _time_ans++;
        _time -= _time_change;
    }
    
    struct Point *ok_points = (struct Point *)malloc((player->row_cnt * player->col_cnt) * sizeof(struct Point));
    int ok_cnt = 0;
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int dx = player->your_posx + example[i][0];
        int dy = player->your_posy + example[i][1];
        if (dx >= _time_ans && dx < (player->row_cnt - _time_ans) && 
            dy >= _time_ans && dy < (player->col_cnt - _time_ans) &&
            (player->mat[dx][dy] == '.' || 
            player->mat[dx][dy] == 'o' || 
            player->mat[dx][dy] == 'O')) {
            flag = 1;
            if (step_isok(player, dx, dy, 0) == 1) {
                if (player->mat[dx][dy] == 'o' || player->mat[dx][dy] == 'O') {
                    return initPoint(dx, dy);
                }
                ok_points[ok_cnt++] = initPoint(dx, dy);
            }
        }
    }
    if (flag == 0) {
        return initPoint(player->your_posx, player->your_posy); 
    }
    struct Point point = initPoint(player->your_posx, player->your_posy); 
    if (ok_cnt > 0) {
        point = ok_points[rand() % ok_cnt];
    }
    free(ok_points);
	return point;
}