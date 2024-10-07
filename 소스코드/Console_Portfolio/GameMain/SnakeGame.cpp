    #include "SnakeGame.h"

void Snake::Rule()
{
    GameBoard* gameBoard = GameBoard::getInstance();

    system("cls");
    system("mode con:cols=120 lines=40");

    init();
    
    gotoxy(53, 11);
    sentence = "스네이크 ";
    textAnimation(sentence, 50);

    gotoxy(52, 13);
    sentence = "◆ 게임룰 ◆";
    textAnimation(sentence, 50);

    gotoxy(46, 15);
    sentence = "조작법 : WASD or 방향키 ";
    textAnimation(sentence, 50);

    gotoxy(44, 17);
    sentence = "뱀 머리 1칸 꼬리 3칸으로 시작";
    textAnimation(sentence, 20);

    gotoxy(40 , 19);
    sentence = "랜덤한 장소에 먹을수 있는 먹이가 생성";
    textAnimation(sentence, 20);

    gotoxy(34, 21);
    sentence = "머리로 먹이를 먹으면 스코어 20점 및 꼬리 1칸 증가";
    textAnimation(sentence, 20);

    gotoxy(41, 23);
    sentence = "시간이 지날수록 뱀의 이동속도 증가";
    textAnimation(sentence, 20);

    gotoxy(32, 25);
    sentence = "30초가 지나거나 머리가 꼬리에 닿거나 벽에 닿으면 게임종료";
    textAnimation(sentence, 20);

    gotoxy(50, 27);
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
                clearLine(27);
                gotoxy(56, 27);

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
            clearLine(27);
            gotoxy(50, 27);
            Sleep(500);
            cout << sentence;
        }
    }
}

void Snake::SetCursorPosition(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Snake::Setup()
{
    GameBoard* gameBoard = GameBoard::getInstance();
    srand(time(NULL));
    gameOver = false;
    direction = 0; // 초기 방향은 위쪽으로 설정

    for (int i = 0; i < INITIAL_SNAKE_LENGTH; ++i)
    {
        // 뱀 시작 지점
        snake[i].x = (width  / 2) + startX;
        snake[i].y = (height / 2) + startY;
    }

    tailLength = INITIAL_SNAKE_LENGTH;
    // 테두리 안에 랜덤한 위치에 먹이 생성
    fruit1.x = rand() % (width - 2) + 1 + startX; 
    fruit1.y = rand() % (height - 2) + 1 + startY;

    fruit2.x = rand() % (width - 2) + 1 + startX;
    fruit2.y = rand() % (height - 2) + 1 + startY;
    startTime = clock();
}

void Snake::Draw()
{
    
    TextColor(10, 0);
    SetCursorPosition(fruit1.x, fruit1.y);
    cout << FOOD_SYMBOL1;


    SetCursorPosition(fruit2.x, fruit2.y);
    cout << FOOD_SYMBOL2;
    TextColor(15, 0);

    // 이전 꼬리의 위치를 지워줍니다.
    SetCursorPosition(snake[tailLength].x, snake[tailLength].y);
    cout << " ";


    // 뱀 자체 시스템 구현 
    // 길이가 4라면 0 은 머리,나머지 1,2,3은 꼬리
    for (int i = 0; i < tailLength; ++i)
    {
        SetCursorPosition(snake[i].x, snake[i].y);
        if (i == 0)
        {
            TextColor(12, 0);
            cout << HEAD_SYMBOL;
            TextColor(15, 0);

        }                   
        else
        {
            TextColor(4, 0);
            cout << BODY_SYMBOL;
            TextColor(15, 0);
        }
    }
}

int SnakeScore = 0;

void Snake::updateScore(int newScore)
{
    SnakeScore += newScore;
}
void Snake::resetScore()
{
    SnakeScore = 0;
}

void Snake::Logic()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            direction = 0;
            break;
        case 's':
            direction = 1;
            break;
        case 'a':
            direction = 2;
            break;
        case 'd':
            direction = 3;
            break;
        case 224:
            switch (_getch())
            {
            case 72: // 위
                direction = 0;
                break;
            case 80: // 아래
                direction = 1;
                break;
            case 75: // 왼쪽
                direction = 2;
                break;
            case 77: // 오른쪽
                direction = 3;
                break;
            }
        }
    }

    

    // 이전 꼬리의 위치를 지워줍니다.
    SetCursorPosition(snake[tailLength - 1].x, snake[tailLength - 1].y);
    cout << " ";

    // 뱀 머리 위치
    // 이전 위치
    Point prevPos = snake[0];
    // 새로운 위치
    Point newPos = snake[0];

    switch (direction)
    {
    case 0: // 위로 이동
        newPos.y--;
        break;
    case 1: // 아래로 이동
        newPos.y++;
        break;
    case 2: // 왼쪽으로 이동
        newPos.x--;
        break;
    case 3: // 오른쪽으로 이동
        newPos.x++;
        break;
    }

    Snake SNAKE;

    // 이동한 위치에 먹이가 있는지 확인
    if (newPos.x == fruit1.x && newPos.y == fruit1.y)
    {
        GameBoard* gameBoard = GameBoard::getInstance();
        PlaySound(TEXT("Getting ITEM.wav"), NULL, SND_FILENAME | SND_ASYNC);
        gameBoard->updateScore(20);
        SNAKE.updateScore(20);
        tailLength++;
        // 테두리 안에 랜덤한 위치에 먹이 생성
        fruit1.x = rand() % (width - 2) + 1 + startX;
        fruit1.y = rand() % (height - 2) + 1 + startY;
    }
    // 이동한 위치에 먹이가 있는지 확인
    if (newPos.x == fruit2.x && newPos.y == fruit2.y)
    {
        GameBoard* gameBoard = GameBoard::getInstance();
        PlaySound(TEXT("Getting ITEM.wav"), NULL, SND_FILENAME | SND_ASYNC);
        gameBoard->updateScore(20);
        SNAKE.updateScore(20);
        tailLength++;
        // 테두리 안에 랜덤한 위치에 먹이 생성
        fruit2.x = rand() % (width - 2) + 1 + startX;
        fruit2.y = rand() % (height - 2) + 1 + startY;
    }

    // 꼬리 이동
    for (int i = tailLength - 1; i > 0; --i)
    {
        snake[i] = snake[i - 1];
    }

    // 머리 이동
    snake[0] = newPos;

    // 충돌 체크
    CheckCollision();
}

