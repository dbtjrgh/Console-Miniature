#pragma once
#include "MainScreen.h"
#include "GameBoard.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

extern int Block_BreakerScore;

class Block_Breaker

{
private:
    string sentence;
    bool gameOver;
    int prevPaddleX;
    int prevBallX;
    int prevBallY;
    int remainingTime;
    clock_t startTime;

public:
    void Play();
    void Rule();
    void draw();
    void update();
    void paddleControl();
    void updateScore(int newScore);
    void resetScore();

};
