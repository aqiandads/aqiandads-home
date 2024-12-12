#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>  
#include<time.h> 
#include<Windows.h>
#include<stdlib.h>  
#include<conio.h>  

#include "header.h"

/**
*1�����ù��λ��
*/
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); 
}

/**
*2������������ɫ
*/
int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}

/**
*3����ʼ����
*/
void welcomeToGame()
{
	int n;
	
	gotoxy(43, 10);
	color(11);
	printf("̰ �� �� �� �� ս");
	
	color(12);
	gotoxy(25, 22);
	printf("1.��ʼ��Ϸ");
	gotoxy(45, 22);
	printf("2.��Ϸ˵��");
	gotoxy(65, 22);
	printf("3.�˳���Ϸ");
	
	gotoxy(80, 35);
	color(15);
	printf("�� ��ѧ����֪���ṩ����֧�֣�");
	
	gotoxy(43,27);
	color(3);
	printf("��ѡ��1 2 3 ��");
	
	scanf("%d", &n);  //����ѡ��
	switch (n)
	{
		case 1:
			system("cls");  //����
			createMap();  //������ͼ 
			initSnake();  //��ʼ������ 
			createFood();  //����ʳ�� 
			keyboardControl();  //�������� 
			break;
		case 2:
			explation();
			break;
		case 3:
			exit(0);  //�˳�
			break;
		default:
			gotoxy(40,28);
			color(12);
			printf("������1-3֮�������");
			_getch();  //���������
			system("cls");  //����
			welcomeToGame();
	 } 
	
}

/**
*4�����Ƶ�ͼ
*/
void createMap()
{
    int i, j;
    for (i = 0; i < 58; i += 2)  //��ӡ���±߿�
    {
        gotoxy(i, 0);
        color(5);
        printf("��");
        gotoxy(i, 26);
        printf("��");
    }
    for (i = 1; i < 26; i++)  //��ӡ���ұ߿�
    {
        gotoxy(0, i);
        printf("��");
        gotoxy(56, i);
        printf("��");
    }
    for (i = 2; i < 56; i += 2)
    {
        for (j = 1; j < 26; j++)
        {
            gotoxy(i, j);
            color(3);
            printf("��");
        }
    }
}

/**
*5����Ϸ�����Ҳ�ĵ÷ֺ�С��ʾ
*/
void scoreAndTips()
{
    gotoxy(74, 2);
    color(12);
    printf("�÷֣�%d", score);
    gotoxy(74, 4);
    color(12);
    levelChange();


    gotoxy(74, 8);
    color(14);
    printf("ÿ��ʳ��÷֣�%d��!",add);
    gotoxy(74, 10);
    printf("������ǽ������ҧ���Լ�!");
    gotoxy(74, 12);
    printf("�á��������ֱ�����ߵ��ƶ�!");
    gotoxy(74, 14);
    printf("F1Ϊ���٣�F2Ϊ����!");
    gotoxy(74, 16);
    printf("space:��ͣ��Ϸ!");


    gotoxy(74, 18);
    printf("ESC:�˳���Ϸ!");
    
    
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    
    gotoxy(74, 22);
    color(15);
    printf("Date��%d/%d/%d\n",1900+p->tm_year,1+p->tm_mon,p->tm_mday);
    gotoxy(74, 24);
    printf("Time :%d:%d:%d",8+p->tm_hour,p->tm_min,p->tm_sec);
    
    gotoxy(74, 26);
    printf("��ѧ����֪�ṩ����֧��!");
}

/**
*6���ȼ�չʾ
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
        case 1 : printf("�ȼ������ͺ���"); break;
        case 2 : printf("�ȼ���Ӣ�»�ͭ"); break;
        case 3 : printf("�ȼ�����������"); break;
        case 4 : printf("�ȼ�����ҫ�ƽ�"); break;
        case 5 : printf("�ȼ������󲬽�"); break;
        default : break;
    }
}

/**
*7����ʼ������
*/
void initSnake()
{
	snake * tail;
	int i;
	tail = (snake*)malloc(sizeof(snake)); 
	tail->x = 24;  //�ߵĳ�ʼλ�� 
	tail->y = 5;
	tail->next = NULL;
	
	for(i = 1; i <= 2; i++)  //������������Ϊ3 
	{
		head = (snake*)malloc(sizeof(snake));
		head->next = tail;  //��ͷ����һλ�� 
		head->x = 24 + 2 * i;
		head->y = 10;
		tail = head;  //��ͷ����β���ظ�ѭ�� 
	 } 
	 while (tail == NULL)
	 {
	 	gotoxy(tail->x, tail->y);
	 	color(14);
	 	printf("��");
	 	tail = tail -> next;  //��ͷһֱ�������β 
	 }
}

