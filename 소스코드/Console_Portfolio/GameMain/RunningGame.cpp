#include "RunningGame.h"

#define DINO_BOTTOM_Y 20
#define TREE_BOTTOM_Y 25
#define TREE_BOTTOM_X1 70
#define TREE_BOTTOM_X2 70

void Running::Rule()
{
    GameBoard* gameBoard = GameBoard::getInstance();
    system("mode con:cols=120 lines=40");

    system("cls");

    init();
    
    gotoxy(49, 11);
    sentence = "  ũ�Ұ��� ";
    textAnimation(sentence, 50);

    gotoxy(50, 13);
    sentence = "�� ���ӷ� ��";
    textAnimation(sentence, 50);

    gotoxy(46, 15);
    sentence = " ���۹� : �����̽� ";
    textAnimation(sentence, 50);

    gotoxy(40, 17);
    sentence = " ������ �̿��� ��ֹ� ���ϱ�";
    textAnimation(sentence, 20);

    gotoxy(40, 19);
    sentence = " �ð��� �������� ���̵� ����";
    textAnimation(sentence, 20);

    gotoxy(40, 21);
    sentence = " ���� �ѹ� �� ���� 10���� ȹ��";
    textAnimation(sentence, 20);

    gotoxy(40, 23);
    sentence = " Please press Enter Key";
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
                gotoxy(46, 23);

                sentence = " Loading ";
                textAnimation(sentence, 100);

                sentence = ". . .";
                textAnimation(sentence, 300);
                break;
            }
        }
        else
        {
            Sleep(500);
            clearLine(23);
            gotoxy(40, 23);
            Sleep(500);
            cout << sentence;
        }
    }
}



// Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void Running::GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// ������ �׸��� �Լ�
void Running::DrawDino(int dinoY)
{
    init();
    GotoXY(0, dinoY);
    static bool legFlag = true;
    TextColor(12, 0);
    printf("        &&&&&&& \n");
    printf("       &&  &&&&&\n");
    printf("       &&&&&&&&&\n");
    printf("&      &&&      \n");
    printf("&&     &&&&&&&  \n");
    printf("&&    &&&&&     \n");
    printf(" &&  &&&&&&&&&& \n");
    printf(" &&&&&&&&&&&    \n");
    printf("  &&&&&&&&&&    \n");
    printf("    &&&&&&&&    \n");
    printf("     &&&&&&     \n");
    if (legFlag)
    {
        printf("     &    &&&    \n");
        printf("     &&          ");
        legFlag = false;
    }
    else
    {
        printf("     &&&  &     \n");
        printf("          &&    ");
        legFlag = true;
    }
    TextColor(15, 0);
}

// ������ �׸��� �Լ�
void Running::DrawTree1(int treeX1)
{
    TextColor(10, 0);
    GotoXY(treeX1, TREE_BOTTOM_Y);
    printf("     &&& ");
    GotoXY(treeX1, TREE_BOTTOM_Y + 1);
    printf("     &&& ");
    GotoXY(treeX1, TREE_BOTTOM_Y + 2);
    printf(" &&  &&&  && ");
    GotoXY(treeX1, TREE_BOTTOM_Y + 3);
    printf(" &&  &&&  && ");
    GotoXY(treeX1, TREE_BOTTOM_Y + 4);
    printf(" &&&&&&&&&&& ");
    GotoXY(treeX1, TREE_BOTTOM_Y + 5);
    printf("     &&& ");
    GotoXY(treeX1, TREE_BOTTOM_Y + 6);
    printf("     &&& ");
    GotoXY(treeX1, TREE_BOTTOM_Y + 7);
    printf("     &&& ");
    TextColor(15, 0);
}
// ������ �׸��� �Լ�
void Running::DrawTree2(int treeX2)
{
    TextColor(10, 0);
    GotoXY(treeX2, TREE_BOTTOM_Y);
    printf("     &&& ");
    GotoXY(treeX2, TREE_BOTTOM_Y + 1);
    printf("     &&& ");
    GotoXY(treeX2, TREE_BOTTOM_Y + 2);
    printf(" &&  &&&  && ");
    GotoXY(treeX2, TREE_BOTTOM_Y + 3);
    printf(" &&  &&&  && ");
    GotoXY(treeX2, TREE_BOTTOM_Y + 4);
    printf(" &&&&&&&&&&& ");
    GotoXY(treeX2, TREE_BOTTOM_Y + 5);
    printf("     &&& ");
    GotoXY(treeX2, TREE_BOTTOM_Y + 6);
    printf("     &&& ");
    GotoXY(treeX2, TREE_BOTTOM_Y + 7);
    printf("     &&& ");
    TextColor(15, 0);
}


