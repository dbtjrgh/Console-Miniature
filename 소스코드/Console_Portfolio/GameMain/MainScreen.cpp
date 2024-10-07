#include "MainScreen.h"
#include <mmsystem.h>    
#pragma comment(lib, "Winmm.lib")

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void clearLine(int line) // 줄 지우기 함수
{
	gotoxy(0, line);
	for (int i = 0; i < 100; ++i) 
	{ // 예시로 가로 길이를 80으로 가정
		cout << " ";
	}
}

void TextColor(int font, int backGround);
void TextColor(int font, int backGround)
{
	int Color = font + backGround * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void init() // 커서 지우는 함수
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void MainScreen::output1() // 메인 1
{
	init();

	system("cls");

	// 텍스트를 출력할 x, y 좌표
	gotoxy(52, 22);
	// 출력할 문자열을 선언합니다.
	cout << "이름 : ";
	cin >> playerName;


	gotoxy(47, 24);
	sentence = "안녕하세요, ";
	textAnimation(sentence, 100);
	cout << playerName;


	gotoxy(47, 26);
	sentence = "Please press Enter Key";
	textAnimation(sentence, 100);


	char ch;
	while (true) 
	{
		if (_kbhit()) 
		{ // 키보드 입력이 있을 때
			ch = _getch(); // 입력 받은 문자를 읽어옴
			if (ch == '\r') // 엔터 키가 입력되면 종료
			{
				clearLine(26);
				gotoxy(50, 26);

				sentence = "Loading ";
				textAnimation(sentence, 100);

				sentence = ". . .";
				textAnimation(sentence, 300);
				break;
			}
		}
		else
		{
			Sleep(500);
			clearLine(26);
			Sleep(500);
			gotoxy(47, 26);
			cout << sentence;
		}
	}

	// 게임 인트로 BGM 삽입
	PlaySound(TEXT("GameBGM.wav"), NULL, SND_FILENAME | SND_ASYNC);

	clearLine(26);
	Sleep(250);

	string art;
	gotoxy(0, 5);
	art = R"(			
		           ______                 
			  / ____/                
			 / /                   
			/ /___                    
			\____/	
		)";
	cout << art;

	Sleep(200);
	gotoxy(0, 5);

	art = R"(					
		           ______                                                    
			  / ____/____                       
			 / /    / __ \                          
			/ /___ / /_/ /                    
			\____/ \____/	
		)";
	cout << art;

	Sleep(200);
	gotoxy(0, 5);


	art = R"(							
		           ______                                           
			  / ____/____   ____                     
			 / /    / __ \ / __ \                        
			/ /___ / /_/ // / / /                    
			\____/ \____//_/ /_/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(
		           ______                                                        
			  / ____/____   ____   _____                   
			 / /    / __ \ / __ \ / ___/                     
			/ /___ / /_/ // / / /(__  )                        
			\____/ \____//_/ /_//____/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(  
		           ______                                                          
			  / ____/____   ____   _____ ____                    
			 / /    / __ \ / __ \ / ___// __ \                   
			/ /___ / /_/ // / / /(__  )/ /_/ /                     
			\____/ \____//_/ /_//____/ \____/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"( 
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /                  
			 / /    / __ \ / __ \ / ___// __ \ / /                        
			/ /___ / /_/ // / / /(__  )/ /_/ // /                   
			\____/ \____//_/ /_//____/ \____//_/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(  
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/                           
			                             
			                ____ ___
			               / __ `__ \
			              / / / / / /
			             /_/ /_/ /_/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/                           
			                            _      
			                ____ ___   (_)
			               / __ `__ \ / /
			              / / / / / // /
			             /_/ /_/ /_//_/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/                           
			                            _       
			                ____ ___   (_)____
			               / __ `__ \ / // __ \
			              / / / / / // // / / /
			             /_/ /_/ /_//_//_/ /_/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/                           
			                            _         _ 
			                ____ ___   (_)____   (_)
			               / __ `__ \ / // __ \ / /
			              / / / / / // // / / // /
			             /_/ /_/ /_//_//_/ /_//_/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/                           
			                            _         _                     
			                ____ ___   (_)____   (_)____ _
			               / __ `__ \ / // __ \ / // __ `/
			              / / / / / // // / / // // /_/ /
			             /_/ /_/ /_//_//_/ /_//_/ \__,_/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/                           
			                            _         _         __                   
			                ____ ___   (_)____   (_)____ _ / /_
			               / __ `__ \ / // __ \ / // __ `// __/
			              / / / / / // // / / // // /_/ // /_
			             /_/ /_/ /_//_//_/ /_//_/ \__,_/ \__/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/                           
			                            _         _         __                   
			                ____ ___   (_)____   (_)____ _ / /_ __  __
			               / __ `__ \ / // __ \ / // __ `// __// / / /
			              / / / / / // // / / // // /_/ // /_ / /_/ /
			             /_/ /_/ /_//_//_/ /_//_/ \__,_/ \__/ \__,_/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/                           
			                            _         _         __                   
			                ____ ___   (_)____   (_)____ _ / /_ __  __ _____
			               / __ `__ \ / // __ \ / // __ `// __// / / // ___/
			              / / / / / // // / / // // /_/ // /_ / /_/ // /
			             /_/ /_/ /_//_//_/ /_//_/ \__,_/ \__/ \__,_//_/
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);


	art = R"(
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/                           
			                            _         _         __                   
			                ____ ___   (_)____   (_)____ _ / /_ __  __ _____ ___ 
			               / __ `__ \ / // __ \ / // __ `// __// / / // ___// _ \
			              / / / / / // // / / // // /_/ // /_ / /_/ // /   /  __/
			             /_/ /_/ /_//_//_/ /_//_/ \__,_/ \__/ \__,_//_/    \___/ 
		)";
	cout << art;
	Sleep(200);
	gotoxy(0, 5);

	while (exit)
	{
		for (int i = 1; i < 16; i += 2)
		{
			if (_kbhit())
			{ // 키보드 입력이 있을 때
				ch = _getch(); // 입력 받은 문자를 읽어옴
				if (ch == '\r') // 엔터 키가 입력되면 종료
				{
					clearLine(26);
					gotoxy(50, 26);

					sentence = "Loading ";
					textAnimation(sentence, 100);

					sentence = ". . .";
					textAnimation(sentence, 500);
					system("cls");
					exit = false;
					break;
				}
			}
			else
			{
				Sleep(500);
				gotoxy(0, 5);
				TextColor(i, 0);
				sentence = R"(
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/                           
			                            _         _         __                   
			                ____ ___   (_)____   (_)____ _ / /_ __  __ _____ ___ 
			               / __ `__ \ / // __ \ / // __ `// __// / / // ___// _ \
			              / / / / / // // / / // // /_/ // /_ / /_/ // /   /  __/
			             /_/ /_/ /_//_//_/ /_//_/ \__,_/ \__/ \__,_//_/    \___/ 
		)";
				cout << sentence;
				sentence = "Please press Enter Key";
				clearLine(26);
				Sleep(500);
				gotoxy(47, 26);
				cout << sentence;
			}			
		}
	}
	
}

