#pragma once

#include <Windows.h>
#include <iostream>
#include <set>

#include "Block_BreakerGame.h"
#include "ChickenGame.h"
#include "AvoidanceGame.h"
#include "RunningGame.h"
#include "SnakeGame.h"
#include "MainScreen.h"

using namespace std;

class GameManager
{
public:    
    int SelectedOption;
    bool GameRuleSkip;

    // ������ ���õ� ������ �����ϴ� ����
    set<int> selectedGames;

    int SelectAndPlayGame();
    int restartGame();
};