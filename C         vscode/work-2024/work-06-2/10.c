#include<stdio.h>
#include<string.h>
#define MaxL 100
//最大的字符串长度
typedef struct node
{
int start,length;
}RecType;

int StringComp(char S[],RecType A[],int s1,RecType tmp)//比较两个字符串的大小
{char str1[MaxL],str2[MaxL];
int i,j;
for(j=0,i=A[s1].start;i<A[s1].start+A[s1].length;i++,j++)
str1[j]=S[i];

str1[j]='\0';
for(j=0,i=tmp.start;i<tmp.start+tmp.length;i++,j++)
str2[j]=S[i];
//将tmp所指的字符申复制到str2中//字符串末尾置\0//调用标准字符申比较函数返回结果
str2[j]='\0';
return strcmp(str1,str2);
}
void QuickSort(char S[],RecType A[],int low,int high)
//实现快速排序
{int i,j;RecType tmp;
i=low;j=high;
if(low<high)
{tmp=A[low];
while(i!=j)
{ while(j>i&&StringComp(S,A,j,tmp)>0)j--;
A[i]=A[j];
while(i<j&& StringComp(S,A,i,tmp)<0)i++;
A[j]=A[i];
}
A[i]=tmp;
QuickSort(S,A,low,i-1);
QuickSort(S,A,i+1,high);
}
}
int main()
{int i,j,n=6;
char S[]={"whileifif-elsedo-whileforcase"};
RecType A[]={{0,5},{5,2},{7,7},{14,8},{22,3},{25,4}};
printf("排序前的字符串：\n");
for(i=0;i<n;i++)
{printf(" ");
for(j=A[i].start;j<A[i].start+A[i].length;j++)
printf("%c",S[j]);
printf("\n");
}
QuickSort(S,A,0,n-1);
printf("排序后的字符申：\n");
for(i=0;i<n;i++)
{printf(" ");
for(j=A[i].start;j<A[i].start+A[i].length;j++)
printf("%c",S[j]);
printf("\n");
}
return 1;
}