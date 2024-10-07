#include "ChickenGame.h"

using namespace std;

bool playerWin = false;

void Chicken::Rule()
{
	GameBoard* gameBoard = GameBoard::getInstance();

	system("cls");
	system("mode con:cols=120 lines=40");

	init();
	
	gotoxy(48, 11);
	sentence = "  러시안룰렛 ";
	textAnimation(sentence, 50);

	gotoxy(50, 13);
	sentence = "◆ 게임룰 ◆";
	textAnimation(sentence, 50);

	gotoxy(46, 15);
	sentence = "플레이어 VS 컴퓨터 ";
	textAnimation(sentence, 50);

	gotoxy(40, 17);
	sentence = "조작법 \"Z\" or \"C\" 꼭 누르고 있기";
	textAnimation(sentence, 50);

	gotoxy(34, 19);
	sentence = " Z : 자신을 향해 발사   C : 컴퓨터에게 발사 ";
	textAnimation(sentence, 50);

	gotoxy(35, 21);
	sentence = "권총을 이용해 한명이 실탄을 맞으면 게임종료";
	textAnimation(sentence, 10);

	gotoxy(35, 23);
	sentence = "총알은 총 6발. 공포탄 5발, 실탄 1발씩 존재";
	textAnimation(sentence, 10);

	gotoxy(32, 25);
	sentence = "공포탄일때 자신에게 발사 시 한번 더 쏠 기회 획득";
	textAnimation(sentence, 10);

	gotoxy(34, 27);
	sentence = "플레이어가 먼저 진행 , 총알 순서는 랜덤";
	textAnimation(sentence, 10);

	gotoxy(36, 29);
	sentence = "플레이어 승리 스코어 300점, 패배 0점";
	textAnimation(sentence, 10);

	gotoxy(36, 31);
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
				clearLine(31);
				gotoxy(42, 31);

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
			clearLine(31);
			gotoxy(36, 31);
			Sleep(500);
			cout << sentence;
		}
	}
}

void Chicken::PlayerTurn()
{
	gotoxy(23, 7);
	TextColor(10, 0); cout << "   O         "; TextColor(12, 0); cout << "             O    "; TextColor(15, 0);
	gotoxy(23, 8);
	TextColor(10, 0); cout << " /｜\\  ____      "; TextColor(12, 0); cout << "        /｜\\ "; TextColor(15, 0);
	gotoxy(23, 9);
	TextColor(10, 0); cout << "｜｜ \\｜ ┌―┚     "; TextColor(12, 0); cout << "       / ｜ \\"; TextColor(15, 0);
	gotoxy(23, 10);
	TextColor(10, 0); cout << " / \\   ￣       "; TextColor(12, 0); cout << "          / \\ "; TextColor(15, 0);
	gotoxy(23, 11);
	TextColor(10, 0); cout << "｜ ｜             "; TextColor(12, 0); cout << "       ｜ ｜  "; TextColor(15, 0);
}

void Chicken::PlayerTurnShoot()
{
	gotoxy(23, 7);
	TextColor(10, 0); cout << "   O         "; TextColor(12, 0); cout << "             O     "; TextColor(15, 0);
	gotoxy(23, 8);
	TextColor(10, 0); cout << " /｜\\  ____    "; TextColor(12, 0); cout << "          /｜\\ "; TextColor(15, 0);
	gotoxy(23, 9);
	TextColor(10, 0); cout << "｜｜ \\｜ ┌―┚    ";  TextColor(14, 0); cout << "●"; TextColor(12, 0);  cout << "       / ｜ \\"; TextColor(15, 0);
	gotoxy(23, 10);
	TextColor(10, 0); cout << " / \\   ￣       "; TextColor(12, 0); cout << "          / \\ "; TextColor(15, 0);
	gotoxy(23, 11);
	TextColor(10, 0); cout << "｜ ｜           "; TextColor(12, 0); cout << "         ｜ ｜ "; TextColor(15, 0);
}

