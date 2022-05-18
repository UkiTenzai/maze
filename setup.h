#ifndef _SETUP_H_ 
#define _SETUP_H_ 
#define _CRT_SECURE_NO_WARNINGS 1

#define STACK_SIZE 100 
#define MAPSIZE 12

//�����밴ť����ֵ���Ƴ����й�
#define X_BEGIN 1
#define Y_BEGIN 1
#define X_END 10
#define Y_END 10

#define BOTTUN_UP 1
#define BOTTUN_DOWN -1

#define MAP_A 10
#define MAP_B 20
#define MAP_C 30

//��ͼ�ж�ά����Ԫ��ֵ�ĺ���
#define TOWALK 0
#define BARRIER 1
#define START_END 2
#define WALKED -1

//ÿһ�����ӵ�����
#define BLOCK_SIZE  40
//����Ŀ�͸�
#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 480


void initial();
int welcome();
int chooseMode();
int chooseMaze();


class Block 
{
public:
	int x;
	int y;
	int round_can_go;
};

class MAZE;
class Stack
{
private:
	Block blocks[STACK_SIZE];	
	int top;
public:
	void findWay(MAZE &maze);
	void showThruWay();
};

class MAZE
{
private:
	int map[MAPSIZE][MAPSIZE];
public:
	MAZE();
	~MAZE();
	void changeAll(int map[MAPSIZE][MAPSIZE]);
	void drawMazeByPlayer();
	void showMaze();
	friend void Stack::findWay(MAZE &maze);
};

void drawMazeBySystem(MAZE &mA, MAZE &mB, MAZE &mC);

#endif