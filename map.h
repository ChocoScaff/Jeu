
void Map_Init(Stage *stage,const char file[],App *app,char mapNumber);
void Map_Draw(App *app,Stage *stage,Entite *entite,int tile);
void Map_Load_Ground(Stage *stage,App app,Entite *entite);
void Map_Load_Collision(Stage *stage,App *app,Entite *entite);
void Map_Load_Foreground(Stage *stage,App app,Entite *entite);
void Map_Destroy(Stage *stage);
char Map_Collision(Entite *entite,Stage *stage,App *app);
void Map_Check_Collision(Stage *stage,App app,Entite *entite);
#if defined DEBUG_SHOW_HITBOX
void Map_DrawHitbox(Entite *entite,App *app);
#endif
void Map_InitTab(Stage *stage);
void Map_Change(Stage *stage,int number);
//void Map1_Init(Stage *stage);
char *readFile(const char *filename);
