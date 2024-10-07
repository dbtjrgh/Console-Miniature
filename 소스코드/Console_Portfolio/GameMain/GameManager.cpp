#include "GameManager.h"

int GameManager::SelectAndPlayGame()
{
    GameBoard* gameBoard = GameBoard::getInstance();
    Avoidance avoidance;
    Block_Breaker block_beaker;
    Chicken chicken;
    Running running;
    Snake snake;

    // ���� ������ ���� �õ� ����
    srand(time(NULL));

    // ���� ���õ� ������ �����ϴ� ����
    int selectedGameIndex;

    // ������ ���õ� ������ �����ϴ� ����
    int prevSelectedGameIndex = -1;

    bool GameStart = false;

    MainScreen screen;
    screen.output1();
    GameManager::GameRuleSkip = true;
    int i = 0;
    int check = 1;

    // ���� ������� ���� ��� �ý��� �ʱ�ȭ
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
            // ���� �� ����
            screen.output3();         
        }
        else if (i == 2)
        {
            if (check % 2 == 1)
            {
                // ���� �� ��ŵ		
                gotoxy(50, 30);
                cout << "  �� ������ ���� ��ŵ�ϰڽ��ϴ�.";
                check++;
                Sleep(2000);
                GameManager::GameRuleSkip = false;
            }
            else if (check % 2 == 0)
            {
                // ���� �� ��ŵ		
                gotoxy(50, 30);
                cout << "  �� ������ ���� �ٽ� ǥ���ϰڽ��ϴ�.";                
                check++;
                Sleep(2000);
                GameManager::GameRuleSkip = true;
            }

        }
        else if (i == 3)
        {
            gotoxy(50, 32);
            cout << "  ������ �����ϰڽ��ϴ�.";
            Sleep(1000);
            system("cls");
            return 1;
        }
    } while (!GameStart);
    
    do {
        // �������� ���� ����
        selectedGameIndex = rand() % 5;
    
        // ���õ� ���� ����
        switch (selectedGameIndex)
        {
        case 0:
        {
            if (!selectedGames.count(0))
            {
                Avoidance game;
                // �� ��ŵ�� �ߴٸ� ��ŵ
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

// ���� �����
int GameManager::restartGame()
{
    string s;
    gotoxy(46, 26);
    s = "������ �ٽ� �����ϰڽ��ϱ�?";
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
        cout << (SelectedOption == 0 ? "�� " : "  ") << "��";
        gotoxy(50, 30);
        cout << (SelectedOption == 1 ? "�� " : "  ") << "�ƴϿ�";

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
        case 119: // ���� Ű
            if (SelectedOption > 0)
                SelectedOption--;
            break;

        case 115: // �Ʒ��� Ű
            if (SelectedOption < 1)
                SelectedOption++;
            break;

        case 13: // ���� Ű

            switch (SelectedOption)
            {
            case 0: // �ٽý���
                return 0;

            case 1: // ����
                return 1;
            }

        }
        
    }
}