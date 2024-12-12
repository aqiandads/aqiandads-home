#include<stdio.h>

void Swap(int *a,int *b);

int main(){
  int a[10];
  for(int i = 0;i < 10;i++){
    scanf("%d",&a[i]);
  }
  int t = 0,max = a[0],m = 0,min = a[0];
  for(int i = 1;i < 10;i++){
    if(max < a[i]){
      max = a[i];
      t = i;
    }
    if(min > a[i]){
      min = a[i];
      m = i;
    }
  }
  printf("%d %d ",a[t],a[m]);

  Swap(&a[t],&a[m]);

  printf("%d %d ",a[t],a[m]);

  printf("\n");

  for(int i = 0;i < 10;i++){
    printf("%d ",a[i]);
  }
  
}

void Swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}