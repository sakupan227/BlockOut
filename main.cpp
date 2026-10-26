#include "DxLib.h"
#include "Game.h"

const int MAX_SCREEN_WIDTH = 1280;
const int MAX_SCREEN_HEIGHT = 720;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
					int nCmdShow) {
	DxLib::SetWindowText(TEXT("BLOCKOUT"));
	DxLib::ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(TRUE, FALSE);
	SetGraphMode(MAX_SCREEN_WIDTH, MAX_SCREEN_HEIGHT,32);
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	if (DxLib_Init() == -1) {
		return -1;
	}

	Game game;
	game.RunGame();

	DxLib_End();

	return 0;
}