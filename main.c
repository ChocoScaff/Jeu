#include "main.h"

void TickRate(void);

enum Etat
{
    LEVEL,
    MENU,
};

int main(int argc,char *argv[])
{
    #ifdef DEBUG_SHOW_COMMAND
	printf("ZQSD move \nF1 fullscreen \nP O resume stop music\n");
	#endif

	//Initalisation des structures
	screen = App_Init();
	Init_Image_Sound();
	mario = Entite_Init(0,0,"graphics/player.png",0,0,1,&screen);
	Input_Init("key.dat");
	screen.etat = MENU;
	while(screen.exit) 
	{
		switch(screen.etat)
		{
			case MENU:
				Game_Menu();
				break;
			case LEVEL:
				Game_Level();
				break;
		}
		
		TickRate();

	}

	Entite_Destroy(&mario);
	Quit_App_Image_Sound(&screen);

	return 0;
}


void TickRate(void)
{
	static int currentTime,lastTime=0;
	currentTime = SDL_GetTicks();
	while(currentTime < (lastTime + TICK))
	{
		currentTime = SDL_GetTicks();
		SDL_Delay(1);
	}

	lastTime = currentTime;
}
