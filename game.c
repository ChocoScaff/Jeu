#include "common.h"
#include "app.h"
#include "entite.h"
#include "background.h"
#include "input.h"
#include "player.h"
#include "map.h"
#include "sound.h"
#include "init.h"
#include "save.h"

extern App screen;
extern Entite mario;

void Game_Level(void)
{
    Background background1;
	Background cloud;
	Background shadowCloud;
	Background light;
	Background wind;
	Stage map;

    background1 = Background_Init(0,0,0,0,BACKGROUND_SCREEN,0,"graphics/panorama/Balgres.png",&screen);
	cloud = Background_Init(0,0,5,0,BACKGROUND_SCREEN,255,"graphics/foreground/cloud.png",&screen);
	shadowCloud = Background_Init(0,0,2,2,BACKGROUND_SCREEN_STATIC,170,"graphics/foreground/shadow_cloud.png",&screen);
	light = Background_Init(0,0,2,2,BACKGROUND_SCREEN_STATIC,70,"graphics/foreground/sunlight-halo-lens-flare.png",&screen);
	wind = Background_Init(0,0,100,0,BACKGROUND_SCREEN_STATIC,255,"graphics/foreground/wind.png",&screen);

    Map_Init(&map,"graphics/sprite.png",&screen,1);
	Map_InitTab(&map);

    Music_Load("music/Hills.ogg");
	Music_Play();


    while (screen.exit)
    {
        Input_Check(&screen); //Regarde les inputs du clavier
        //Input_Wait(&screen);
        Input_App(&screen); //Input lier à la fenêtre
        Input_Entite(screen,&mario); //Input joueur

        Map_Check_Collision(&map,screen,&mario);

        //App_Background(&screen,0x6b,0x8c,0xff,255); // Couleur d'arrière plan
        App_RenderClear(&screen); //Netoie la fenêtre

        Background_Render(&background1,&screen,mario,map); //Affiche l'arrière plan

        Background_Render(&cloud,&screen,mario,map); //Affiche l'arrière plan

        Map_Load_Ground(&map,screen,&mario); //Affiche le décore
        Map_Load_Collision(&map,&screen,&mario);

        Player_Render(&mario,&screen); //Affiche le joueur

        Map_Load_Foreground(&map,screen,&mario);

        Background_Render(&shadowCloud,&screen,mario,map);
        Background_Render(&light,&screen,mario,map);
        Background_Render(&wind,&screen,mario,map);

        #ifdef 	DEBUG_SHOW_HITBOX
        Map_DrawHitbox(&mario,&screen);
        #endif

        App_RenderPresent(&screen); //Met à jours l'affichage
    }
    //Destruction structure
	Background_Destroy(&background1);
	Background_Destroy(&cloud);
	Background_Destroy(&shadowCloud);
	Background_Destroy(&light);
	Background_Destroy(&wind);
    Map_Destroy(&map);
}

void Game_Menu(void)
{
    char menu = 1;
    Background Menu,Title;
    Menu = Background_Init(0,0,0,0,BACKGROUND_STATIC,0,"graphics/panorama/Oceanv02.png",&screen);
    Title = Background_Init(0,0,0,0,BACKGROUND_STATIC,255,"graphics/title/Title.png",&screen);
    Music_Load("music/Main_Theme.ogg");
    Music_Play();

    //App_Background(&screen,0xff,0xff,0xff,255); // Couleur d'arrière plan
    App_RenderClear(&screen); 

    Background_Menu(&Menu,&screen);
    Background_Menu(&Title,&screen);
    App_RenderPresent(&screen);

    while (menu && screen.exit)
    {
        Input_Wait(&screen);
        menu = Input_Menu(&screen);
    }
    screen.etat = 0;
}
