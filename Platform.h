#pragma once
#ifndef PLATFORM_H 
#define PLATFORM_H
#include "GameObject.h"

class Platform : public GameObject
{

public:
	Platform(int speedChange);
	int getSpeedMult();

private:
	int m_ChangeSpeed;




};

#endif // !PLATFORM_H 