/**
*8���������������ʳ��
*/
void createFood()
{
	snake * food_1;
	srand((unsigned)time(NULL));
	food_1 = (snake*)malloc(sizeof(snake));
	food_1->x = rand() % 52 + 2;
	//food_1->y = 9;
	
	//��֤��Ϊż����ʳ��������������� 
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
	 		free(food_1);  //���������ʳ���غϣ��ͷ�ʳ��ָ�� 
	 		createFood();  //���´���ʳ�� 
		 }
		 q = q->next ; 
	  } 
	  gotoxy(food_1->x, food_1->y);
	  food = food_1;
	  color(12);
	  printf("��");  //���ʳ�� 
	
}

/**
*9���ж��Ƿ�ҧ���Լ�
*/
int biteSelf()
{
	snake * self;  //����һ������ڵ�self
	self = head-> next;  //self����ͷ֮�������ڵ�
	while(self != NULL)
	{
		//���self������Ľڵ��غ� 
		if(self->x == head->x && self->y == head->y)
		{
			return 1; //����1 
		 } 
		 self = self->next;
	}
	 return 0;
}

/**
*10��������ײǽ�����
*/
void cantcrossWall()
{
	if(head->x == 0 || head->x ==56 || head->y == 0 || head->y == 26)
	{
		endgamestatus = 1;  //��ͷײǽ
		endGame();  //������Ϸ�������� 
	}
}

/**
*11����F1����
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
*12����F2����
*/
void speedDown()
{
	if(sleeptime < 350)  //���ʱ����С��350 
	{
		sleeptime = sleeptime + 30;  //ʱ��������30 
		add = add - 2;  //ÿ��ʳ��÷ּ�2 
	}
}

/**
*13��������ǰ������
#define U 1  //�� 
#define D 2  //�� 
#define L 3  //�� 
#define R 4  //��
*/
void snakeMove()
{
	snake * nexthead;
	cantcrossWall();
	nexthead = (snake*)malloc(sizeof(snake)); //��һ�����ٿռ� 
	
	if(status == U)  //������
	{
		nexthead->x = head->x;  //����ǰ���ǣ�x���겻�䣬y����-1 
		nexthead->y = head->y - 1;
		nexthead->next = head;
		head = nexthead;
		q = head;
		
		//�����һ��λ�õ������ʳ����ͬ 
		if(nexthead->x == food->x && nexthead->y == food->y)
		{
			while(q != NULL)
			{
				gotoxy(q->x, q->y);
				color(14);
				printf("��");  //ԭ��ʳ���λ�û������� 
				q = q->next; //ָ��qֻ���������һλҲҪִ��ѭ������ 
			 } 
			 score = score + add;  //�Ե�ʳ����ܷ��ϼ���ʳ��ķ� 
			 speedUp();
			 createFood();
		}
		else
		{
			while(q->next->next != NULL)
			{
				gotoxy(q->x, q->y);
				color(14);
				printf("��");  //��������ǰ�� 
				q =q->next;   //��������������� 
			}
			//���������ѭ����qָ������β����β����һλ�������߹���λ��
			gotoxy(q->next->x, q->next->y) ;
			color(3);
			printf("��");
			free(q->next);  //���������ͼ֮���ͷ���һλ��ָ�� 
			q->next = NULL; //ָ�����һλ��Ϊ�� 
		 } 
		
	 } 
	 
	if(status == D) //������
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
				printf("��");
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
				 printf("��");
				 q = q->next; 
			 }
			 gotoxy(q->next->x, q->next->y);
			 color(3);
			 printf("��");
			 free(q->next);
			 q->next = NULL; 
		 }
	 } 
	 
	 if(status == L)  //������
	 {
	 	nexthead->x = head->x - 2;  //�����ߣ�x����-2��y���겻��
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
				printf("��");
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
		  		printf("��");
		  		q = q->next;
			  }
			  gotoxy(q->next->x,q->next->y);
			  color(3);
			  printf("��");
			  free(q->next);
			  q->next = NULL;
		  }
	 	
	  } 
	  
	  if(status == R)  //������
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
				printf("��");
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
		  		printf("��");
		  		q = q->next;
			  }
			  gotoxy(q->next->x,q->next->y);
			  color(3);
			  printf("��");
			  free(q->next);
			  q->next = NULL;
		  }
	   } 
	   if(biteSelf() == 1) //�ж��Ƿ�ҧ���Լ� 
	   {
	   		endgamestatus = 2;  //ҧ���Լ���Ϸ���� 
	   		endGame();
	   }
	 
}

