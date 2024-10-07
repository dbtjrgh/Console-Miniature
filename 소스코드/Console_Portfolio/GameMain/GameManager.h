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

    // 이전에 선택된 게임을 저장하는 변수
    set<int> selectedGames;

    int SelectAndPlayGame();
    int restartGame();
};