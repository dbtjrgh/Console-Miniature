#include "GameBoard.h"

// GameBoard Ŭ������ ���� ��� ���� �ʱ�ȭ
GameBoard* GameBoard::instance = nullptr;

// �̱��� �ν��Ͻ��� ��ȯ�ϴ� ���� �޼��� ����
GameBoard* GameBoard::getInstance()
{
    // �ν��Ͻ��� ���� ��쿡�� ���� �����Ͽ� ��ȯ
    if (!instance)
    {
        instance = new GameBoard();
    }
    return instance;
}

// ������ ������Ʈ�ϴ� �޼��� ����
void GameBoard::updateScore(int points)
{
    Score += points;
}

// ���� �ʱ�ȭ
void GameBoard::resetScore()
{
    Score = 0;
}

// ���� ������ ��ȯ�ϴ� �޼��� ����
int GameBoard::getScore() const
{
    return Score;
}

void GameBoard::drawBorder(int width, int height)
{
    // ���� ��ܿ��� �׵θ��� ��� ���� ���� ���� ���
    int startX = 21;
    int startY = 5;

    system("cls");

    // ���ʿ� ���� �߰�
    for (int i = 0; i < startY; ++i)
    {
        cout << endl;
    }

    // �׵θ� �׸���
    for (int y = 0; y < height; ++y)
    {
        // ���ʿ� ���� �߰�
        for (int i = 0; i < startX; ++i)
        {
            cout << " ";
        }

        for (int x = 0; x < width; ++x)
        {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
            {
                if (x == 0 && y == 0)
                {
                    cout << "+"; // ȭ���� �𼭸� �κ�
                }
                else if (x == 0 && y == height - 1)
                {
                    cout << "+";
                }
                else if (x == width - 1 && y == 0)
                {
                    cout << "+";
                }
                else if (x == width - 1 && y == height - 1)
                {
                    cout << "+";
                }
                else if (x == 0 || x == width - 1)
                {
                    cout << "|"; // ���� �׵θ�
                }
                else
                {
                    cout << "-"; // ���� �׵θ�
                }
            }
            else
            {
                cout << " "; // �� ����
            }
        }
        cout << endl;
    }
}