void Snake::CheckCollision()
{
    // 벽에 부딪힘
    if (snake[0].x == 0 + startX || // 왼
        snake[0].x >= width - 1 + startX || // 오
        snake[0].y == 0 + startY ||  // 위
        snake[0].y >= height - 1 + startY) // 아래
    {
        Sleep(1000);
        gameOver = true;
    }

    // 꼬리에 닿음
    for (int i = 1; i < tailLength; ++i)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            Sleep(1000);
            gameOver = true; // 머리가 꼬리에 닿으면 게임 종료
        }
    }

    // 게임 시간 초과
    if (33 - (clock() - startTime) / CLOCKS_PER_SEC == 0)
    {
        Sleep(1000);
        gameOver = true;
    }
}

void Snake::DrawScore()
{
    GameBoard* gameBoard = GameBoard::getInstance();

    remainingTime = 33 - ((clock() - startTime) / CLOCKS_PER_SEC);

    gotoxy(width + 5 + startX, 9);
    cout << "시간 : " << remainingTime << "초  ";
    gotoxy(width + 5 + startX, 11);
    cout << "점수 : " << gameBoard->getScore() << "점 ";
}

void Snake::Play()
{
    system("mode con:cols=100 lines=35");
    init();
    int i = 0;
    gameOver = false;

    GameBoard* gameBoard = GameBoard::getInstance();

    // 테두리 그리기
    system("cls");
    gameBoard->drawBorder(width, height);
    Setup();

    while (!gameOver)
    {
        Draw();
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
        DrawScore();
        Logic();

        // 남은시간에 따라 속도 조절
        if (remainingTime < 10)
        {
            FPSnum = 50;
        }
        else if (remainingTime < 20)
        {
            FPSnum = 70;
        }
        else if (remainingTime < 25)
        {
            FPSnum = 100;
        }
        else
        {
            FPSnum = 130;
        }
        Sleep(FPSnum); // 게임 속도 조절
    }
}