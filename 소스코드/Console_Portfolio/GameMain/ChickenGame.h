#pragma once

#include "MainScreen.h"
#include "GameBoard.h"

using namespace std;

extern int ChickenScore;

class Chicken
{
private:
    string sentence;
    int bullets[6]; // 4발의 총알, 실탄이 있는 위치는 1로 표시
    bool playerTurn; // 현재 플레이어의 차례인지 여부
    bool gameOver; // 게임 오버 여부


public:
    void Play();
    void Rule();

    void ChickenLogic();
    void updateScore(int newScore);
    void resetScore();

    void PlayerTurn();
    void PlayerTurnShoot();
    void PlayerTurnPlayer();
    void PlayerTurnPlayerShoot();

    void EnemyTurn();
    void EnemyTurnShoot();
    void EnemyTurnEnemy();
    void EnemyTurnEnemyShoot();
};