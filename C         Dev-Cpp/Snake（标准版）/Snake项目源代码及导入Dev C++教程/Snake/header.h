#ifndef HEADER_FILE
#define HEADER_FILE

/*************�� �� �� ��************/
//�ߵ�״̬ 
#define U 1  //�� 
#define D 2  //�� 
#define L 3  //�� 
#define R 4  //��

/*******�� �� ȫ �� �� ��*******/
/*�ṹ�����*/
//�����һ���ڵ�
typedef struct snake  
{
	int x;
	int y;
	struct snake* next;
}snake;

/*******�� ͨ ȫ �� �� ��*******/
int score = 0, add = 10, level = 0;  //�ܵ÷֡�ÿ��ʳ��÷֡��ȼ� 

int endgamestatus = 0;  //��Ϸ�����������1��ײ��ǽ��2��ҧ���Լ���3�������˳���Ϸ 

int sleeptime = 200;  //ÿ�����е�ʱ���� 

int status = R;//�ߵ�ǰ��״̬ 

snake * head, * food; //��ͷָ�룬ʳ��ָ�� 
snake *q;  //���������ʱ���õ��м�ָ�� 


/*******��������*******/
void gotoxy(int x, int y);  //1�����ù��λ��
int color(int c);  //2������������ɫ
void welcomeToGame();  //3����ʼ����
void createMap();  //4�����Ƶ�ͼ
void scoreAndTips();  //5����Ϸ�����Ҳ�ĵ÷ֺ�С��ʾ
void levelChange();  //6���ȼ�չʾ
void initSnake();  //7����ʼ������������
void createFood();  //8���������������ʳ��
int biteSelf();  //9���ж��Ƿ�ҧ���Լ�
void cantcrossWall();  //10��������ײǽ���
void speedUp();  //11������
void speedDown();  //12������
void snakeMove();  //13��������ǰ������
void keyboardControl();  //14�����Ƽ��̰���
void lostDraw();  //15����Ϸ��������
void endGame();  //16����Ϸ����
void choose();  //17����Ϸ����֮���ѡ��
void explation();  //18����Ϸ˵��

#endif
