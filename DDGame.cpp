#include "Game.h"
#include <SDL_image.h>
#include <iostream>
#include "SDL_draw.h"

const int LEVEL_WIDTH = 10000;
const int LEVEL_HEIGHT = 3000;

const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 750;

const int JOYSTICK_DEAD_ZONE = 8000;

void Game::image_load_Level_1() {
	SDL_Surface *temp = IMG_Load("assets/16x1Platform.png");
	m_Textures[0] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/16x12Platform with lights.png");
	m_Textures[1] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/8x8Hydrant.png");
	m_Textures[2] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/8x8NewsBox.png");
	m_Textures[3] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/8x16TyreStack.png");
	m_Textures[4] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/32x16Bench.png");
	m_Textures[5] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/8x8TrashCan.png");
	m_Textures[6] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/160x110Box.png");
	m_Textures[7] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/8x8NewsBox.png");
	m_Textures[8] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/43x32House.png");
	m_Textures[9] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/49x21Truck.png");
	m_Textures[10] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/16x16Bread.png");
	m_Textures[11] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

}

void Game::image_load_Level_2()
{
	SDL_Surface *temp = IMG_Load("assets/16x1Platform.png");
	m_Textures[0] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/16x12Platform with lights.png");
	m_Textures[1] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/8x8Hydrant.png");
	m_Textures[2] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/8x8NewsBox.png");
	m_Textures[3] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/8x16TyreStack.png");
	m_Textures[4] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/32x16Bench.png");
	m_Textures[5] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/8x8TrashCan.png");
	m_Textures[6] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/160x110Box.png");
	m_Textures[7] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/8x8NewsBox.png");
	m_Textures[8] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/43x32House.png");
	m_Textures[9] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/49x21Truck.png");
	m_Textures[10] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/16x16Bread.png");
	m_Textures[11] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/100x160Pine.png");
	m_Textures[12] = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	


}

void Game::image_load()
{
	// LOAD QUACK WAVE
	SDL_Surface* pQuackSurf = IMG_Load("assets/16x16Wave.png");
	if (pQuackSurf == NULL)
		std::cout << "\nUnable to load image!\n";

	// LOAD IN THE PLAYER IMAGE
	SDL_Surface* pPlayerSurface = IMG_Load("assets/Derk16Alpha.png");
	if (pPlayerSurface == NULL)
		std::cout << "\nUnable to load image!\n";


	SDL_Surface *temp = IMG_Load("assets/1440x160short hop quack.png");
	pPlayer->t_DuckHop = SDL_CreateTextureFromSurface(m_pRenderer, temp);
		
	temp = IMG_Load("assets/500x150Falling.png");
	pPlayer->t_DuckFalling = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/980x140Death Animation.png");
	pPlayer->t_DuckDeath = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/940x150DuckIdle.png");
	pPlayer->t_DuckIdle = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/960x150WalkingQuack.png");
	pPlayer->t_DuckQuack = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/960x150WDuckWalk.png");
	pPlayer->t_DuckWalk = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	temp = IMG_Load("assets/1450x160SurpriseHop.png");
	pPlayer->t_DuckSuprised = SDL_CreateTextureFromSurface(m_pRenderer, temp);

	m_pQuackTexture = SDL_CreateTextureFromSurface(m_pRenderer, pQuackSurf);
	SDL_FreeSurface(pQuackSurf);

	SDL_FreeSurface(pPlayerSurface);

	//Level Objects
	if (Level == 0)
	{
		image_load_Level_1();
	}
	if (Level == 1)
	{
		image_load_Level_2();
	}

	SDL_FreeSurface(temp);	
}

