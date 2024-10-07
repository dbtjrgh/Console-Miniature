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
	sentence = "  ���þȷ귿 ";
	textAnimation(sentence, 50);

	gotoxy(50, 13);
	sentence = "�� ���ӷ� ��";
	textAnimation(sentence, 50);

	gotoxy(46, 15);
	sentence = "�÷��̾� VS ��ǻ�� ";
	textAnimation(sentence, 50);

	gotoxy(40, 17);
	sentence = "���۹� \"Z\" or \"C\" �� ������ �ֱ�";
	textAnimation(sentence, 50);

	gotoxy(34, 19);
	sentence = " Z : �ڽ��� ���� �߻�   C : ��ǻ�Ϳ��� �߻� ";
	textAnimation(sentence, 50);

	gotoxy(35, 21);
	sentence = "������ �̿��� �Ѹ��� ��ź�� ������ ��������";
	textAnimation(sentence, 10);

	gotoxy(35, 23);
	sentence = "�Ѿ��� �� 6��. ����ź 5��, ��ź 1�߾� ����";
	textAnimation(sentence, 10);

	gotoxy(32, 25);
	sentence = "����ź�϶� �ڽſ��� �߻� �� �ѹ� �� �� ��ȸ ȹ��";
	textAnimation(sentence, 10);

	gotoxy(34, 27);
	sentence = "�÷��̾ ���� ���� , �Ѿ� ������ ����";
	textAnimation(sentence, 10);

	gotoxy(36, 29);
	sentence = "�÷��̾� �¸� ���ھ� 300��, �й� 0��";
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
	TextColor(10, 0); cout << " /��\\  ____      "; TextColor(12, 0); cout << "        /��\\ "; TextColor(15, 0);
	gotoxy(23, 9);
	TextColor(10, 0); cout << "���� \\�� ������     "; TextColor(12, 0); cout << "       / �� \\"; TextColor(15, 0);
	gotoxy(23, 10);
	TextColor(10, 0); cout << " / \\   ��       "; TextColor(12, 0); cout << "          / \\ "; TextColor(15, 0);
	gotoxy(23, 11);
	TextColor(10, 0); cout << "�� ��             "; TextColor(12, 0); cout << "       �� ��  "; TextColor(15, 0);
}

void Chicken::PlayerTurnShoot()
{
	gotoxy(23, 7);
	TextColor(10, 0); cout << "   O         "; TextColor(12, 0); cout << "             O     "; TextColor(15, 0);
	gotoxy(23, 8);
	TextColor(10, 0); cout << " /��\\  ____    "; TextColor(12, 0); cout << "          /��\\ "; TextColor(15, 0);
	gotoxy(23, 9);
	TextColor(10, 0); cout << "���� \\�� ������    ";  TextColor(14, 0); cout << "��"; TextColor(12, 0);  cout << "       / �� \\"; TextColor(15, 0);
	gotoxy(23, 10);
	TextColor(10, 0); cout << " / \\   ��       "; TextColor(12, 0); cout << "          / \\ "; TextColor(15, 0);
	gotoxy(23, 11);
	TextColor(10, 0); cout << "�� ��           "; TextColor(12, 0); cout << "         �� �� "; TextColor(15, 0);
}

void Chicken::PlayerTurnPlayer()
{
	gotoxy(23, 7);
	TextColor(10, 0); cout << "   O   _____     "; TextColor(12, 0); cout << "         O     "; TextColor(15, 0);
	gotoxy(23, 8);
	TextColor(10, 0); cout << " /��\\  �š��� ��   "; TextColor(12, 0); cout << "         /��\\  "; TextColor(15, 0);
	gotoxy(23, 9); 
	TextColor(10, 0); cout << "���� \\    ��     "; TextColor(12, 0); cout << "       / �� \\ "; TextColor(15, 0);
	gotoxy(23, 10);
	TextColor(10, 0); cout << " / \\           "; TextColor(12, 0); cout << "           / \\"; TextColor(15, 0);
	gotoxy(23, 11);
	TextColor(10, 0); cout << "�� ��          "; TextColor(12, 0); cout << "          �� �� "; TextColor(15, 0);
}
void Chicken::PlayerTurnPlayerShoot()
{
	gotoxy(23, 7);
	TextColor(10, 0); cout << "   O "; TextColor(14, 0); cout << "��"; TextColor(10, 0); cout << " _____      "; TextColor(12, 0); cout << "        O    "; TextColor(15, 0);
	gotoxy(23, 8);
	TextColor(10, 0); cout << " /��\\  �š��� ��   "; TextColor(12, 0); cout << "         /��\\ "; TextColor(15, 0);
	gotoxy(23, 9); 
	TextColor(10, 0); cout << "���� \\    ��    "; TextColor(12, 0); cout << "        / �� \\ "; TextColor(15, 0);
	gotoxy(23, 10);
	TextColor(10, 0); cout << " / \\          "; TextColor(12, 0); cout << "            / \\"; TextColor(15, 0);
	gotoxy(23, 11);
	TextColor(10, 0); cout << "�� ��           "; TextColor(12, 0); cout << "         �� ��  "; TextColor(15, 0);
}

