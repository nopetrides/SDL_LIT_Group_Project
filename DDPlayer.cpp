#include "Player.h"
#include <SDL_image.h>

void Player::update() {
	// Animation Logic
	//if (b_isAirborne)
	
	vertical_velocity += 0.00002;
	m_y += vertical_velocity;

	if (vertical_velocity > 0 && b_isAlive == true) {
		if (b_isAirborne)
		{
			m_ptexture = t_DuckFalling;
			m_sourceRectangle = r_RectFalling;
			m_sourceRectangle.x = 240 * int(((SDL_GetTicks() / 200) % 2));
			
		}
		else if (walking == false)
		{
			m_ptexture = t_DuckIdle;
			m_sourceRectangle = r_RectIdle;
			m_sourceRectangle.x = 232 * int(((SDL_GetTicks() / 300) % 4));			
		}
		else if (walking)
		{
			m_ptexture = t_DuckWalk;
			m_sourceRectangle = r_RectWalk;
			m_sourceRectangle.x = 240 * int(((SDL_GetTicks() / 150) % 4));
		}
		
	}
	else if (b_isAlive == false)
	{
		m_ptexture = t_DuckDeath;
		m_sourceRectangle = r_RectWalk;
		m_sourceRectangle.x = 240 * int(((SDL_GetTicks() / 200) % 4));
	}
	else 
	{
		m_ptexture = t_DuckHop;
		m_sourceRectangle = r_RectHop;
		m_sourceRectangle.x = 240 * int(((SDL_GetTicks() / 200) % 6));
	}
}

void Player::jump() {
	// Jump Logic
	if (b_isAirborne == false)
	{
		//JUMP!
		vertical_velocity = -0.07;
		b_isAirborne = true;
	}
	else if (b_hasDJ == true)
	{
		//DO A DOUBLE JUMP!
		vertical_velocity = -0.05;
		b_hasDJ = false;
	}
}

void Player::sonar(int x, int y) {
	// Sonar Logic
	if (b_quackcooldown == false)
	{
		b_quackcooldown = true;
		Sonar.r = 1;
		Sonar.x = x;
		Sonar.y = y;
	}
}