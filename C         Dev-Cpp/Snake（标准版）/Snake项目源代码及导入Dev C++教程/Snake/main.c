#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>  
#include<time.h> 
#include<Windows.h>
#include<stdlib.h>  
#include<conio.h>  

#include "header.h"

/**
*1、设置光标位置
*/
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); 
}

/**
*2、更改文字颜色
*/
int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}

/**
*3、开始界面
*/
void welcomeToGame()
{
	int n;
	
	gotoxy(43, 10);
	color(11);
	printf("贪 吃 蛇 大 作 战");
	
	color(12);
	gotoxy(25, 22);
	printf("1.开始游戏");
	gotoxy(45, 22);
	printf("2.游戏说明");
	gotoxy(65, 22);
	printf("3.退出游戏");
	
	gotoxy(80, 35);
	color(15);
	printf("由 “学以致知”提供技术支持！");
	
	gotoxy(43,27);
	color(3);
	printf("请选择1 2 3 ：");
	
	scanf("%d", &n);  //输入选项
	switch (n)
	{
		case 1:
			system("cls");  //清屏
			createMap();  //创建地图 
			initSnake();  //初始化蛇身 
			createFood();  //创建食物 
			keyboardControl();  //按键控制 
			break;
		case 2:
			explation();
			break;
		case 3:
			exit(0);  //退出
			break;
		default:
			gotoxy(40,28);
			color(12);
			printf("请输入1-3之间的数！");
			_getch();  //输入任意键
			system("cls");  //清屏
			welcomeToGame();
	 } 
	
}

/**
*4、绘制地图
*/
void createMap()
{
    int i, j;
    for (i = 0; i < 58; i += 2)  //打印上下边框
    {
        gotoxy(i, 0);
        color(5);
        printf("□");
        gotoxy(i, 26);
        printf("□");
    }
    for (i = 1; i < 26; i++)  //打印左右边框
    {
        gotoxy(0, i);
        printf("□");
        gotoxy(56, i);
        printf("□");
    }
    for (i = 2; i < 56; i += 2)
    {
        for (j = 1; j < 26; j++)
        {
            gotoxy(i, j);
            color(3);
            printf("■");
        }
    }
}

/**
*5、游戏界面右侧的得分和小提示
*/
void scoreAndTips()
{
    gotoxy(74, 2);
    color(12);
    printf("得分：%d", score);
    gotoxy(74, 4);
    color(12);
    levelChange();


    gotoxy(74, 8);
    color(14);
    printf("每个食物得分：%d分!",add);
    gotoxy(74, 10);
    printf("不能碰墙，不能咬到自己!");
    gotoxy(74, 12);
    printf("用↑↓←→分别控制蛇的移动!");
    gotoxy(74, 14);
    printf("F1为加速，F2为减速!");
    gotoxy(74, 16);
    printf("space:暂停游戏!");


    gotoxy(74, 18);
    printf("ESC:退出游戏!");
    
    
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    
    gotoxy(74, 22);
    color(15);
    printf("Date：%d/%d/%d\n",1900+p->tm_year,1+p->tm_mon,p->tm_mday);
    gotoxy(74, 24);
    printf("Time :%d:%d:%d",8+p->tm_hour,p->tm_min,p->tm_sec);
    
    gotoxy(74, 26);
    printf("由学以致知提供技术支持!");
}

/**
*6、等级展示
*/
void levelChange()
{
    if(score >= 0 && score < 50) level = 1;
    else if(score >= 50 && score < 200) level = 2;
    else if(score >= 200 && score < 500) level = 3;
    else if(score >= 500 && score < 1000) level = 4;
    else level = 5;    
    
    switch(level)
    {
        case 1 : printf("等级：坚韧黑铁"); break;
        case 2 : printf("等级：英勇黄铜"); break;
        case 3 : printf("等级：不屈白银"); break;
        case 4 : printf("等级：荣耀黄金"); break;
        case 5 : printf("等级：华贵铂金"); break;
        default : break;
    }
}

/**
*7、初始化蛇身
*/
void initSnake()
{
	snake * tail;
	int i;
	tail = (snake*)malloc(sizeof(snake)); 
	tail->x = 24;  //蛇的初始位置 
	tail->y = 5;
	tail->next = NULL;
	
	for(i = 1; i <= 2; i++)  //设置蛇身，长度为3 
	{
		head = (snake*)malloc(sizeof(snake));
		head->next = tail;  //蛇头的下一位置 
		head->x = 24 + 2 * i;
		head->y = 10;
		tail = head;  //蛇头变蛇尾，重复循环 
	 } 
	 while (tail == NULL)
	 {
	 	gotoxy(tail->x, tail->y);
	 	color(14);
	 	printf("★");
	 	tail = tail -> next;  //蛇头一直输出到蛇尾 
	 }
}