void displayMenu(int selectedOption)
{

	gotoxy(50, 24);
	cout << "◎ 게임메뉴 ◎";
	gotoxy(50, 26);
	cout << (selectedOption == 0 ? "▶ " : "  ") << "게임시작";
	gotoxy(50, 28);
	cout << (selectedOption == 1 ? "▶ " : "  ") << "게임설명";
	gotoxy(50, 30);
	cout << (selectedOption == 2 ? "▶ " : "  ") << "설명생략";
	gotoxy(50, 32);
	cout << (selectedOption == 3 ? "▶ " : "  ") << "게임종료";
}

int MainScreen::output2()
{

	// 처음은 첫 번째 옵션 선택
	selectedOption = 0;
	

	system("cls");
	init();
	gotoxy(0, 5);
	int i = rand() % 15 + 1;
	TextColor(i, 0);
	sentence = R"(
		           ______                            __                              
			  / ____/____   ____   _____ ____   / /___                           
			 / /    / __ \ / __ \ / ___// __ \ / // _ \                          
			/ /___ / /_/ // / / /(__  )/ /_/ // //  __/                          
			\____/ \____//_/ /_//____/ \____//_/ \___/                           
			                            _         _         __                   
			                ____ ___   (_)____   (_)____ _ / /_ __  __ _____ ___ 
			               / __ `__ \ / // __ \ / // __ `// __// / / // ___// _ \
			              / / / / / // // / / // // /_/ // /_ / /_/ // /   /  __/
			             /_/ /_/ /_//_//_/ /_//_/ \__,_/ \__/ \__,_//_/    \___/ 
		)";
	cout << sentence;
	TextColor(15, 0);

	

	gotoxy(44, 20);
	cout << "환영합니다. " << playerName;
	sentence = "님";
	textAnimation(sentence, 20);

	int key;
	while (1)
	{
		displayMenu(selectedOption);

		key = _getch();
		if (key == 224)
		{
			key = _getch();
			switch (key)
			{
			case 72:
				if (selectedOption > 0)
					selectedOption--;
				break;
			case 80:
				if (selectedOption < 3)
					selectedOption++;
				break;
			}
		}
		switch (key)
		{
		case 119: // 위쪽 키
			if (selectedOption > 0)
				selectedOption--;
			break;

		case 115: // 아래쪽 키
			if (selectedOption < 3)
				selectedOption++;
			break;		

		case 13: // 엔터 키
			switch (selectedOption) 
			{
			case 0: // 게임시작
				return 0;
			case 1: // 게임설명
				return 1;
			case 2: // 게임룰 스킵
				return 2;
			case 3: // 게임종료
				return 3;	
			}
		}

	}
}

