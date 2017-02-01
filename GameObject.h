#pragma once
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "SDL.h"
#include <string>

class GameObject
{
public:
	GameObject(std::string typeID = "Base Game Object");
	virtual void update();

	int GetX();
	int GetY();
	int GetSpeed();
	int GetHealth();
	void increaseX(int arg);
	void increaseY(int arg);

protected:
	int m_X;
	int m_Y;
	std::string m_TypeID;
	int m_Health;
	float m_Speed;
};





#endif