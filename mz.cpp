#pragma once
#include "setup.h"
#include <graphics.h>
#include <sstream>
using namespace std;

MAZE::MAZE()
{
    int x, y;
    for (x=0; x<MAPSIZE; x++)
    {
        for (y=0; y<MAPSIZE; y++)
        {
            map[y][x]=1;
        }
    }
}
MAZE::~MAZE()
{
    int x, y;
    for (x=0; x<12; x++)
    {
        for (y=0; y<12; y++)
        {
            map[y][x]=0;
        }
    }
}
void MAZE::changeAll(int a[MAPSIZE][MAPSIZE])
{
    int x, y;
    for (x=0; x<MAPSIZE; x++)
    {
        for (y=0; y<MAPSIZE; y++)
        {
            map[y][x]=a[y][x];
        }
    }
}

void initial()
{
    initgraph(WINDOW_HEIGHT, WINDOW_WIDTH);
    setbkcolor(LIGHTGRAY);
    cleardevice();

    setcolor(GREEN);
    setfillcolor(BLUE);

    settextstyle(40, 0, "����", 0, 0, 400, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);
    setbkmode(TRANSPARENT);
    settextcolor(WHITE);
}

int welcome()
{
    char wc[48]="�����������Թ���������";
    outtextxy((480 - textwidth(wc)) / 2, 80, wc);
    solidrectangle(160, 200, 320, 260);
    solidrectangle(160, 320, 320, 380);

    
    char s[10]="��ʼ��Ϸ";
    char ss[10]="�˳�";
    outtextxy((480 - textwidth(s)) / 2, 210, s);
    outtextxy((480 - textwidth(ss)) / 2, 331, ss);

    while (true)
    {
        MOUSEMSG m = GetMouseMsg();
        if (m.x>160 && m.x<320 && m.y>200 && m.y<260)
        {
            if (m.uMsg == WM_LBUTTONDOWN)
            {
                return BOTTUN_UP;
            }
        }
        if (m.x>160 && m.x<320 && m.y>320 && m.y<380)
        {
            if (m.uMsg == WM_LBUTTONDOWN)
            {
                return BOTTUN_DOWN;
            }
        }
    }
}


int chooseMode()
{
    clearrectangle(0, 0, 480, 480);
    char wc[48]="��������ѡ��ģʽ��������";
    outtextxy((480 - textwidth(wc)) / 2, 80, wc);
    solidrectangle(120, 200, 360, 260);
    solidrectangle(120, 320, 360, 380);

    char s[20]="�Լ����Ƶ�ͼ";
    char ss[20]="ѡ��ϵͳ��ͼ";
    outtextxy((480 - textwidth(s)) / 2, 210, s);
    outtextxy((480 - textwidth(ss)) / 2, 331, ss);

    while (true)
    {
        MOUSEMSG m = GetMouseMsg();
        if (m.x>120 && m.x<360 && m.y>200 && m.y<260)
        {
            if (m.uMsg == WM_LBUTTONDOWN)
            {
                return BOTTUN_UP;
            }
        }
        if (m.x>120 && m.x<360 && m.y>320 && m.y<380)
        {
            if (m.uMsg == WM_LBUTTONDOWN)
            {
                return BOTTUN_DOWN;
            }
        }
    }
}


