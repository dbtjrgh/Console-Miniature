#include "AvoidanceGame.h"

using namespace std;

void Avoidance::Rule()
{
    GameBoard* gameBoard = GameBoard::getInstance();

    system("cls");
    system("mode con:cols=120 lines=40");

	init();
    
	gotoxy(56, 11);
	a = "총알피하기";
	textAnimation(a, 50);

    gotoxy(56, 13);
    a = "◆ 게임룰 ◆";
    textAnimation(a, 50);

    gotoxy(50, 15);
    a = "조작법 : WASD or 방향키 ";
    textAnimation(a, 20);

    gotoxy(48, 17);
    a = "게임시작 1초마다 10점씩 획득";
    textAnimation(a, 20);

    gotoxy(48, 19);
    a = "시간이 지날수록 게임 속도 증가";
    textAnimation(a, 20);  

    Sleep(1000);

    gotoxy(46, 19);
    a = "                                         ";
    textAnimation(a, 20);

    gotoxy(48, 19);
    a = "  탄막에 닿는다면 게임오버";
    textAnimation(a, 20);

    gotoxy(50, 21);
    a = "Please press Enter Key";
    textAnimation(a, 20);

	char ch;
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == '\r')
			{
				clearLine(21);
				gotoxy(56, 21);

				a = "Loading ";
				textAnimation(a, 100);

				a = ". . .";
				textAnimation(a, 300);
				break;
			}
		}
		else
		{
			Sleep(500);
			clearLine(21);
			gotoxy(50, 21);
			Sleep(500);
			cout << a;
		}
	}
}

int AvoidanceScore = 0;

void Avoidance::updateScore(int newScore)
{
    AvoidanceScore += newScore;
}

void Avoidance::resetScore()
{
    AvoidanceScore = 0;
}

