#include "common.h"
#include "app.h"
#include "sound.h"
#include "input.h"

#define MAX_KEYBOARD_KEYS      350

extern Key key;

void Input_Wait(App *app)
{
    SDL_WaitEvent(&app->event);
    app->key = SDL_GetKeyboardState(NULL);
}

void Input_Check(App *app)
{
    SDL_PollEvent(&app->event);
    app->key = SDL_GetKeyboardState(NULL);
}

char Input_App(App *app)
{
    if (app->event.type == SDL_QUIT)
    {
	app->exit = 0;
    } 
    else if (app->key[SDL_SCANCODE_ESCAPE] == 1)
    {
	app->exit = 0;
    }

    if (app->event.type == SDL_KEYDOWN)
    {
    	if (app->key[SDL_SCANCODE_F1] == 1)
    	{
	        App_Fullscreen(app);
    	}
    }
 
    if (app->key[SDL_SCANCODE_P] == 1)
    {
	    Music_Pause();
    }

    if (app->key[SDL_SCANCODE_O] == 1)
    {
	    Music_Resume();
    }

    return 1;
}

void Input_Entite(App app,Entite *entite)
{
    entite->xp = entite->x;
    entite->yp = entite->y;
    if (app.key[key.left] == 1)
    {
        entite->x -= PLAYER_SPEED;
    }
    else if (app.key[key.up] == 1 )
    {
        entite->y -= PLAYER_SPEED;
    }
    else if (app.key[key.right] == 1)
    {
        entite->x += PLAYER_SPEED;
    }
    else if (app.key[key.down] == 1)
    {
	entite->y += PLAYER_SPEED;
    }
    /*
    if (app.key[SDL_SCANCODE_SPACE] == 1 && entite->saut == 0)
    {
	    entite->saut=1;
    }
    */
}

char Input_Menu(App *app)
{
	
    if (app->event.type == SDL_KEYDOWN)
    {
    	if (app->key[SDL_SCANCODE_F1] == 1)
    	{
	        App_Fullscreen(app);
    	}
    }
    if (app->event.type == SDL_QUIT)
	app->exit = 0;
    if (app->key[SDL_SCANCODE_ESCAPE] == 1)
	app->exit=0;
    if (app->key[SDL_SCANCODE_SPACE] == 1)
        return 0;
    return 1;
}

//void Input_Init(char *buffer)
void Input_Init(const char file[])
{
    FILE *keyFile;
    int ch;
    int i;
    char *search;
    char buf[255];

    keyFile = fopen(file,"r");
    if (keyFile == NULL)
    {
        printf("error key data");
    }
    
    i=0;
    while((buf[i]=fgetc(keyFile))!=EOF){
        printf("%c",buf[i]);
        i++;
    }
    
    search = strchr(buf,'U');
    search=search+4;
    key.up = Input_Bind(*search);
    search = strchr(buf,'D');
    search=search+4;
    key.down = Input_Bind(*search);
    search = strchr(buf,'L');
    search=search+4;
    key.left = Input_Bind(*search);
    search = strchr(buf,'R');
    search=search+4;
    key.right = Input_Bind(*search);
}

//void Input_Check(char letter,char *buffer)
int Input_Bind(char letter)
{
    // <editor-fold defaultstate="collapsed" desc="Input">
    if (letter == 'a')
    {
        return SDL_SCANCODE_A;
    }
    else if (letter == 'b')
    {
        return SDL_SCANCODE_B;
    }
    else if (letter == 'c')
    {
        return SDL_SCANCODE_C;
    }
    else if (letter == 'd')
    {
        return SDL_SCANCODE_D;
    }
    else if (letter == 'e')
    {
        return SDL_SCANCODE_E;
    }
    else if (letter == 'f')
    {
        return SDL_SCANCODE_F;
    }
    else if (letter == 'g')
    {
        return SDL_SCANCODE_G;
    }
    else if (letter == 'h')
    {
        return SDL_SCANCODE_H;
    }
    else if (letter == 'i')
    {
        return SDL_SCANCODE_I;
    }
    else if (letter == 'j')
    {
        return SDL_SCANCODE_J;
    }
    else if (letter == 'k')
    {
        return SDL_SCANCODE_K;
    }
    else if (letter == 'l')
    {
        return SDL_SCANCODE_L;
    }
    else if (letter == 'm')
    {
        return SDL_SCANCODE_M;
    }
    else if (letter == 'n')
    {
        return SDL_SCANCODE_N;
    }
    else if (letter == 'o')
    {
        return SDL_SCANCODE_O;
    }
    else if (letter == 'p')
    {
        return SDL_SCANCODE_P;
    }
    else if (letter == 'q')
    {
        return SDL_SCANCODE_Q;
    }
    else if (letter == 'r')
    {
        return SDL_SCANCODE_R;
    }
    else if (letter == 's')
    {
        return SDL_SCANCODE_S;
    }
    else if (letter == 't')
    {
        return SDL_SCANCODE_T;
    }
    else if (letter == 'u')
    {
        return SDL_SCANCODE_U;
    }
    else if (letter == 'v')
    {
        return SDL_SCANCODE_V;
    }
    else if (letter == 'w')
    {
        return SDL_SCANCODE_W;
    }
    else if (letter == 'x')
    {
        return SDL_SCANCODE_X;
    }
    else if (letter == 'y')
    {
        return SDL_SCANCODE_Y;
    }
    else if (letter == 'z')
    {
        return SDL_SCANCODE_Z;
    }
    // </editor-fold>
}