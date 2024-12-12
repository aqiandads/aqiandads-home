#include <stdio.h>
#include <stdbool.h>
#define MAX 10000
char out[MAX][21];

bool isSeven(int count) {
    if (count >= 100) {
        count = count % 100;
    }
    if (count % 7 == 0) {
        return true;
    }
    int num[20];
    int i = 0;
    while (count >= 10) {
        num[i] = count % 10;
        i++;
        count = count / 10;
    }
    num[i] = count;
    for (int j = 0; j <= i; j++) {
        if (num[j] == 7) {
            return true;
        }
    }
    return false;
}

void CountOff(int n, int r, int m) {
    for(int i = 0; i < n; i++) {
        scanf("%s", out[i]);
    }
    
    int index = r - 1;
    int count = m - 1;
    int round = 1;
    
    while (round < n) {
        if (out[index][0] != '1') {
            count++;
        }
        if (isSeven(count)) {
            out[index][0] = '1';
            round++;
        }
        index++;
        if (index >= n) {
            index = index % n;
        }                      
    }
    
    return ;
}

int main() {
    int n, r, m;
    
    scanf("%d %d %d", &n, &r, &m);
    CountOff(n, r, m);
        
    for (int i = 0; i < n; i++) {
        if (out[i][0] != '1') {
            printf("%s", out[i]);
            break;
        }
    }
    
    return 0;
}