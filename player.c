#include "common.h"

void Player(Entite *entite)
{

}


void Player_Render(Entite *entite,App *app)
{

	SDL_Rect srcrect;
	SDL_Rect dstrect;

    srcrect.x=0;
    srcrect.y=0;
    srcrect.w = entite->image->w;
    srcrect.h = entite->image->h;

    //dstrect.x =entite->x;
    //dstrect.y =entite->y;
    dstrect.x =SCREEN_WIDTH/2;
    dstrect.y =SCREEN_HEIGHT/2;
    dstrect.w = TILE_SIZE;
    dstrect.h = TILE_SIZE;

   SDL_RenderCopy(app->renderer, entite->texture, &srcrect,&dstrect);

   #ifdef DEBUG_SHOW_XY
   printf("x=%d y=%d\n",entite->x,entite->y);
   #endif 
}
