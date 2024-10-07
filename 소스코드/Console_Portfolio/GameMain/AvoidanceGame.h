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
	bool gameOver; // ������ �������� ���θ� �����ϴ� ����
	
	string a;

public:

	void Play();
	void Rule(); // ������ ����
	

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