#pragma once
#include <iostream>

using namespace std;
class GameBoard
{
private:
    int Score; // 점수를 저장할 변수
	
    // 싱글톤 인스턴스를 저장할 정적 멤버 변수
    static GameBoard* instance;
	GameBoard() : Score(0) {} // 생성자는 private로 선언하여 외부에서 인스턴스 생성 불가능


public:	

    // 싱글톤 인스턴스를 가져오는 정적 메서드
    static GameBoard* getInstance();
		
	// 점수를 업데이트하는 메서드
	void updateScore(int points);

	void resetScore();

	// 현재 점수를 반환하는 메서드
	int getScore() const;

	// 테두리 그리기 함수 선언
	static void drawBorder(int width, int height);
};