// �浹������ true, �ƴϸ� false
bool Running::isCollision(const int treeX1, const int treeX2, const int dinoY)
{
    // Ʈ���� X�� ������ ��ü�ʿ� ������,
    // ������ ���̰� ������� �ʴٸ� �浹�� ó��
    GotoXY(0, 0);
    cout << "treeX1 : " << treeX1 << "  treeX2 : " << treeX2; 
    GotoXY(0, 1);
    cout << "dinoY : " << dinoY;
    if (treeX1 <= 6 && treeX1 >= 1 && dinoY > 14)
    {
        Sleep(1000);
        return true;
    }    
    if (treeX2 <= 6 && treeX2 >= 1 && dinoY > 14)
    {
        Sleep(1000);
        return true;
    }
    return false;
}

int RunningScore = 0;

void Running::updateScore(int newScore)
{
    RunningScore += newScore;
}

void Running::resetScore()
{
    RunningScore = 0;
}

void Running::Play()
{
    system("mode con:cols=160 lines=33");
    GameBoard* gameBoard = GameBoard::getInstance();

    clock_t gameStartTime = clock(); // ���� ���� �ð� ����

    //���� ���۽� �ʱ�ȭ
    bool isJumping = false;
    bool isBottom = true;
    bool Time = false;
    const int gravity = 3;

    int dinoY = DINO_BOTTOM_Y;
    int treeX1 = TREE_BOTTOM_X1;
    int treeX2 = TREE_BOTTOM_X2;
    int score = 0;
    int i = 0;
    clock_t start, curr;    // ���� ���� �ʱ�ȭ
    start = clock();        // ���۽ð� �ʱ�ȭ
    Running running;

    while (!gameOver)
    {
        

        // �浹üũ Ʈ���� x���� ������ y������ �Ǵ�
        if (isCollision(treeX1, treeX2, dinoY))
        {
            gameOver = true;
        }

        // �����̽� Ű�� ���Ȱ�, �ٴ��� �� ����
        if ((GetAsyncKeyState(VK_SPACE) & 0x8000 && isBottom))
        {
            isJumping = true;
            isBottom = false;
            PlaySound(TEXT("Getting ITEM.wav"), NULL, SND_FILENAME | SND_ASYNC);

            // �����Ҷ����� 10�� ����
            gameBoard->updateScore(10);
            running.updateScore(10);
        }

        // �������̶�� Y�� ����, ������ �������� Y�� ����.
        if (isJumping)
        {
            dinoY -= gravity;
        }
        else
        {
            dinoY += gravity;
        }

        // Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
        if (dinoY >= DINO_BOTTOM_Y)
        {
            dinoY = DINO_BOTTOM_Y;
            isBottom = true;
        }
        // ������ ������ ������ ������ ���� ��Ȳ.
        if (dinoY <= 9)
        {
            isJumping = false;
        }

        DrawDino(dinoY);        //draw dino
        DrawTree1(treeX1);      //draw Tree

        for (; i < 1; i++)
        {
            gotoxy(50, 15);
            cout << "3�� �� ���۵˴ϴ�.";
            Sleep(1000);

            gotoxy(50, 15);
            cout << "2�� �� ���۵˴ϴ�.";
            Sleep(1000);

            gotoxy(50, 15);
            cout << "1�� �� ���۵˴ϴ�.";
            Sleep(1000);

            gotoxy(50, 15);
            cout << "                     ";
        }

        // ���� �ð��� �����ͼ� ���� ���� �ð������� ��� �ð��� ���
        curr = clock();
        int elapsedTime = (int)(curr - gameStartTime) / CLOCKS_PER_SEC;

        // ���� �ð� ���
        GotoXY(22, 0);
        int remainingTime = 33 - elapsedTime;
        cout << "�ð� : " << remainingTime << "��";
        gotoxy(44, 1);
        cout << "���� : " << gameBoard->getScore() << "��";

        // ������ �������� (x����) �������ϰ�
        // ������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
        int speed = 2; // ���� �ӵ�
        if (remainingTime < 25) // �����ð� 25�� ���ϸ� �ӵ� �߰�
        {
            speed = 3;
        }
        if ((remainingTime < 10)) // �����ð� 10�� ���ϸ� �ӵ� �߰�
        {
            speed = 4;
        }

        treeX1 -= speed; // ���� �̵� �ӵ�

        if (treeX1 < 0)
        {
            treeX1 = TREE_BOTTOM_X1;
        }

        // ��� �ð��� 0�ʰ� �Ǹ� ���� ����
        if (remainingTime == 0)
        {
            Sleep(1000);
            gameOver = true;            
        }

        if (remainingTime < 20 && treeX1 > 10 && treeX1 < 20)
        {
            Time = true;
        }
        if (Time ) // �����ð� 20�� ���ϸ� ���� �߰�
        {
            treeX2 -= speed; // ���� �̵� �ӵ�
            if (treeX2 < 0)
            {
                treeX2 = TREE_BOTTOM_X2;
            }
            DrawTree2(treeX2);        //draw Tree
        }

        Sleep(60);
        system("cls");        
    }
}
