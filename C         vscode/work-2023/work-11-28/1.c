#include <stdio.h>
#include <string.h>

void replace(char *str, char *fstr, char *rstr); 

int main() {
    char original_str[] = "iffordowhileelsewhilebreak";
    char search_str[] = "while";
    int a = strcmp(original_str + 18,search_str);
    printf("a = %d",a);
}