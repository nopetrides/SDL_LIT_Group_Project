#include "Player.h"
#include <SDL_image.h>
#include <iostream>
#include "Game.h"



Player::Player(int x, int y, int health, float speed)
{
	m_X = x;
	m_Y = y;
	m_Health = health;
	m_Speed = speed;
	m_TypeID = "Player";

}

void Player::init()
{



}

void Player::update()
{
	
	m_Y += gravity;
	if (m_Y > 200)
	{
		m_Y = 200;
	}


}

void Player::jump()
{
	m_Y -= 100;
}
