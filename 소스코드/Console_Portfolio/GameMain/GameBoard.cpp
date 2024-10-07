#include "GameBoard.h"

// GameBoard 클래스의 정적 멤버 변수 초기화
GameBoard* GameBoard::instance = nullptr;

// 싱글톤 인스턴스를 반환하는 정적 메서드 구현
GameBoard* GameBoard::getInstance()
{
    // 인스턴스가 없을 경우에만 새로 생성하여 반환
    if (!instance)
    {
        instance = new GameBoard();
    }
    return instance;
}

// 점수를 업데이트하는 메서드 구현
void GameBoard::updateScore(int points)
{
    Score += points;
}

// 점수 초기화
void GameBoard::resetScore()
{
    Score = 0;
}

// 현재 점수를 반환하는 메서드 구현
int GameBoard::getScore() const
{
    return Score;
}

void GameBoard::drawBorder(int width, int height)
{
    // 왼쪽 상단에서 테두리를 띄워 놓을 공백 개수 계산
    int startX = 21;
    int startY = 5;

    system("cls");

    // 위쪽에 공백 추가
    for (int i = 0; i < startY; ++i)
    {
        cout << endl;
    }

    // 테두리 그리기
    for (int y = 0; y < height; ++y)
    {
        // 왼쪽에 공백 추가
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
                    cout << "+"; // 화면의 모서리 부분
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
                    cout << "|"; // 세로 테두리
                }
                else
                {
                    cout << "-"; // 가로 테두리
                }
            }
            else
            {
                cout << " "; // 빈 공간
            }
        }
        cout << endl;
    }
}