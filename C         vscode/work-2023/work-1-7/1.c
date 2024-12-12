#include<stdio.h>

int main(){
    int x[3][3] = {{1,2},{3,4},{5,6}};
    int (*p)[3] = x;
    int *a = x;
    printf("%d %d\n",*p,**p);
    p++;
    printf("%d %d\n",*p,**p);
    p++;
    printf("%d %d\n",*p,**p);
    printf("%d\n",*a);
    a++;
    printf("%d\n",*a);
    a++;
    printf("%d\n",*a);
    a++;
    printf("%d\n",*a);

    return 0;
}