/**
*8、创建并随机出现食物
*/
void createFood()
{
	snake * food_1;
	srand((unsigned)time(NULL));
	food_1 = (snake*)malloc(sizeof(snake));
	food_1->x = rand() % 52 + 2;
	//food_1->y = 9;
	
	//保证其为偶数，食物出现在网格线上 
	while((food_1->x % 2) != 0)
	{
		food_1->x = rand() % 52 + 2;
	 }
	 food_1->y = rand() % 24 +1; 
	 
	 q = head;
	 while(q->next == NULL)
	 {
	 	if (q->x == food_1->x && q->y == food_1->y)
	 	{
	 		free(food_1);  //如果蛇身与食物重合，释放食物指针 
	 		createFood();  //重新创建食物 
		 }
		 q = q->next ; 
	  } 
	  gotoxy(food_1->x, food_1->y);
	  food = food_1;
	  color(12);
	  printf("●");  //输出食物 
	
}

/**
*9、判断是否咬到自己
*/
int biteSelf()
{
	snake * self;  //定义一个蛇身节点self
	self = head-> next;  //self是蛇头之外的蛇身节点
	while(self != NULL)
	{
		//如果self和蛇身的节点重合 
		if(self->x == head->x && self->y == head->y)
		{
			return 1; //返回1 
		 } 
		 self = self->next;
	}
	 return 0;
}

/**
*10、设置蛇撞墙的情况
*/
void cantcrossWall()
{
	if(head->x == 0 || head->x ==56 || head->y == 0 || head->y == 26)
	{
		endgamestatus = 1;  //蛇头撞墙
		endGame();  //出现游戏结束画面 
	}
}

/**
*11、按F1加速
*/
void speedUp()
{
	if(sleeptime >= 50)
	{
		sleeptime = sleeptime - 10;
		add = add + 2; 
	 } 
}

/**
*12、按F2减速
*/
void speedDown()
{
	if(sleeptime < 350)  //如果时间间隔小于350 
	{
		sleeptime = sleeptime + 30;  //时间间隔加上30 
		add = add - 2;  //每次食物得分减2 
	}
}

