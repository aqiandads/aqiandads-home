#include <stdio.h>
#include <string.h>
int num[26];

int main () {
    char s[2000];
    printf("ÇëÊäÈë×Ö·û´® :\n");
    scanf("%s", &s);
    char sstandard[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = strlen (s);
    
    printf ("×ÜÊı : %d\n", len);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            if (s[i] == sstandard[j]) {
                num[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%c : %d\n", sstandard[i], num[i]);
    }
}