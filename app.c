#include "common.h"

App App_Init(void)
{
	App app;
	SDL_Init(SDL_INIT_EVERYTHING);
	app.window = SDL_CreateWindow("RPG",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,
												#if defined(WINDOW_BORDERLESS)
												SDL_WINDOW_BORDERLESS
												#else
												SDL_WINDOW_FULLSCREEN
												#endif
												);
	if (app.window == NULL)
	{
		fprintf(stderr, "error : %s",SDL_GetError());
		return ;
	}
	app.renderer = SDL_CreateRenderer(app.window,-1,SDL_RENDERER_ACCELERATED
			#ifdef V_SYNC
			| SDL_RENDERER_PRESENTVSYNC
			#endif
			);

	if (app.renderer == NULL)
	{
		fprintf(stderr, "error : %s",SDL_GetError());
		return ;
	}

    #ifdef DEBUG_SHOW_SYSTEM
	App_ShowSystem();
    #endif
	
	app.exit = 1;

	return app;
}

void App_Background(App *app,unsigned char R,unsigned char G,unsigned char B,unsigned char O)
{
	SDL_SetRenderDrawColor(app->renderer,R,G,B,O);
	//SDL_RenderClear(app->renderer);
}
void App_RenderPresent(App *app)
{
	SDL_RenderPresent(app->renderer);
}
void App_RenderClear(App *app)
{
	SDL_RenderClear(app->renderer);
}

void App_Destroy(App *app)
{
	SDL_DestroyRenderer(app->renderer);
	SDL_DestroyWindow(app->window);
}

void App_Fullscreen(App *app)
{
	static char fullscreen = 'b';
	if (fullscreen == 'b')
	{
		SDL_SetWindowFullscreen(app->window,SDL_WINDOW_FULLSCREEN);
		fullscreen = 'f';
	}

	else
	{
		SDL_SetWindowFullscreen(app->window,SDL_WINDOW_BORDERLESS);
		fullscreen = 'b';
	}
	if (app->window == NULL)
	{
		fprintf(stderr, "error : %s",SDL_GetError());
	}
}

#ifdef DEBUG_SHOW_SYSTEM
void App_ShowSystem(void)
{
    printf("OS %s\n",SDL_GetPlatform());
    SDL_Log("Number of logical CPU cores: %d\n", SDL_GetCPUCount());
    printf("RAM %d MO\n",SDL_GetSystemRAM());
}
#endif // DEBUG_SHOW_SYSTEM