void Chicken::PlayerTurnPlayer()
{
	gotoxy(23, 7);
	TextColor(10, 0); cout << "   O   _____     "; TextColor(12, 0); cout << "         O     "; TextColor(15, 0);
	gotoxy(23, 8);
	TextColor(10, 0); cout << " /｜\\  ┖―┐ ｜   "; TextColor(12, 0); cout << "         /｜\\  "; TextColor(15, 0);
	gotoxy(23, 9); 
	TextColor(10, 0); cout << "｜｜ \\    ￣     "; TextColor(12, 0); cout << "       / ｜ \\ "; TextColor(15, 0);
	gotoxy(23, 10);
	TextColor(10, 0); cout << " / \\           "; TextColor(12, 0); cout << "           / \\"; TextColor(15, 0);
	gotoxy(23, 11);
	TextColor(10, 0); cout << "｜ ｜          "; TextColor(12, 0); cout << "          ｜ ｜ "; TextColor(15, 0);
}
void Chicken::PlayerTurnPlayerShoot()
{
	gotoxy(23, 7);
	TextColor(10, 0); cout << "   O "; TextColor(14, 0); cout << "●"; TextColor(10, 0); cout << " _____      "; TextColor(12, 0); cout << "        O    "; TextColor(15, 0);
	gotoxy(23, 8);
	TextColor(10, 0); cout << " /｜\\  ┖―┐ ｜   "; TextColor(12, 0); cout << "         /｜\\ "; TextColor(15, 0);
	gotoxy(23, 9); 
	TextColor(10, 0); cout << "｜｜ \\    ￣    "; TextColor(12, 0); cout << "        / ｜ \\ "; TextColor(15, 0);
	gotoxy(23, 10);
	TextColor(10, 0); cout << " / \\          "; TextColor(12, 0); cout << "            / \\"; TextColor(15, 0);
	gotoxy(23, 11);
	TextColor(10, 0); cout << "｜ ｜           "; TextColor(12, 0); cout << "         ｜ ｜  "; TextColor(15, 0);
}

void Chicken::EnemyTurn()
{
	gotoxy(23, 16);
	TextColor(10, 0); cout << "   O          "; TextColor(12, 0); cout << "           O     "; TextColor(15, 0);
	gotoxy(23, 17);
	TextColor(10, 0); cout << " /｜\\        "; TextColor(12, 0); cout << "    _____  /｜\\ "; TextColor(15, 0);
	gotoxy(23, 18);
	TextColor(10, 0); cout << "｜｜ \\        "; TextColor(12, 0); cout << "   ┖―┐ ｜/ ｜ \\ "; TextColor(15, 0);
	gotoxy(23, 19);
	TextColor(10, 0); cout << " / \\          "; TextColor(12, 0); cout << "     ￣    / \\  "; TextColor(15, 0);
	gotoxy(23, 20);
	TextColor(10, 0); cout << "｜ ｜            "; TextColor(12, 0); cout << "       ｜ ｜  "; TextColor(15, 0);
}
void Chicken::EnemyTurnShoot()
{
	gotoxy(23, 16);
	TextColor(10, 0); cout << "   O          "; TextColor(12, 0); cout << "           O     "; TextColor(15, 0);
	gotoxy(23, 17);
	TextColor(10, 0); cout << " /｜\\         "; TextColor(12, 0); cout <<  "   _____  /｜\\ "; TextColor(15, 0);
	gotoxy(23, 18);
	TextColor(10, 0); cout << "｜｜ \\  "; TextColor(14, 0); cout << "●"; TextColor(12, 0); cout << "        ┖―┐ ｜/ ｜ \\ "; TextColor(15, 0);
	gotoxy(23, 19);
	TextColor(10, 0); cout << " / \\          "; TextColor(12, 0); cout << "     ￣    / \\  "; TextColor(15, 0);
	gotoxy(23, 20);
	TextColor(10, 0); cout << "｜ ｜         "; TextColor(12, 0); cout << "          ｜ ｜  "; TextColor(15, 0);
}
void Chicken::EnemyTurnEnemy()
{
	gotoxy(23, 16);
	TextColor(10, 0); cout << "   O         "; TextColor(12, 0); cout << "    _____   O     "; TextColor(15, 0);
	gotoxy(23, 17);
	TextColor(10, 0); cout << " /｜\\        "; TextColor(12, 0); cout << "   ｜ ┌―┚  /｜\\ "; TextColor(15, 0);
	gotoxy(23, 18);
	TextColor(10, 0); cout << "｜｜ \\       "; TextColor(12, 0); cout << "    ￣    / ｜ \\ "; TextColor(15, 0);
	gotoxy(23, 19);
	TextColor(10, 0); cout << " / \\         "; TextColor(12, 0); cout << "            / \\  "; TextColor(15, 0);
	gotoxy(23, 20);
	TextColor(10, 0); cout << "｜ ｜         "; TextColor(12, 0); cout << "          ｜ ｜  "; TextColor(15, 0);
}
void Chicken::EnemyTurnEnemyShoot()
{
	gotoxy(23, 16);
	TextColor(10, 0); cout << "   O         "; TextColor(12, 0); cout << "    _____ "; TextColor(14, 0); cout << "●"; TextColor(12, 0); cout << " O     "; TextColor(15, 0);
	gotoxy(23, 17);
	TextColor(10, 0); cout << " /｜\\       "; TextColor(12, 0); cout << "    ｜ ┌―┚  /｜\\ "; TextColor(15, 0);
	gotoxy(23, 18);
	TextColor(10, 0); cout << "｜｜ \\       "; TextColor(12, 0); cout << "    ￣    / ｜ \\ "; TextColor(15, 0);
	gotoxy(23, 19);
	TextColor(10, 0); cout << " / \\        "; TextColor(12, 0); cout << "             / \\  "; TextColor(15, 0);
	gotoxy(23, 20);
	TextColor(10, 0); cout << "｜ ｜        "; TextColor(12, 0); cout << "           ｜ ｜  "; TextColor(15, 0);
}