void Game::spawner_level_1()
{
	pObjects[0] = new Obstacle;
	pObjects[0]->spawn("Flat", 0, 100, SCREEN_HEIGHT - 200, m_Textures[0]);

	//Dont use
	pObjects[1] = new Obstacle;
	pObjects[1]->spawn("Flat", 0, -200, SCREEN_HEIGHT - 200, m_Textures[1]);
	//
	pObjects[2] = new Obstacle;
	pObjects[2]->spawn("Hydrant", 0, 850, SCREEN_HEIGHT - 280, m_Textures[2]);

	pObjects[3] = new Obstacle;
	pObjects[3]->spawn("NewsBox", 0, 600, SCREEN_HEIGHT - 280, m_Textures[3]);

	pObjects[4] = new Obstacle;
	pObjects[4]->spawn("Flat", 0, 260, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[5] = new Obstacle;
	pObjects[5]->spawn("Flat", 0, 300, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[6] = new Obstacle;
	pObjects[6]->spawn("TyreStack", 0, 300, SCREEN_HEIGHT, m_Textures[4]);

	pObjects[7] = new Obstacle;
	pObjects[7]->spawn("Bench", 0, 600, SCREEN_HEIGHT, m_Textures[5]);

	pObjects[8] = new Obstacle;
	pObjects[8]->spawn("Flat", 0, 800, SCREEN_HEIGHT, m_Textures[0]);

	pObjects[9] = new Obstacle;
	pObjects[9]->spawn("Flat", 0, 900, SCREEN_HEIGHT, m_Textures[0]);

//Dont use
	pObjects[10] = new Obstacle;
	pObjects[10]->spawn("TrashCan", 0, 1200, SCREEN_HEIGHT - 0, m_Textures[6]);
//
	pObjects[11] = new Obstacle;
	pObjects[11]->spawn("Box", 0, 1000, SCREEN_HEIGHT - 310, m_Textures[7]);

	pObjects[12] = new Obstacle;
	pObjects[12]->spawn("Box", 0, 1000, SCREEN_HEIGHT - 420, m_Textures[7]);

	pObjects[13] = new Obstacle;
	pObjects[13]->spawn("TrashCan", 0, 1200, SCREEN_HEIGHT - 200, m_Textures[6]);

	pObjects[14] = new Obstacle;
	pObjects[14]->spawn("Flat", 0, 1360, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[15] = new Obstacle;
	pObjects[15]->spawn("Flat", 0, 1520, SCREEN_HEIGHT - 200, m_Textures[0]);

//FIRE ANIMATION HERE 1400,200

	pObjects[16] = new Obstacle;
	pObjects[16]->spawn("Flat", 0, 1850, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[17] = new Obstacle;
	pObjects[17]->spawn("House", 0, 1600, SCREEN_HEIGHT - 210, m_Textures[9]);

	pObjects[18] = new Obstacle;
	pObjects[18]->spawn("Flat", 0, 1680, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[19] = new Obstacle;
	pObjects[19]->spawn("Flat", 0, 1760, SCREEN_HEIGHT - 210, m_Textures[0]);

	pObjects[10] = new Obstacle;
	pObjects[10]->spawn("TrashCan", 0, 2000, SCREEN_HEIGHT - 200, m_Textures[6]);

	pObjects[11] = new Obstacle;
	pObjects[11]->spawn("Box", 0, 2200, SCREEN_HEIGHT - 310, m_Textures[7]);

	pObjects[20] = new Obstacle;
	pObjects[20]->spawn("Bread", 0, 2500, SCREEN_HEIGHT - 250, m_Textures[11]);


}

void Game::spawner_level_2()
{
    pObjects[0] = new Obstacle;
	pObjects[0]->spawn("Flat", 0, 100, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[1] = new Obstacle;
	pObjects[1]->spawn("Flat", 0, 560, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[2] = new Obstacle;
	pObjects[2]->spawn("Flat", 0, 910, SCREEN_HEIGHT - 250, m_Textures[0]);

	pObjects[3] = new Obstacle;
	pObjects[3]->spawn("Flat", 0, 1300, SCREEN_HEIGHT - 250, m_Textures[0]);

	pObjects[4] = new Obstacle;
	pObjects[4]->spawn("Flat", 0, 1750, SCREEN_HEIGHT - 250, m_Textures[0]);

	pObjects[5] = new Obstacle;
	pObjects[5]->spawn("Box", 0, 2010, SCREEN_HEIGHT - 250, m_Textures[7]);

	pObjects[6] = new Obstacle;
	pObjects[6]->spawn("Flat", 0, 2310, SCREEN_HEIGHT - 250, m_Textures[0]);

	pObjects[7] = new Obstacle;
	pObjects[7]->spawn("Flat", 0, 2690, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[8] = new Obstacle;
	pObjects[8]->spawn("Pine", 0, 2990, SCREEN_HEIGHT - 200, m_Textures[12]);

	pObjects[9] = new Obstacle;
	pObjects[9]->spawn("Flat", 0, 3340, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[10] = new Obstacle;
	pObjects[10]->spawn("TireStack", 0, 3640, SCREEN_HEIGHT - 200, m_Textures[4]);

	pObjects[11] = new Obstacle;
	pObjects[11]->spawn("Flat", 0, 4000, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[12] = new Obstacle;
	pObjects[12]->spawn("Flat", 0, 4350, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[13] = new Obstacle;
	pObjects[13]->spawn("Flat", 0, 4600, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[14] = new Obstacle;
	pObjects[14]->spawn("Truck", 0, 5000, SCREEN_HEIGHT - 200, m_Textures[10]);

	pObjects[15] = new Obstacle;
	pObjects[15]->spawn("Flat", 0, 5600, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[16] = new Obstacle;
	pObjects[16]->spawn("Flat", 0, 5910, SCREEN_HEIGHT - 200, m_Textures[0]);

	pObjects[17] = new Obstacle;
	pObjects[17]->spawn("Bench", 0, 6310, SCREEN_HEIGHT - 200, m_Textures[5]);

	pObjects[18] = new Obstacle;
	pObjects[18]->spawn("Hydrant", 0, 6850, SCREEN_HEIGHT - 150, m_Textures[2]);

	pObjects[19] = new Obstacle;
	pObjects[19]->spawn("Bread", 0, 7200, SCREEN_HEIGHT - 200, m_Textures[11]);


}

void Game::spawner()
{
	// Spawn player with name, speed, x,y and texture
	pPlayer->spawn("Player", 3, 160, LEVEL_HEIGHT - 400, pPlayer->t_DuckFalling);

	// Spawn QUACK with name, speed, x,y and texture
	pQuack->spawn("Quack", 3, 160, LEVEL_HEIGHT - 400, m_pQuackTexture);

	//OBJECTS IN LEVEL
	//spawner_level_1();
	if (Level == 0)
	{
		spawner_level_1();
	}
	if (Level == 1)
	{
		spawner_level_2();
	}

}

void Game::destination_level_1()
{
	pObjects[0]->m_sourceRectangle.x = 0;
	pObjects[0]->m_sourceRectangle.y = 0;
	pObjects[0]->m_sourceRectangle.w = 16;
	pObjects[0]->m_sourceRectangle.h = 1;
	m_dests[0].x = pObjects[0]->m_x;
	m_dests[0].y = pObjects[0]->m_y;
	m_dests[0].w = pObjects[0]->m_sourceRectangle.w * 10;
	m_dests[0].h = pObjects[0]->m_sourceRectangle.h * 10;
	DoubleObject[0].x = m_dests[0].x;
	DoubleObject[0].y = m_dests[0].y;
	DoubleObject[0].w = m_dests[0].w;
	DoubleObject[0].h = m_dests[0].h;
	Starting_Pos[0].x = m_dests[0].x;
	Starting_Pos[0].y = m_dests[0].y;
	Starting_Pos[0].w = m_dests[0].w;
	Starting_Pos[0].h = m_dests[0].h;

	//Don't use this block
	pObjects[1]->m_sourceRectangle.x = 0;
	pObjects[1]->m_sourceRectangle.y = 0;
	pObjects[1]->m_sourceRectangle.w = 16;
	pObjects[1]->m_sourceRectangle.h = 12;
	m_dests[1].x = pObjects[1]->m_x;
	m_dests[1].y = pObjects[1]->m_y;
	m_dests[1].w = pObjects[1]->m_sourceRectangle.w * 10;
	m_dests[1].h = pObjects[1]->m_sourceRectangle.h * 10;
	DoubleObject[1].x = m_dests[1].x;
	DoubleObject[1].y = m_dests[1].y;
	DoubleObject[1].w = m_dests[1].w;
	DoubleObject[1].h = m_dests[1].h;
	Starting_Pos[1].x = m_dests[1].x;
	Starting_Pos[1].y = m_dests[1].y;
	Starting_Pos[1].w = m_dests[1].w;
	Starting_Pos[1].h = m_dests[1].h;
	//

	pObjects[2]->m_sourceRectangle.x = 0;
	pObjects[2]->m_sourceRectangle.y = 0;
	pObjects[2]->m_sourceRectangle.w = 6;
	pObjects[2]->m_sourceRectangle.h = 8;
	m_dests[2].x = pObjects[2]->m_x;
	m_dests[2].y = pObjects[2]->m_y;
	m_dests[2].w = pObjects[2]->m_sourceRectangle.w * 10;
	m_dests[2].h = pObjects[2]->m_sourceRectangle.h * 10;
	DoubleObject[2].x = m_dests[2].x;
	DoubleObject[2].y = m_dests[2].y;
	DoubleObject[2].w = m_dests[2].w;
	DoubleObject[2].h = m_dests[2].h;
	Starting_Pos[2].x = m_dests[2].x;
	Starting_Pos[2].y = m_dests[2].y;
	Starting_Pos[2].w = m_dests[2].w;
	Starting_Pos[2].h = m_dests[2].h;

	pObjects[3]->m_sourceRectangle.x = 0;
	pObjects[3]->m_sourceRectangle.y = 0;
	pObjects[3]->m_sourceRectangle.w = 6;
	pObjects[3]->m_sourceRectangle.h = 8;
	m_dests[3].x = pObjects[3]->m_x;
	m_dests[3].y = pObjects[3]->m_y;
	m_dests[3].w = pObjects[3]->m_sourceRectangle.w * 10;
	m_dests[3].h = pObjects[3]->m_sourceRectangle.h * 10;
	DoubleObject[3].x = m_dests[3].x;
	DoubleObject[3].y = m_dests[3].y;
	DoubleObject[3].w = m_dests[3].w;
	DoubleObject[3].h = m_dests[3].h;
	Starting_Pos[3].x = m_dests[3].x;
	Starting_Pos[3].y = m_dests[3].y;
	Starting_Pos[3].w = m_dests[3].w;
	Starting_Pos[3].h = m_dests[3].h;

	pObjects[4]->m_sourceRectangle.x = 0;
	pObjects[4]->m_sourceRectangle.y = 0;
	pObjects[4]->m_sourceRectangle.w = 16;
	pObjects[4]->m_sourceRectangle.h = 1;
	m_dests[4].x = pObjects[4]->m_x;
	m_dests[4].y = pObjects[4]->m_y;
	m_dests[4].w = pObjects[4]->m_sourceRectangle.w * 10;
	m_dests[4].h = pObjects[4]->m_sourceRectangle.h * 10;
	DoubleObject[4].x = m_dests[4].x;
	DoubleObject[4].y = m_dests[4].y;
	DoubleObject[4].w = m_dests[4].w;
	DoubleObject[4].h = m_dests[4].h;
	Starting_Pos[4].x = m_dests[4].x;
	Starting_Pos[4].y = m_dests[4].y;
	Starting_Pos[4].w = m_dests[4].w;
	Starting_Pos[4].h = m_dests[4].h;

	pObjects[5]->m_sourceRectangle.x = 0;
	pObjects[5]->m_sourceRectangle.y = 0;
	pObjects[5]->m_sourceRectangle.w = 16;
	pObjects[5]->m_sourceRectangle.h = 1;
	m_dests[5].x = pObjects[5]->m_x;
	m_dests[5].y = pObjects[5]->m_y;
	m_dests[5].w = pObjects[5]->m_sourceRectangle.w * 10;
	m_dests[5].h = pObjects[5]->m_sourceRectangle.h * 10;
	DoubleObject[5].x = m_dests[5].x;
	DoubleObject[5].y = m_dests[5].y;
	DoubleObject[5].w = m_dests[5].w;
	DoubleObject[5].h = m_dests[5].h;
	Starting_Pos[5].x = m_dests[5].x;
	Starting_Pos[5].y = m_dests[5].y;
	Starting_Pos[5].w = m_dests[5].w;
	Starting_Pos[5].h = m_dests[5].h;

	pObjects[6]->m_sourceRectangle.x = 0;
	pObjects[6]->m_sourceRectangle.y = 0;
	pObjects[6]->m_sourceRectangle.w = 8;
	pObjects[6]->m_sourceRectangle.h = 16;
	m_dests[6].x = pObjects[6]->m_x;
	m_dests[6].y = pObjects[6]->m_y;
	m_dests[6].w = pObjects[6]->m_sourceRectangle.w * 10;
	m_dests[6].h = pObjects[6]->m_sourceRectangle.h * 10;
	DoubleObject[6].x = m_dests[6].x;
	DoubleObject[6].y = m_dests[6].y;
	DoubleObject[6].w = m_dests[6].w;
	DoubleObject[6].h = m_dests[6].h;
	Starting_Pos[6].x = m_dests[6].x;
	Starting_Pos[6].y = m_dests[6].y;
	Starting_Pos[6].w = m_dests[6].w;
	Starting_Pos[6].h = m_dests[6].h;

	pObjects[7]->m_sourceRectangle.x = 0;
	pObjects[7]->m_sourceRectangle.y = 0;
	pObjects[7]->m_sourceRectangle.w = 32;
	pObjects[7]->m_sourceRectangle.h = 16;
	m_dests[7].x = pObjects[7]->m_x;
	m_dests[7].y = pObjects[7]->m_y;
	m_dests[7].w = pObjects[7]->m_sourceRectangle.w * 10;
	m_dests[7].h = pObjects[7]->m_sourceRectangle.h * 10;
	DoubleObject[7].x = m_dests[7].x;
	DoubleObject[7].y = m_dests[7].y;
	DoubleObject[7].w = m_dests[7].w;
	DoubleObject[7].h = m_dests[7].h;
	Starting_Pos[7].x = m_dests[7].x;
	Starting_Pos[7].y = m_dests[7].y;
	Starting_Pos[7].w = m_dests[7].w;
	Starting_Pos[7].h = m_dests[7].h;

	pObjects[8]->m_sourceRectangle.x = 0;
	pObjects[8]->m_sourceRectangle.y = 0;
	pObjects[8]->m_sourceRectangle.w = 400;
	pObjects[8]->m_sourceRectangle.h = 1;
	m_dests[8].x = pObjects[0]->m_x;
	m_dests[8].y = pObjects[0]->m_y;
	m_dests[8].w = pObjects[0]->m_sourceRectangle.w * 10;
	m_dests[8].h = pObjects[0]->m_sourceRectangle.h * 10;
	DoubleObject[8].x = m_dests[8].x;
	DoubleObject[8].y = m_dests[8].y;
	DoubleObject[8].w = m_dests[8].w;
	DoubleObject[8].h = m_dests[8].h;
	Starting_Pos[8].x = m_dests[8].x;
	Starting_Pos[8].y = m_dests[8].y;
	Starting_Pos[8].w = m_dests[8].w;
	Starting_Pos[8].h = m_dests[8].h;

	pObjects[9]->m_sourceRectangle.x = 0;
	pObjects[9]->m_sourceRectangle.y = 0;
	pObjects[9]->m_sourceRectangle.w = 400;
	pObjects[9]->m_sourceRectangle.h = 1;
	m_dests[9].x = pObjects[9]->m_x;
	m_dests[9].y = pObjects[9]->m_y;
	m_dests[9].w = pObjects[9]->m_sourceRectangle.w * 10;
	m_dests[9].h = pObjects[9]->m_sourceRectangle.h * 10;
	DoubleObject[9].x = m_dests[9].x;
	DoubleObject[9].y = m_dests[9].y;
	DoubleObject[9].w = m_dests[9].w;
	DoubleObject[9].h = m_dests[9].h;
	Starting_Pos[9].x = m_dests[9].x;
	Starting_Pos[9].y = m_dests[9].y;
	Starting_Pos[9].w = m_dests[9].w;
	Starting_Pos[9].h = m_dests[9].h;

	pObjects[10]->m_sourceRectangle.x = 0;
	pObjects[10]->m_sourceRectangle.y = 0;
	pObjects[10]->m_sourceRectangle.w = 8;
	pObjects[10]->m_sourceRectangle.h = 8;
	m_dests[10].x = pObjects[10]->m_x;
	m_dests[10].y = pObjects[10]->m_y;
	m_dests[10].w = pObjects[10]->m_sourceRectangle.w * 10;
	m_dests[10].h = pObjects[10]->m_sourceRectangle.h * 10;
	DoubleObject[10].x = m_dests[10].x;
	DoubleObject[10].y = m_dests[10].y;
	DoubleObject[10].w = m_dests[10].w;
	DoubleObject[10].h = m_dests[10].h;
	Starting_Pos[10].x = m_dests[10].x;
	Starting_Pos[10].y = m_dests[10].y;
	Starting_Pos[10].w = m_dests[10].w;
	Starting_Pos[10].h = m_dests[10].h;

	pObjects[11]->m_sourceRectangle.x = 0;
	pObjects[11]->m_sourceRectangle.y = 0;
	pObjects[11]->m_sourceRectangle.w = 16;
	pObjects[11]->m_sourceRectangle.h = 11;
	m_dests[11].x = pObjects[11]->m_x;
	m_dests[11].y = pObjects[11]->m_y;
	m_dests[11].w = pObjects[11]->m_sourceRectangle.w * 10;
	m_dests[11].h = pObjects[11]->m_sourceRectangle.h * 10;
	DoubleObject[11].x = m_dests[11].x;
	DoubleObject[11].y = m_dests[11].y;
	DoubleObject[11].w = m_dests[11].w;
	DoubleObject[11].h = m_dests[11].h;
	Starting_Pos[11].x = m_dests[11].x;
	Starting_Pos[11].y = m_dests[11].y;
	Starting_Pos[11].w = m_dests[11].w;
	Starting_Pos[11].h = m_dests[11].h;

	pObjects[12]->m_sourceRectangle.x = 0;
	pObjects[12]->m_sourceRectangle.y = 0;
	pObjects[12]->m_sourceRectangle.w = 16;
	pObjects[12]->m_sourceRectangle.h = 11;
	m_dests[12].x = pObjects[12]->m_x;
	m_dests[12].y = pObjects[12]->m_y;
	m_dests[12].w = pObjects[12]->m_sourceRectangle.w * 10;
	m_dests[12].h = pObjects[12]->m_sourceRectangle.h * 10;
	DoubleObject[12].x = m_dests[12].x;
	DoubleObject[12].y = m_dests[12].y;
	DoubleObject[12].w = m_dests[12].w;
	DoubleObject[12].h = m_dests[12].h;
	Starting_Pos[12].x = m_dests[12].x;
	Starting_Pos[12].y = m_dests[12].y;
	Starting_Pos[12].w = m_dests[12].w;
	Starting_Pos[12].h = m_dests[12].h;

	pObjects[13]->m_sourceRectangle.x = 0;
	pObjects[13]->m_sourceRectangle.y = 0;
	pObjects[13]->m_sourceRectangle.w = 8;
	pObjects[13]->m_sourceRectangle.h = 8;
	m_dests[13].x = pObjects[13]->m_x;
	m_dests[13].y = pObjects[13]->m_y;
	m_dests[13].w = pObjects[13]->m_sourceRectangle.w * 10;
	m_dests[13].h = pObjects[13]->m_sourceRectangle.h * 10;
	DoubleObject[13].x = m_dests[13].x;
	DoubleObject[13].y = m_dests[13].y;
	DoubleObject[13].w = m_dests[13].w;
	DoubleObject[13].h = m_dests[13].h;
	Starting_Pos[13].x = m_dests[13].x;
	Starting_Pos[13].y = m_dests[13].y;
	Starting_Pos[13].w = m_dests[13].w;
	Starting_Pos[13].h = m_dests[13].h;
	
	pObjects[14]->m_sourceRectangle.x = 0;
	pObjects[14]->m_sourceRectangle.y = 0;
	pObjects[14]->m_sourceRectangle.w = 16;
	pObjects[14]->m_sourceRectangle.h = 1;
	m_dests[14].x = pObjects[14]->m_x;
	m_dests[14].y = pObjects[14]->m_y;
	m_dests[14].w = pObjects[14]->m_sourceRectangle.w * 10;
	m_dests[14].h = pObjects[14]->m_sourceRectangle.h * 10;
	DoubleObject[14].x = m_dests[14].x;
	DoubleObject[14].y = m_dests[14].y;
	DoubleObject[14].w = m_dests[14].w;
	DoubleObject[14].h = m_dests[14].h;
	Starting_Pos[14].x = m_dests[14].x;
	Starting_Pos[14].y = m_dests[14].y;
	Starting_Pos[14].w = m_dests[14].w;
	Starting_Pos[14].h = m_dests[14].h;

	pObjects[15]->m_sourceRectangle.x = 0;
	pObjects[15]->m_sourceRectangle.y = 0;
	pObjects[15]->m_sourceRectangle.w = 16;
	pObjects[15]->m_sourceRectangle.h = 1;
	m_dests[15].x = pObjects[15]->m_x;
	m_dests[15].y = pObjects[15]->m_y;
	m_dests[15].w = pObjects[15]->m_sourceRectangle.w * 10;
	m_dests[15].h = pObjects[15]->m_sourceRectangle.h * 10;
	DoubleObject[15].x = m_dests[15].x;
	DoubleObject[15].y = m_dests[15].y;
	DoubleObject[15].w = m_dests[15].w;
	DoubleObject[15].h = m_dests[15].h;
	Starting_Pos[15].x = m_dests[15].x;
	Starting_Pos[15].y = m_dests[15].y;
	Starting_Pos[15].w = m_dests[15].w;
	Starting_Pos[15].h = m_dests[15].h;

	pObjects[16]->m_sourceRectangle.x = 0;
	pObjects[16]->m_sourceRectangle.y = 0;
	pObjects[16]->m_sourceRectangle.w = 16;
	pObjects[16]->m_sourceRectangle.h = 1;
	m_dests[16].x = pObjects[16]->m_x;
	m_dests[16].y = pObjects[16]->m_y;
	m_dests[16].w = pObjects[16]->m_sourceRectangle.w * 10;
	m_dests[16].h = pObjects[16]->m_sourceRectangle.h * 10;
	DoubleObject[16].x = m_dests[16].x;
	DoubleObject[16].y = m_dests[16].y;
	DoubleObject[16].w = m_dests[16].w;
	DoubleObject[16].h = m_dests[16].h;
	Starting_Pos[16].x = m_dests[16].x;
	Starting_Pos[16].y = m_dests[16].y;
	Starting_Pos[16].w = m_dests[16].w;
	Starting_Pos[16].h = m_dests[16].h;

	pObjects[17]->m_sourceRectangle.x = 0;
	pObjects[17]->m_sourceRectangle.y = 0;
	pObjects[17]->m_sourceRectangle.w = 43;
	pObjects[17]->m_sourceRectangle.h = 32;
	m_dests[17].x = pObjects[17]->m_x;
	m_dests[17].y = pObjects[17]->m_y;
	m_dests[17].w = pObjects[17]->m_sourceRectangle.w * 10;
	m_dests[17].h = pObjects[17]->m_sourceRectangle.h * 10;
	DoubleObject[17].x = m_dests[17].x;
	DoubleObject[17].y = m_dests[17].y;
	DoubleObject[17].w = m_dests[17].w;
	DoubleObject[17].h = m_dests[17].h;
	Starting_Pos[17].x = m_dests[17].x;
	Starting_Pos[17].y = m_dests[17].y;
	Starting_Pos[17].w = m_dests[17].w;
	Starting_Pos[17].h = m_dests[17].h;

	pObjects[18]->m_sourceRectangle.x = 0;
	pObjects[18]->m_sourceRectangle.y = 0;
	pObjects[18]->m_sourceRectangle.w = 16;
	pObjects[18]->m_sourceRectangle.h = 1;
	m_dests[18].x = pObjects[18]->m_x;
	m_dests[18].y = pObjects[18]->m_y;
	m_dests[18].w = pObjects[18]->m_sourceRectangle.w * 10;
	m_dests[18].h = pObjects[18]->m_sourceRectangle.h * 10;
	DoubleObject[18].x = m_dests[18].x;
	DoubleObject[18].y = m_dests[18].y;
	DoubleObject[18].w = m_dests[18].w;
	DoubleObject[18].h = m_dests[18].h;
	Starting_Pos[18].x = m_dests[18].x;
	Starting_Pos[18].y = m_dests[18].y;
	Starting_Pos[18].w = m_dests[18].w;
	Starting_Pos[18].h = m_dests[18].h;

	pObjects[19]->m_sourceRectangle.x = 0;
	pObjects[19]->m_sourceRectangle.y = 0;
	pObjects[19]->m_sourceRectangle.w = 16;
	pObjects[19]->m_sourceRectangle.h = 1;
	m_dests[19].x = pObjects[19]->m_x;
	m_dests[19].y = pObjects[19]->m_y;
	m_dests[19].w = pObjects[19]->m_sourceRectangle.w * 10;
	m_dests[19].h = pObjects[19]->m_sourceRectangle.h * 10;
	DoubleObject[19].x = m_dests[19].x;
	DoubleObject[19].y = m_dests[19].y;
	DoubleObject[19].w = m_dests[19].w;
	DoubleObject[19].h = m_dests[19].h;
	Starting_Pos[19].x = m_dests[19].x;
	Starting_Pos[19].y = m_dests[19].y;
	Starting_Pos[19].w = m_dests[19].w;
	Starting_Pos[19].h = m_dests[19].h;

	pObjects[20]->m_sourceRectangle.x = 0;
	pObjects[20]->m_sourceRectangle.y = 0;
	pObjects[20]->m_sourceRectangle.w = 16;
	pObjects[20]->m_sourceRectangle.h = 16;
	m_dests[20].x = pObjects[20]->m_x;
	m_dests[20].y = pObjects[20]->m_y;
	m_dests[20].w = pObjects[20]->m_sourceRectangle.w *10 ;
	m_dests[20].h = pObjects[20]->m_sourceRectangle.h *10 ;
	DoubleObject[20].x = m_dests[20].x;
	DoubleObject[20].y = m_dests[20].y;
	DoubleObject[20].w = m_dests[20].w;
	DoubleObject[20].h = m_dests[20].h;
	Starting_Pos[20].x = m_dests[20].x;
	Starting_Pos[20].y = m_dests[20].y;
	Starting_Pos[20].w = m_dests[20].w;
	Starting_Pos[20].h = m_dests[20].h;
}

void Game::destination_level_2()
{
	pObjects[0]->m_sourceRectangle.x = 0;
	pObjects[0]->m_sourceRectangle.y = 0;
	pObjects[0]->m_sourceRectangle.w = 16;
	pObjects[0]->m_sourceRectangle.h = 1;
	m_dests[0].x = pObjects[0]->m_x;
	m_dests[0].y = pObjects[0]->m_y;
	m_dests[0].w = pObjects[0]->m_sourceRectangle.w * 10;
	m_dests[0].h = pObjects[0]->m_sourceRectangle.h * 10;
	DoubleObject[0].x = m_dests[0].x;
	DoubleObject[0].y = m_dests[0].y;
	DoubleObject[0].w = m_dests[0].w;
	DoubleObject[0].h = m_dests[0].h;
	Starting_Pos[0].x = m_dests[0].x;
	Starting_Pos[0].y = m_dests[0].y;
	Starting_Pos[0].w = m_dests[0].w;
	Starting_Pos[0].h = m_dests[0].h;

	pObjects[1]->m_sourceRectangle.x = 0;
	pObjects[1]->m_sourceRectangle.y = 0;
	pObjects[1]->m_sourceRectangle.w = 16;
	pObjects[1]->m_sourceRectangle.h = 1;
	m_dests[1].x = pObjects[1]->m_x;
	m_dests[1].y = pObjects[1]->m_y;
	m_dests[1].w = pObjects[1]->m_sourceRectangle.w * 10;
	m_dests[1].h = pObjects[1]->m_sourceRectangle.h * 10;
	DoubleObject[1].x = m_dests[1].x;
	DoubleObject[1].y = m_dests[1].y;
	DoubleObject[1].w = m_dests[1].w;
	DoubleObject[1].h = m_dests[1].h;
	Starting_Pos[1].x = m_dests[1].x;
	Starting_Pos[1].y = m_dests[1].y;
	Starting_Pos[1].w = m_dests[1].w;
	Starting_Pos[1].h = m_dests[1].h;

	pObjects[2]->m_sourceRectangle.x = 0;
	pObjects[2]->m_sourceRectangle.y = 0;
	pObjects[2]->m_sourceRectangle.w = 16;
	pObjects[2]->m_sourceRectangle.h = 1;
	m_dests[2].x = pObjects[2]->m_x;
	m_dests[2].y = pObjects[2]->m_y;
	m_dests[2].w = pObjects[2]->m_sourceRectangle.w * 10;
	m_dests[2].h = pObjects[2]->m_sourceRectangle.h * 10;
	DoubleObject[2].x = m_dests[2].x;
	DoubleObject[2].y = m_dests[2].y;
	DoubleObject[2].w = m_dests[2].w;
	DoubleObject[2].h = m_dests[2].h;
	Starting_Pos[2].x = m_dests[2].x;
	Starting_Pos[2].y = m_dests[2].y;
	Starting_Pos[2].w = m_dests[2].w;
	Starting_Pos[2].h = m_dests[2].h;

	pObjects[3]->m_sourceRectangle.x = 0;
	pObjects[3]->m_sourceRectangle.y = 0;
	pObjects[3]->m_sourceRectangle.w = 16;
	pObjects[3]->m_sourceRectangle.h = 1;
	m_dests[3].x = pObjects[3]->m_x;
	m_dests[3].y = pObjects[3]->m_y;
	m_dests[3].w = pObjects[3]->m_sourceRectangle.w * 10;
	m_dests[3].h = pObjects[3]->m_sourceRectangle.h * 10;
	DoubleObject[3].x = m_dests[3].x;
	DoubleObject[3].y = m_dests[3].y;
	DoubleObject[3].w = m_dests[3].w;
	DoubleObject[3].h = m_dests[3].h;
	Starting_Pos[3].x = m_dests[3].x;
	Starting_Pos[3].y = m_dests[3].y;
	Starting_Pos[3].w = m_dests[3].w;
	Starting_Pos[3].h = m_dests[3].h;

	pObjects[4]->m_sourceRectangle.x = 0;
	pObjects[4]->m_sourceRectangle.y = 0;
	pObjects[4]->m_sourceRectangle.w = 16;
	pObjects[4]->m_sourceRectangle.h = 1;
	m_dests[4].x = pObjects[4]->m_x;
	m_dests[4].y = pObjects[4]->m_y;
	m_dests[4].w = pObjects[4]->m_sourceRectangle.w * 10;
	m_dests[4].h = pObjects[4]->m_sourceRectangle.h * 10;
	DoubleObject[4].x = m_dests[4].x;
	DoubleObject[4].y = m_dests[4].y;
	DoubleObject[4].w = m_dests[4].w;
	DoubleObject[4].h = m_dests[4].h;
	Starting_Pos[4].x = m_dests[4].x;
	Starting_Pos[4].y = m_dests[4].y;
	Starting_Pos[4].w = m_dests[4].w;
	Starting_Pos[4].h = m_dests[4].h;

	pObjects[5]->m_sourceRectangle.x = 0;
	pObjects[5]->m_sourceRectangle.y = 0;
	pObjects[5]->m_sourceRectangle.w = 16;
	pObjects[5]->m_sourceRectangle.h = 1;
	m_dests[5].x = pObjects[5]->m_x;
	m_dests[5].y = pObjects[5]->m_y;
	m_dests[5].w = pObjects[5]->m_sourceRectangle.w * 10;
	m_dests[5].h = pObjects[5]->m_sourceRectangle.h * 10;
	DoubleObject[5].x = m_dests[5].x;
	DoubleObject[5].y = m_dests[5].y;
	DoubleObject[5].w = m_dests[5].w;
	DoubleObject[5].h = m_dests[5].h;
	Starting_Pos[5].x = m_dests[5].x;
	Starting_Pos[5].y = m_dests[5].y;
	Starting_Pos[5].w = m_dests[5].w;
	Starting_Pos[5].h = m_dests[5].h;

	pObjects[6]->m_sourceRectangle.x = 0;
	pObjects[6]->m_sourceRectangle.y = 0;
	pObjects[6]->m_sourceRectangle.w = 16;
	pObjects[6]->m_sourceRectangle.h = 10;
	m_dests[6].x = pObjects[6]->m_x;
	m_dests[6].y = pObjects[6]->m_y;
	m_dests[6].w = pObjects[6]->m_sourceRectangle.w * 10;
	m_dests[6].h = pObjects[6]->m_sourceRectangle.h * 10;
	DoubleObject[6].x = m_dests[6].x;
	DoubleObject[6].y = m_dests[6].y;
	DoubleObject[6].w = m_dests[6].w;
	DoubleObject[6].h = m_dests[6].h;
	Starting_Pos[6].x = m_dests[6].x;
	Starting_Pos[6].y = m_dests[6].y;
	Starting_Pos[6].w = m_dests[6].w;
	Starting_Pos[6].h = m_dests[6].h;

	pObjects[7]->m_sourceRectangle.x = 0;
	pObjects[7]->m_sourceRectangle.y = 0;
	pObjects[7]->m_sourceRectangle.w = 16;
	pObjects[7]->m_sourceRectangle.h = 1;
	m_dests[7].x = pObjects[7]->m_x;
	m_dests[7].y = pObjects[7]->m_y;
	m_dests[7].w = pObjects[7]->m_sourceRectangle.w * 10;
	m_dests[7].h = pObjects[7]->m_sourceRectangle.h * 10;
	DoubleObject[7].x = m_dests[7].x;
	DoubleObject[7].y = m_dests[7].y;
	DoubleObject[7].w = m_dests[7].w;
	DoubleObject[7].h = m_dests[7].h;
	Starting_Pos[7].x = m_dests[7].x;
	Starting_Pos[7].y = m_dests[7].y;
	Starting_Pos[7].w = m_dests[7].w;
	Starting_Pos[7].h = m_dests[7].h;

	pObjects[8]->m_sourceRectangle.x = 0;
	pObjects[8]->m_sourceRectangle.y = 0;
	pObjects[8]->m_sourceRectangle.w = 16;
	pObjects[8]->m_sourceRectangle.h = 1;
	m_dests[8].x = pObjects[8]->m_x;
	m_dests[8].y = pObjects[8]->m_y;
	m_dests[8].w = pObjects[8]->m_sourceRectangle.w * 10;
	m_dests[8].h = pObjects[8]->m_sourceRectangle.h * 10;
	DoubleObject[8].x = m_dests[8].x;
	DoubleObject[8].y = m_dests[8].y;
	DoubleObject[8].w = m_dests[8].w;
	DoubleObject[8].h = m_dests[8].h;
	Starting_Pos[8].x = m_dests[8].x;
	Starting_Pos[8].y = m_dests[8].y;
	Starting_Pos[8].w = m_dests[8].w;
	Starting_Pos[8].h = m_dests[8].h;

	pObjects[9]->m_sourceRectangle.x = 0;
	pObjects[9]->m_sourceRectangle.y = 0;
	pObjects[9]->m_sourceRectangle.w = 16;
	pObjects[9]->m_sourceRectangle.h = 10;
	m_dests[9].x = pObjects[9]->m_x;
	m_dests[9].y = pObjects[9]->m_y;
	m_dests[9].w = pObjects[9]->m_sourceRectangle.w * 10;
	m_dests[9].h = pObjects[9]->m_sourceRectangle.h * 10;
	DoubleObject[9].x = m_dests[9].x;
	DoubleObject[9].y = m_dests[9].y;
	DoubleObject[9].w = m_dests[9].w;
	DoubleObject[9].h = m_dests[9].h;
	Starting_Pos[9].x = m_dests[9].x;
	Starting_Pos[9].y = m_dests[9].y;
	Starting_Pos[9].w = m_dests[9].w;
	Starting_Pos[9].h = m_dests[9].h;

	pObjects[10]->m_sourceRectangle.x = 0;
	pObjects[10]->m_sourceRectangle.y = 0;
	pObjects[10]->m_sourceRectangle.w = 16;
	pObjects[10]->m_sourceRectangle.h = 1;
	m_dests[10].x = pObjects[10]->m_x;
	m_dests[10].y = pObjects[10]->m_y;
	m_dests[10].w = pObjects[10]->m_sourceRectangle.w * 10;
	m_dests[10].h = pObjects[10]->m_sourceRectangle.h * 10;
	DoubleObject[10].x = m_dests[10].x;
	DoubleObject[10].y = m_dests[10].y;
	DoubleObject[10].w = m_dests[10].w;
	DoubleObject[10].h = m_dests[10].h;
	Starting_Pos[10].x = m_dests[10].x;
	Starting_Pos[10].y = m_dests[10].y;
	Starting_Pos[10].w = m_dests[10].w;
	Starting_Pos[10].h = m_dests[10].h;

	pObjects[11]->m_sourceRectangle.x = 0;
	pObjects[11]->m_sourceRectangle.y = 0;
	pObjects[11]->m_sourceRectangle.w = 8;
	pObjects[11]->m_sourceRectangle.h = 16;
	m_dests[11].x = pObjects[11]->m_x;
	m_dests[11].y = pObjects[11]->m_y;
	m_dests[11].w = pObjects[11]->m_sourceRectangle.w * 10;
	m_dests[11].h = pObjects[11]->m_sourceRectangle.h * 10;
	DoubleObject[11].x = m_dests[11].x;
	DoubleObject[11].y = m_dests[11].y;
	DoubleObject[11].w = m_dests[11].w;
	DoubleObject[11].h = m_dests[11].h;
	Starting_Pos[11].x = m_dests[11].x;
	Starting_Pos[11].y = m_dests[11].y;
	Starting_Pos[11].w = m_dests[11].w;
	Starting_Pos[11].h = m_dests[11].h;

	pObjects[12]->m_sourceRectangle.x = 0;
	pObjects[12]->m_sourceRectangle.y = 0;
	pObjects[12]->m_sourceRectangle.w = 16;
	pObjects[12]->m_sourceRectangle.h = 1;
	m_dests[12].x = pObjects[12]->m_x;
	m_dests[12].y = pObjects[12]->m_y;
	m_dests[12].w = pObjects[12]->m_sourceRectangle.w * 10;
	m_dests[12].h = pObjects[12]->m_sourceRectangle.h * 10;
	DoubleObject[12].x = m_dests[12].x;
	DoubleObject[12].y = m_dests[12].y;
	DoubleObject[12].w = m_dests[12].w;
	DoubleObject[12].h = m_dests[12].h;
	Starting_Pos[12].x = m_dests[12].x;
	Starting_Pos[12].y = m_dests[12].y;
	Starting_Pos[12].w = m_dests[12].w;
	Starting_Pos[12].h = m_dests[12].h;

	pObjects[13]->m_sourceRectangle.x = 0;
	pObjects[13]->m_sourceRectangle.y = 0;
	pObjects[13]->m_sourceRectangle.w = 16;
	pObjects[13]->m_sourceRectangle.h = 1;
	m_dests[13].x = pObjects[13]->m_x;
	m_dests[13].y = pObjects[13]->m_y;
	m_dests[13].w = pObjects[13]->m_sourceRectangle.w * 10;
	m_dests[13].h = pObjects[13]->m_sourceRectangle.h * 10;
	DoubleObject[13].x = m_dests[13].x;
	DoubleObject[13].y = m_dests[13].y;
	DoubleObject[13].w = m_dests[13].w;
	DoubleObject[13].h = m_dests[13].h;
	Starting_Pos[13].x = m_dests[13].x;
	Starting_Pos[13].y = m_dests[13].y;
	Starting_Pos[13].w = m_dests[13].w;
	Starting_Pos[13].h = m_dests[13].h;

	pObjects[14]->m_sourceRectangle.x = 0;
	pObjects[14]->m_sourceRectangle.y = 0;
	pObjects[14]->m_sourceRectangle.w = 49;
	pObjects[14]->m_sourceRectangle.h = 21;
	m_dests[14].x = pObjects[14]->m_x;
	m_dests[14].y = pObjects[14]->m_y;
	m_dests[14].w = pObjects[14]->m_sourceRectangle.w * 10;
	m_dests[14].h = pObjects[14]->m_sourceRectangle.h * 10;
	DoubleObject[14].x = m_dests[14].x;
	DoubleObject[14].y = m_dests[14].y;
	DoubleObject[14].w = m_dests[14].w;
	DoubleObject[14].h = m_dests[14].h;
	Starting_Pos[14].x = m_dests[14].x;
	Starting_Pos[14].y = m_dests[14].y;
	Starting_Pos[14].w = m_dests[14].w;
	Starting_Pos[14].h = m_dests[14].h;

	pObjects[15]->m_sourceRectangle.x = 0;
	pObjects[15]->m_sourceRectangle.y = 0;
	pObjects[15]->m_sourceRectangle.w = 16;
	pObjects[15]->m_sourceRectangle.h = 1;
	m_dests[15].x = pObjects[15]->m_x;
	m_dests[15].y = pObjects[15]->m_y;
	m_dests[15].w = pObjects[15]->m_sourceRectangle.w * 10;
	m_dests[15].h = pObjects[15]->m_sourceRectangle.h * 10;
	DoubleObject[15].x = m_dests[15].x;
	DoubleObject[15].y = m_dests[15].y;
	DoubleObject[15].w = m_dests[15].w;
	DoubleObject[15].h = m_dests[15].h;
	Starting_Pos[15].x = m_dests[15].x;
	Starting_Pos[15].y = m_dests[15].y;
	Starting_Pos[15].w = m_dests[15].w;
	Starting_Pos[15].h = m_dests[15].h;

	pObjects[16]->m_sourceRectangle.x = 0;
	pObjects[16]->m_sourceRectangle.y = 0;
	pObjects[16]->m_sourceRectangle.w = 16;
	pObjects[16]->m_sourceRectangle.h = 1;
	m_dests[16].x = pObjects[16]->m_x;
	m_dests[16].y = pObjects[16]->m_y;
	m_dests[16].w = pObjects[16]->m_sourceRectangle.w * 10;
	m_dests[16].h = pObjects[16]->m_sourceRectangle.h * 10;
	DoubleObject[16].x = m_dests[16].x;
	DoubleObject[16].y = m_dests[16].y;
	DoubleObject[16].w = m_dests[16].w;
	DoubleObject[16].h = m_dests[16].h;
	Starting_Pos[16].x = m_dests[16].x;
	Starting_Pos[16].y = m_dests[16].y;
	Starting_Pos[16].w = m_dests[16].w;
	Starting_Pos[16].h = m_dests[16].h;

	pObjects[17]->m_sourceRectangle.x = 0;
	pObjects[17]->m_sourceRectangle.y = 0;
	pObjects[17]->m_sourceRectangle.w = 32;
	pObjects[17]->m_sourceRectangle.h = 16;
	m_dests[17].x = pObjects[17]->m_x;
	m_dests[17].y = pObjects[17]->m_y;
	m_dests[17].w = pObjects[17]->m_sourceRectangle.w * 10;
	m_dests[17].h = pObjects[17]->m_sourceRectangle.h * 10;
	DoubleObject[17].x = m_dests[17].x;
	DoubleObject[17].y = m_dests[17].y;
	DoubleObject[17].w = m_dests[17].w;
	DoubleObject[17].h = m_dests[17].h;
	Starting_Pos[17].x = m_dests[17].x;
	Starting_Pos[17].y = m_dests[17].y;
	Starting_Pos[17].w = m_dests[17].w;
	Starting_Pos[17].h = m_dests[17].h;

	pObjects[18]->m_sourceRectangle.x = 0;
	pObjects[18]->m_sourceRectangle.y = 0;
	pObjects[18]->m_sourceRectangle.w = 8;
	pObjects[18]->m_sourceRectangle.h = 8;
	m_dests[18].x = pObjects[18]->m_x;
	m_dests[18].y = pObjects[18]->m_y;
	m_dests[18].w = pObjects[18]->m_sourceRectangle.w * 10;
	m_dests[18].h = pObjects[18]->m_sourceRectangle.h * 10;
	DoubleObject[18].x = m_dests[18].x;
	DoubleObject[18].y = m_dests[18].y;
	DoubleObject[18].w = m_dests[18].w;
	DoubleObject[18].h = m_dests[18].h;
	Starting_Pos[18].x = m_dests[18].x;
	Starting_Pos[18].y = m_dests[18].y;
	Starting_Pos[18].w = m_dests[18].w;
	Starting_Pos[18].h = m_dests[18].h;

	pObjects[19]->m_sourceRectangle.x = 0;
	pObjects[19]->m_sourceRectangle.y = 0;
	pObjects[19]->m_sourceRectangle.w = 16;
	pObjects[19]->m_sourceRectangle.h = 16;
	m_dests[19].x = pObjects[19]->m_x;
	m_dests[19].y = pObjects[19]->m_y;
	m_dests[19].w = pObjects[19]->m_sourceRectangle.w * 10;
	m_dests[19].h = pObjects[19]->m_sourceRectangle.h * 10;
	DoubleObject[19].x = m_dests[19].x;
	DoubleObject[19].y = m_dests[19].y;
	DoubleObject[19].w = m_dests[19].w;
	DoubleObject[19].h = m_dests[19].h;
	Starting_Pos[19].x = m_dests[19].x;
	Starting_Pos[19].y = m_dests[19].y;
	Starting_Pos[19].w = m_dests[19].w;
	Starting_Pos[19].h = m_dests[19].h;
	// hydrant, bread

}

void Game::destination()
{
	//Sonar Circle Initiation
	pPlayer->Sonar.x = pPlayer->m_x;
	pPlayer->Sonar.y = pPlayer->m_y;
	pPlayer->Sonar.r = 1;
	// Create texture from the image FOR QUACK

	playerFlip = SDL_FLIP_NONE;

	// note needed SDL_QueryTexture(m_pTexture, NULL, NULL,&m_sourceRectangle.w, &m_sourceRectangle.h);

	//Set Player's Starting size and position
	pPlayer->m_sourceRectangle = pPlayer->r_RectFalling;
	m_PlayerDest.x = pPlayer->m_x;
	m_PlayerDest.y = pPlayer->m_y;
	m_PlayerDest.w = pPlayer->m_sourceRectangle.w / 2;
	m_PlayerDest.h = pPlayer->m_sourceRectangle.h / 2;


	// Set Quack Starting size and position
	m_QuackDest.x = pPlayer->m_x;
	m_QuackDest.y = pPlayer->m_y;
	m_QuackDest.w = pPlayer->Sonar.r * 2;
	m_QuackDest.h = pPlayer->Sonar.r * 2;
	pQuack->m_sourceRectangle.x = 0;
	pQuack->m_sourceRectangle.y = 0;
	pQuack->m_sourceRectangle.w = 16;
	pQuack->m_sourceRectangle.h = 16;

	//OBJECTS IN LEVEL
	//destination_level_1();
	if (Level == 0)
	{
		destination_level_1();
	}
	if (Level == 1)
	{
		destination_level_2();
	}
}

void Game::render_check()
{
	pPlayer->draw(m_pRenderer, &m_PlayerDest, playerFlip, camera.x, camera.y);

	for (int i = 0; m_dests[i].w != NULL; i++)
	{
		if (pPlayer->b_quackcooldown == true)
		{
			if (sonar_check(pPlayer->Sonar, m_dests[i]))
			{
				pObjects[i]->quackcollide = true;
			}
		}
		else
		{
			pObjects[i]->quackcollide = false;
		}
		if (pObjects[i]->quackcollide)
		{
			//m_dests[i].y = SCREEN_HEIGHT - 200;
			pObjects[i]->draw(m_pRenderer, &m_dests[i], SDL_FLIP_NONE, 0, 0);
		}
			//pObjects[i]->draw(m_pRenderer, &m_dests[i], SDL_FLIP_NONE, 0, 0);
	}

	if (pPlayer->b_quackcooldown == true)
	{
		pQuack->draw(m_pRenderer, &m_QuackDest, SDL_FLIP_NONE, camera.x, camera.y);
	}

}

bool Game::init(const char* title, int xpos, int ypos, int width,int height, bool fullscreen)
{
	for (int i = 0; i < 127; i++)
	{
		m_dests[i].x = 0;
		m_dests[i].y = 0;
		m_dests[i].h = 0;
		m_dests[i].w = 0;
	}

	// attempt to initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO | SDL_INIT_VIDEO) == 0)
	{
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			std::cout << "Failed to make Mixer.";
		}

		gJump = Mix_LoadWAV("assets/MattsQuack.wav");
		gQuack = Mix_LoadWAV("assets/JayQuack.wav");
		gMusic = Mix_LoadMUS("assets/Upbeat 8 bit.wav");
		Mix_PlayMusic(gMusic, -1);

		int flags = 0;
		if(fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}
		std::cout << "SDL init success\n";

		SDL_Texture *img = NULL;
		SDL_Texture *img2 = NULL;
		SDL_Texture *img3 = NULL;
		SDL_Texture *img4 = NULL;
		SDL_Texture *img5 = NULL;
		SDL_Texture *img6 = NULL;
		SDL_Texture *img7 = NULL;

		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,width, height, 4);
		if(m_pWindow != 0) // window init success
		{
			std::cout << "window creation success about to setup textures\n";
			
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			//Check for joysticks
			if (SDL_NumJoysticks() < 1)
			{
				printf("Warning: No joysticks connected!\n");
			}
			else
			{
				//Load joystick
				joystick = SDL_JoystickOpen(0);
				if (joystick == NULL)
				{
					printf("Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
				}

			}


			//MENU GO HERE
			int w, h; // texture width & height
			
			SDL_Texture *temp = IMG_LoadTexture(m_pRenderer, "assets/Splash-16by9.png");

			SDL_Rect temprect; temprect.x = 0; temprect.y = 0; temprect.w = SCREEN_WIDTH; temprect.h = SCREEN_HEIGHT;
			SDL_RenderCopy(m_pRenderer, temp, NULL, &temprect);

			SDL_RenderPresent(m_pRenderer);
			SDL_Delay(2000);

			temp = IMG_LoadTexture(m_pRenderer, "assets/DerkTheDuck.png");

			SDL_RenderCopy(m_pRenderer, temp, NULL, &temprect);

			SDL_RenderPresent(m_pRenderer);
			SDL_Delay(2000);


			img = IMG_LoadTexture(m_pRenderer, "assets/playbutton.png");
			img2 = IMG_LoadTexture(m_pRenderer, "assets/optionbutton.png");
			img3 = IMG_LoadTexture(m_pRenderer, "assets/Level 1.png");
			img4 = IMG_LoadTexture(m_pRenderer, "assets/Level 2.png");
			/*	img5 = IMG_LoadTexture(m_pRenderer, "assets/Level 3.png");
			img6 = IMG_LoadTexture(m_pRenderer, "assets/Level 4.png");
			img7 = IMG_LoadTexture(m_pRenderer, "assets/Level 5.png");
			*/
			SDL_QueryTexture(img, NULL, NULL, &w, &h);
			SDL_QueryTexture(img2, NULL, NULL, &w, &h);
			SDL_QueryTexture(img3, NULL, NULL, &w, &h);
			SDL_QueryTexture(img4, NULL, NULL, &w, &h);
			/*SDL_QueryTexture(img5, NULL, NULL, &w, &h);
			SDL_QueryTexture(img6, NULL, NULL, &w, &h);
			SDL_QueryTexture(img7, NULL, NULL, &w, &h);
			*/

			SDL_Rect texr; texr.x = (SCREEN_WIDTH / 2) - 90; texr.y = (SCREEN_HEIGHT / 2) - 200; texr.w = w; texr.h = h;
			SDL_Rect texr1; texr1.x = (SCREEN_WIDTH / 2) - 90; texr1.y = (SCREEN_HEIGHT / 2) - 20; texr1.w = w; texr1.h = h;
			SDL_Rect texr2; texr2.x = (SCREEN_WIDTH / 2) - 350; texr2.y = (SCREEN_HEIGHT / 2) - 200; texr2.w = w; texr2.h = h;
			SDL_Rect texr3; texr3.x = (SCREEN_WIDTH / 2) - 100; texr3.y = (SCREEN_HEIGHT / 2) - 200; texr3.w = w; texr3.h = h;
			/*SDL_Rect texr4; texr4.x = (SCREEN_WIDTH / 2) - 50; texr4.y = (SCREEN_HEIGHT / 2) - 200; texr4.w = w; texr4.h = h;
			SDL_Rect texr5; texr5.x = (SCREEN_WIDTH / 2) - -100; texr5.y = (SCREEN_HEIGHT / 2) - 200; texr5.w = w; texr5.h = h;
			SDL_Rect texr6; texr6.x = (SCREEN_WIDTH / 2) - -250; texr6.y = (SCREEN_HEIGHT / 2) - 200; texr6.w = w; texr6.h = h;
			*/
			int currentlyhighlighted = 0;
			int OriginalWidth1 = texr.w;
			int OriginalWidth2 = texr1.w;
			int OriginalWidth3 = texr2.w;
			int OriginalWidth4 = texr3.w;
			/*	int OriginalWidth5 = texr4.w;
			int OriginalWidth6 = texr5.w;
			int OriginalWidth7 = texr6.w;
			*/
			int MainMenu = true;
			bool LevelMenu = false;
			bool SettingsMenu = false;

			while (MainMenu) {
				if (currentlyhighlighted == 0)
				{
					texr.w = OriginalWidth1 + 50;
					texr1.w = OriginalWidth1;
				}
				else if (currentlyhighlighted == 1)
				{
					texr1.w = OriginalWidth2 + 50;
					texr.w = OriginalWidth2;
				}

				else if (currentlyhighlighted == 2)
				{


				}

				// event handling
				int xDir = 0;
				int yDir = 0;

				SDL_Event event;
				if (SDL_PollEvent(&event))
				{
					switch (event.type)
					{
					case SDL_JOYAXISMOTION:
						if (event.jaxis.which == 0)
						{
							if (event.jaxis.axis == 0)
							{
								if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
								{
									xDir = -1;
									currentlyhighlighted = 0;
								}
								else if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
								{
									xDir = 1;
									if (currentlyhighlighted == 0)
									{
										currentlyhighlighted = 1;

									}
								}
								else
								{
									xDir = 0;
								}
								break;
							}
						}
					case SDL_JOYBUTTONDOWN:  /* Handle Joystick Button Presses */
						if (event.jbutton.button == 0)
						{
							/* code goes here */
							std::cout << "Button 0 ";
							MainMenu = false;
							if (currentlyhighlighted == 0)
							{
								LevelMenu = true;
							}
							else if (currentlyhighlighted == 1)
							{
								LevelMenu = true; // TEMP
								//SettingsMenu = true;
								//UNDER CONSTRUCTION
							}
						}
						if (event.jbutton.button == 2)
						{
							/* code goes here */
							std::cout << "Button 2 ";


						}
						break;
					case SDL_QUIT:
						m_bRunning = false;
						break;
					default:
						break;
					}
				}
				// clear the screen
				SDL_RenderClear(m_pRenderer);
				// copy the texture to the rendering context
				SDL_RenderCopy(m_pRenderer, img, NULL, &texr);
				SDL_RenderCopy(m_pRenderer, img2, NULL, &texr1);
				// flip the backbuffer
				// this means that everything that we prepared behind the screens is actually shown
				SDL_RenderPresent(m_pRenderer);
			}


			while (LevelMenu)
			{
				if (currentlyhighlighted == 0)
				{
					texr2.w = OriginalWidth3 + 50;
					texr3.w = OriginalWidth4;
					/*					texr4.w = OriginalWidth5;
					texr5.w = OriginalWidth6;
					texr6.w = OriginalWidth7;
					*/
				}
				else if (currentlyhighlighted == 1)
				{
					texr3.w = OriginalWidth2 + 50;
					texr2.w = OriginalWidth3;
					/*				texr4.w = OriginalWidth5;
					texr5.w = OriginalWidth6;
					texr6.w = OriginalWidth7;
						*/
				}

				/*		else if (currentlyhighlighted == 2)
				{
				texr4.w = OriginalWidth2 + 50;
				texr3.w = OriginalWidth4;
				texr2.w = OriginalWidth3;
				texr5.w = OriginalWidth6;
				texr6.w = OriginalWidth7;
				}
				else if (currentlyhighlighted == 3)
				{
				texr5.w = OriginalWidth2 + 50;
				texr3.w = OriginalWidth4;
				texr4.w = OriginalWidth5;
				texr2.w = OriginalWidth3;
				texr6.w = OriginalWidth7;
				}
				else if (currentlyhighlighted == )
				{
				texr6.w = OriginalWidth2 + 50;
				texr3.w = OriginalWidth4;
				texr4.w = OriginalWidth5;
				texr5.w = OriginalWidth6;
				texr2.w = OriginalWidth3;
				}
				*/
				// event handling
				int xDir = 0;
				int yDir = 0;

				SDL_Event event;
				if (SDL_PollEvent(&event))
				{
					switch (event.type)
					{
					case SDL_JOYAXISMOTION:
						if (event.jaxis.which == 0)
						{
							if (event.jaxis.axis == 0)
							{
								if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
								{
									xDir = -1;
									currentlyhighlighted = 0;
								}
								else if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
								{
									xDir = 1;
									if (currentlyhighlighted == 0)
									{
										currentlyhighlighted = 1;

									}
								}
								else
								{
									xDir = 0;
								}
								break;
							}
						}
					case SDL_JOYBUTTONDOWN:  /* Handle Joystick Button Presses */
						if (event.jbutton.button == 0)
						{
							/* code goes here */
							std::cout << "Button 0 ";
							LevelMenu = false;
							if (currentlyhighlighted == 0)
							{
								Level = 0;
							}
							else if (currentlyhighlighted == 1)
							{
								Level = 1;
							}
						}
						if (event.jbutton.button == 2)
						{
							/* code goes here */
							std::cout << "Button 2 ";
						}
						break;
					case SDL_QUIT:
						m_bRunning = false;
						break;
					default:
						break;
					}
				}
				// clear the screen
				SDL_RenderClear(m_pRenderer);
				// copy the texture to the rendering context
				SDL_RenderCopy(m_pRenderer, img3, NULL, &texr2);
				SDL_RenderCopy(m_pRenderer, img4, NULL, &texr3);
				/*				SDL_RenderCopy(m_pRenderer, img5, NULL, &texr1);
				SDL_RenderCopy(m_pRenderer, img6, NULL, &texr);
				SDL_RenderCopy(m_pRenderer, img7, NULL, &texr);
				*/				// flip the backbuffer
				// this means that everything that we prepared behind the screens is actually shown
				SDL_RenderPresent(m_pRenderer);
			}

			while (SettingsMenu)
			{
				//No settings currently
			}


			
			image_load(); // Loads in images

			//create that sexy caaaaaaaamera white boyyyyyy
			camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};			

			spawner(); // Spawn objects

			destination();
			
			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer,0,0,0,255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	std::cout << "init success\n";

	m_bRunning = true; // everything inited successfully, start the main loop
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

	render_check();

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean()
{
	SDL_Texture *temp = IMG_LoadTexture(m_pRenderer, "assets/Win.png");

	SDL_Rect temprect; temprect.x = 0; temprect.y = 0; temprect.w = SCREEN_WIDTH; temprect.h = SCREEN_HEIGHT;
	SDL_RenderCopy(m_pRenderer, temp, NULL, &temprect);

	SDL_RenderPresent(m_pRenderer);
	SDL_Delay(2000);

	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::update()
{

	if (pPlayer->Sonar.r >= 600)
	{
		pPlayer->b_quackcooldown = false;
	}
	else
	{
		pPlayer->Sonar.r += 0.048;
		m_QuackDest.w = pPlayer->Sonar.r * 2;
		m_QuackDest.h = pPlayer->Sonar.r * 2;
		DoubleQuack.x -= 0.048;
		DoubleQuack.y -= 0.048;
		m_QuackDest.x = int(DoubleQuack.x);
		m_QuackDest.y = int(DoubleQuack.y);

	}

	//define its position yeeeeeeeaaaaaahhhhhh
	camera.x = (pPlayer->m_x + m_PlayerDest.w / 2) - SCREEN_WIDTH / 2;
	camera.y = (pPlayer->m_y + m_PlayerDest.h / 2) - SCREEN_HEIGHT / 2;
	//keep that camera innnn bounds white boy
	if (camera.x < 0)
	{
		camera.x = 0;
	}
	if (camera.y < 0)
	{
		camera.y = 0;
	}
	if (camera.x > LEVEL_WIDTH - camera.w)
	{
		camera.x = LEVEL_WIDTH - camera.w;
	}
	if (camera.y > LEVEL_HEIGHT - camera.h)
	{
		camera.y = LEVEL_HEIGHT - camera.h;
	}

	for (int i = 0; m_dests[i].w != 0; ++i)
	{
		if (collision_check(m_PlayerDest, m_dests[i]))
		{
			if (pObjects[i]->m_objectID == "Bread")
				m_bRunning = false;
		}
		
	}

	pPlayer->update();

	if (pPlayer->m_y + m_PlayerDest.h > LEVEL_HEIGHT)
	{
		pPlayer->m_x = 160;
		pPlayer->m_y = LEVEL_HEIGHT - 400;
		for (int i = 0; m_dests[i].w != NULL; ++i)
		{
			m_dests[i].x = DoubleObject[i].x = Starting_Pos[i].x;
			
			m_dests[i].y = DoubleObject[i].y = Starting_Pos[i].y;
		}
		
	}

	m_PlayerDest.x = pPlayer->m_x;
	m_PlayerDest.y = pPlayer->m_y;
	
	//m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::handleEvents()
{

	SDL_JoystickUpdate();
	pPlayer->walking = false;
	if ((SDL_JoystickGetAxis(joystick, 0) < -3200) || (SDL_JoystickGetAxis(joystick, 0) > 3200))
	{
		if (SDL_JoystickGetAxis(joystick, 0) < 0)
		{
			playerFlip = SDL_FLIP_HORIZONTAL;
		}
		else
		{
			playerFlip = SDL_FLIP_NONE;
		}
		// Player Movement Logic
		double move = (SDL_JoystickGetAxis(joystick, 0) * 0.000001) * pPlayer->m_velocity;
		pPlayer->m_x += move;
		for (int i = 0; m_dests[i].w != NULL; ++i)
		{
			DoubleObject[i].x -= move;
			m_dests[i].x = (int)DoubleObject[i].x;
		}

		if ((pPlayer->m_x < 0) || (pPlayer->m_x + m_PlayerDest.w > LEVEL_WIDTH))
		{
			// Move back if we moved out of bounds left or right
			pPlayer->m_x -= move;
			for (int i = 0; m_dests[i].w != NULL; ++i)
			{
				DoubleObject[i].x += move;
				m_dests[i].x = (int)DoubleObject[i].x;
			}
			pPlayer->Sonar.x += move;
		}
		
		if (pPlayer->m_x < 0)
		{
			pPlayer->m_x -= pPlayer->vertical_velocity;
		}
		if (pPlayer->m_y < 0)
		{
			pPlayer->m_y -= pPlayer->vertical_velocity;
		}

		pPlayer->walking = true;
	}

	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_JOYBUTTONDOWN:  /* Handle Joystick Button Presses */
			if (event.jbutton.button == 0)
			{
				/* code goes here */
				std::cout << "Button 0 ";
				if (pPlayer->b_isAirborne == false)
				{

					Mix_PlayChannel(-1, gJump, 0);
				}
				pPlayer->jump();
			}
			if (event.jbutton.button == 2)
			{
				/* code goes here */
				std::cout << "Button 2 ";
				if (pPlayer->b_quackcooldown == false)
				{
					m_QuackDest.x = pPlayer->m_x + m_PlayerDest.w / 2;
					m_QuackDest.y = pPlayer->m_y + m_PlayerDest.h / 2;
					DoubleQuack.x = m_QuackDest.x;
					DoubleQuack.y = m_QuackDest.y;

					Mix_PlayChannel(-1, gQuack, 0);
				}
				pPlayer->sonar(m_PlayerDest.x, m_PlayerDest.y);

			}
			break;
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

bool Game::collision_check(SDL_Rect A, SDL_Rect B) {
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	//Calculate the sides of rect B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	bool collide = false;

	if (bottomA <= bottomB && bottomA >= topB && leftA <= rightB && rightA >= leftB)
	{
		pPlayer->b_isAirborne = false;
		pPlayer->b_hasDJ = true;
		pPlayer->vertical_velocity = 0;
		pPlayer->m_y--;
		collide = true;

		return true;
	}
	if (topA >= topB && topA <= bottomB && leftA <= rightB && rightA >= leftB)
	{
		pPlayer->vertical_velocity = 0;
		pPlayer->m_y++;
		collide = true;
		
		return true;
	}
	if (leftA >= leftB && leftA <= rightB && topA <= bottomB && bottomA >= topB)
	{
		pPlayer->m_x++;
		collide = true;

		return true;
	}
	if (rightA <= rightB && rightA >= leftB && topA <= bottomB && bottomA >= topB)
	{
		pPlayer->m_x--;
		collide = true;
		return true;
	}
	if (pPlayer->vertical_velocity > 0.02 || pPlayer->vertical_velocity < -0.02)
	for (int i = 0; m_dests[i].w != NULL; ++i)
	{
		DoubleObject[i].y -= pPlayer->vertical_velocity / 10;
		m_dests[i].y = (int)DoubleObject[i].y;
	}
	if (collide == false)
		return false;
}

bool Game::sonar_check(Player::Circle &A, SDL_Rect &B)
{
	//Closest point on collision box
	int cX, cY;

	//Go through the B boxes
	//Find closest x offset
		if (A.x < B.x)
		{
			cX = B.x;
		}
		else if (A.x > B.x + B.w)
		{
			cX = B.x + B.w;
		}
		else
		{
			cX = A.x;
		}
		//Find closest y offset
		if (A.y < B.y)
		{
			cY = B.y;
		}
		else if (A.y > B.y + B.h)
		{
			cY = B.y + B.h;
		}
		else
		{
			cY = A.y;
		}
		//If the closest point is inside the circle
		if (distance(A.x, A.y, cX, cY) < A.r)
		{
			//This box and the circle have collided
			return true;
		}
	
	//If the shapes have not collided
	return false;
}

double Game::distance(int x1, int y1, int x2, int y2)
{
	//Return the distance between the two points
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}