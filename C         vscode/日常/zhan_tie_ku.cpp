#include<bits/stdc++.h>
#include"ku.h"
#include<Windows.h>
using namespace std;
//参考链接
//https://www.cnblogs.com/rosesmall/p/5759804.html#:~:text=Windows%E6%8F%90%E4%BE%9B%E4%BA%86%E4%B8%80%E4%B8%AA%E6%A8%A1%E6%8B%9F%E9%94%AE%E7%9B%98API%E5%87%BD%E6%95%B0Keybd_event%EF%BC%88%EF%BC%89%EF%BC%8C%E8%AF%A5%E5%87%BD%E6%95%B0%E8%83%BD%E8%A7%A6%E5%8F%91%E4%B8%80%E4%B8%AA%E6%8C%89%E9%94%AE%E4%BA%8B%E4%BB%B6%EF%BC%8C%E4%B9%9F%E5%B0%B1%E6%98%AF%E8%AF%B4%E4%BC%9A%E4%BA%A7%E7%94%9F%E4%B8%80%E4%B8%AAWM_KEYDOWN%E6%88%96WM_KEYUP%E6%B6%88%E6%81%AF%E3%80%82%20%5BDllImport%20%28%22user32.dll%22%2C%20EntryPoint%20%3D%20%22keybd_event%22%29%5D,public%20static%20extern%20void%20keybd_event%20%28
//https://www.codeleading.com/article/16143337113/#:~:text=%E5%9C%A8C%2FC%2B%2B%E4%B9%8B%E4%B8%AD,%E5%87%BD%E6%95%B0%E7%9A%84%E4%BD%BF%E7%94%A8%E5%A6%82%E4%B8%8B%E3%80%82
//https://learn.microsoft.com/en-us/windows-hardware/customize/enterprise/keyboardfilter-key-names
void down(int vk)//按下一个键
{
	keybd_event(vk,0,0,0);
}
void up(int vk)//松开一个键
{
	keybd_event(vk,0,KEYEVENTF_KEYUP,0);
}

void press(int vk)
{
	if(ku[vk]/1000){
		down(16);
		down(ku[vk]%1000);
		up(ku[vk]%1000);
		up(16);
	}else{
		down(ku[vk]%1000);
		up(ku[vk]%1000);
	}
}
int main()
{
	cout<<"Only most English characters are supported.\nPlease switch to English input method.\nPlease copy the content to be pasted into this interface.\n(Just press ctrl+V and ENTER, it is normal not to show)\nAfter moving the cursor to the place where it needs to be pasted and press F8, some characters may not be pasted.\nBY:bian_xie\n";

//	freopen("in.txt","r",stdin);
	char a;
//	while(scanf("%c",&a)!=-1)//读取字符
//	{
	while(!GetKeyState(119));//检测F8是否按下
	while(1)
	{
		char a[100007];
		memset(a,0,sizeof(a));
		gets(a);
		while(GetKeyState(119)>=0);//检测F8是否按下
		for(int i=0; i<strlen(a); i++)
		{
			press((int)a[i]);
		}
		keybd_event(VK_RETURN,0,0,0);
		keybd_event(VK_RETURN,0,KEYEVENTF_KEYUP,0);
	}
}