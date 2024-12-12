//�ļ���:exp7-11.cpp
#include "btree.cpp"				//�����������Ļ��������㷨
#include "sqstring.cpp"				//����˳�򴮵Ļ��������㷨
int i=0;							//ȫ�ֱ���
SqString PreOrderSeq(BTNode *b)  	//�ɶ�����b�����������л�����str
{
	SqString str,str1,leftstr,rightstr;
	if (b==NULL)
	{
		StrAssign(str,"#");
		return str;
	}
	str.data[0]=b->data; str.length=1;	//����ֻ��b->data�ַ����ַ���str
	leftstr=PreOrderSeq(b->lchild);
	str1=Concat(str,leftstr);
	rightstr=PreOrderSeq(b->rchild);
	str=Concat(str1,rightstr);
	return str;
}
BTNode *CreatePreSeq(SqString str)		//���������л�����str���������������ظ����
{
	BTNode *b;
	char value;
	if (i>=str.length)					//i���緵�ؿ�
		return NULL;
	value=str.data[i]; i++;				//��str��ȡ��һ���ַ�value
	if (value=='#')						//��valueΪ'#'�����ؿ�
		return NULL;
	b=(BTNode *)malloc(sizeof(BTNode));	//���������
	b->data=value;
	b->lchild=CreatePreSeq(str);		//�ݹ鹹��������
	b->rchild=CreatePreSeq(str);		//�ݹ鹹��������
	return b;							//���ظ����
}
void GetNext(SqString t,int next[])	//��ģʽ��t���nextֵ
{	int j,k;
	j=0;k=-1;next[0]=-1;
	while (j<t.length-1)
	{	if (k==-1 || t.data[j]==t.data[k]) 	//kΪ-1��Ƚϵ��ַ����ʱ
		{	j++;k++;
			next[j]=k;
		}
		else  k=next[k];
	}
}
int KMPIndex(SqString s,SqString t)	//KMP�㷨
{
	int next[MaxSize],i=0,j=0;
	GetNext(t,next);
	while (i<s.length && j<t.length) 
	{	if (j==-1 || s.data[i]==t.data[j]) 
		{	i++;
			j++;				//i,j����1
		}
		else j=next[j]; 		//i����,j����
	}
	if (j>=t.length)
		return(i-t.length);		//����ƥ��ģʽ�������ַ��±�
	else
		return(-1);				//���ز�ƥ���־
}