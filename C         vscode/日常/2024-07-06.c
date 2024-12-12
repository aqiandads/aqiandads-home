#include <stdio.h>
#include <stdlib.h>

#define MAX_SHOPS 100000

typedef struct {
    int shopId;
    long int income;
    long int expense;
} ShopRecord;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    ShopRecord shops[MAX_SHOPS + 1]; // +1 for 0-indexing
    for (int i = 1; i <= n; i++) {
        shops[i].shopId = i;
        shops[i].income = 0;
        shops[i].expense = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        shops[a].expense += c; // 店铺a向b支付c万元，所以a的支出增加c万元
        shops[b].income += c;  // 店铺b收到c万元，所以b的收入增加c万元
    }

    long int maxTotal = -1;
    int maxShop = -1;
    for (int i = 1; i <= n; i++) {
        int total = shops[i].income + shops[i].expense;
        if (total > maxTotal || (total == maxTotal && i < maxShop)) {
            maxTotal = total;
            maxShop = i;
        }
    }

    printf("%d\n", maxShop);
    return 0;
}