#ifndef __Game__
#define __Game__
#include "Menu.h"
#include "Player.h"
#include "Platform.h"
#include "SDL_mixer.h"
#include "TTF_Controller.h"

class Game
{
private:
	//Player
	SDL_Rect m_PlayerSrc; // the first rectangle
	SDL_Rect m_PlayerDst; // another rectangle
	SDL_Texture* m_PlayerTexture; // Texture for turning transferring images to their surfaces
	SDL_Surface* m_PlayerSurface;

	//Background
	SDL_Rect m_BackgroundSrc;
	SDL_Rect m_BackgroundDst;
	SDL_Texture* m_BackgroundTexture;
	SDL_Surface* m_BackgroundSurface;
	
	//Platform
	SDL_Rect m_PlatformSrc;
	SDL_Rect m_PlatformDst;
	SDL_Texture* m_PlatformTexture;
	SDL_Surface* m_PlatformSurface;

	//Controller Obj
	SDL_GameController* gameController = nullptr;

	SDL_Joystick *joystick;

	//Font
	SDL_Surface *textSurface;
	TTF_Font *myFont; //Create pointer to Font object
	SDL_Color white;

	

	SDL_Window* m_pWindow; //Window to Render to
	SDL_Renderer* m_pRenderer; // Renderer

	//Music 
	// MUSIC VARIABLES
	Mix_Chunk *gSoundFX; // SOUND BYTE
	Mix_Music *gMusic; // BACKGROUND MUSIC
	

	bool m_bRunning;
	bool m_Right = false;
	bool m_Left = false;

public:
	
	
	Player* p_Player = new Player(0, 200, 100, 1);
	Platform* p_Plat1 = new Platform(1);

	TTF_Controller* fontController = new TTF_Controller();
	SDL_Rect m_TimerSrc;
	SDL_Rect m_TimerDst;
	SDL_Texture* m_TimerTexture;

	float collisionZone = 5.0f; // Used to check if the player is within a certain distance from a platform. 
	// simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width,int height, bool fullscreen);
	bool playerOnTop(SDL_Rect player, SDL_Rect b);
	void render();
	void update();
	void handleEvents();
	void clean();

	const int SCREEN_WIDTH = 9;
	const int SCREEN_HEIGHT = 10;

	// a function to access the private running variable
	bool running() { return m_bRunning; }


};
#endif /* defined(__Game__) */