void Avoidance::Play()
{
    system("mode con:cols=140 lines=45");

    init();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // 콘솔 핸들 가져오기

    int width = 70; // 테두리의 폭
    int height = 40; // 테두리의 높이
                                      
    GameBoard* gameBoard = GameBoard::getInstance();
    gameBoard->drawBorder(width, height);
    

    int startX = 21;
    int startY = 5;
    int playerX = startX + width / 2; // 가로 중앙
    int playerY = startY + height / 2; // 세로 중앙

    vector<Bullet> bullets; // 총알을 저장할 벡터 선언

    srand(time(NULL)); // 난수 생성을 위한 시드 설정

    char input;
    gameOver = false;

    // 타이머 변수 초기화
    time_t startTime = time(nullptr);
    int remainingTime = 30;

    // 3초마다 총알 생성 횟수 변수 초기화
    int bulletSpawnFrequency = 1;
    time_t lastBulletSpawnTime = time(nullptr);

    Avoidance avoidance;

    gotoxy(playerX - 7, playerY);
    cout << "3초 후 시작됩니다.";
    Sleep(1000);

    gotoxy(playerX - 7, playerY);
    cout << "2초 후 시작됩니다.";
    Sleep(1000);

    gotoxy(playerX - 7, playerY);
    cout << "1초 후 시작됩니다.";
    Sleep(1000);

    gotoxy(playerX - 7, playerY);
    cout << "                     ";

    while (!gameOver && remainingTime > 0)
    {
        // 타이머 업데이트
        time_t currentTime = time(nullptr);
        remainingTime = 33 - (currentTime - startTime);

        // 타이머 출력
        COORD timerPos = { static_cast<SHORT>(width + 25), 10 }; // 타이머 위치 조정
        SetConsoleCursorPosition(hConsole, timerPos);
        cout << "시간 : " << remainingTime << "초  ";

        // 1초마다 스코어를 업데이트
        static time_t lastScoreUpdateTime = startTime;
        if (currentTime - lastScoreUpdateTime >= 1 && remainingTime < 30)
        {
            lastScoreUpdateTime = currentTime;
            gameBoard->updateScore(10); // 점수 10점씩 증가
            avoidance.updateScore(10);
        }

        // 점수 출력
        gotoxy(95, 12);
        cout << "점수 : " << gameBoard->getScore() << "점" << endl;

        // 3초가 지날 때마다 총알 생성 횟수 증가
        if (currentTime - lastBulletSpawnTime >= 2) 
        {
            bulletSpawnFrequency+= 15;
            lastBulletSpawnTime = currentTime;
        }

        // 이전 위치의 플레이어 삭제
        COORD prevPlayerPos = { static_cast<SHORT>(playerX), static_cast<SHORT>(playerY) };
        SetConsoleCursorPosition(hConsole, prevPlayerPos);
        cout << " ";

        // 플레이어 이동
        if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState('A') & 0x8000)
        { // 방향키 왼쪽 또는 'A'
            if (playerX > startX + 1) // 테두리를 벗어나지 않도록
            {
                playerX--;
            }
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState('D') & 0x8000)
        { // 방향키 오른쪽 또는 'D'
            if (playerX < startX + width - 3) // 테두리를 벗어나지 않도록
            {
                playerX++;
            }
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState('W') & 0x8000)
        { // 방향키 위 또는 'W'
            if (playerY > startY) // 테두리를 벗어나지 않도록
            {
                playerY--;
            }
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState('S') & 0x8000)
        { // 방향키 아래 또는 'S'
            if (playerY < startY + height - 3) // 테두리를 벗어나지 않도록
            {
                playerY++;
            }
        }

        // 변경된 위치에 플레이어 출력
        COORD playerPos = { static_cast<SHORT>(playerX), static_cast<SHORT>(playerY) };
        SetConsoleCursorPosition(hConsole, playerPos);
        TextColor(10, 0); cout << "&"; TextColor(15, 0); // 플레이어를 표시

        gotoxy(95, 5);
        cout << "player X : "<< static_cast<SHORT>(playerX) << "  player Y : " << static_cast<SHORT>(playerY) << " ";

        // 플레이어와 총알 충돌 검사
        for (const auto& bullet : bullets)
        {
            if (playerX == bullet.x && playerY == bullet.y)
            {
                Sleep(1000);
                gameOver = true;
            }
        }   

        // 총알 생성
        if (bulletSpawnFrequency > 0 && 1) // 총알 생성 빈도를 변수로 변경
        {
            Bullet bullet;
            // 총알을 랜덤한 위치에 생성
            int side = rand() % 4;
            switch (side)
            {
            case 0: // 위쪽 가장자리
                bullet.x = startX + rand() % (width - 4) + 1; // 벽과 총알 간격을 둠
                bullet.y = startY ; // 벽 위에 생성되지 않도록
                bullet.dx = rand() % 3 - 1; // 무작위 초기 가로 방향 (-1, 0, 또는 1)
                bullet.dy = 1; // 항상 아래쪽으로 이동
                break;

            case 1: // 오른쪽 가장자리
                bullet.x = startX + width - 3;
                bullet.y = startY + rand() % (height - 4) + 1; // 벽과 총알 간격을 둠
                bullet.dx = -1; // 항상 왼쪽으로 이동
                bullet.dy = rand() % 3 - 1; // 무작위 초기 세로 방향 (-1, 0, 또는 1)
                break;

            case 2: // 아래쪽 가장자리
                bullet.x = startX + rand() % (width - 4) + 1; // 벽과 총알 간격을 둠
                bullet.y = startY + height - 3;
                bullet.dx = rand() % 3 - 1; // 무작위 초기 가로 방향 (-1, 0, 또는 1)
                bullet.dy = -1; // 항상 위쪽으로 이동
                break;

            case 3: // 왼쪽 가장자리
                bullet.x = startX + 2; // 벽 왼쪽에 생성되지 않도록
                bullet.y = startY + rand() % (height - 4) + 1; // 벽과 총알 간격을 둠
                bullet.dx = 1; // 항상 오른쪽으로 이동
                bullet.dy = rand() % 3 - 1; // 무작위 초기 세로 방향 (-1, 0, 또는 1)
                break;
            }
            // 총알을 벡터에 추가
            bullets.push_back(bullet);
        }

        // 총알 이동 및 출력
        for (auto it = bullets.begin(); it != bullets.end();) 
        {
            auto& bullet = *it;

            // 이전 위치의 총알 삭제
            COORD prevBulletPos = { static_cast<SHORT>(bullet.x), static_cast<SHORT>(bullet.y) };
            SetConsoleCursorPosition(hConsole, prevBulletPos);
            cout << " ";

            // 총알 이동
            bullet.x += bullet.dx;
            bullet.y += bullet.dy;

            // 총알이 벽에 부딪히는지 확인
            if (bullet.x <= startX  || bullet.x >= startX + width - 2 || bullet.y <= startY - 1 || bullet.y >= startY + height - 2)
            {
                // 만약 총알이 벽에 부딪힌다면, 벡터에서 해당 총알을 제거
                it = bullets.erase(it);
            }
            else
            {
                // 총알이 벽에 부딪히지 않는다면, 새 위치에 총알을 표시하고 다음 총알로 이동
                COORD bulletPos = { static_cast<SHORT>(bullet.x), static_cast<SHORT>(bullet.y) };
                SetConsoleCursorPosition(hConsole, bulletPos);
                TextColor(12, 0); cout << "*"; TextColor(15, 0);

                ++it; // 다음 총알로 이동
            }
        }
       
        // 화면 지연 (초당 30프레임)
        Sleep(remainingTime + 20);
    }
}
