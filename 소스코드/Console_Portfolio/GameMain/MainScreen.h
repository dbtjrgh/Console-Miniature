#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <conio.h>
#include "GameBoard.h"
#include "GameManager.h"

using namespace std;

void gotoxy(int x, int y);

inline void textAnimation(const string& s, int delay)
{
	// 문자열의 각 문자를 하나씩 출력합니다.
	for (const auto c : s)
	{
		cout << c << flush;
		this_thread::sleep_for(chrono::milliseconds(delay));
	}
}

void clearLine(int line);
void TextColor(int font, int backGround);
void init();

class MainScreen
{
private:
	
	string sentence;
	bool exit = true;
	char input;
	int x;
	int y;
	int check = 1;

	// 게임 순서 횟수	
	int n = 2;

public:
	string playerName;
	int selectedOption;
		
	void output1();
	int  output2();
	void output3();
	void scoreStatus();
	// 최종점수
	void finalscore();
	
};