void CleanPlayer()
{
	gotoxy(60, 9);
	cout << "                                                 ";
	gotoxy(60, 11);
	cout << "                                                 ";
	gotoxy(60, 13);
	cout << "                                                 ";
	gotoxy(60, 15);
	cout << "                                                 ";
	gotoxy(60, 17);
}

void CleanEnemy()
{
	gotoxy(60, 20);
	cout << "                                                 ";
	gotoxy(60, 22);
	cout << "                                                 ";
	gotoxy(60, 24);
	cout << "                                                 ";
	gotoxy(60, 26);
	cout << "                                                 ";
	gotoxy(60, 28);
}

void BulletsRemaining(int remainingBullets)
{
	gotoxy(60, 7); // 원하는 위치로 커서 이동
	cout << "남은 총알 : " << remainingBullets << "발"; // 남은 총알 수를 출력합니다.
}

void Clean()
{
	gotoxy(23, 7);
	cout << "                                ";
	gotoxy(23, 8);
	cout << "                                ";
	gotoxy(23, 9);
	cout << "                                ";
	gotoxy(23, 10);
	cout << "                                ";
	gotoxy(23, 11);
	cout << "                                ";
	gotoxy(23, 16);
	cout << "                                ";
	gotoxy(23, 17);
	cout << "                                ";
	gotoxy(23, 18);
	cout << "                                ";
	gotoxy(23, 19);
	cout << "                                ";
	gotoxy(23, 20);
	cout << "                                ";
}

int ChickenScore = 0;

void Chicken::updateScore(int newScore)
{
	ChickenScore += newScore;
}
void Chicken::resetScore()
{
	ChickenScore = 0;
}