/**
*13、控制蛇前进方向
#define U 1  //上 
#define D 2  //下 
#define L 3  //左 
#define R 4  //右
*/
void snakeMove()
{
	snake * nexthead;
	cantcrossWall();
	nexthead = (snake*)malloc(sizeof(snake)); //下一步开辟空间 
	
	if(status == U)  //向上走
	{
		nexthead->x = head->x;  //向上前进是，x坐标不变，y坐标-1 
		nexthead->y = head->y - 1;
		nexthead->next = head;
		head = nexthead;
		q = head;
		
		//如果下一个位置的坐标和食物相同 
		if(nexthead->x == food->x && nexthead->y == food->y)
		{
			while(q != NULL)
			{
				gotoxy(q->x, q->y);
				color(14);
				printf("★");  //原来食物的位置换成蛇身 
				q = q->next; //指针q只想蛇身的下一位也要执行循环操作 
			 } 
			 score = score + add;  //吃到食物，在总分上加上食物的分 
			 speedUp();
			 createFood();
		}
		else
		{
			while(q->next->next != NULL)
			{
				gotoxy(q->x, q->y);
				color(14);
				printf("★");  //蛇正常往前走 
				q =q->next;   //继续输出整个蛇身 
			}
			//经过上面的循环，q指向了蛇尾，蛇尾的下一位就是蛇走过的位置
			gotoxy(q->next->x, q->next->y) ;
			color(3);
			printf("■");
			free(q->next);  //进行输出地图之后，释放下一位的指针 
			q->next = NULL; //指针的下一位就为空 
		 } 
		
	 } 
	 
	if(status == D) //向下走
	{
		nexthead->x = head->x;
		nexthead->y = head->y + 1;
		nexthead->next = head;
		head = nexthead;
		q = head;
		
		if(nexthead->x == food->x && nexthead->y == food->y)
		{
			while(q != NULL)
			{
				gotoxy(q->x, q->y);
				color(14);
				printf("★");
				q = q->next;
			}
			score= score + add;
			speedUp();
			createFood();
		 } 
		 else
		 {
		 	while(q->next->next != NULL)
		 	{
		 		gotoxy(q->x,q->y);
				 color(14);
				 printf("★");
				 q = q->next; 
			 }
			 gotoxy(q->next->x, q->next->y);
			 color(3);
			 printf("■");
			 free(q->next);
			 q->next = NULL; 
		 }
	 } 
	 
	 if(status == L)  //向左走
	 {
	 	nexthead->x = head->x - 2;  //向左走，x坐标-2，y坐标不懂
		nexthead->y = head->y;
		nexthead->next = head;
		head = nexthead;
		q = head;
		
		if(nexthead->x == food->x && nexthead->y == food->y)
		{
			while(q != NULL)
			{
				gotoxy(q->x,q->y);
				color(14);
				printf("★");
				q = q->next; 
			}
			score = score + add;
			speedUp();
			createFood(); 
		  }  
		  else
		  {
		  	while(q->next->next != NULL)
		  	{
		  		gotoxy(q->x,q->y);
		  		color(14);
		  		printf("★");
		  		q = q->next;
			  }
			  gotoxy(q->next->x,q->next->y);
			  color(3);
			  printf("■");
			  free(q->next);
			  q->next = NULL;
		  }
	 	
	  } 
	  
	  if(status == R)  //向右走
	  {
	  	nexthead->x = head->x + 2;
	  	nexthead->y = head->y;
	  	nexthead->next = head;
	  	head = nexthead;
	  	q = head;
	  	
	  	if(nexthead->x == food->x && nexthead->y == food->y)
	  	{
	  		while(q != NULL)
	  		{
	  			gotoxy(q->x,q->y);
				color(14);
				printf("★");
				q= q->next;   
			  }
			  score = score + add;
			  speedUp();
			  createFood();
		  }
		  else
		  {
		  	while(q->next->next != NULL)
		  	{
		  		gotoxy(q->x,q->y) ;
		  		color(14);
		  		printf("★");
		  		q = q->next;
			  }
			  gotoxy(q->next->x,q->next->y);
			  color(3);
			  printf("■");
			  free(q->next);
			  q->next = NULL;
		  }
	   } 
	   if(biteSelf() == 1) //判断是否咬到自己 
	   {
	   		endgamestatus = 2;  //咬到自己游戏结束 
	   		endGame();
	   }
	 
}

/**
*14、控制键盘按键
#define U 1  //上 
#define D 2  //下 
#define L 3  //左 
#define R 4  //右
GetAsyncKeyState函数用来判断函数调用时指定虚拟键的状态
Sleep()实现进程暂停，指定达到里面设置的参数时间 
*/
void keyboardControl()
{
	status = R;  //初始蛇向右移动
	while(1)
	{
		scoreAndTips();
		if(GetAsyncKeyState(VK_UP) && status != D)
		{
			status = U;  //如果蛇不是向下前进的时候，按上键，执行向上前进操作。 
		}
		else if(GetAsyncKeyState(VK_DOWN) && status != U)
		{
			status = D;  //如果蛇不是向上前进，按下键，执行向下前进操作 
		 }
		else if(GetAsyncKeyState(VK_LEFT) && status != R)
		{
			status = L;  //如果蛇不是向右前进，按左键，执行向左前进操作 
		 } 
		else if(GetAsyncKeyState(VK_RIGHT) && status != L)
		{
			status = R;  //果果蛇不是向左前进。按右键，执行向右强行操作 
		}
		
		if(GetAsyncKeyState(VK_SPACE))  //按空格键，执行暂停操作
		{
			while(1)
			{
				Sleep(300);
				if(GetAsyncKeyState(VK_SPACE))
				{
					break;
				}
			 } 
		 }
		else if(GetAsyncKeyState(VK_ESCAPE))
		{
		 	endgamestatus = 3;  //按esc键，直接结束游戏
			 break; 
		} 
		else if(GetAsyncKeyState(VK_F1))  //按F1键， 加速
		{
			speedUp(); 
		 } 
		else if(GetAsyncKeyState(VK_F2))  //按F2键盘，减速
		{
			speedDown();
		 }
		 Sleep(sleeptime);
		 snakeMove(); 
	  }
}

