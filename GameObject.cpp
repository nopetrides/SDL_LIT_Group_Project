#include "GameObject.h"



GameObject::GameObject(std::string typeID)
{
	m_TypeID = typeID;
}

void GameObject::update()
{
}

int GameObject::GetX()
{
	return m_X; // Return the X position
}

int GameObject::GetY()
{
	return m_Y; // Return the Y position
}

int GameObject::GetSpeed()
{
	return m_Speed; // Return Player Speed
}

int GameObject::GetHealth()
{
	return m_Health;// Return player Health. 
}

void GameObject::increaseX(int arg)
{
	m_X += arg;
}

void GameObject::increaseY(int arg)
{
	m_Y += arg;
}
