#include "common.h"
#include "background.h"
#include "app.h"

#define SPEED_PARALLAXE 10
#define SPEED_BACKGROUND 10

Background Background_Init(int x,int y,int vitesseX,int vitesseY,char move,unsigned char opacity,const char file[],App *app)
{
	Background background;
	background.x=x;
	background.y=y;
	background.vitesseX=vitesseX;
	background.vitesseY=vitesseY;
	background.move = move;

	background.image = IMG_Load(file); 
	if (background.image == NULL)
	{
		fprintf(stderr, "error : %s",SDL_GetError());
	}
	background.texture = SDL_CreateTextureFromSurface(app->renderer, background.image);
	if (background.texture  == NULL)
	{
		fprintf(stderr, "error : %s",SDL_GetError());
	}
	SDL_SetTextureAlphaMod(background.texture,opacity); 

	return background;
}

void Background_Render(Background *background,App *app,Entite entite,Stage stage)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;
	
	srcrect.x=0;
	srcrect.y=0;
	srcrect.w=background->image->w;
	srcrect.h=background->image->h;
	if (background->move == BACKGROUND_SCREEN)
	{
		dstrect.x = background->x/SPEED_BACKGROUND;
		dstrect.y = background->y/SPEED_BACKGROUND;
		dstrect.w = SCREEN_WIDTH;
		dstrect.h = SCREEN_HEIGHT;

		SDL_RenderCopy(app->renderer, background->texture, &srcrect,&dstrect);
	
		if (background->x == 0)	
			dstrect.x=0;
		else
			dstrect.x = -(SCREEN_WIDTH-background->x/SPEED_BACKGROUND);
		if (background->y == 0)
			dstrect.y=0;
		else
			dstrect.y = -(SCREEN_HEIGHT-background->y/SPEED_BACKGROUND);
		dstrect.w = SCREEN_WIDTH;
		dstrect.h = SCREEN_HEIGHT;

		SDL_RenderCopy(app->renderer, background->texture, &srcrect,&dstrect);

 		background->x += background->vitesseX;
		if (background->x/SPEED_BACKGROUND > SCREEN_WIDTH)
		{
			background->x=0;
		}

 		background->y += background->vitesseY;
		if (background->y/SPEED_BACKGROUND > SCREEN_HEIGHT)
		{
			background->y=0;
		}
	}
	else if (background->move == BACKGROUND_STATIC)
	{
		dstrect.x = 0-entite.x;
		dstrect.y = 0-entite.y;
		dstrect.w = stage.width*TILE_SIZE;
		dstrect.h = stage.height*TILE_SIZE;

		SDL_RenderCopy(app->renderer, background->texture, &srcrect,&dstrect);
	}
	else if (background->move == BACKGROUND_PARALLAXE)
	{	

		srcrect.x = 50+entite.x/SPEED_PARALLAXE;
		srcrect.y = 50+entite.y/SPEED_PARALLAXE;
		srcrect.w = background->image->w/2+entite.x/SPEED_PARALLAXE;
		srcrect.h = background->image->h/2+entite.y/SPEED_PARALLAXE;

		dstrect.x = background->x;
		dstrect.y = background->y;
		dstrect.w = SCREEN_WIDTH;
		dstrect.h = SCREEN_HEIGHT;

		SDL_RenderCopy(app->renderer, background->texture, &srcrect,&dstrect);
	}
	else if (background->move == BACKGROUND_SCREEN_STATIC)
	{
	
		dstrect.x = background->x/SPEED_BACKGROUND-entite.x;
		dstrect.y = background->y/SPEED_BACKGROUND-entite.y;
		dstrect.w = stage.width*TILE_SIZE;
		dstrect.h = stage.height*TILE_SIZE;

		/*
		dstrect.w = SCREEN_WIDTH;
		dstrect.h = SCREEN_HEIGHT;
		*/	

		SDL_RenderCopy(app->renderer, background->texture, &srcrect,&dstrect);
		
		if (background->x == 0)	
			dstrect.x=0-entite.x;
		else
			dstrect.x = -(stage.width*TILE_SIZE-background->x/SPEED_BACKGROUND)-entite.x;
		
		if (background->y == 0)
			dstrect.y=0-entite.y;
		else
			dstrect.y = -(stage.height*TILE_SIZE-background->y/SPEED_BACKGROUND)-entite.y;

		SDL_RenderCopy(app->renderer, background->texture, &srcrect,&dstrect);
	
 		background->x += background->vitesseX;
		if (background->x/SPEED_BACKGROUND > stage.width*TILE_SIZE)
		{
			background->x=0;
		}

 		background->y += background->vitesseY;
		if (background->y/SPEED_BACKGROUND > stage.height*TILE_SIZE)
		{
			background->y=0;
		}
		
	}
}

void Background_Destroy(Background *background)
{
	SDL_FreeSurface(background->image);
	SDL_DestroyTexture(background->texture);
}

void Background_Menu(Background *background,App *app)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;
	
	srcrect.x=0;
	srcrect.y=0;
	srcrect.w=background->image->w;
	srcrect.h=background->image->h;

	dstrect.x = 0;
	dstrect.y = 0;
	dstrect.w = SCREEN_WIDTH;
	dstrect.h = SCREEN_HEIGHT;

	SDL_RenderCopy(app->renderer, background->texture, NULL,&dstrect);
}
