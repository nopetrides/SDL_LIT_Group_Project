#include "Menu.h"
#include <SDL_image.h>

Menu::Menu() 
{

}

void Menu::load_menu(SDL_Renderer *Renderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
{
	SDL_Texture *temp = IMG_LoadTexture(Renderer, "assets/Splash-16by9.png");

	SDL_Rect temprect; temprect.x = 0; temprect.y = 0; temprect.w = SCREEN_WIDTH; temprect.h = SCREEN_HEIGHT;
	SDL_RenderCopy(Renderer, temp, NULL, &temprect);

	SDL_RenderPresent(Renderer);
	SDL_Delay(2000);

	temp = IMG_LoadTexture(Renderer, "assets/LightWave.png");

	SDL_RenderCopy(Renderer, temp, NULL, &temprect);

	SDL_RenderPresent(Renderer);
	SDL_Delay(2000);
}

void Menu::menu_run(SDL_Renderer *Renderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT, bool &Running) {
	//MENU GO HERE
	
	load_menu(Renderer, SCREEN_WIDTH, SCREEN_HEIGHT);


	img[0] = IMG_LoadTexture(Renderer, "assets/playbutton.png");
	img[1] = IMG_LoadTexture(Renderer, "assets/optionbutton.png");
	img[2] = IMG_LoadTexture(Renderer, "assets/quitbutton.png");
	img[3] = IMG_LoadTexture(Renderer, "assets/Level 2.png");
	/*	img5 = IMG_LoadTexture(m_pRenderer, "assets/Level 3.png");
	img6 = IMG_LoadTexture(m_pRenderer, "assets/Level 4.png");
	img7 = IMG_LoadTexture(m_pRenderer, "assets/Level 5.png");
	*/
	SDL_QueryTexture(img[0], NULL, NULL, &w, &h);
	SDL_QueryTexture(img[1], NULL, NULL, &w, &h);
	SDL_QueryTexture(img[2], NULL, NULL, &w, &h);
	SDL_QueryTexture(img[3], NULL, NULL, &w, &h);
	/*SDL_QueryTexture(img5, NULL, NULL, &w, &h);
	SDL_QueryTexture(img6, NULL, NULL, &w, &h);
	SDL_QueryTexture(img7, NULL, NULL, &w, &h);
	*/

	SDL_Rect main1; main1.x = (SCREEN_WIDTH / 2) - 90; main1.y = (SCREEN_HEIGHT / 2) - 200; main1.w = w; main1.h = h/2;
	SDL_Rect main2; main2.x = (SCREEN_WIDTH / 2) - 90; main2.y = (SCREEN_HEIGHT / 2) - 100; main2.w = w; main2.h = h/2;
	SDL_Rect main3; main3.x = (SCREEN_WIDTH / 2) - 90; main3.y = (SCREEN_HEIGHT / 2) + 0; main3.w = w; main3.h = h / 2;
	SDL_Rect texr2; texr2.x = (SCREEN_WIDTH / 2) - 290; texr2.y = (SCREEN_HEIGHT / 2) - 200; texr2.w = w; texr2.h = h/2;
	SDL_Rect texr3; texr3.x = (SCREEN_WIDTH / 2) - 0; texr3.y = (SCREEN_HEIGHT / 2) - 200; texr3.w = w; texr3.h = h/2;
	/*SDL_Rect texr4; texr4.x = (SCREEN_WIDTH / 2) - 50; texr4.y = (SCREEN_HEIGHT / 2) - 200; texr4.w = w; texr4.h = h;
	SDL_Rect texr5; texr5.x = (SCREEN_WIDTH / 2) - -100; texr5.y = (SCREEN_HEIGHT / 2) - 200; texr5.w = w; texr5.h = h;
	SDL_Rect texr6; texr6.x = (SCREEN_WIDTH / 2) - -250; texr6.y = (SCREEN_HEIGHT / 2) - 200; texr6.w = w; texr6.h = h;
	*/
	int currentlyhighlighted = 0;
	int OriginalWidth1 = main1.w;
	int OriginalWidth2 = main2.w;
	int OriginalWidth3 = main3.w;
	int OriginalWidth4 = texr3.w;
	int OriginalHeight1 = main1.h;
	int OriginalHeight2 = main2.h;
	int OriginalHeight3 = main3.h;
	int OriginalHeight4 = texr3.h;
	/*	int OriginalWidth5 = texr4.w;
	int OriginalWidth6 = texr5.w;
	int OriginalWidth7 = texr6.w;
	*/
	int MainMenu = true;
	bool LevelMenu = false;
	bool SettingsMenu = false;

	while (MainMenu) {
		if (currentlyhighlighted == 0)
		{
			main1.w = OriginalWidth1 +20;
			main1.h = OriginalHeight1 +20;
			main1.x = (SCREEN_WIDTH / 2) - 100;
			main1.y = (SCREEN_HEIGHT / 2) - 210;
			main2.w = OriginalWidth2;
			main2.h = OriginalHeight2;
			main2.x = (SCREEN_WIDTH / 2) - 90;
			main2.y = (SCREEN_HEIGHT / 2) - 100;
			main3.w = OriginalWidth3;
			main3.h = OriginalHeight3;
			main3.x = (SCREEN_WIDTH / 2) - 90;
			main3.y = (SCREEN_HEIGHT / 2) + 0;

		}
		else if (currentlyhighlighted == 1)
		{
			main2.w = OriginalWidth2 + 20;
			main2.h = OriginalHeight2 + 20;
			main2.x = (SCREEN_WIDTH / 2) - 100;
			main2.y = (SCREEN_HEIGHT / 2) - 110;
			main1.w = OriginalWidth1;
			main1.h = OriginalHeight1;
			main1.x = (SCREEN_WIDTH / 2) - 90;
			main1.y = (SCREEN_HEIGHT / 2) - 200;
			main3.w = OriginalWidth3;
			main3.h = OriginalHeight3;
			main3.x = (SCREEN_WIDTH / 2) - 90;
			main3.y = (SCREEN_HEIGHT / 2) + 0;
		}

		else if (currentlyhighlighted == 2)
		{
			main3.w = OriginalWidth3 + 20;
			main3.h = OriginalHeight3 + 20;
			main3.x = (SCREEN_WIDTH / 2) - 100;
			main3.y = (SCREEN_HEIGHT / 2) - 10;
			main1.w = OriginalWidth1;
			main1.h = OriginalHeight1;
			main1.x = (SCREEN_WIDTH / 2) - 90;
			main1.y = (SCREEN_HEIGHT / 2) - 200;
			main2.w = OriginalWidth2;
			main2.h = OriginalHeight2;
			main2.x = (SCREEN_WIDTH / 2) - 90;
			main2.y = (SCREEN_HEIGHT / 2) - 100;
		}

		// event handling
		int xDir = 0;
		int yDir = 0;

		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_JOYAXISMOTION:
				if (event.jaxis.which == 0)
				{
					if (event.jaxis.axis == 1)
					{
						if (event.jaxis.value < -8000)
						{
							xDir = -1;
							if (currentlyhighlighted > 0)
							currentlyhighlighted -=1;
						}
						else if (event.jaxis.value > 8000)
						{
							xDir = 1;
							if (currentlyhighlighted < 2)
							{
								currentlyhighlighted += 1;

							}
						}
						else
						{
							xDir = 0;
						}
						break;
					}
				}
			case SDL_JOYBUTTONDOWN:  /* Handle Joystick Button Presses */
				if (event.jbutton.button == 0)
				{
					/* code goes here */
					MainMenu = false;
					if (currentlyhighlighted == 0)
					{
						LevelMenu = true;
					}
					else if (currentlyhighlighted == 1)
					{
						LevelMenu = true; // TEMP
										  //SettingsMenu = true;
										  //UNDER CONSTRUCTION
					}
					else if (currentlyhighlighted == 2)
					{
						LevelMenu = true; // TEMP
										  //Quit = true;
										  //UNDER CONSTRUCTION
					}
				}
				if (event.jbutton.button == 2)
				{
					/* code goes here */

				}
				break;
			case SDL_QUIT:
				Running = false;
				break;
			default:
				break;
			}
		}
		// clear the screen
		SDL_RenderClear(Renderer);
		// copy the texture to the rendering context
		SDL_RenderCopy(Renderer, img[0], NULL, &main1);
		SDL_RenderCopy(Renderer, img[1], NULL, &main2);
		SDL_RenderCopy(Renderer, img[2], NULL, &main3);
		// flip the backbuffer
		// this means that everything that we prepared behind the screens is actually shown
		SDL_RenderPresent(Renderer);
	}


	while (LevelMenu)
	{
		if (currentlyhighlighted == 0)
		{
			texr2.w = OriginalWidth3 + 50;
			texr3.w = OriginalWidth4;
			/*					texr4.w = OriginalWidth5;
			texr5.w = OriginalWidth6;
			texr6.w = OriginalWidth7;
			*/
		}
		else if (currentlyhighlighted == 1)
		{
			texr3.w = OriginalWidth2 + 50;
			texr2.w = OriginalWidth3;
			/*				texr4.w = OriginalWidth5;
			texr5.w = OriginalWidth6;
			texr6.w = OriginalWidth7;
			*/
		}

		/*		else if (currentlyhighlighted == 2)
		{
		texr4.w = OriginalWidth2 + 50;
		texr3.w = OriginalWidth4;
		texr2.w = OriginalWidth3;
		texr5.w = OriginalWidth6;
		texr6.w = OriginalWidth7;
		}
		else if (currentlyhighlighted == 3)
		{
		texr5.w = OriginalWidth2 + 50;
		texr3.w = OriginalWidth4;
		texr4.w = OriginalWidth5;
		texr2.w = OriginalWidth3;
		texr6.w = OriginalWidth7;
		}
		else if (currentlyhighlighted == )
		{
		texr6.w = OriginalWidth2 + 50;
		texr3.w = OriginalWidth4;
		texr4.w = OriginalWidth5;
		texr5.w = OriginalWidth6;
		texr2.w = OriginalWidth3;
		}
		*/
		// event handling
		int xDir = 0;
		int yDir = 0;

		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_JOYAXISMOTION:
				if (event.jaxis.which == 0)
				{
					if (event.jaxis.axis == 0)
					{
						if (event.jaxis.value < -8000)
						{
							xDir = -1;
							currentlyhighlighted = 0;
						}
						else if (event.jaxis.value > 8000)
						{
							xDir = 1;
							if (currentlyhighlighted == 0)
							{
								currentlyhighlighted = 1;

							}
						}
						else
						{
							xDir = 0;
						}
						break;
					}
				}
			case SDL_JOYBUTTONDOWN:  /* Handle Joystick Button Presses */
				if (event.jbutton.button == 0)
				{
					/* code goes here */
					LevelMenu = false;
					if (currentlyhighlighted == 0)
					{
						Level = 0;
					}
					else if (currentlyhighlighted == 1)
					{
						Level = 1;
					}
				}
				break;
			case SDL_QUIT:
				Running = false;
				break;
			default:
				break;
			}
		}
		// clear the screen
		SDL_RenderClear(Renderer);
		// copy the texture to the rendering context
		SDL_RenderCopy(Renderer, img[2], NULL, &texr2);
		SDL_RenderCopy(Renderer, img[3], NULL, &texr3);
		/*				SDL_RenderCopy(m_pRenderer, img5, NULL, &main2);
		SDL_RenderCopy(m_pRenderer, img6, NULL, &texr);
		SDL_RenderCopy(m_pRenderer, img7, NULL, &texr);
		*/				// flip the backbuffer
		// this means that everything that we prepared behind the screens is actually shown
		SDL_RenderPresent(Renderer);
	}

	while (SettingsMenu)
	{
		//No settings currently
	}
}