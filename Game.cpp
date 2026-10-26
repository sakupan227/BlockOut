#include "Game.h"

void Game::RunGame(){
	Block block(95, 50);
	while (ProcessMessage() != -1) {
		ClearDrawScreen();
		SetFontSize(48);

		switch (state) {
		case Title:
			textWidth = GetDrawStringWidth(TEXT("Block Out"),-1);
			DrawString(maxX/2-textWidth/2, 360, TEXT("Block Out"), GetColor(255, 255, 255), -1);
			textWidth = GetDrawStringWidth(TEXT("Enterキーでスタート"), -1);
			DrawString(maxX / 2 - textWidth / 2, 360+48, TEXT("Enterキーでスタート"), GetColor(255, 255, 255), -1);
			if (CheckHitKey(KEY_INPUT_RETURN)) {
				state = Ready;
			}

			break;
		case Ready:
			textWidth = GetDrawStringWidth(TEXT("SPACEキーで開始"),-1);
			DrawString(maxX/2-textWidth/2, 360, TEXT("SPACEキーで開始"), GetColor(255, 255, 255), -1);
			if (CheckHitKey(KEY_INPUT_SPACE)) {
				state = Playing;
				ballLaunched = TRUE;
			}

			break;
		case Playing:
			block.Draw();
			if (ballLaunched) {
				cirX = (int)(cirX+ballSpeedX);
				cirY = (int)(cirY + ballSpeedY);

				if (cirX > maxX-rad) {
					cirX = maxX-rad;
					ballSpeedX *= -1;
				}
				else if(cirX < minX+rad){
					cirX = minX+rad;
					ballSpeedX *= -1;
				}

				if (cirY < topY-rad) {
					cirY = topY-rad;
					ballSpeedY *= -1;
				}
				else if (cirY > floorY+rad) {
					cirY = floorY+rad;
					ballSpeedY *= -1;

					state = Game_Over;
					ballLaunched = false;

					cirX = StartcirX;
					cirY = StartcirY;
					ballSpeedX = 4;
					ballSpeedY = -4;

					x = StartPadleX;
					y = StartPadleY;
					endX = EndPadleX;
					endY = EndPadleY;
					break;
				}

				DrawCircle(cirX, cirY, rad, GetColor(255, 255, 255), TRUE);
			}
			if (CheckHitKey(KEY_INPUT_LEFT)) {
				x -= padleSpeed;
				endX -= padleSpeed;
			}
			if (CheckHitKey(KEY_INPUT_RIGHT)) {
				x += padleSpeed;
				endX += padleSpeed;
			}
			if (x < minX) {
				x = minX;
				endX = minX + padleLength;
			}else if (endX > maxX) {
				x = maxX - padleLength;
				endX = maxX;
			}

			DrawBox(x, y, endX, endY, GetColor(255, 255, 255), TRUE);

			if (cirY + rad >= y && cirY+rad<endY && cirX > x && cirX < endX) {
				cirY = y - rad;
				hitOffset = ((float)(cirX - x) / padleLength) - 0.5f;
				ballSpeedX = hitOffset * 8;
				ballSpeedY = -sqrt(32.0f - (ballSpeedX * ballSpeedX));
			}

			break;
		case Game_Over:
			textWidth= GetDrawStringWidth(TEXT("GAME OVER"),-1);
			DrawString(maxX / 2 - textWidth / 2, floorY / 2, TEXT("GAME OVER"), GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_R)) state = Title;
			break;
		case Clear:

			break;
		}

		ScreenFlip();
	}
}