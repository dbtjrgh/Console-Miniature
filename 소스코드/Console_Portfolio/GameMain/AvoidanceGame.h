#pragma once
#include "MainScreen.h"
#include "GameBoard.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <conio.h>
#include <vector>

using namespace std;

extern int AvoidanceScore;

class Avoidance
{
private:
	bool gameOver; // 게임이 끝났는지 여부를 저장하는 변수
	
	string a;

public:

	void Play();
	void Rule(); // 시작전 설명
	

	void updateScore(int newScore);
	void resetScore();

	struct Bullet
	{
		int x;
		int y;
		int dx;
		int dy;
	};
};