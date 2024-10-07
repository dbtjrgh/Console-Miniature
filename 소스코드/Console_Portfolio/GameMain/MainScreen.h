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
	// ���ڿ��� �� ���ڸ� �ϳ��� ����մϴ�.
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

	// ���� ���� Ƚ��	
	int n = 2;

public:
	string playerName;
	int selectedOption;
		
	void output1();
	int  output2();
	void output3();
	void scoreStatus();
	// ��������
	void finalscore();
	
};