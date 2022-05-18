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

    settextstyle(40, 0, "等线", 0, 0, 400, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);
    setbkmode(TRANSPARENT);
    settextcolor(WHITE);
}

int welcome()
{
    char wc[48]="————走迷宫————";
    outtextxy((480 - textwidth(wc)) / 2, 80, wc);
    solidrectangle(160, 200, 320, 260);
    solidrectangle(160, 320, 320, 380);

    
    char s[10]="开始游戏";
    char ss[10]="退出";
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
    char wc[48]="————选择模式————";
    outtextxy((480 - textwidth(wc)) / 2, 80, wc);
    solidrectangle(120, 200, 360, 260);
    solidrectangle(120, 320, 360, 380);

    char s[20]="自己绘制地图";
    char ss[20]="选择系统地图";
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
    map[1][1] = START_END; map[10][10] = START_END;    //高亮起点和终点位置
    showMaze();
    int x=0, y=0;

    MessageBox(0, "地图左上角和右下角紫色方块代表起点终点.\n用鼠标左击方块绘制地图，完成绘制后，右击终点方块.\n请不要点击最外一圈的围墙方块.", "绘制", 0);
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
    char wc[48]="————选择地图————";
    outtextxy((480 - textwidth(wc)) / 2, 80, wc);

    //填充矩形
    solidrectangle(160, 180, 320, 240);
    solidrectangle(160, 280, 320, 340);
    solidrectangle(160, 380, 320, 440);

    char sA[10]="地图A";
    char sB[10]="地图B";
    char sC[10]="地图C";
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



//绘制
void MAZE::showMaze()
{
    clearrectangle(0, 0, 480, 480);

    for (int y = 0; y < WINDOW_HEIGHT / BLOCK_SIZE; y++)
    {
        for (int x = 0; x < WINDOW_WIDTH / BLOCK_SIZE; x++)
        {
            //没有走过，或者此路不通
            if (map[y][x] == TOWALK)
            {
                setcolor(RED);
                setfillcolor(DARKGRAY);
                fillrectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
                rectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
            }

            //障碍物
            if (map[y][x] == BARRIER)
            {
                setcolor(RED);
                setfillcolor(BLACK);
                fillrectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
                rectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
            }

            //已经走过的路径
            if (map[y][x] == WALKED)
            {
                setcolor(RED);
                setfillcolor(GREEN);
                fillrectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
                rectangle(x*BLOCK_SIZE, y*BLOCK_SIZE, (x + 1)*BLOCK_SIZE, (y + 1)*BLOCK_SIZE);
            }
            //起点和终点
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
            maze.showMaze();    //先直接在图上直观地画出通路
            showThruWay();    //再用提示框以文本形式显示通路上各方块信息
            return;
        }

        find=0;
        while (direction<4&&find==0)    //检查当前方块周围（左下右上）可以走的方向 
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
            }    //找到了下一个可走方块（x，y） 
        }

        if (find==1)    //走到可走方块，并将此方块入栈
        {
            blocks[top].round_can_go = direction;    //标记走的方向
            top++;    //往下走
            blocks[top].x = x;
            blocks[top].y = y;
            blocks[top].round_can_go = -1;
            maze.map[y][x] = WALKED;
        }
        else    //未找到可走方块，出栈，后退
        {
            maze.map[blocks[top].y][blocks[top].x] = TOWALK;
            top--;    //后退
        }
    }

    //走完所有路，发现没能走出来
    if (maze.map[11][11]!=WALKED)
    {
        maze.showMaze();
        MessageBoxA(0, "迷宫没有通路", "提示", 0);
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
            case 0: direction = "←"; break;
            case 1: direction = " ↓ "; break;
            case 2: direction = "→"; break;
            case 3: direction = " ↑ "; break;
            default: direction = "end"; break;
        }
        buf << "(" << blocks[i].x << "," << blocks[i].y << "," << direction << ") ";
        outstr.append(buf.str());
        if (i%5==0)
        {
            outstr.append("\n");
        }
    }
    MessageBoxA(0, outstr.c_str(), "提示", 0);
}