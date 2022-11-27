
void Entite_Render(Entite *entite,Entite *player,App *app);
void Entite_Destroy(Entite *entite);
Entite Entite_Init(int x,int y,const char file[],int dx,int dy,char life,App *app);
void Entite_Move(Entite * entite);
void Entite_Ennemi(Entite *entite);
