#include<stdio.h>

void Input(int *p,int m,int n);
int FindMax(int *p,int m,int n,int *pRow,int *pCol);

int main(){
    int *cheng,m,n,row,col,max;
    printf("输入m,n:\n");
    scanf("%d %d",&m,&n);
    cheng = (int*)calloc(m*n,sizeof(int));
    Input(cheng,m,n);
    max = FindMax(cheng,m,n,&row,&col);
    printf("max = %d,第%d班,第%d个学生",max,row + 1,col + 1);
    free(cheng);
}

void Input(int *p,int m,int n){
    int i,j;
    printf("输入%d*%d的学生成绩:\n",m,n);
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