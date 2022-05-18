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
        initial();    //���ý��棬��ť�������
        if (welcome()==BOTTUN_DOWN)    //�ڻ�ӭ�����˳�����
        {
            closegraph();
            return 0;
        }
        else
        {
            if (chooseMode()==BOTTUN_DOWN)    //ѡ��ϵͳ���õ�ͼ
            {
                MAZE mazeA, mazeB, mazeC;
                drawMazeBySystem(mazeA, mazeB, mazeC);    //����Ĭ�ϵ�ͼ
                Stack stack;
                switch (chooseMaze()) {
                case MAP_A: stack.findWay(mazeA); break;
                case MAP_B: stack.findWay(mazeB); break;
                case MAP_C: stack.findWay(mazeC); break;
                }
            }
            else    //ѡ���Լ�����ͼ
            {
                MAZE mazeDraw;
                Stack stack;
                mazeDraw.drawMazeByPlayer();
                stack.findWay(mazeDraw);
            }
        }     
    }
}

