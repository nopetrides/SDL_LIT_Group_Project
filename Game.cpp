#include "Game.h"
#include <SDL_image.h>
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width,int height, bool fullscreen)
{
	
	
// attempt to initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK) == 0)
	{
		SDL_Init(SDL_INIT_GAMECONTROLLER);
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			if (SDL_IsGameController(i))
			{
				gameController = SDL_GameControllerOpen(i);
			}
		}

		//Music
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) // ** OPEN THE MIXER, DEFAULT VALUES 
		{
			std::cout << "Failed to make Mixer.";
		}
		gSoundFX = Mix_LoadWAV("assets/Dawn.wav"); // ** LOAD A SOUND FX / SOUND BYTE FROM FILE - CAN ONLY BE .WAV (?)
		gMusic = Mix_LoadMUS("assets/Upbeat 8 bit.wav"); // ** LOAD A MUSIC FILE, USUALLY USED FOR BGM AS IT CAN BE LOOPED LATER 
		


		std::cout << "Number of Joysticks connected: " << SDL_NumJoysticks() << std::endl;
		//Loading all sprites into their surfaces. 

		//Load Player sprite and set it to the surface
		SDL_Surface* m_PlayerSurface = IMG_Load("assets/player-animate-corrected.png");
		//SDL_Surface* m_PlayerSurface = IMG_Load("assets/red.png");
		if (m_PlayerSurface == NULL)
			std::cout << "\nUnable to Player load sprite\n";

		//Load Background sprite and set it to the surface
		SDL_Surface* m_BackgroundSurface = IMG_Load("assets/street.png");
		if (m_BackgroundSurface == NULL)
			std::cout << "\nUnable to load Background sprite\n";

		//Load Platform sprite and set it to the surface
		SDL_Surface* m_PlatformSurface = IMG_Load("assets/platform.png");
		if (m_PlatformSurface == NULL)
			std::cout << "\nUnable to load Platform sprite\n";

		//Play the sound
		//TODO:: Move theese to where we need them., 

		Mix_PlayChannel(-1, gSoundFX, 2); // ** PLAY SFX/SOUND BYTE - PUT THIS WHEREVER THE SFX WOULD BE PLAYED - the '2' means it loops 3 times total
		//SDL_Delay(2000);

		Mix_PlayMusic(gMusic, -1); // ** START BGM, the '-1' means it will loop ad inifitum
		//SDL_Delay(5000); // ** NOTE THAT DELAYS DO NOT PAUSE SOUND FX OR MUSIC, AS THEY ARE RUNNING ON A THREAD (?)
	

		
		int flags = 0;
		if(fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,width, height, flags);
		if(m_pWindow != 0) // window init success
		{
			std::cout << "window creation success about to setup textures\n";
			
			fontController->init();
			fontController->setUpFont();


		
			white = { 255,255,255 };//Create colour object with white RGB vals
			
			//Load the font.
			//Having the font loaded as really big allows for nice scaling and 'high pixel density on the font. 
			myFont = TTF_OpenFont("Assets/Times.ttf", 100);
			
			if (!(myFont))
			{
				std::cout << "Font Error: " << TTF_GetError();
			}
			textSurface = TTF_RenderText_Solid(myFont, "Text here", white);
		
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0); // Create renderer

																//Check for joysticks
			if (SDL_NumJoysticks() < 1)
			{
				printf("Warning: No joysticks connected!\n");
			}
			else
			{
				//Load joystick
				joystick = SDL_JoystickOpen(0);
				if (joystick == NULL)
				{
					printf("Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
				}

			}

			// MENU CODE
			//menu()
			Menu *Game_Menu = new Menu;

			Game_Menu->menu_run(m_pRenderer, width, height, m_bRunning );

			//Create Texture with the temp surface.
			// pTempSurface must be set to the new IMG_Load and a SDL_CreateTextureFromSurface call must be made for each image we're adding. 
			m_PlayerTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_PlayerSurface);
			m_BackgroundTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_BackgroundSurface);
			m_PlatformTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_PlatformSurface);			
			m_TimerTexture = SDL_CreateTextureFromSurface(m_pRenderer, textSurface);
			
			

			//Player Rect Defaults
			m_PlayerSrc.w=71;//Source Rect width for player 
			m_PlayerSrc.h=71;//Source Rect height for player

			//Source Rect position on PNG file to get first sprite. 
			//TODO: This should be changed to the 'idle' sprite animation, since they
			//      aren't running off the start. 
			m_PlayerSrc.x = 0;
			m_PlayerSrc.y = 0;

			//Dest width and height, equal to the source width and height
			m_PlayerDst.w = m_PlayerSrc.w;
			m_PlayerDst.h = m_PlayerSrc.h;

			//Player Starting position on start / on screen. 
			m_PlayerDst.x = 160;
			m_PlayerDst.y = 149 - m_PlayerDst.h;

			//Background Rect Defaults
			//Source
			m_BackgroundSrc.w = 200;
			m_BackgroundSrc.h = 75;
			m_BackgroundSrc.x = 0;
			m_BackgroundSrc.y = 0;

			//Destination
			m_BackgroundDst.x = 0;
			m_BackgroundDst.y= 0;
			m_BackgroundDst.w = 640;
			m_BackgroundDst.h = 480;

			
			//TODO:: Dynamically generate a vector of platforms with different positions. 
			//       Not sure how textures and surfaces are going to work with that. 
			//		 Maybe have one texture and reference it with different Src and Dst
			//		 Rects to have mutliple versions of the platform. Have different vectors
			//		 of textures for the various platform types. 
			
			//Platform 1
			//Source
			m_PlatformSrc.x = 200;
			m_PlatformSrc.y = 200; 
			m_PlatformSrc.w = 100;
			m_PlatformSrc.h = 40;
			
			
			//Destination
			m_PlatformDst.x = 150;
			m_PlatformDst.y = 150;
			m_PlatformDst.w = m_PlatformSrc.w;
			m_PlatformDst.h = m_PlatformSrc.h;

			//Timer Rect setup. 
			// Think we just need a Dst because source should be "all" or null when rendered to get the whole text. 
			m_TimerDst.x = 0;
			m_TimerDst.y = 0;
			m_TimerDst.w = 100;
			m_TimerDst.h = 75;
			





			//Free used surfaces because the texture was created and surface isn't need anymore. 
			SDL_FreeSurface(m_PlayerSurface);
			SDL_FreeSurface(m_BackgroundSurface);
			SDL_FreeSurface(m_PlatformSurface);
			SDL_FreeSurface(textSurface);

			if(m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer,0,0,0,255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	std::cout << "init success\n";
	m_bRunning = true; // everything inited successfully, start the main loop
	return true;
}
void Game::render()
{
	
	SDL_RenderClear(m_pRenderer); // Clear the renderer

	//NOTE:: Order matters here, first thing sent to the RenderCopy will be further back on the screen / viewing stack. 
	SDL_RenderCopy(m_pRenderer, m_BackgroundTexture, NULL, NULL); // Send Background to the renderer
	SDL_RenderCopy(m_pRenderer, m_PlayerTexture, &m_PlayerSrc,&m_PlayerDst); // Send Player to the renderer
	SDL_RenderCopy(m_pRenderer, m_PlatformTexture, NULL, &m_PlatformDst); // Send Player to the renderer
	SDL_RenderCopy(m_pRenderer, m_TimerTexture, NULL, &m_TimerDst);

	SDL_RenderPresent(m_pRenderer); // Render current frame
}
void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TTF_Quit();
	SDL_Quit(); // Close SDL
}

