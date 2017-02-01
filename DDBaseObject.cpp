#include "BaseObject.h"
#include <string>
#include <SDL_image.h>

BaseObject::BaseObject(std::string objectID, int velocity, int x, int y) :
	m_objectID(objectID),
	m_velocity(velocity),
	m_x(x),
	m_y(y)
{}

void BaseObject::spawn(std::string objectID, int velocity, int x, int y, SDL_Texture *texture) { // create an object
	this->m_objectID = objectID; // Set the objects variables to the ones passed into the spawn function during initialization
	this->m_velocity = velocity;
	this->m_x = x;
	this->m_y = y;
	this->m_ptexture = texture;
}

void BaseObject::draw(SDL_Renderer *Renderer, SDL_Rect *destinationRectangle, SDL_RendererFlip flip, int camx, int camy) {
	destinationRectangle->x -= camx;
	destinationRectangle->y -= camy;
	SDL_Point center = { destinationRectangle->w / 2, destinationRectangle->h / 2 };
	SDL_RenderCopyEx(Renderer, m_ptexture, &m_sourceRectangle, destinationRectangle, 0.0, &center, flip);
		
	
	//std::cout << "OBJECT DRAWN\n";
	//else
		//std::cout << "FAILED\n";
}

void BaseObject::update() { // virtual function
							// Nothing should go here, as the virtual function should never be called upon
}
