
//TODO faire un enum
#define BACKGROUND_STATIC 0
#define BACKGROUND_SCREEN 1
#define BACKGROUND_PARALLAXE 2
#define BACKGROUND_SCREEN_STATIC 3

//Warning if transparancy opacity = 255 else 0
Background Background_Init(int x,int y,int vitesseX,int vitesseY,char move,unsigned char opacity,const char file[],App *app);
void Background_Render(Background *background,App *app,Entite entite,Stage stage);
void Background_Destroy(Background *background);
void Background_Menu(Background *background,App *app);

