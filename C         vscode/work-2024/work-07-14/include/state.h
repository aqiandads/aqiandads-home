#ifndef STATE_H_
#define STATE_H_
#include "suan_png.h"
#include "pxl.h"


struct State {
    // data structure
    //int f[600][2100];
    //int industry[600][2100];
};

// function
int in(int x, int y);
int h(int x, int y);
void dfs(int x, int y, int sum);

void init_State(struct State *s);
void delete_State(struct State *s);
void assign(struct State *a, struct State *b);
void parse(struct State *s, struct PNG *p);
int solve1(struct State *s);
int solve2(struct State *s);

#endif
