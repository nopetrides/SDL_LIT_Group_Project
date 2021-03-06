#include "Game.h"
#include <Windows.h>
#include <stdio.h>
// our Game object
Game* g_game = 0;
int main(int argc, char* argv[])
{
	AllocConsole();
	FILE *myFile;
	freopen_s(&myFile,"CON","w", stdout);
	g_game = new Game();
	g_game->init("Chapter 1", 100, 100, 1500, 750, false);

	while(g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
		//SDL_Delay(60);
	}
	g_game->clean();

	return 0;
}