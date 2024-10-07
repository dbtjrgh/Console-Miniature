#pragma once
#include <iostream>

using namespace std;
class GameBoard
{
private:
    int Score; // ������ ������ ����
	
    // �̱��� �ν��Ͻ��� ������ ���� ��� ����
    static GameBoard* instance;
	GameBoard() : Score(0) {} // �����ڴ� private�� �����Ͽ� �ܺο��� �ν��Ͻ� ���� �Ұ���


public:	

    // �̱��� �ν��Ͻ��� �������� ���� �޼���
    static GameBoard* getInstance();
		
	// ������ ������Ʈ�ϴ� �޼���
	void updateScore(int points);

	void resetScore();

	// ���� ������ ��ȯ�ϴ� �޼���
	int getScore() const;

	// �׵θ� �׸��� �Լ� ����
	static void drawBorder(int width, int height);
};