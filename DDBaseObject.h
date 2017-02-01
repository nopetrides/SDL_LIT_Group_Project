#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include "SDL.h"
#include <iostream> // cin/cout library, anything that derives from GameObject will include this as well


class BaseObject {
public:
	BaseObject(std::string objectID = "", int velocity = 0, int x = 0, int y = 0); // Default constructor with default arguments
	void spawn(std::string objectID, int velocity, int x, int y, SDL_Texture *ptexture); // create an object
	void draw(SDL_Renderer *Renderer, SDL_Rect *destinationRectangle, SDL_RendererFlip flip, int camx, int camy); // print to the screen the typeID and its x and y coords
	virtual void update(); //virtual function
	std::string m_objectID; // String that defines the object, used for telling objects apart
	int m_velocity; // value between 1 and 4
	double m_x; // Value between 1 and 23
	double m_y; // Value between 1 and 23
	bool rev_x = false; // Used to determine if the object hits a perimeter in the x axis
	bool rev_y = false; // Used to determine if the object hits a perimeter in the y axis
	SDL_Texture *m_ptexture;
	SDL_Rect m_sourceRectangle; // the source rectangle of the sprite
};

#endif