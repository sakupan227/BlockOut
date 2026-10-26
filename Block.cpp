#include "Block.h"

Block::Block(int startX, int startY)
	:x(startX), y(startY) {
}

void Block::Draw() {
	DrawBox(x, y, x + width, y + height, GetColor(255, 255, 255), true);
}