void drawMazeBySystem(MAZE &mA, MAZE &mB, MAZE &mC)
{ 
    int a[MAPSIZE][MAPSIZE] ={
         {1,1,1,1,1,1,1,1,1,1,1,1},
         {1,0,1,0,0,0,0,0,0,0,0,1},
         {1,0,1,0,1,1,1,1,1,1,0,1},
         {1,0,1,0,1,0,1,0,0,0,0,1},
         {1,0,0,0,1,0,1,1,0,1,1,1},
         {1,1,1,1,1,0,0,0,0,1,0,1},
         {1,0,0,0,1,0,1,1,1,1,0,1},
         {1,0,1,0,1,0,1,0,0,0,0,1},
         {1,0,1,0,0,0,1,0,1,0,1,1},
         {1,0,1,1,1,1,1,0,1,0,1,1},
         {1,0,0,0,0,0,0,0,1,0,0,1},
         {1,1,1,1,1,1,1,1,1,1,1,1},
    };

    int b[MAPSIZE][MAPSIZE] ={
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,1,0,0,0,0,1},
        {1,1,1,0,1,0,1,0,1,1,1,1},
        {1,0,0,0,1,0,0,0,0,0,1,1},
        {1,0,1,1,1,1,1,1,1,0,1,1},
        {1,0,0,1,0,0,1,0,0,0,1,1},
        {1,1,1,1,1,0,1,1,0,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,0,1,1,1,0,1,1,1,0,1},
        {1,0,0,1,0,1,1,1,0,1,1,1},
        {1,1,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1},
    };

    int c[MAPSIZE][MAPSIZE] ={
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,0,0,0,0,0,1},
        {1,0,1,0,1,1,1,1,1,1,0,1},
        {1,0,1,0,1,0,0,0,0,1,0,1},
        {1,0,1,0,1,1,1,1,0,1,0,1},
        {1,0,1,0,0,0,1,1,0,1,0,1},
        {1,0,1,0,1,1,0,0,0,1,0,1},
        {1,0,1,0,1,1,1,1,0,1,0,1},
        {1,0,1,0,0,0,0,1,0,1,0,1},
        {1,0,1,1,1,1,1,1,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1},
    };

    mA.changeAll(a); mB.changeAll(b); mC.changeAll(c);
}

void MAZE::drawMazeByPlayer()
{
    map[1][1] = START_END; map[10][10] = START_END;    //���������յ�λ��
    showMaze();
    int x=0, y=0;

    MessageBox(0, "��ͼ���ϽǺ����½���ɫ�����������յ�.\n��������������Ƶ�ͼ����ɻ��ƺ��һ��յ㷽��.\n�벻Ҫ�������һȦ��Χǽ����.", "����", 0);
    MOUSEMSG m;
    while (true)
    {
        m = GetMouseMsg();
        if (m.uMsg == WM_LBUTTONDOWN)
        {
            x = int(m.x)/BLOCK_SIZE; y = int(m.y)/BLOCK_SIZE;
            if (x>=X_BEGIN && y>=X_BEGIN && x<=X_END && y<=X_END)
            {
                map[y][x] = TOWALK;
                showMaze();
            }
        }
        else if (m.uMsg == WM_RBUTTONDOWN)
        {
            x = int(m.x)/BLOCK_SIZE; y = int(m.y)/BLOCK_SIZE;
            if (x==X_END && y==X_END)
            {
                return;
            }
        }
    }
}


int chooseMaze()
{
    clearrectangle(0, 0, 480, 480);
    char wc[48]="��������ѡ���ͼ��������";
    outtextxy((480 - textwidth(wc)) / 2, 80, wc);

    //������
    solidrectangle(160, 180, 320, 240);
    solidrectangle(160, 280, 320, 340);
    solidrectangle(160, 380, 320, 440);

    char sA[10]="��ͼA";
    char sB[10]="��ͼB";
    char sC[10]="��ͼC";
    outtextxy((480 - textwidth(sA)) / 2, 192, sA);
    outtextxy((480 - textwidth(sB)) / 2, 292, sB);
    outtextxy((480 - textwidth(sA)) / 2, 392, sC);

    while (true)
    {
        MOUSEMSG m = GetMouseMsg();

        if (m.uMsg == WM_LBUTTONDOWN)
        {
            if (m.x>160 && m.x<320 && m.y>180 && m.y<240)
            {                
                return MAP_A;               
            }
            if (m.x>160 && m.x<320 && m.y>280 && m.y<340)
            {                
                return MAP_B;                
            }
            if (m.x>160 && m.x<320 && m.y>380 && m.y<440)
            {                    
                return MAP_C;                
            }
        }
        
    }
}



