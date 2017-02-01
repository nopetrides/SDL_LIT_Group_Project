#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "SDL.h"
#include "GameObject.h"

class Player : public GameObject
{
public:

	Player(int x, int y, int health, float speed);
	void init();
	void update(); // Checks for player input and handles Dst and Src rects.
	void jump();
	void dash();
	void grapple();
	void movement();
	int gravity = 1;

	bool isJumping = false;

	//Rect prototypes. 
	SDL_Rect m_PlayerSrc; // the first rectangle
	SDL_Rect m_PlayerDst; // another rectangle

	//Texture for surface migration
	SDL_Texture* m_pTexture; // Texture for turning transferring images to thier surfaces
protected:


};





#endif