void Chicken::EnemyTurn()
{
	gotoxy(23, 16);
	TextColor(10, 0); cout << "   O          "; TextColor(12, 0); cout << "           O     "; TextColor(15, 0);
	gotoxy(23, 17);
	TextColor(10, 0); cout << " /��\\        "; TextColor(12, 0); cout << "    _____  /��\\ "; TextColor(15, 0);
	gotoxy(23, 18);
	TextColor(10, 0); cout << "���� \\        "; TextColor(12, 0); cout << "   �š��� ��/ �� \\ "; TextColor(15, 0);
	gotoxy(23, 19);
	TextColor(10, 0); cout << " / \\          "; TextColor(12, 0); cout << "     ��    / \\  "; TextColor(15, 0);
	gotoxy(23, 20);
	TextColor(10, 0); cout << "�� ��            "; TextColor(12, 0); cout << "       �� ��  "; TextColor(15, 0);
}
void Chicken::EnemyTurnShoot()
{
	gotoxy(23, 16);
	TextColor(10, 0); cout << "   O          "; TextColor(12, 0); cout << "           O     "; TextColor(15, 0);
	gotoxy(23, 17);
	TextColor(10, 0); cout << " /��\\         "; TextColor(12, 0); cout <<  "   _____  /��\\ "; TextColor(15, 0);
	gotoxy(23, 18);
	TextColor(10, 0); cout << "���� \\  "; TextColor(14, 0); cout << "��"; TextColor(12, 0); cout << "        �š��� ��/ �� \\ "; TextColor(15, 0);
	gotoxy(23, 19);
	TextColor(10, 0); cout << " / \\          "; TextColor(12, 0); cout << "     ��    / \\  "; TextColor(15, 0);
	gotoxy(23, 20);
	TextColor(10, 0); cout << "�� ��         "; TextColor(12, 0); cout << "          �� ��  "; TextColor(15, 0);
}
void Chicken::EnemyTurnEnemy()
{
	gotoxy(23, 16);
	TextColor(10, 0); cout << "   O         "; TextColor(12, 0); cout << "    _____   O     "; TextColor(15, 0);
	gotoxy(23, 17);
	TextColor(10, 0); cout << " /��\\        "; TextColor(12, 0); cout << "   �� ������  /��\\ "; TextColor(15, 0);
	gotoxy(23, 18);
	TextColor(10, 0); cout << "���� \\       "; TextColor(12, 0); cout << "    ��    / �� \\ "; TextColor(15, 0);
	gotoxy(23, 19);
	TextColor(10, 0); cout << " / \\         "; TextColor(12, 0); cout << "            / \\  "; TextColor(15, 0);
	gotoxy(23, 20);
	TextColor(10, 0); cout << "�� ��         "; TextColor(12, 0); cout << "          �� ��  "; TextColor(15, 0);
}
void Chicken::EnemyTurnEnemyShoot()
{
	gotoxy(23, 16);
	TextColor(10, 0); cout << "   O         "; TextColor(12, 0); cout << "    _____ "; TextColor(14, 0); cout << "��"; TextColor(12, 0); cout << " O     "; TextColor(15, 0);
	gotoxy(23, 17);
	TextColor(10, 0); cout << " /��\\       "; TextColor(12, 0); cout << "    �� ������  /��\\ "; TextColor(15, 0);
	gotoxy(23, 18);
	TextColor(10, 0); cout << "���� \\       "; TextColor(12, 0); cout << "    ��    / �� \\ "; TextColor(15, 0);
	gotoxy(23, 19);
	TextColor(10, 0); cout << " / \\        "; TextColor(12, 0); cout << "             / \\  "; TextColor(15, 0);
	gotoxy(23, 20);
	TextColor(10, 0); cout << "�� ��        "; TextColor(12, 0); cout << "           �� ��  "; TextColor(15, 0);
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
	gotoxy(60, 7); // ���ϴ� ��ġ�� Ŀ�� �̵�
	cout << "���� �Ѿ� : " << remainingBullets << "��"; // ���� �Ѿ� ���� ����մϴ�.
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
	// �Ѿ� �ʱ�ȭ
	int bullets[6] = { 0 }; // 6���� �Ѿ�, ��ź�� �ִ� ��ġ�� 1�� ǥ��

	// ��ź ��ġ ���� ����
	srand(time(NULL));
	// 0 ~ 5 �߿� �ϳ��� ��ź
	int idx = rand() % 6;
	bullets[idx] = 1;
	int turn = 0;

	bool gameOver = false; // ���� ���� ����
	bool playerTurn = true; // �÷��̾� ���� ����
	bool shootSelf;

	// Ÿ�̸� ���� �ʱ�ȭ
	time_t startTime = time(nullptr);
	int remainingTime;

	Chicken chicken;

	// �����ư��鼭 �÷��̾�� ��ǻ�Ͱ� ���� ��� ���� ����
	while (!gameOver)
	{
		// Ÿ�̸� ������Ʈ
		time_t currentTime = time(nullptr);
		remainingTime = 30 - (currentTime - startTime);



		if (playerTurn)
		{
			Sleep(1000);
			CleanPlayer();
						
			BulletsRemaining(6 - turn);
			GameBoard* gameBoard = GameBoard::getInstance();

			// Ÿ�̸� ���
			gotoxy(60, 5);
			cout << "�ð� : " << remainingTime << "��  ";
			gotoxy(60, 6);
			cout << "���� : " << gameBoard->getScore() << "��";

			if (remainingTime < 1)
			{
				gameOver = true;
			}

			Clean();

			PlayerTurn();

			gotoxy(60, 9);
			cout << "                                                 ";
			gotoxy(60, 9);
			cout << "�÷��̾� �����Դϴ�. Z : �� , C : ���";

			if (GetAsyncKeyState('Z') & 0x8000)
			{
				gotoxy(60, 11);
				cout << "                              ";
				gotoxy(60, 11);
				sentence = "�ڽ��� ���ϴ�.";
				textAnimation(sentence, 20);
				PlayerTurnPlayer();
				Sleep(500);

				// �÷��̾ �ڽ��� �� ��
				if (bullets[turn] == 0)
				{
					// ����ź�� ���� ���
					gotoxy(60, 13);
					cout << "                                               ";
					gotoxy(60, 13);
					cout << "����ź�̿����ϴ�!";
					gotoxy(60, 15);
					cout << "                                               ";
					gotoxy(60, 15);
					cout << "�� �� �� ��ȸ�� ����ϴ�.";
					Sleep(500);
					playerTurn = true; // �÷��̾��� ���ʷ� �ٽ� ���ư�
					turn++;
				}
				else if ((bullets[turn] != 0))
				{
					// ��ź�� ���� ���
					Clean();
					PlayerTurnPlayerShoot();
					gotoxy(60, 13);
					cout << "                                               ";
					gotoxy(60, 13);
					cout << "��ź�̿����ϴ�!";
					gotoxy(60, 15);
					cout << "                                               ";
					gotoxy(60, 15);
					cout << "���� ����!";
					gotoxy(60, 17);
					cout << "                                               ";
					gotoxy(60, 17);
					TextColor(12, 0); cout << "�÷��̾� �й�!"; TextColor(15, 0);
					gameOver = true;
					Sleep(2000);
				}
			}
			else if (GetAsyncKeyState('C') & 0x8000)
			{
				gotoxy(60, 11);
				cout << "                                               ";
				gotoxy(60, 11);
				
				sentence = "�÷��̾ ��ǻ�͸� ���ϴ�.";
				textAnimation(sentence, 20);
				Sleep(500);
				// �÷��̾ ��븦 �� ��
				if (bullets[turn] == 1)
				{
					// ��ź�� ���� ���
					Clean();
					PlayerTurnShoot();
					gotoxy(60, 13); 
					cout << "                                               ";
					gotoxy(60, 13);
					cout << "��ź�� �������ϴ�!";
					gotoxy(60, 15);
					cout << "                                               ";
					gotoxy(60, 15);
					cout << "���� ����!";
					gotoxy(60, 17);
					cout << "                                               ";
					gotoxy(60, 17);
					TextColor(10, 0);  cout << "�÷��̾� �¸�! 300�� ȹ��!"; TextColor(15, 0);
					PlaySound(TEXT("Getting ITEM.wav"), NULL, SND_FILENAME | SND_ASYNC);
					Sleep(2000);
					gameBoard->updateScore(300);
					chicken.updateScore(300);
					playerWin = true;
					gameOver = true;
					
				}
				else if (bullets[turn] != 1)
				{
					// ��ź�� ���� ���� ���
					gotoxy(60, 13);
					cout << "                                               ";
					gotoxy(60, 13);
					cout << "����ź�Դϴ�.";
					Sleep(500);
					turn++;
					playerTurn = false; // �÷��̾� ���� ����
				}
			}
			gotoxy(60, 5);
			cout << "�ð� : " << remainingTime << "��  ";
		}
		
		else if (!playerTurn)
		{
			gotoxy(60, 5);
			cout << "�ð� : " << remainingTime << "��  ";
		    CleanEnemy();			
			gotoxy(60, 20);
			sentence = "��ǻ�� �����Դϴ�.";
			textAnimation(sentence, 50);			
			BulletsRemaining(6 - turn);
			Clean();
			EnemyTurn();
			Sleep(500);
			// 3�� ��� �� ��ǻ�Ͱ� ���� ���ϴ�.
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
				cout << "�ð� : " << remainingTime << "��  ";
				gotoxy(60, 22);
				cout << "                                               ";
				gotoxy(60, 22);
				cout << "��ǻ�Ͱ� �ڽ��� ���ϴ�.";
				Clean();
				EnemyTurnEnemy();
				Sleep(500);
				// ��ǻ�Ͱ� �ڽ��� �� ��
				if (bullets[turn] == 0)
				{
					// ����ź�� ���� ���
					gotoxy(60, 24);
					cout << "                                               ";
					gotoxy(60, 24);
					cout << "����ź�̿����ϴ�!";
					gotoxy(60, 26);
					cout << "                                               ";
					gotoxy(60, 26);
					cout << "�� �� �� ��ȸ�� ����ϴ�.";
					Sleep(500);
					playerTurn = false; // �÷��̾� ���� ����
					turn++;
				}
				else
				{
					// ��ź�� ���� ���
					Clean();
					EnemyTurnEnemyShoot();
					gotoxy(60, 24);
					cout << "                                               ";
					gotoxy(60, 24);
					cout << "��ź�̿����ϴ�!";
					gotoxy(60, 26);
					cout << "                                               ";
					gotoxy(60, 26);
					cout << "���� ����!";
					Sleep(2000);
					gotoxy(60, 28);
					cout << "                                               ";
					gotoxy(60, 28);
					PlaySound(TEXT("Getting ITEM.wav"), NULL, SND_FILENAME | SND_ASYNC);
					TextColor(10, 0); cout << "�÷��̾� �¸�! 300�� ȹ��!"; TextColor(15, 0);
					GameBoard* gameBoard = GameBoard::getInstance();
					Sleep(2000);
					gameBoard->updateScore(300);
					chicken.updateScore(300);
					playerWin = true;
					gameOver = true;
					
				}
				gotoxy(60, 5);
				cout << "�ð� : " << remainingTime << "��  ";
			}
			else
			{
				GameBoard* gameBoard = GameBoard::getInstance();

				// Ÿ�̸� ���
				gotoxy(60, 5);
				cout << "�ð� : " << remainingTime << "��  ";
				gotoxy(60, 6);
				cout << "���� : " << gameBoard->getScore() << "��";

				gotoxy(60, 22);
				cout << "                                               ";
				gotoxy(60, 22);
				cout << "��ǻ�Ͱ� �÷��̾ ���ϴ�.";
				Sleep(500);

				// ��ǻ�Ͱ� ��븦 �� ��
				if (bullets[turn] == 1)
				{
					Clean();
					EnemyTurnShoot();
					gotoxy(60, 24);
					// ��ź�� ���� ���
					cout << "                                               ";
					gotoxy(60, 24);
					cout << "��ź�� �������ϴ�!";
					gotoxy(60, 26);
					cout << "                                               ";
					gotoxy(60, 26);
					cout << "���� ����! ";
					gotoxy(60, 28);
					cout << "                                               ";
					gotoxy(60, 28);
					TextColor(12, 0); cout << "�÷��̾� �й�!"; TextColor(15, 0);
					gameOver = true;
					Sleep(2000);
				}
				else
				{
					// ��ź�� ���� ���� ���
					gotoxy(60, 24);					
					cout << "                                               ";
					gotoxy(60, 24);
					cout << "����ź�Դϴ�.";
					Sleep(500);
					playerTurn = true; // �÷��̾� ���ʷ� ����
					turn++;
				}
				gotoxy(60, 5);
				Sleep(500);
				cout << "�ð� : " << remainingTime << "��  ";
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

	int width = 35; // �׵θ��� ��
	int height = 20; // �׵θ��� ����

	GameBoard* gameBoard = GameBoard::getInstance();

	// �׵θ� �׸���
	gameBoard->drawBorder(width, height);

	gotoxy((width + 25 ) / 2, height / 2);
	cout << "3�� �� ���۵˴ϴ�.";
	Sleep(1000);

	gotoxy((width + 25)  / 2, height / 2);
	cout << "2�� �� ���۵˴ϴ�.";
	Sleep(1000);

	gotoxy((width + 25)  / 2, height / 2);
	cout << "1�� �� ���۵˴ϴ�.";
	Sleep(1000);	

	gotoxy((width + 25) / 2, height / 2);
	cout << "                     ";

	ChickenLogic();

	system("cls");
}