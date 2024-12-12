#include<stdio.h>

int main(){
  int a[5][5] = {0};
  a[0][2] = 1;
  int h = 0,l = 2;
  for(int i = 2;i <= 25;i++){
    if(h == 0){
      h = 5;
    }
    if(l == 4){
      l = -1;
    }
    if(a[h - 1][l + 1] != 0){
      a[h][l + 1] = i;
      l = l + 1;
    }else{
      a[h - 1][l + 1] = i;
      h = h - 1;
      l = l + 1;
    }
  }
  for(int i = 0;i <= 4;i++){
    for(int j = 0;j <= 4;j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
}