void MainScreen::output3()
{
	system("cls");
	init();

	gotoxy(48, 11);
	sentence = "    ◆ 게임설명 ◆";
	textAnimation(sentence, 50);

	gotoxy(32, 13);
	sentence = "이 게임은 여러 게임을 통해 점수를 획득하는 게임입니다. ";
	textAnimation(sentence, 20);

	gotoxy(40, 15);
	sentence = "게임은 실력, 운, 판단 등이 요구됩니다.";
	textAnimation(sentence, 20);

	gotoxy(49, 17);
	sentence = "5가지 게임이 있습니다. ";
	textAnimation(sentence, 20);

	gotoxy(46, 19);
	sentence = "각 게임은 30초간 진행합니다.";
	textAnimation(sentence, 20);

	gotoxy(49, 21);
	sentence = "게임 순서는 랜덤입니다.";
	textAnimation(sentence, 20);

	gotoxy(49, 23);
	sentence = "Please press Enter Key";
	textAnimation(sentence, 20);

	char ch;
	while (true)
	{
		if (_kbhit())
		{ 
			ch = _getch(); 
			if (ch == '\r') 
			{
				clearLine(23);
				gotoxy(55, 23);

				sentence = "Loading ";
				textAnimation(sentence, 100);

				sentence = ". . .";
				textAnimation(sentence, 100);
				system("cls");
				break;
			}
		}
		else
		{
			Sleep(500);
			clearLine(23);
			gotoxy(49, 23);
			Sleep(500);	
			cout << sentence;
		}
	}
}

void MainScreen::scoreStatus()
{
	system("mode con:cols=120 lines=40");
	GameBoard* gameBoard = GameBoard::getInstance();

	system("cls");

	init();

	gotoxy(46, 11);
	cout << playerName;
	sentence = "님의 현재 스코어 : ";
	textAnimation(sentence, 50);
	cout << gameBoard->getScore() << "점" << endl;

	if (n < 6)
	{
		gotoxy(46, 13);
		cout << n;
		sentence = "번째 게임을 진행하고싶다면";
		textAnimation(sentence, 20);
		n++;
	}
	else
	{
		gotoxy(46, 13);
		sentence = " 마지막 게임이였습니다. ";
		textAnimation(sentence, 20);

		gotoxy(46, 15);
		sentence = " 최종 결과를 보고싶다면";
		textAnimation(sentence, 20);

	}
	

	gotoxy(47, 17);
	sentence = "Please press Enter Key";
	textAnimation(sentence, 20);

	char ch;
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == '\r')
			{
				clearLine(17);
				gotoxy(55, 17);

				sentence = "Loading ";
				textAnimation(sentence, 100);

				sentence = ". . .";
				textAnimation(sentence, 300);
				system("cls");
				break;
			}
		}
		else
		{
			Sleep(500);
			clearLine(17);
			gotoxy(47, 17);
			Sleep(500);
			cout << sentence;
		}
	}
}


void MainScreen::finalscore()
{
	GameBoard* gameBoard = GameBoard::getInstance();

	extern int AvoidanceScore;
	extern int Block_BreakerScore;
	extern int ChickenScore;
	extern int RunningScore;
	extern int SnakeScore;

	system("cls");
	init();

	gotoxy(46, 11);
	cout << playerName;
	sentence = "님의 최종 점수 : ";
	textAnimation(sentence, 50);
	cout << gameBoard->getScore() << "점";

	gotoxy(54, 13);
	sentence = "★ 통계 ★";
	textAnimation(sentence, 50);

	gotoxy(50, 15);
	sentence = "총알피하기 : ";
	textAnimation(sentence, 20);
	cout << AvoidanceScore << "점";

	gotoxy(50, 17);
	sentence = "벽돌깨기   : ";
	textAnimation(sentence, 20);
	cout << Block_BreakerScore << "점";

	gotoxy(50, 19);
	sentence = "러시안룰렛 : ";
	textAnimation(sentence, 20);
	cout << ChickenScore << "점";

	gotoxy(50, 21);
	sentence = "크롬공룡   : ";
	textAnimation(sentence, 20);
	cout << RunningScore << "점";

	gotoxy(50, 23);
	sentence = "스네이크   : ";
	textAnimation(sentence, 20);
	cout << SnakeScore << "점";
}
