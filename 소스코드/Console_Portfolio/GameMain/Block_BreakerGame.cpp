#include "Block_BreakerGame.h"

void Block_Breaker::Rule()
{
    GameBoard* gameBoard = GameBoard::getInstance();

    system("cls");
    system("mode con:cols=120 lines=40");

    init();
    
    gotoxy(53, 11);
    sentence = "벽돌깨기";
    textAnimation(sentence, 50);

    gotoxy(52, 13);
    sentence = "◆ 게임룰 ◆";
    textAnimation(sentence, 50);

    gotoxy(44, 15);
    sentence = "조작법 : A D or 방향키 좌 우 ";
    textAnimation(sentence, 20);

    gotoxy(36, 17);
    sentence = "막대를 조종해서 공을 받아내 벽돌을 부수는 게임 ";
    textAnimation(sentence, 20);

    gotoxy(42, 19);
    sentence = "벽돌 하나를 깰때마다 10점씩 획득";
    textAnimation(sentence, 20);

    gotoxy(36, 21);
    sentence = "난이도를 위해 시간이 지날수록 게임 속도 증가";
    textAnimation(sentence, 20);

    gotoxy(44, 23);
    sentence = "공을 받아내지 못하면 게임종료";
    textAnimation(sentence, 20);

    gotoxy(44, 25);
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
                clearLine(25);
                gotoxy(50, 25);

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
            clearLine(25);
            gotoxy(44, 25);
            Sleep(500);
            cout << sentence;
        }
    }
}



const int width = 50;
const int height = 30;

int startX = 21;
int startY = 5;

const char PADDLE = '=';
const char BALL = 'O';
const char BRICK = '#';
const int PADDLE_LENGTH = 7;


// 막대 초기 위치
int paddleX = width / 2 + startX - 2;

// 공 초기 위치
int ballX = paddleX + 2;
int ballY = (height - 2 - startY);

// 공 이동 방향
int ballDirX = 1, ballDirY = -1;

// 벽돌 배열
bool bricks[width][height];

// 콘솔 핸들 가져오기
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

// 콘솔에 문자 그리기 색깔 O
void DrawCharacter(int x, int y, char character, WORD attributes)
{
    COORD pos = { x, y };
    DWORD written;
    SetConsoleCursorPosition(console, pos);
    SetConsoleTextAttribute(console, attributes);
    WriteConsoleA(console, &character, 1, &written, nullptr);
}
// 콘솔에 문자 그리기 색깔 X
void drawcharacter(int x, int y, char character)
{
    COORD pos = { x, y };
    DWORD written;
    SetConsoleCursorPosition(console, pos);
    WriteConsoleA(console, &character, 1, &written, nullptr);
}

