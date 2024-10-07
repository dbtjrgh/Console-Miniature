#pragma once

#include "MainScreen.h"
#include "GameBoard.h"
#include <vector>
#include <iostream>

using namespace std;

struct Point
{
    int x, y;
};

extern int SnakeScore;

class Snake 
{
private:

    string sentence;
    const int width = 50;
    const int height = 25;
    const int INITIAL_SNAKE_LENGTH =5;
    const string HEAD_SYMBOL = "��"; // �Ӹ�
    const string BODY_SYMBOL = "��"; // ����
    const char FOOD_SYMBOL1 = '$'; // ����
    const char FOOD_SYMBOL2 = '$'; // ����

    bool gameOver;
    Point snake[100];
    Point fruit1;
    Point fruit2;
    int tailLength;
    int score;
    int direction; // 0: ��, 1: ��, 2: ��, 3: ��
    int startX = 21;
    int startY = 5;
    int remainingTime;
    int FPSnum;
    clock_t startTime;

public:
    void Rule();
    void Play();
    void Setup();
    void updateScore(int newScore);
    void resetScore();

    void Draw();
    void Logic();
    void CheckCollision();
    void SetCursorPosition(int x, int y);
    void DrawScore();
};