bool Game::playerOnTop(SDL_Rect player, SDL_Rect b)
{
	//Different collision types exist here. 
	//The first collision is checking if the player rect is on top of another rect.
	int bottomA = player.y + player.h;
	if (player.x >= b.x && (player.x + player.w) <= (b.x + b.w) && (b.y - bottomA) <= collisionZone && bottomA <= b.y)
	{
		//Player is on top off a platform and within the collision contact distance
		std::cout << "Player on top of other rect.\n";
		return true;
	}

	else
		return false;
}

void Game::update()
{
	
	playerOnTop(m_PlayerDst, m_PlatformDst);

	m_PlayerDst.x = p_Player->GetX();
	m_PlayerDst.y = p_Player->GetY();
	p_Player->update();


	// TODO: Have a vector / list of platforms and check the player against all of them. 
	//       Consider ways to optimize. IE not on this level, dont check, too far away dont check. 
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
		if (event.type == SDL_CONTROLLERBUTTONDOWN)
		{
			if (event.cbutton.button == SDL_CONTROLLER_BUTTON_A)
			{
					p_Player->jump(); //TO DO m_Playerdst not connected to m_Y in anyway
			}
		}
		if (event.type == SDL_CONTROLLERAXISMOTION)
		{
			if (event.caxis.which == 0) //Check for which controller the axis motion came from
			{
				if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX) // Checks to see if axis is moved on the x axis
				{
					if (event.caxis.value < -4000) //left of deadzone
					{
						m_Left = true;
					}
					else if (event.caxis.value > 4000)
					{
						m_Right = true;
					}
					else
					{
						m_Left = false;
						m_Right = false;
					}
				}
			}
		}

		if (m_Right == true)
		{
			p_Player->increaseX(p_Player->GetSpeed());
			m_PlayerSrc.x = 71 * int(((SDL_GetTicks() / 50) % 7));
		}

		if (m_Left == true)
		{
			p_Player->increaseX(p_Player->GetSpeed()*-1);
		}
	}
