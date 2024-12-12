#include<stdio.h>

void InputArray(int *p,int m,int n);
int FindMax(int *p,int m,int n,int *pRow,int *pCol);

int main(){
    int a[10][10],m,n,row,col,max;
    printf(" ‰»Îm,n:\n");
    scanf("%d %d",&m,&n);
    InputArray(a,m,n);
    max = FindMax(a,m,n,&row,&col);
    printf("max = %d,row = %d,col = %d",max,row,col);
}

void InputArray(int *p,int m,int n){
    int i,j;
    printf(" ‰»Î%d*%dµƒæÿ’Û:\n",m,n);
    for(i = 0;i < m;i++){
        for(j = 0;j < n;j++){
            scanf("%d",&p[i*n + j]);
        }
    }
}

int FindMax(int *p,int m,int n,int *pRow,int *pCol){
    int i,j,max = p[0];
    *pRow = 0;
    *pCol = 0;
    for ( i = 0; i < m; i++){
        for(j = 0;j < n;j++){
            if(p[i*n + j] > max){
                max = p[i * n + j];
                *pRow = i;
                *pCol = j;
            }
        }
    }
    return max;
}