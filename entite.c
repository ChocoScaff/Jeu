#include "common.h"

void Entite_Render(Entite *entite,Entite *player,App *app)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	if (player->x > SCREEN_MIDDLE)
	{
		srcrect.x=0;
		srcrect.y=0;
		srcrect.w = entite->image->w;
		srcrect.h = entite->image->h; 
	
		dstrect.x =entite->x-player->x+SCREEN_MIDDLE;
		dstrect.y =entite->y;
		dstrect.w = 40;
		dstrect.h = 40;
	}
	else
	{
		srcrect.x=0;
		srcrect.y=0;
		srcrect.w = entite->image->w;
		srcrect.h = entite->image->h; 
	
		dstrect.x =entite->x;
		dstrect.y =entite->y;
		dstrect.w = 40;
		dstrect.h = 40;
	}
	SDL_RenderCopy(app->renderer, entite->texture, &srcrect,&dstrect);
}

void Entite_Destroy(Entite *entite)
{
	SDL_FreeSurface(entite->image);
	SDL_DestroyTexture(entite->texture);
}

Entite Entite_Init(int x,int y,const char file[],int dx,int dy,char life,App *app)
{
	Entite entite;
	entite.x=x;
	entite.y=y;
	entite.dy=dy;
	entite.dx=dx;
	entite.life=life;
	entite.image = IMG_Load(file); 
	if (entite.image == NULL)
	{
		fprintf(stderr, "error : %s",SDL_GetError());
	}
	entite.texture = SDL_CreateTextureFromSurface(app->renderer, entite.image);
	if (entite.texture  == NULL)
	{
		fprintf(stderr, "error : %s",SDL_GetError());
	}
	return entite;
}

void Entite_Move(Entite *entite)
{
	entite->x+=entite->dx;
	entite->y+=entite->dy;
}

void Entite_Ennemi(Entite *entite)
{
	Entite_Move(entite);
	
}

void Entite_Collision(Entite *player,Entite *ennemi)
{
	SDL_Rect rect_player = {player->x,player->y,TILE_SIZE,TILE_SIZE};
	SDL_Rect rect_ennemi = {ennemi->x,ennemi->y,TILE_SIZE,TILE_SIZE};

	if (SDL_HasIntersection(&rect_player,&rect_ennemi) == SDL_TRUE)
	{
		player->life =0;
	}
}
