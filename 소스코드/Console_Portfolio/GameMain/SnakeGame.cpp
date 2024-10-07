    #include "SnakeGame.h"

void Snake::Rule()
{
    GameBoard* gameBoard = GameBoard::getInstance();

    system("cls");
    system("mode con:cols=120 lines=40");

    init();
    
    gotoxy(53, 11);
    sentence = "������ũ ";
    textAnimation(sentence, 50);

    gotoxy(52, 13);
    sentence = "�� ���ӷ� ��";
    textAnimation(sentence, 50);

    gotoxy(46, 15);
    sentence = "���۹� : WASD or ����Ű ";
    textAnimation(sentence, 50);

    gotoxy(44, 17);
    sentence = "�� �Ӹ� 1ĭ ���� 3ĭ���� ����";
    textAnimation(sentence, 20);

    gotoxy(40 , 19);
    sentence = "������ ��ҿ� ������ �ִ� ���̰� ����";
    textAnimation(sentence, 20);

    gotoxy(34, 21);
    sentence = "�Ӹ��� ���̸� ������ ���ھ� 20�� �� ���� 1ĭ ����";
    textAnimation(sentence, 20);

    gotoxy(41, 23);
    sentence = "�ð��� �������� ���� �̵��ӵ� ����";
    textAnimation(sentence, 20);

    gotoxy(32, 25);
    sentence = "30�ʰ� �����ų� �Ӹ��� ������ ��ų� ���� ������ ��������";
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
    direction = 0; // �ʱ� ������ �������� ����

    for (int i = 0; i < INITIAL_SNAKE_LENGTH; ++i)
    {
        // �� ���� ����
        snake[i].x = (width  / 2) + startX;
        snake[i].y = (height / 2) + startY;
    }

    tailLength = INITIAL_SNAKE_LENGTH;
    // �׵θ� �ȿ� ������ ��ġ�� ���� ����
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

    // ���� ������ ��ġ�� �����ݴϴ�.
    SetCursorPosition(snake[tailLength].x, snake[tailLength].y);
    cout << " ";


    // �� ��ü �ý��� ���� 
    // ���̰� 4��� 0 �� �Ӹ�,������ 1,2,3�� ����
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
            case 72: // ��
                direction = 0;
                break;
            case 80: // �Ʒ�
                direction = 1;
                break;
            case 75: // ����
                direction = 2;
                break;
            case 77: // ������
                direction = 3;
                break;
            }
        }
    }

    

    // ���� ������ ��ġ�� �����ݴϴ�.
    SetCursorPosition(snake[tailLength - 1].x, snake[tailLength - 1].y);
    cout << " ";

    // �� �Ӹ� ��ġ
    // ���� ��ġ
    Point prevPos = snake[0];
    // ���ο� ��ġ
    Point newPos = snake[0];

    switch (direction)
    {
    case 0: // ���� �̵�
        newPos.y--;
        break;
    case 1: // �Ʒ��� �̵�
        newPos.y++;
        break;
    case 2: // �������� �̵�
        newPos.x--;
        break;
    case 3: // ���������� �̵�
        newPos.x++;
        break;
    }

    Snake SNAKE;

    // �̵��� ��ġ�� ���̰� �ִ��� Ȯ��
    if (newPos.x == fruit1.x && newPos.y == fruit1.y)
    {
        GameBoard* gameBoard = GameBoard::getInstance();
        PlaySound(TEXT("Getting ITEM.wav"), NULL, SND_FILENAME | SND_ASYNC);
        gameBoard->updateScore(20);
        SNAKE.updateScore(20);
        tailLength++;
        // �׵θ� �ȿ� ������ ��ġ�� ���� ����
        fruit1.x = rand() % (width - 2) + 1 + startX;
        fruit1.y = rand() % (height - 2) + 1 + startY;
    }
    // �̵��� ��ġ�� ���̰� �ִ��� Ȯ��
    if (newPos.x == fruit2.x && newPos.y == fruit2.y)
    {
        GameBoard* gameBoard = GameBoard::getInstance();
        PlaySound(TEXT("Getting ITEM.wav"), NULL, SND_FILENAME | SND_ASYNC);
        gameBoard->updateScore(20);
        SNAKE.updateScore(20);
        tailLength++;
        // �׵θ� �ȿ� ������ ��ġ�� ���� ����
        fruit2.x = rand() % (width - 2) + 1 + startX;
        fruit2.y = rand() % (height - 2) + 1 + startY;
    }

    // ���� �̵�
    for (int i = tailLength - 1; i > 0; --i)
    {
        snake[i] = snake[i - 1];
    }

    // �Ӹ� �̵�
    snake[0] = newPos;

    // �浹 üũ
    CheckCollision();
}

void Snake::CheckCollision()
{
    // ���� �ε���
    if (snake[0].x == 0 + startX || // ��
        snake[0].x >= width - 1 + startX || // ��
        snake[0].y == 0 + startY ||  // ��
        snake[0].y >= height - 1 + startY) // �Ʒ�
    {
        Sleep(1000);
        gameOver = true;
    }

    // ������ ����
    for (int i = 1; i < tailLength; ++i)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            Sleep(1000);
            gameOver = true; // �Ӹ��� ������ ������ ���� ����
        }
    }

    // ���� �ð� �ʰ�
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
    cout << "�ð� : " << remainingTime << "��  ";
    gotoxy(width + 5 + startX, 11);
    cout << "���� : " << gameBoard->getScore() << "�� ";
}

void Snake::Play()
{
    system("mode con:cols=100 lines=35");
    init();
    int i = 0;
    gameOver = false;

    GameBoard* gameBoard = GameBoard::getInstance();

    // �׵θ� �׸���
    system("cls");
    gameBoard->drawBorder(width, height);
    Setup();

    while (!gameOver)
    {
        Draw();
        for (; i < 1; i++)
        {
            gotoxy((width + startX) / 2, (height + startY) / 2);
            cout << "3�� �� ���۵˴ϴ�.";
            Sleep(1000);

            gotoxy((width + startX) / 2, (height + startY) / 2);
            cout << "2�� �� ���۵˴ϴ�.";
            Sleep(1000);

            gotoxy((width + startX) / 2, (height + startY) / 2);
            cout << "1�� �� ���۵˴ϴ�.";
            Sleep(1000);

            gotoxy((width + startX) / 2, (height + startY) / 2);
            cout << "                     ";
        }
        DrawScore();
        Logic();

        // �����ð��� ���� �ӵ� ����
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
        Sleep(FPSnum); // ���� �ӵ� ����
    }
}