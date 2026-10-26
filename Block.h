#pragma once
#include "DxLib.h"

class Block {
public:
	Block(int startX,int startY);
	void Draw();
private:
	int x;
	int y;
	int width = 100;
	int height = 24;
	bool isAlive = true;
};