// 콘솔 화면 지우기
void ClearScreen()
{
    COORD topLeft = { 0, 0 };
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;
    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

// 화면 그리기
void Block_Breaker::draw()
{
    ClearScreen();

    // 상단 테두리 그리기
    drawcharacter(startX - 1, startY - 1, '+');
    drawcharacter(startX + width, startY - 1, '+');
    for (int i = startX; i < width + startX; ++i)
    {
        drawcharacter(i, startY - 1, '-');
    }

    // 하단 테두리 그리기
    drawcharacter(startX - 1, height + startY, '+');
    drawcharacter(startX + width, height + startY, '+');
    for (int i = startX; i < width + startX; ++i)
    {
        drawcharacter(i, height + startY, '-');
    }

    // 좌측 테두리 그리기
    for (int i = startY; i < height + startY; ++i)
    {
        drawcharacter(startX - 1, i, '|');
    }

    // 우측 테두리 그리기
    for (int i = startY; i < height + startY; ++i)
    {
        drawcharacter(startX + width, i, '|');
    }

    // 벽돌
    for (int i = startX; i < width + startX - 1; ++i)
    {
        for (int j = startY; j < height / 2; ++j)
        {
            if (bricks[i - startX][j - startY])
            {
                DrawCharacter(i, j, BRICK, FOREGROUND_RED);
            }
        }
    }

    // 패들
    for (int i = 0; i < PADDLE_LENGTH; ++i)
    {
        DrawCharacter(paddleX + i, height + startY - 1, PADDLE, FOREGROUND_GREEN);
    }

    // 공
    DrawCharacter(ballX, ballY, BALL, FOREGROUND_GREEN);

}

int Block_BreakerScore = 0;

void Block_Breaker::updateScore(int newScore)
{
    Block_BreakerScore += newScore;
}

void Block_Breaker::resetScore()
{
    Block_BreakerScore = 0;
}

// 게임 업데이트
void Block_Breaker::update()
{
    // 공의 다음 위치 계산
    int nextX = ballX + ballDirX;
    int nextY = ballY + ballDirY;

    Block_Breaker block_breaker;

    // 벽돌과의 충돌 체크
    if (nextY < height / 2)
    {
        int brickX = (nextX - startX) % width;
        int brickY = nextY - startY;
        if (bricks[brickX][brickY])
        {
            bricks[brickX][brickY] = false;
            ballDirY *= -1;
            // 점수 획득시 효과음
            PlaySound(TEXT("Getting ITEM.wav"), NULL, SND_FILENAME | SND_ASYNC);
            // 벽돌이 부숴졌을 때 처리
            GameBoard* gameBoard = GameBoard::getInstance();
            gameBoard->updateScore(10);  // 벽돌 부술때마다 10점씩 획득
            block_breaker.updateScore(10);
            return; // 벽돌과의 충돌이 감지되면 공의 위치 업데이트를 중지하고 함수를 종료합니다.
        }
    }

    // 공 이동
    ballX += ballDirX;
    ballY += ballDirY;

    // 공과 벽 충돌 체크
    if (ballX == width + startX - 2 || ballX == startX + 1)
    {
        ballDirX *= -1;
    }
    if (ballY <= startY - 1)  // 공이 위쪽 벽에 부딪혔을 때
    {
        ballY++;
        ballDirY *= -1;
    }
    if (ballY > height + startY - 3)
    {
        if (ballX >= paddleX && ballX <= paddleX + 6) // 공이 패들 범위 안에 있을 때
        {
            ballDirY = -1; // 공이 패들에 부딪혔을 때 방향을 바꿉니다.
        }
        else if (ballY >= height + startY) // 공이 아래로 떨어졌을 때
        {
            // 게임 오버 처리
            Sleep(1000);
            // 막대 초기 위치
            int paddleX = width / 2 + startX - 2;

            // 공의 초기 위치 설정
            int ballX = paddleX + 2;
            int ballY = (height - 2 - startY);

            // 패들
            for (int i = 0; i < PADDLE_LENGTH; ++i)
            {
                DrawCharacter(paddleX + i, height + startY - 1, PADDLE, FOREGROUND_GREEN);
            }

            // 공
            DrawCharacter(ballX, ballY, BALL,FOREGROUND_GREEN);
            gameOver = true;
        }
    }

    // 현재 시간 계산
    clock_t currentTime = clock();

    // 경과 시간 계산
    int elapsedTime = (int)(currentTime - startTime) / CLOCKS_PER_SEC;

    // 남은 시간 계산
    remainingTime = 30 - elapsedTime;
    // 게임 시간 초과
    if (remainingTime <= 0)
    {
        // 막대 초기 위치
        int paddleX = width / 2 + startX - 2;

        // 공의 초기 위치 설정
        int ballX = paddleX + 2;
        int ballY = (height - 2 - startY);

        // 패들
        for (int i = 0; i < PADDLE_LENGTH; ++i)
        {
            DrawCharacter(paddleX + i, height + startY - 1, PADDLE, FOREGROUND_GREEN);
        }

        // 공
        DrawCharacter(ballX, ballY, BALL,FOREGROUND_GREEN);
        gameOver = true;
    }
    GameBoard* gameBoard = GameBoard::getInstance();
    TextColor(15, 0);
    gotoxy(width + 5 + startX, 9);
    cout << "시간 : " << remainingTime << "초  ";

    gotoxy(width + 5 + startX, 11);
    cout << "점수 : " << gameBoard->getScore() << "점 ";
    
}

// 패들 컨트롤
void Block_Breaker::paddleControl() 
{
    if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState('A') & 0x8000)
    { // 방향키 왼쪽 또는 'A'
        if (paddleX > 1 + startX - 1)
        {
            paddleX--;
        }
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState('D') & 0x8000)
    { // 방향키 오른쪽 또는 'D'
        if (paddleX + 5 < width + startX - 2) // 테두리를 벗어나지 않도록
        {
            paddleX++;
        }
    }
}

void Block_Breaker::Play() 
{
    system("cls");
    system("mode con:cols=100 lines=40");
    init();

    int i = 0;
    gameOver = false;
    startTime = clock(); // 게임이 시작되면 startTime을 현재 시간으로 초기화

    // 패들 초기 위치 설정
    paddleX = width / 2 + startX - 2;

    // 공 초기 위치 설정
    ballX = paddleX + 2;
    ballY = (height - 2 - startY);
    ballDirY = -1;
    

    // 벽돌 초기화
    for (int i = 1; i < width; ++i)
    {
        for (int j = 1; j < height / 4; ++j)
        {
            // 벽돌 스폰하는 모든 곳에 20% 확률로 벽돌을 배치
            if (rand() % 4 == 0)
            {
                bricks[i][j] = true;
            }
            else
            {
                bricks[i][j] = false;
            }
        }
    }

    while (! gameOver) 
    {
        draw();
        for (; i < 1; i++)
        {
            gotoxy((width + startX) / 2, (height + startY) / 2);
            cout << "3초 후 시작됩니다.";
            Sleep(1000);

            gotoxy((width + startX) / 2, (height + startY) / 2);
            cout << "2초 후 시작됩니다.";
            Sleep(1000);

            gotoxy((width + startX) / 2, (height + startY) / 2);
            cout << "1초 후 시작됩니다.";
            Sleep(1000);
            gotoxy((width + startX) / 2, (height + startY) / 2);
            cout << "                     ";
        }
        update();
        paddleControl();
        int speed = remainingTime;
        Sleep(speed+20);
    }    
    system("cls");
}
