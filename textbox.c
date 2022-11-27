#include "common.h"

#define TEXT_WIDTH 8
#define TEXT_HEIGHT 8

Text Textbox_Init(const char file[],App *app)
{
    Text text;
    text.image = IMG_Load(file); 
	if (text.image == NULL)
	{
		fprintf(stderr, "error : %s",SDL_GetError());
	}
	text.texture = SDL_CreateTextureFromSurface(app->renderer, text.image);
	if (text.texture  == NULL)
	{
		fprintf(stderr, "error : %s",SDL_GetError());
	}
	//SDL_SetTextureAlphaMod(background.texture,opacity); 
	return text;
}

void Textbox_Render(Text text,char *buffer,int x,int y,App *app)
{
    int i;
    int letterX,letterY;
    SDL_Rect srcrect,dstrect;
    for (i=0; buffer[i] == '\0'; i++)
    {
        if (buffer[i] == 'a')
        {
            letterX = TEXT_WIDTH *1;
            letterY = TEXT_HEIGHT *4;
        }

    }
    free(buffer);

    srcrect.x = letterX;
    srcrect.y = letterY;
    srcrect.w = TEXT_WIDTH;
    srcrect.h = TEXT_HEIGHT;

    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = TEXT_WIDTH;
    dstrect.h = TEXT_HEIGHT;
    
    SDL_RenderCopy(app->renderer, text.texture, &srcrect,&dstrect);
}