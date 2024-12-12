#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MaxSize 50001
typedef int KeyType;
void swap(KeyType &x,KeyType &y)
{KeyType tmp=x;
x=y;y=tmp;
}
void initial(int R[],int low,int high)
{  int i;
srand((unsigned)time(NULL));
for(i=low;i<high;i++)
R[i]=rand()%99+1;
}
void copy(int R[],int R1[],int n)
{  for(int i=0;i<n;i++)
R1[i]=R[i];
}
void copy1(int R[],int R1[],int n)
{  for(int i=0;i<n;i++)
R1[i+1]=R[i];
}
bool test(KeyType R[],int low,int high)
{  int i;
for(i=low;i<high-1;i++)
if(R[i]>R[i+1])
return false;
return true;
}
//-------直接插入排序--
void InsertSort(KeyType R[],int n)
{  int i,j;KeyType tmp;
for(i=1;i<n;i++)
{  if(R[i]<R[i-1])
{  tmp=R[i];
j=i-1;
do
{  R[j+1]=R[j];
j--;
}while (j>=0 &&R[j]>tmp);
R[j+1]=tmp;
}
}
}
void InsertSortTime(KeyType R[],int n)
//求直接插入排序的时间
{clock_t t;
printf("直接插入排序\t");
t=clock();
InsertSort(R,n);
t=clock()-t;
printf("%lf秒",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
printf("\t正确\n");
else
printf("\t错误\n");
}
void BinInsertSort(KeyType R[],int n)
{  int i,j,low,high,mid;
KeyType tmp;
for(i=1;i<n;i++)
{  if(R[i]<R[i-1])
//反序时//将R[i]保存到tmp中
{  tmp=R[i];
low =0;high=i-1;
while(low<=high)
//在R[low..high]中查找插入的位置//取中间位置
{  mid=(low+high)/2;
if(tmp<R[mid])
high=mid-1;
//插入点在左半区
else
low=mid+1;
//插入点在右半区
}
//找位置high
for(j=i-1;j>=high+1;j--)
//集中进行元素后移
R[j+1]=R[j];
R[high+1]=tmp;
//插入tmp
}
}
}
void BinInsertSortTime(KeyType R[],int n)
//求折半插入排序的时间
{  clock_t t;
printf("折半插入排序\t");
t=clock();
BinInsertSort(R,n);
t=clock()-t;
printf("%lf秒",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
//排序结果正确性验证
printf("\t正确\n");
else
printf("\t错误\n");
}
void ShellSort(KeyType R[],int n)
{  int i,j,d;
KeyType tmp;
d=n/2;
while(d>0)
{  for(i=d;i<n;i++)
{  tmp=R[i];
j=i-d;
while(j>=0 &&tmp<R[j])
{  R[j+d]=R[j];
j=j-d;
}
R[j+d]=tmp;
}
d=d/2;
}
}
void ShellSortTime(KeyType R[],int n)
{  clock_t t;
printf("希尔排序\t");
t=clock();
ShellSort(R,n);
t=clock()-t;
printf("%lf秒",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
//排序结果正确性验证
printf("\t正确\n");
else
printf("\t错误\n");
}
//--------冒泡排序算法--
void BubbleSort(KeyType R[],int n)
{  int i,j;
bool exchange;
for(i=0;i<n-1;i++)
{  exchange=false;
//一趟前exchange置为假//归位R[i],循环n-i-1次//相邻两个元素反序时
for(j=n-1;j>i;j--)
if(R[j]<R[j-1])
{  swap(R[j],R[j-1]);
//将R[j]和R[j-1]两个元素交换//一旦有交换，exchange置为真
exchange =true;
}
if(!exchange)
//本趟没有发生交换，中途结束算法
return;
}
}
void BubbleSortTime(KeyType R[],int n)
{  clock_t t;
printf("冒泡排序\t");t=clock();BubbleSort(R,n);t=clock()-t;
printf("%lf秒",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
printf("\t正确\n");
else printf("\t错误\n");
}
//--------快速排序算法--
int partition(KeyType R[],int s,int t)
{  int i=s,j=t;
KeyType tmp=R[i];
//以R[i]为基准//从两端交替向中间扫描，直至i=j为止
while(i<j)
{  while(j>i&&R[j]>=tmp)
j--;
//从右向左扫描，找一个小于tmp的R[j]//找到这样的R[j],放入R[i]处
R[i]=R[j];
while(i<j&&R[i]<=tmp)
i++;
//从左向右扫描，找一个大于tmp的R[i]//找到这样的R[i],放入R[j]处
R[j]=R[i];
}
R[i]=tmp;
return i;
}
void QuickSort(KeyType R[],int s,int t)
{  int i;
if(s<t)
{  i=partition(R,s,t);
QuickSort(R,s,i-1);
//对左区间递归排序
QuickSort(R,i+1,t);
//对右区间递归排序
}
}
void QuickSortTime(KeyType R[],int n)
//求快速排序算法的时间
{  clock_t t;
printf("快速排序\t");
t=clock();
QuickSort(R,0,n-1);
t=clock()-t;
printf("%lf秒",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
//排序结果正确性验证
printf("\t正确\n");
else
printf("\t错误\n");
}
void SelectSort(KeyType R[],int n)
{  int i,j,k;
for(i=0;i<n-1;i++)
//做第i趟排序
{  k=i;
for(j=i+1;j<n;j++)
//在当前无序区R[i..n-1]中选key最小的R[k]
if(R[j]<R[k])
k=j;
//k记下目前找到的最小关键字所在的位置//R[i]和R[k]两个元素交换
if(k!=i)
swap(R[i],R[k]);
}
}
void SelectSortTime(KeyType R[],int n)
//求简单选择排序算法的时间
{  clock_t t;
printf("简单选择排序\t");t=clock();SelectSort(R,n);t=clock()-t;
printf("%lf秒",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))printf("\t正确\n");
else printf("\t错误\n");
}
void sift(KeyType R[],int low,int high)
{  int i=low,j=2*i;
//R[j]是R[i]的左孩子
KeyType tmp=R[i];
while(j<=high)
{  if(j<high &&R[j]<R[j+1])//若右孩子较大，把j指向右孩子
j++;
if(tmp<R[j])
//若根结点小于最大孩子的关键字//将R[j]调整到双亲结点位置上//修改i和j值，以便继续向下筛选
{  R[i]=R[j];
i=j;
j=2*i;
}
else break;
//若根结点大于等于最大孩子关键字，筛选结束//被筛选结点放入最终位置上
}
R[i]=tmp;
}
void HeapSort(KeyType R[],int n)
//堆排序
{  int i;
for(i=n/2;i>=1;i--)
//循环建立初始堆，调用sift算法n/2次
sift(R,i,n);
for(i=n;i>=2;i--)
//进行n-1趟完成推排序，每一趟堆排序的元素个数减1//将最后一个元素与根R[1]交换
{  swap(R[1],R[i]);
sift(R,1,i-1);
//对R[1..i-1]进行筛选，得到i-1个结点的堆
}
}
void HeapSortTime(KeyType R[],int n)//求堆排序算法的时间
{  clock_t t;
printf("堆排序\t");
t=clock();
HeapSort(R,n);
t=clock()-t;
printf("        %lf秒",((float)t)/CLOCKS_PER_SEC);
if(test(R,1,n))
//排序结果正确性验证
printf("\t正确\n");
else
printf("\t错误\n");
}
void Merge(KeyType R[],int low,int mid,int high)
{  KeyType *R1;
int i=low,j=mid+1,k=0;
//k是R1的下标，i、j分别为第1、2段的下标
R1=(KeyType *)malloc((high-low+1)*sizeof(KeyType));
//动态分配空间
while(i<=mid &&j<=high)
//在第1段和第2段均未扫描完时循环
if(R[i]<=R[j])
//将第1段中的元素放入R1中
{  R1[k]=R[i];
i++;k++;
}
else
//将第2段中的元素放入R1中
{  R1[k]=R[j];
j++;k++;
}
while(i<=mid)
{  R1[k]=R[i];
i++;k++;
}
while(j<=high)
{  R1[k]=R[j];
j++;k++;
}
for(k=0,i=low;i<=high;k++,i++)
    R[i]=R1[k];
free(R1);
}
void MergePass(KeyType R[],int length,int n)
{  int i;
for(i=0;i+2*length-1<n;i=i+2*length)
Merge(R,i,i+length-1,i+2*length-1);
if(i+length-1<n-1)
Merge(R,i,i+length-1,n-1);
}
void MergeSort(KeyType R[],int n)
{int length;
for(length=1;length<n;length=2*length)
MergePass(R,length,n);
}
void MergeSortTime(KeyType R[],int n)
{  clock_t t;
printf("二路归并排序\t");
t=clock();
MergeSort(R,n);
t=clock()-t;
printf("%lf秒",((float)t)/CLOCKS_PER_SEC);
if(test(R,0,n-1))
printf("\t正确\n");
else
printf("\t错误\n");
}
int main()
{  KeyType R[MaxSize],R1[MaxSize];
printf("随机产生50000个1-99的正整数，各种排序方法的比较\n");
int n =50000;
printf("-----------------------------\n");
printf("排序方法     用时      结果验证\n");
printf("-----------------------------\n");
initial(R,0,n-1);
copy(R,R1,n);
InsertSortTime(R1,n);
copy(R,R1,n);
BinInsertSortTime(R1,n);
copy(R,R1,n);
ShellSortTime(R1,n);
copy(R,R1,n);
BubbleSortTime(R1,n);
copy(R,R1,n);
QuickSortTime(R1,n);
copy(R,R1,n);
SelectSortTime(R1,n);copy1(R,R1,n);HeapSortTime(R1,n);
copy(R,R1,n);
MergeSortTime(R1,n);printf("---------\n");
return 1;
}