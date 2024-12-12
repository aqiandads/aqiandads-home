#include <stdio.h>

int main() {
    int n, m;
    long long int shops[100000] = {0};
    
    scanf("%d %d", &n, &m);

    int top;
    for (int i = 0; i < m; i++) {
        int shop1, shop2, moneys;
        scanf("%d %d %d", &shop1, &shop2, &moneys);
        shops[shop1 - 1] += moneys;
        shops[shop2 - 1] += moneys;
        if (shop1 > top) {
            top = shop1;
        }
        if (shop2 > top) {
            top = shop2;
        }
    }
    
    long long int max = 0;
    int pmax = 0;
    for (int i = 0; i < top; i++) {
        if (shops[i] > max) {
            max = shops[i];
            pmax = i + 1;
        }
    }
    printf("%d", pmax);
    

    return 0;
}