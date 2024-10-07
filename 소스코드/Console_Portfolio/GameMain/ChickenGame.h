#pragma once

#include "MainScreen.h"
#include "GameBoard.h"

using namespace std;

extern int ChickenScore;

class Chicken
{
private:
    string sentence;
    int bullets[6]; // 4���� �Ѿ�, ��ź�� �ִ� ��ġ�� 1�� ǥ��
    bool playerTurn; // ���� �÷��̾��� �������� ����
    bool gameOver; // ���� ���� ����


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