#ifndef PLAYER_H
#define PLAYER_H

#include "BaseObject.h"

class Player : public BaseObject {

public:
	void update();
	void jump();
	void sonar(int x, int y);

	struct Circle
	{
		double x, y;
		double r;
	};
	Circle Sonar;

	bool b_isAlive = true;
	bool b_isAirborne = false;
	bool b_isFlipped = false; // Flipped direction for moving
	bool b_isIdle = true;
	bool b_hasDJ = true; // Double Jump available
	bool b_quackcooldown = false;
	bool walking = false;

	double vertical_velocity = 0;

	SDL_Texture *t_DuckHop;
	SDL_Texture *t_DuckDeath;
	SDL_Texture *t_DuckFalling;
	SDL_Texture *t_DuckIdle;
	SDL_Texture *t_DuckQuack;
	SDL_Texture *t_DuckWalk;
	SDL_Texture *t_DuckSuprised;

	SDL_Rect r_RectHop{ 0, 0, 200, 200 };
	SDL_Rect r_RectDeath{ 0, 0, 230, 300 };
	SDL_Rect r_RectFalling{ 0, 0, 200, 200 };
	SDL_Rect r_RectIdle{ 0, 0, 200, 200 };
	SDL_Rect r_RectQuack{ 0, 0, 200, 200 };
	SDL_Rect r_RectWalk{ 0, 0, 200, 200 };
	SDL_Rect r_RectSuprised{ 0, 0, 200, 200 };

};

#endif