//����
void MAZE::showMaze()
{
    clearrectangle(0, 0, 480, 480);

    for (int y = 0; y < WINDOW_HEIGHT / BLOCK_SIZE; y++)
    {
        for (int x = 0; x < WINDOW_WIDTH / BLOCK_SIZE; x++)
        {
            //û���߹������ߴ�·��ͨ
            if (map[y][x] == TOWALK)
            {
                setcolor(RED);
                setfillcolor(DARKGRAY);
                fillrectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
                rectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
            }

            //�ϰ���
            if (map[y][x] == BARRIER)
            {
                setcolor(RED);
                setfillcolor(BLACK);
                fillrectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
                rectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
            }

            //�Ѿ��߹���·��
            if (map[y][x] == WALKED)
            {
                setcolor(RED);
                setfillcolor(GREEN);
                fillrectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
                rectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
            }
            //�����յ�
            if (map[y][x] == START_END)
            {
                setcolor(RED);
                setfillcolor(MAGENTA);
                fillrectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
                rectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
            }
        }
    }
}


void Stack::findWay(MAZE &maze)
{
    int x, y, direction, find;

    top = 0;
    blocks[top].x = X_BEGIN;
    blocks[top].y = Y_BEGIN;
    blocks[top].round_can_go = -1;
    maze.map[Y_BEGIN][X_BEGIN]=-1; 
    while (top>-1)
    {
        x = blocks[top].x;
        y = blocks[top].y;
        direction = blocks[top].round_can_go;
    
        if (x==X_END && y==Y_END)
        {
            maze.showMaze();    //��ֱ����ͼ��ֱ�۵ػ���ͨ·
            showThruWay();    //������ʾ�����ı���ʽ��ʾͨ·�ϸ�������Ϣ
            return;
        }

        find=0;
        while (direction<4&&find==0)    //��鵱ǰ������Χ���������ϣ������ߵķ��� 
        {
            direction++;
            switch (direction)
            {
                case 0:x=blocks[top].x-1; y=blocks[top].y; break;
                case 1:x=blocks[top].x; y=blocks[top].y+1; break;
                case 2:x=blocks[top].x+1; y=blocks[top].y; break;
                case 3:x=blocks[top].x; y=blocks[top].y-1; break;
            }
            if (maze.map[y][x]==TOWALK) 
            { 
                find=1;
            }    //�ҵ�����һ�����߷��飨x��y�� 
        }

        if (find==1)    //�ߵ����߷��飬�����˷�����ջ
        {
            blocks[top].round_can_go = direction;    //����ߵķ���
            top++;    //������
            blocks[top].x = x;
            blocks[top].y = y;
            blocks[top].round_can_go = -1;
            maze.map[y][x] = WALKED;
        }
        else    //δ�ҵ����߷��飬��ջ������
        {
            maze.map[blocks[top].y][blocks[top].x] = TOWALK;
            top--;    //����
        }
    }

    //��������·������û���߳���
    if (maze.map[11][11]!=WALKED)
    {
        maze.showMaze();
        MessageBoxA(0, "�Թ�û��ͨ·", "��ʾ", 0);
        return;

    }
}

void Stack::showThruWay()
{
    int i=0;
    string outstr = "";
    for (i=0; i<=top; i++)
    {
        ostringstream buf;
        string direction;
        switch (blocks[i].round_can_go)
        {
            case 0: direction = "��"; break;
            case 1: direction = " �� "; break;
            case 2: direction = "��"; break;
            case 3: direction = " �� "; break;
            default: direction = "end"; break;
        }
        buf << "(" << blocks[i].x << "," << blocks[i].y << "," << direction << ") ";
        outstr.append(buf.str());
        if (i%5==0)
        {
            outstr.append("\n");
        }
    }
    MessageBoxA(0, outstr.c_str(), "��ʾ", 0);
}