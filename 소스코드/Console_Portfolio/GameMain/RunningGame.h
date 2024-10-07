#pragma once
#include "MainScreen.h"
#include "GameBoard.h"
#include <iostream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

extern int RunningScore;
using namespace std;

class Running
{
private:
    string sentence;
    bool gameOver = false; // 게임이 끝났는지 여부를 저장하는 변수

public:
    void Rule();
    void Play();
    void updateScore(int newScore);
    void resetScore();

    void GotoXY(int x, int y);
    void DrawDino(int dinoY);
    void DrawTree1(int treeX1);
    void DrawTree2(int treeX2);
    bool isCollision(const int treeX1, const int treeX2, const int dinoY);
};