/**
*15、绘制游戏失败界面
*/
void lostDraw()
{
    system("cls");
    int i;
    
    //打印图案的头 
    gotoxy(46, 2);
    color(6);
    printf("\\\\\\|///");
    gotoxy(43, 3);
    printf("\\\\");
    gotoxy(47, 3);
    color(15);
    printf(".-.-");
    gotoxy(54, 3);
    color(6);
    printf("//");

	//打印图案的脸 
    gotoxy(44, 4);
    color(14);
    printf("(");
    gotoxy(47, 4);
    color(15);
    printf(".@.@");
    gotoxy(54, 4);
    color(14);
    printf(")");

	//打印图案上边框 
    gotoxy(17, 5);
    color(11);
    printf("+------------------------");
    gotoxy(35, 5);
    color(14);
    printf("o00o");
    gotoxy(39, 5);
    color(11);
    printf("---------");
    gotoxy(48, 5);
    color(14);
    printf("(_)");
    gotoxy(51, 5);
    color(11);
    printf("---------");
    gotoxy(61, 5);
    color(14);
    printf("o00o");
    gotoxy(65, 5);
    color(11);
    printf("-----------------+");

	//打印左右边框 
    for (i = 6; i <= 19; i++)
    {
        gotoxy(17, i);
        printf("|");
        gotoxy(82, i);
        printf("|");
    }

	//打印图案的下边框 
    gotoxy(17, 20);
    printf("+----------------------------");
    gotoxy(47, 20);
    color(14);
    printf("☆ ☆ ☆");
    gotoxy(56, 20);
    color(11);
    printf("--------------------------+");
}


/**
*16、游戏结束
*/
void endGame()
{
	system("cls");  //清屏
	if(endgamestatus == 1)
	{
		lostDraw();
		gotoxy(45,10);
		color(12);
		printf("你撞墙了哦！");
	 } 
	else if(endgamestatus == 2)
	{
		lostDraw();
		gotoxy(45,10);
		color(12);
		printf("咬到自己了哦！");
	}
	else if(endgamestatus == 3)
	{
		lostDraw();
		gotoxy(45,10);
		color(12);
		printf("Game Over!");
	}
	gotoxy(44,13);
	color(11);
	printf("您的得分是 %d", score);
	gotoxy(44,15);
	color(14);
	levelChange();
	choose();
}

/**
*17、游戏结束之后的选择
*/
void choose()
{
	int n;
	
	gotoxy(30,24);
	color(12);
	printf("继续游戏-----1");
	gotoxy(57,24);
	printf("退出游戏-----2");
	gotoxy(47,28);
	color(11); 
	printf("请选择(1或2)：");
	
	scanf("%d",  &n);
	switch(n)
	{
		case 1:
			system("cls");  //清屏
			score = 0;
			sleeptime = 200;
			add = 10;
			welcomeToGame();
			break;
		case 2:
			exit(0);
			break;
		default:
			gotoxy(35,27);
			color(12);
			printf("输入有误！请重新输入1或2！");
			system("pause > null");
			endGame();
			choose();
			break; 
	}
}

/**
*18、游戏说明
*/
void explation()
{
    system("cls");
    int i,j=1;
    
    color(13);
    gotoxy(44,3);
    printf("游戏说明");
    color(2);
    for (i = 6; i <= 25; i++)  //输出上下边框
    {
        for (j = 20; j <= 75; j++)  //输出左右边框
        {
            gotoxy(j, i);
            if (i == 6 || i == 25) printf("=");
            else if (j == 20 || j == 75) printf("||");
        }
    }
    color(3);
    gotoxy(30, 8);
    printf("1.不能穿墙，不能咬到自己");
    color(10);
    gotoxy(30, 11);
    printf("2.分别用↑↓←→控制蛇的移动");
    color(14);
    gotoxy(30, 14);
    printf("3.小惊喜 F1可以加速\tF2可以减速");
    color(11);
    gotoxy(30, 17);
    printf("4.按空格键暂停，再按继续");


    color(15);
    gotoxy(30, 20);
    printf("5.由学以致知提供技术支持");


    color(4);
    gotoxy(30, 23);
    printf("6.按任意键返回开始界面");
    _getch();  //任意键返回开始界面
    system("cls");
    welcomeToGame();
}

int main()
{
	system("mode con cols=110 lines=40");  //设置控制台宽高 
	welcomeToGame();
	
	keyboardControl();
	endGame();
    return 0; 
}