/**
*14�����Ƽ��̰���
#define U 1  //�� 
#define D 2  //�� 
#define L 3  //�� 
#define R 4  //��
GetAsyncKeyState���������жϺ�������ʱָ���������״̬
Sleep()ʵ�ֽ�����ͣ��ָ���ﵽ�������õĲ���ʱ�� 
*/
void keyboardControl()
{
	status = R;  //��ʼ�������ƶ�
	while(1)
	{
		scoreAndTips();
		if(GetAsyncKeyState(VK_UP) && status != D)
		{
			status = U;  //����߲�������ǰ����ʱ�򣬰��ϼ���ִ������ǰ�������� 
		}
		else if(GetAsyncKeyState(VK_DOWN) && status != U)
		{
			status = D;  //����߲�������ǰ�������¼���ִ������ǰ������ 
		 }
		else if(GetAsyncKeyState(VK_LEFT) && status != R)
		{
			status = L;  //����߲�������ǰ�����������ִ������ǰ������ 
		 } 
		else if(GetAsyncKeyState(VK_RIGHT) && status != L)
		{
			status = R;  //�����߲�������ǰ�������Ҽ���ִ������ǿ�в��� 
		}
		
		if(GetAsyncKeyState(VK_SPACE))  //���ո����ִ����ͣ����
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
		 	endgamestatus = 3;  //��esc����ֱ�ӽ�����Ϸ
			 break; 
		} 
		else if(GetAsyncKeyState(VK_F1))  //��F1���� ����
		{
			speedUp(); 
		 } 
		else if(GetAsyncKeyState(VK_F2))  //��F2���̣�����
		{
			speedDown();
		 }
		 Sleep(sleeptime);
		 snakeMove(); 
	  }
}

/**
*15��������Ϸʧ�ܽ���
*/
void lostDraw()
{
    system("cls");
    int i;
    
    //��ӡͼ����ͷ 
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

	//��ӡͼ������ 
    gotoxy(44, 4);
    color(14);
    printf("(");
    gotoxy(47, 4);
    color(15);
    printf(".@.@");
    gotoxy(54, 4);
    color(14);
    printf(")");

	//��ӡͼ���ϱ߿� 
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

	//��ӡ���ұ߿� 
    for (i = 6; i <= 19; i++)
    {
        gotoxy(17, i);
        printf("|");
        gotoxy(82, i);
        printf("|");
    }

	//��ӡͼ�����±߿� 
    gotoxy(17, 20);
    printf("+----------------------------");
    gotoxy(47, 20);
    color(14);
    printf("�� �� ��");
    gotoxy(56, 20);
    color(11);
    printf("--------------------------+");
}


/**
*16����Ϸ����
*/
void endGame()
{
	system("cls");  //����
	if(endgamestatus == 1)
	{
		lostDraw();
		gotoxy(45,10);
		color(12);
		printf("��ײǽ��Ŷ��");
	 } 
	else if(endgamestatus == 2)
	{
		lostDraw();
		gotoxy(45,10);
		color(12);
		printf("ҧ���Լ���Ŷ��");
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
	printf("���ĵ÷��� %d", score);
	gotoxy(44,15);
	color(14);
	levelChange();
	choose();
}

/**
*17����Ϸ����֮���ѡ��
*/
void choose()
{
	int n;
	
	gotoxy(30,24);
	color(12);
	printf("������Ϸ-----1");
	gotoxy(57,24);
	printf("�˳���Ϸ-----2");
	gotoxy(47,28);
	color(11); 
	printf("��ѡ��(1��2)��");
	
	scanf("%d",  &n);
	switch(n)
	{
		case 1:
			system("cls");  //����
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
			printf("������������������1��2��");
			system("pause > null");
			endGame();
			choose();
			break; 
	}
}

/**
*18����Ϸ˵��
*/
void explation()
{
    system("cls");
    int i,j=1;
    
    color(13);
    gotoxy(44,3);
    printf("��Ϸ˵��");
    color(2);
    for (i = 6; i <= 25; i++)  //������±߿�
    {
        for (j = 20; j <= 75; j++)  //������ұ߿�
        {
            gotoxy(j, i);
            if (i == 6 || i == 25) printf("=");
            else if (j == 20 || j == 75) printf("||");
        }
    }
    color(3);
    gotoxy(30, 8);
    printf("1.���ܴ�ǽ������ҧ���Լ�");
    color(10);
    gotoxy(30, 11);
    printf("2.�ֱ��á������������ߵ��ƶ�");
    color(14);
    gotoxy(30, 14);
    printf("3.С��ϲ F1���Լ���\tF2���Լ���");
    color(11);
    gotoxy(30, 17);
    printf("4.���ո����ͣ���ٰ�����");


    color(15);
    gotoxy(30, 20);
    printf("5.��ѧ����֪�ṩ����֧��");


    color(4);
    gotoxy(30, 23);
    printf("6.����������ؿ�ʼ����");
    _getch();  //��������ؿ�ʼ����
    system("cls");
    welcomeToGame();
}

int main()
{
	system("mode con cols=110 lines=40");  //���ÿ���̨��� 
	welcomeToGame();
	
	keyboardControl();
	endGame();
    return 0; 
}


