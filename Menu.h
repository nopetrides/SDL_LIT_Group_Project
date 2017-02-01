#ifndef MENU_H
#define MENU_H

#include "SDL.h"

class Menu {
	public:
		Menu();
		void load_menu(SDL_Renderer *Renderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
		void menu_run(SDL_Renderer *Renderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT, bool &Running);
			//Background
		SDL_Rect m_BackgroundSrc;
		SDL_Texture* m_BackgroundTexture;
		SDL_Surface* m_BackgroundSurface;
		SDL_Texture *img[4];
		int Level = 0;
		int w, h; // texture width & height
};


#endif
