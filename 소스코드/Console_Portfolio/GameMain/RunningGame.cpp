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
    sentence = "  크롬공룡 ";
    textAnimation(sentence, 50);

    gotoxy(50, 13);
    sentence = "◆ 게임룰 ◆";
    textAnimation(sentence, 50);

    gotoxy(46, 15);
    sentence = " 조작법 : 스페이스 ";
    textAnimation(sentence, 50);

    gotoxy(40, 17);
    sentence = " 점프를 이용해 장애물 피하기";
    textAnimation(sentence, 20);

    gotoxy(40, 19);
    sentence = " 시간이 지날수록 난이도 증가";
    textAnimation(sentence, 20);

    gotoxy(40, 21);
    sentence = " 점프 한번 당 점수 10점씩 획득";
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



// 커서의 위치를 x, y로 이동하는 함수
void Running::GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 공룡을 그리는 함수
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

// 나무를 그리는 함수
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
// 나무를 그리는 함수
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


// 충돌했으면 true, 아니면 false
bool Running::isCollision(const int treeX1, const int treeX2, const int dinoY)
{
    // 트리의 X가 공룡의 몸체쪽에 있을때,
    // 공룡의 높이가 충분하지 않다면 충돌로 처리
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

    clock_t gameStartTime = clock(); // 게임 시작 시간 저장

    //게임 시작시 초기화
    bool isJumping = false;
    bool isBottom = true;
    bool Time = false;
    const int gravity = 3;

    int dinoY = DINO_BOTTOM_Y;
    int treeX1 = TREE_BOTTOM_X1;
    int treeX2 = TREE_BOTTOM_X2;
    int score = 0;
    int i = 0;
    clock_t start, curr;    // 점수 변수 초기화
    start = clock();        // 시작시간 초기화
    Running running;

    while (!gameOver)
    {
        

        // 충돌체크 트리의 x값과 공룡의 y값으로 판단
        if (isCollision(treeX1, treeX2, dinoY))
        {
            gameOver = true;
        }

        // 스페이스 키가 눌렸고, 바닥일 때 점프
        if ((GetAsyncKeyState(VK_SPACE) & 0x8000 && isBottom))
        {
            isJumping = true;
            isBottom = false;
            PlaySound(TEXT("Getting ITEM.wav"), NULL, SND_FILENAME | SND_ASYNC);

            // 점프할때마다 10점 증가
            gameBoard->updateScore(10);
            running.updateScore(10);
        }

        // 점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
        if (isJumping)
        {
            dinoY -= gravity;
        }
        else
        {
            dinoY += gravity;
        }

        // Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
        if (dinoY >= DINO_BOTTOM_Y)
        {
            dinoY = DINO_BOTTOM_Y;
            isBottom = true;
        }
        // 점프의 맨위를 찍으면 점프가 끝난 상황.
        if (dinoY <= 9)
        {
            isJumping = false;
        }

        DrawDino(dinoY);        //draw dino
        DrawTree1(treeX1);      //draw Tree

        for (; i < 1; i++)
        {
            gotoxy(50, 15);
            cout << "3초 후 시작됩니다.";
            Sleep(1000);

            gotoxy(50, 15);
            cout << "2초 후 시작됩니다.";
            Sleep(1000);

            gotoxy(50, 15);
            cout << "1초 후 시작됩니다.";
            Sleep(1000);

            gotoxy(50, 15);
            cout << "                     ";
        }

        // 현재 시간을 가져와서 게임 시작 시간부터의 경과 시간을 계산
        curr = clock();
        int elapsedTime = (int)(curr - gameStartTime) / CLOCKS_PER_SEC;

        // 남은 시간 출력
        GotoXY(22, 0);
        int remainingTime = 33 - elapsedTime;
        cout << "시간 : " << remainingTime << "초";
        gotoxy(44, 1);
        cout << "점수 : " << gameBoard->getScore() << "점";

        // 나무가 왼쪽으로 (x음수) 가도록하고
        // 나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
        int speed = 2; // 나무 속도
        if (remainingTime < 25) // 남은시간 25초 이하면 속도 추가
        {
            speed = 3;
        }
        if ((remainingTime < 10)) // 남은시간 10초 이하면 속도 추가
        {
            speed = 4;
        }

        treeX1 -= speed; // 나무 이동 속도

        if (treeX1 < 0)
        {
            treeX1 = TREE_BOTTOM_X1;
        }

        // 경과 시간이 0초가 되면 게임 종료
        if (remainingTime == 0)
        {
            Sleep(1000);
            gameOver = true;            
        }

        if (remainingTime < 20 && treeX1 > 10 && treeX1 < 20)
        {
            Time = true;
        }
        if (Time ) // 남은시간 20초 이하면 나무 추가
        {
            treeX2 -= speed; // 나무 이동 속도
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
