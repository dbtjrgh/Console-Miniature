#include "GameManager.h"

int GameManager::SelectAndPlayGame()
{
    GameBoard* gameBoard = GameBoard::getInstance();
    Avoidance avoidance;
    Block_Breaker block_beaker;
    Chicken chicken;
    Running running;
    Snake snake;

    // 난수 생성을 위해 시드 설정
    srand(time(NULL));

    // 랜덤 선택된 게임을 저장하는 변수
    int selectedGameIndex;

    // 이전에 선택된 게임을 저장하는 변수
    int prevSelectedGameIndex = -1;

    bool GameStart = false;

    MainScreen screen;
    screen.output1();
    GameManager::GameRuleSkip = true;
    int i = 0;
    int check = 1;

    // 게임 재시작을 위한 모든 시스템 초기화
    selectedGames.clear();
    gameBoard->resetScore();
    avoidance.resetScore();
    block_beaker.resetScore();
    chicken.resetScore();
    running.resetScore();
    snake.resetScore();
    
    do {
        i = screen.output2();

        if (i == 0)
        {
            GameStart = true;
        }
        else if (i == 1)
        {
            // 게임 룰 설명
            screen.output3();         
        }
        else if (i == 2)
        {
            if (check % 2 == 1)
            {
                // 게임 룰 스킵		
                gotoxy(50, 30);
                cout << "  각 게임의 룰을 스킵하겠습니다.";
                check++;
                Sleep(2000);
                GameManager::GameRuleSkip = false;
            }
            else if (check % 2 == 0)
            {
                // 게임 룰 스킵		
                gotoxy(50, 30);
                cout << "  각 게임의 룰을 다시 표기하겠습니다.";                
                check++;
                Sleep(2000);
                GameManager::GameRuleSkip = true;
            }

        }
        else if (i == 3)
        {
            gotoxy(50, 32);
            cout << "  게임을 종료하겠습니다.";
            Sleep(1000);
            system("cls");
            return 1;
        }
    } while (!GameStart);
    
    do {
        // 무작위로 게임 선택
        selectedGameIndex = rand() % 5;
    
        // 선택된 게임 실행
        switch (selectedGameIndex)
        {
        case 0:
        {
            if (!selectedGames.count(0))
            {
                Avoidance game;
                // 룰 스킵을 했다면 스킵
                if (GameManager::GameRuleSkip)
                {
                    game.Rule();
                }
                game.Play();
                screen.scoreStatus();
                selectedGames.insert(0);
            }
            break;
        }
        case 1:
        {
            if (!selectedGames.count(1))
            {
                Block_Breaker game;
                if (GameManager::GameRuleSkip)
                {
                    game.Rule();
                }
                game.Play();
                screen.scoreStatus();
                selectedGames.insert(1);
            }
            break;
        }
        case 2:
        {
            if (!selectedGames.count(2))
            {
                Chicken game;
                if (GameManager::GameRuleSkip)
                {
                    game.Rule();
                }
                game.Play();
                screen.scoreStatus();
                selectedGames.insert(2);
            }
            break;
        }
        case 3:
        {
            if (!selectedGames.count(3))
            {
                Running game;
                if (GameManager::GameRuleSkip)
                {
                    game.Rule();
                }
                game.Play();
                screen.scoreStatus();
                selectedGames.insert(3);
            }
            break;
        }
        case 4:
        {
            if (!selectedGames.count(4))
            {
                Snake game;
                if (GameManager::GameRuleSkip)
                {
                    game.Rule();
                }
                game.Play();
                screen.scoreStatus();
                selectedGames.insert(4);
            }
            break;
        }
        }
    
    
    } while (selectedGames.size() < 5);

    
    
    system("mode con:cols=120 lines=40");
    screen.finalscore();
}

// 게임 재시작
int GameManager::restartGame()
{
    string s;
    gotoxy(46, 26);
    s = "게임을 다시 시작하겠습니까?";
    textAnimation(s, 20);

    if (SelectedOption == 1)
    {
        return 1;
    }

    SelectedOption = 0;
    int key;
    while (1)
    {
        gotoxy(50, 28);
        cout << (SelectedOption == 0 ? "▶ " : "  ") << "예";
        gotoxy(50, 30);
        cout << (SelectedOption == 1 ? "▶ " : "  ") << "아니요";

        key = _getch();

        if (key == 224)
        {
            key = _getch();
            switch (key)
            {
            case 72:
                if (SelectedOption > 0)
                    SelectedOption--;
                break;
            case 80:
                if (SelectedOption < 1)
                    SelectedOption++;
                break;
            }
        }
        switch (key)
        {
        case 119: // 위쪽 키
            if (SelectedOption > 0)
                SelectedOption--;
            break;

        case 115: // 아래쪽 키
            if (SelectedOption < 1)
                SelectedOption++;
            break;

        case 13: // 엔터 키

            switch (SelectedOption)
            {
            case 0: // 다시시작
                return 0;

            case 1: // 종료
                return 1;
            }

        }
        
    }
}