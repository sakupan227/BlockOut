#pragma once
#include "DxLib.h"
#include "Block.h"
#include <cmath>

class Game {
public:
	enum GameState {
		Title,
		Ready,
		Playing,
		Game_Over,
		Clear
	};

	float ballSpeedX = 4.0f;
	float ballSpeedY = -4.0f;

	void SetState(GameState newState);
	void RunGame();
private:
	GameState state = Title;
	int textWidth = 0;

	bool ballLaunched = false;
	
	int StartPadleX = 590;
	int StartPadleY = 640;
	int x = StartPadleX;
	int y = StartPadleY;
	int padleSpeed = 7;
	int padleLength = 100;

	int EndPadleX = 690;
	int EndPadleY = 656;
	int endX = EndPadleX;
	int endY = EndPadleY;
	float hitOffset=0.0;

	int StartcirX = 640;
	int StartcirY = 580;
	int cirX = StartcirX;
	int cirY = StartcirY;
	const int rad = 8;

	const int maxX = 1280;
	const int minX = 0;
	const int topY = 0;
	const int floorY = 720;
};