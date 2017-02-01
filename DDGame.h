#ifndef __Game__
#define __Game__
#include "SDL.h"
#include "Player.h"
#include "Obstacle.h"
#include <vector>
#include "SDL_mixer.h"

class Game
{
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pPlayerTexture; // the new SDL_Texture variable
	SDL_Texture* m_pQuackTexture;
	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; // another rectangle
	SDL_Rect m_PlayerDest;
	SDL_Rect m_QuackDest;

	bool m_bRunning;		

public:
	Game() {}
	~Game() {}

	// simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width,int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	bool collision_check(SDL_Rect A, SDL_Rect B);
	bool sonar_check(Player::Circle &A, SDL_Rect &B);
	double distance(int x1, int y1, int x2, int y2);
	int Level = 0;
	//bool b_quackcollide = false;

	void image_load();
	void spawner();
	void destination();
	void render_check();

	void image_load_Level_1();
	void image_load_Level_2();
	void image_load_Level_3();
	void image_load_Level_4();
	void image_load_Level_5();

	void spawner_level_1();
	void spawner_level_2 ();
	void spawner_level_3();
	void spawner_level_4();
	void spawner_level_5();

	void destination_level_1();
	void destination_level_2();
	void destination_level_3();
	void destination_level_4();
	void destination_level_5();
	//void cameraRender(SDL_Rect *destRect, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip);


	struct DoubleRect {
		double x;
		double y;
		double w;
		double h;
	};

	DoubleRect DoubleQuack;

	// a function to access the private running variable
	bool running() { return m_bRunning; }
	Obstacle *pQuack = new Obstacle;
	DoubleRect DoubleObject[128];
	DoubleRect Starting_Pos[128];
	Obstacle *pObjects[128];
	SDL_Texture* m_Textures[128];
	SDL_Rect m_dests[128];
	Player *pPlayer = new Player;
	SDL_Joystick *joystick;
	Mix_Chunk *gQuack;
	Mix_Chunk *gJump;
	Mix_Music *gMusic;
	SDL_Rect camera;
	SDL_RendererFlip playerFlip;
};
#endif /* defined(__Game__) */

