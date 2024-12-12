//文件名:exp7-11.cpp
#include "btree.cpp"				//包含二叉树的基本运算算法
#include "sqstring.cpp"				//包含顺序串的基本运算算法
int i=0;							//全局变量
SqString PreOrderSeq(BTNode *b)  	//由二叉链b产生先序序列化序列str
{
	SqString str,str1,leftstr,rightstr;
	if (b==NULL)
	{
		StrAssign(str,"#");
		return str;
	}
	str.data[0]=b->data; str.length=1;	//构造只有b->data字符的字符串str
	leftstr=PreOrderSeq(b->lchild);
	str1=Concat(str,leftstr);
	rightstr=PreOrderSeq(b->rchild);
	str=Concat(str1,rightstr);
	return str;
}
BTNode *CreatePreSeq(SqString str)		//由先序序列化序列str创建二叉链并返回根结点
{
	BTNode *b;
	char value;
	if (i>=str.length)					//i超界返回空
		return NULL;
	value=str.data[i]; i++;				//从str中取出一个字符value
	if (value=='#')						//若value为'#'，返回空
		return NULL;
	b=(BTNode *)malloc(sizeof(BTNode));	//创建根结点
	b->data=value;
	b->lchild=CreatePreSeq(str);		//递归构造左子树
	b->rchild=CreatePreSeq(str);		//递归构造右子树
	return b;							//返回根结点
}
void GetNext(SqString t,int next[])	//由模式串t求出next值
{	int j,k;
	j=0;k=-1;next[0]=-1;
	while (j<t.length-1)
	{	if (k==-1 || t.data[j]==t.data[k]) 	//k为-1或比较的字符相等时
		{	j++;k++;
			next[j]=k;
		}
		else  k=next[k];
	}
}
int KMPIndex(SqString s,SqString t)	//KMP算法
{
	int next[MaxSize],i=0,j=0;
	GetNext(t,next);
	while (i<s.length && j<t.length) 
	{	if (j==-1 || s.data[i]==t.data[j]) 
		{	i++;
			j++;				//i,j各增1
		}
		else j=next[j]; 		//i不变,j后退
	}
	if (j>=t.length)
		return(i-t.length);		//返回匹配模式串的首字符下标
	else
		return(-1);				//返回不匹配标志
}