void Chicken::ChickenLogic()
{
	MainScreen mainscreen;
	// 총알 초기화
	int bullets[6] = { 0 }; // 6발의 총알, 실탄이 있는 위치는 1로 표시

	// 실탄 위치 랜덤 선택
	srand(time(NULL));
	// 0 ~ 5 중에 하나만 실탄
	int idx = rand() % 6;
	bullets[idx] = 1;
	int turn = 0;

	bool gameOver = false; // 게임 오버 여부
	bool playerTurn = true; // 플레이어 차례 여부
	bool shootSelf;

	// 타이머 변수 초기화
	time_t startTime = time(nullptr);
	int remainingTime;

	Chicken chicken;

	// 번갈아가면서 플레이어와 컴퓨터가 총을 쏘는 게임 진행
	while (!gameOver)
	{
		// 타이머 업데이트
		time_t currentTime = time(nullptr);
		remainingTime = 30 - (currentTime - startTime);



		if (playerTurn)
		{
			Sleep(1000);
			CleanPlayer();
						
			BulletsRemaining(6 - turn);
			GameBoard* gameBoard = GameBoard::getInstance();

			// 타이머 출력
			gotoxy(60, 5);
			cout << "시간 : " << remainingTime << "초  ";
			gotoxy(60, 6);
			cout << "점수 : " << gameBoard->getScore() << "점";

			if (remainingTime < 1)
			{
				gameOver = true;
			}

			Clean();

			PlayerTurn();

			gotoxy(60, 9);
			cout << "                                                 ";
			gotoxy(60, 9);
			cout << "플레이어 차례입니다. Z : 나 , C : 상대";

			if (GetAsyncKeyState('Z') & 0x8000)
			{
				gotoxy(60, 11);
				cout << "                              ";
				gotoxy(60, 11);
				sentence = "자신을 쏩니다.";
				textAnimation(sentence, 20);
				PlayerTurnPlayer();
				Sleep(500);

				// 플레이어가 자신을 쏠 때
				if (bullets[turn] == 0)
				{
					// 공포탄을 맞은 경우
					gotoxy(60, 13);
					cout << "                                               ";
					gotoxy(60, 13);
					cout << "공포탄이였습니다!";
					gotoxy(60, 15);
					cout << "                                               ";
					gotoxy(60, 15);
					cout << "한 번 더 기회를 얻습니다.";
					Sleep(500);
					playerTurn = true; // 플레이어의 차례로 다시 돌아감
					turn++;
				}
				else if ((bullets[turn] != 0))
				{
					// 실탄을 맞은 경우
					Clean();
					PlayerTurnPlayerShoot();
					gotoxy(60, 13);
					cout << "                                               ";
					gotoxy(60, 13);
					cout << "실탄이였습니다!";
					gotoxy(60, 15);
					cout << "                                               ";
					gotoxy(60, 15);
					cout << "게임 종료!";
					gotoxy(60, 17);
					cout << "                                               ";
					gotoxy(60, 17);
					TextColor(12, 0); cout << "플레이어 패배!"; TextColor(15, 0);
					gameOver = true;
					Sleep(2000);
				}
			}
			else if (GetAsyncKeyState('C') & 0x8000)
			{
				gotoxy(60, 11);
				cout << "                                               ";
				gotoxy(60, 11);
				
				sentence = "플레이어가 컴퓨터를 쏩니다.";
				textAnimation(sentence, 20);
				Sleep(500);
				// 플레이어가 상대를 쏠 때
				if (bullets[turn] == 1)
				{
					// 실탄을 맞은 경우
					Clean();
					PlayerTurnShoot();
					gotoxy(60, 13); 
					cout << "                                               ";
					gotoxy(60, 13);
					cout << "실탄을 맞혔습니다!";
					gotoxy(60, 15);
					cout << "                                               ";
					gotoxy(60, 15);
					cout << "게임 종료!";
					gotoxy(60, 17);
					cout << "                                               ";
					gotoxy(60, 17);
					TextColor(10, 0);  cout << "플레이어 승리! 300점 획득!"; TextColor(15, 0);
					PlaySound(TEXT("Getting ITEM.wav"), NULL, SND_FILENAME | SND_ASYNC);
					Sleep(2000);
					gameBoard->updateScore(300);
					chicken.updateScore(300);
					playerWin = true;
					gameOver = true;
					
				}
				else if (bullets[turn] != 1)
				{
					// 실탄을 맞지 않은 경우
					gotoxy(60, 13);
					cout << "                                               ";
					gotoxy(60, 13);
					cout << "공포탄입니다.";
					Sleep(500);
					turn++;
					playerTurn = false; // 플레이어 차례 종료
				}
			}
			gotoxy(60, 5);
			cout << "시간 : " << remainingTime << "초  ";
		}
		
		else if (!playerTurn)
		{
			gotoxy(60, 5);
			cout << "시간 : " << remainingTime << "초  ";
		    CleanEnemy();			
			gotoxy(60, 20);
			sentence = "컴퓨터 차례입니다.";
			textAnimation(sentence, 50);			
			BulletsRemaining(6 - turn);
			Clean();
			EnemyTurn();
			Sleep(500);
			// 3초 대기 후 컴퓨터가 총을 쏩니다.
			if (turn == 5)
			{
				shootSelf = 0;
			}
			else
			{
				shootSelf = (rand() % 2) == 0;
			}
			if (shootSelf)
			{
				gotoxy(60, 5);
				cout << "시간 : " << remainingTime << "초  ";
				gotoxy(60, 22);
				cout << "                                               ";
				gotoxy(60, 22);
				cout << "컴퓨터가 자신을 쏩니다.";
				Clean();
				EnemyTurnEnemy();
				Sleep(500);
				// 컴퓨터가 자신을 쏠 때
				if (bullets[turn] == 0)
				{
					// 공포탄을 맞은 경우
					gotoxy(60, 24);
					cout << "                                               ";
					gotoxy(60, 24);
					cout << "공포탄이였습니다!";
					gotoxy(60, 26);
					cout << "                                               ";
					gotoxy(60, 26);
					cout << "한 번 더 기회를 얻습니다.";
					Sleep(500);
					playerTurn = false; // 플레이어 차례 종료
					turn++;
				}
				else
				{
					// 실탄을 맞은 경우
					Clean();
					EnemyTurnEnemyShoot();
					gotoxy(60, 24);
					cout << "                                               ";
					gotoxy(60, 24);
					cout << "실탄이였습니다!";
					gotoxy(60, 26);
					cout << "                                               ";
					gotoxy(60, 26);
					cout << "게임 종료!";
					Sleep(2000);
					gotoxy(60, 28);
					cout << "                                               ";
					gotoxy(60, 28);
					PlaySound(TEXT("Getting ITEM.wav"), NULL, SND_FILENAME | SND_ASYNC);
					TextColor(10, 0); cout << "플레이어 승리! 300점 획득!"; TextColor(15, 0);
					GameBoard* gameBoard = GameBoard::getInstance();
					Sleep(2000);
					gameBoard->updateScore(300);
					chicken.updateScore(300);
					playerWin = true;
					gameOver = true;
					
				}
				gotoxy(60, 5);
				cout << "시간 : " << remainingTime << "초  ";
			}
			else
			{
				GameBoard* gameBoard = GameBoard::getInstance();

				// 타이머 출력
				gotoxy(60, 5);
				cout << "시간 : " << remainingTime << "초  ";
				gotoxy(60, 6);
				cout << "점수 : " << gameBoard->getScore() << "점";

				gotoxy(60, 22);
				cout << "                                               ";
				gotoxy(60, 22);
				cout << "컴퓨터가 플레이어를 쏩니다.";
				Sleep(500);

				// 컴퓨터가 상대를 쏠 때
				if (bullets[turn] == 1)
				{
					Clean();
					EnemyTurnShoot();
					gotoxy(60, 24);
					// 실탄을 맞춘 경우
					cout << "                                               ";
					gotoxy(60, 24);
					cout << "실탄을 맞혔습니다!";
					gotoxy(60, 26);
					cout << "                                               ";
					gotoxy(60, 26);
					cout << "게임 종료! ";
					gotoxy(60, 28);
					cout << "                                               ";
					gotoxy(60, 28);
					TextColor(12, 0); cout << "플레이어 패배!"; TextColor(15, 0);
					gameOver = true;
					Sleep(2000);
				}
				else
				{
					// 실탄을 맞지 않은 경우
					gotoxy(60, 24);					
					cout << "                                               ";
					gotoxy(60, 24);
					cout << "공포탄입니다.";
					Sleep(500);
					playerTurn = true; // 플레이어 차례로 변경
					turn++;
				}
				gotoxy(60, 5);
				Sleep(500);
				cout << "시간 : " << remainingTime << "초  ";
			}			
		}
	}

}


void Chicken::Play()
{
	system("cls");
	system("mode con:cols=100 lines=32");

	init();

	gameOver = false;

	int width = 35; // 테두리의 폭
	int height = 20; // 테두리의 높이

	GameBoard* gameBoard = GameBoard::getInstance();

	// 테두리 그리기
	gameBoard->drawBorder(width, height);

	gotoxy((width + 25 ) / 2, height / 2);
	cout << "3초 후 시작됩니다.";
	Sleep(1000);

	gotoxy((width + 25)  / 2, height / 2);
	cout << "2초 후 시작됩니다.";
	Sleep(1000);

	gotoxy((width + 25)  / 2, height / 2);
	cout << "1초 후 시작됩니다.";
	Sleep(1000);	

	gotoxy((width + 25) / 2, height / 2);
	cout << "                     ";

	ChickenLogic();

	system("cls");
}