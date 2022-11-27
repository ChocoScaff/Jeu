#include "common.h"
#include "app.h"

void Init_Image_Sound(void)
{	
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	Sound_Init();
}

void Quit_App_Image_Sound(App *app)
{
	IMG_Quit();
	Sound_Quit();
	App_Destroy(app);
	SDL_Quit();
}
