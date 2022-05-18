#pragma once
#include <graphics.h>
#include <iostream>
#include "setup.h"
using namespace std;

//add some commit
//now in branch b

int main()
{
    while (true)
    {
        initial();    //设置界面，按钮，字体等
        if (welcome()==BOTTUN_DOWN)    //在欢迎界面退出程序
        {
            closegraph();
            return 0;
        }
        else
        {
            if (chooseMode()==BOTTUN_DOWN)    //选择系统内置地图
            {
                MAZE mazeA, mazeB, mazeC;
                drawMazeBySystem(mazeA, mazeB, mazeC);    //绘制默认地图
                Stack stack;
                switch (chooseMaze()) {
                case MAP_A: stack.findWay(mazeA); break;
                case MAP_B: stack.findWay(mazeB); break;
                case MAP_C: stack.findWay(mazeC); break;
                }
            }
            else    //选择自己画地图
            {
                MAZE mazeDraw;
                Stack stack;
                mazeDraw.drawMazeByPlayer();
                stack.findWay(mazeDraw);
            }
        }     
    }
}

