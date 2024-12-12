#ifndef HEADER_FILE
#define HEADER_FILE

/*定义常量*/
//蛇的状态， 
#define U 1  //上 
#define D 2  //下 
#define L 3  //左 
#define R 4  //右


/**********定 义 全 局 变 量**********/
/*结构体变量*/
//蛇身的一个节点 
typedef struct snake
{
	int x;
	int y;
	struct snake* next;
 } snake;

/*普 通 全 局 变 量*/ 
int score = 0, add = 10, level = 0;  //总得分、每次食物得分、等级 

int endgamestatus = 0;  //游戏结束的情况，1：撞到墙，2：咬到自己，3：主动退出游戏 

int sleeptime = 200;  //每次运行的时间间隔 

int status = R;//蛇的前进状态 

snake * head, * food; //蛇头指针，食物指针 
snake *q;  //遍历蛇身的时候用的中间指针 


/**********函 数 声 明**********/
void gotoxy(int x,int y); //1、设置光标位置 
int color(int c);         //2、更改文字颜色 
void welcomeToGame();     //3、开始界面 
void createMap();         //4、绘制地图 
void scoreAndTips();      //5、游戏界面右侧的得分和小提示 
void levelChange();       //6、等级展示 
void initSnake();         //7、初始化蛇身 
void createFood();        //8、创建随机出现的食物 
int biteSelf();           //9、判断是否咬到自己 
void cantcrossWall();     //10、设置蛇撞墙的情况 
void speedUp();           //11、按F1加速 
void speedDown();         //12、按F2减速 
void snakeMove();         //13、控制蛇的前进方向 
void keyboardControl();   //14、控制键盘按键 
void lostDraw();          //15、绘制游戏失败界面 
void endGame();           //16、游戏结束 
void choose();            //17、游戏结束之后的选择 
void explation();         //18、游戏说明 


#endif
