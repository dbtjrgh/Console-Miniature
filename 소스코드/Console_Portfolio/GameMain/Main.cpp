#include "GameManager.h"

int main()
{
    
    system("mode con:cols=120 lines=40");
    system("title 경일게임아카데미 VR7기 유석호 콘솔 미니어쳐 게임");
    GameManager manager;
    int result = 0;
    while (result == 0)
    {
        result = manager.SelectAndPlayGame();
        if (result == 1)
        {
            system("cls");
            break;
        }
        result = manager.restartGame();
        if (result == 1)
        {
            system("cls");
            break;
        }
    }
    return 0;
}