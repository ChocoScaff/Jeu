#include "common.h"
#include "map.h"
#include "map/mapTab.h"

void Map_Init(Stage *stage,const char file[],App *app,char mapNumber)
{

	stage->image = IMG_Load(file);
	if (stage->image == NULL)
	{
		fprintf(stderr, "error : %s",SDL_GetError());
	}
	stage->texture = SDL_CreateTextureFromSurface(app->renderer, stage->image);
	if (stage->texture  == NULL)
	{
		fprintf(stderr, "error : %s",SDL_GetError());
	}
	stage->number=mapNumber;
}

void Map_Load_Ground(Stage *stage,App app,Entite *entite)
{
	/*
	for (stage->y = 0 ; stage->y < stage->height; stage->y++)
	{
		for (stage->x = 0; stage->x < stage->width; stage->x++)
		{
			if (stage->map_ground[stage->y][stage->x] != 0)
			{
				Map_Draw(&app,stage,entite,stage->map_ground[stage->y][stage->x]);
			}
		}
	}
	*/
	for (stage->y = entite->y/TILE_SIZE; stage->y < SCREEN_HEIGHT/TILE_SIZE+entite->y/TILE_SIZE+1; stage->y++)
	{
		for (stage->x = entite->x/TILE_SIZE; stage->x < SCREEN_WIDTH/TILE_SIZE+entite->x/TILE_SIZE; stage->x++)
		{
			if(stage->y > -1 && stage->y < stage->height && stage->x > -1 && stage->x < stage->width)
			{
				if (stage->map_ground[stage->y][stage->x] != 0)
				{
					Map_Draw(&app,stage,entite,stage->map_ground[stage->y][stage->x]);
				}
			}
		}
	}
		
}

void Map_Load_Collision(Stage *stage,App *app,Entite *entite)
{

	#ifdef DEBUG_SHOW_HITBOX
		SDL_Rect rect_stage;
	#endif

	for (stage->y = entite->y/TILE_SIZE ; stage->y < SCREEN_HEIGHT/TILE_SIZE+entite->y/TILE_SIZE+1; stage->y++)
	{
		for (stage->x = entite->x/TILE_SIZE; stage->x < SCREEN_WIDTH/TILE_SIZE+entite->x/TILE_SIZE; stage->x++)
		{
			if(stage->y > -1 && stage->y < stage->height && stage->x > -1 && stage->x < stage->width)
			{
				if (stage->map_collision[stage->y][stage->x] != 0)
				{

					Map_Draw(app,stage,entite,stage->map_collision[stage->y][stage->x]);

					#ifdef DEBUG_SHOW_HITBOX
						rect_stage.x = stage->x*TILE_SIZE-entite->x; rect_stage.y = stage->y*TILE_SIZE-entite->y; rect_stage.w = TILE_SIZE; rect_stage.h = TILE_SIZE;	
						SDL_RenderDrawRect(app->renderer,&rect_stage);
					#endif
				}
			}
		}
	}
}

void Map_Check_Collision(Stage *stage,App app,Entite *entite)
{

	for (stage->y = entite->y/TILE_SIZE ; stage->y < SCREEN_HEIGHT/TILE_SIZE+entite->y/TILE_SIZE+1; stage->y++)
	{
		for (stage->x = entite->x/TILE_SIZE; stage->x < SCREEN_WIDTH/TILE_SIZE+entite->x/TILE_SIZE; stage->x++)
		{
			if(stage->y > -1 && stage->y < stage->height && stage->x > -1 && stage->x < stage->width)
			{
				if (stage->map_collision[stage->y][stage->x] != 0)
				{
					Map_Collision(entite,stage,&app);
				}
			}
		}
	}
}

void Map_Load_Foreground(Stage *stage,App app,Entite *entite)
{

	for (stage->y = entite->y/TILE_SIZE ; stage->y < SCREEN_HEIGHT/TILE_SIZE+entite->y/TILE_SIZE+1; stage->y++)
	{
		for (stage->x = entite->x/TILE_SIZE; stage->x < SCREEN_WIDTH/TILE_SIZE+entite->x/TILE_SIZE; stage->x++)
		{
			if (stage->map_foreground[stage->y][stage->x] != 0)
			{
				Map_Draw(&app,stage,entite,stage->map_foreground[stage->y][stage->x]);
			}
		}
	}
}

void Map_Draw(App *app,Stage *stage,Entite *entite,int tile)
{

	SDL_Rect srcrect;
	SDL_Rect dstrect;

    srcrect.x=(TILE_FILE_SIZE*tile-TILE_FILE_SIZE) - (TILE_FILE_SIZE*21*(tile/21)) ;
    srcrect.y=TILE_FILE_SIZE*(tile/21);
    srcrect.w = TILE_FILE_SIZE;
    srcrect.h = TILE_FILE_SIZE;

    dstrect.x = stage->x*TILE_SIZE-entite->x;
    dstrect.y = stage->y*TILE_SIZE-entite->y;
    dstrect.w = TILE_SIZE;
    dstrect.h = TILE_SIZE;


	SDL_RenderCopy(app->renderer, stage->texture, &srcrect,&dstrect);
}

void Map_Destroy(Stage *stage)
{
	SDL_FreeSurface(stage->image);
	SDL_DestroyTexture(stage->texture);
}

char Map_Collision(Entite *entite,Stage *stage,App *app)
{
	//static int compt=0;
	SDL_Rect rect_entite = {SCREEN_WIDTH/2,SCREEN_HEIGHT/2,TILE_SIZE,TILE_SIZE};
	SDL_Rect rect_stage = {stage->x*TILE_SIZE-entite->x,stage->y*TILE_SIZE-entite->y,TILE_SIZE,TILE_SIZE};

	if (SDL_HasIntersection(&rect_entite,&rect_stage) == SDL_TRUE)
	{
	//	printf("collision %d\n",compt);
	//	compt++;
		entite->y = entite->yp;
		entite->x = entite->xp;
	}
}
#if defined DEBUG_SHOW_HITBOX
void Map_DrawHitbox(Entite *entite,App *app)
{

	SDL_SetRenderDrawColor(app->renderer,255,0,0,255);
	SDL_Rect rect_entite = {SCREEN_WIDTH/2,SCREEN_HEIGHT/2,TILE_SIZE,TILE_SIZE};

	SDL_RenderDrawRect(app->renderer,&rect_entite);
}
#endif

void Map_InitTab(Stage *stage)
{
	
	
	if (stage->number == 1)
		Map1_Init(stage);
	
	/*
	int x, y;
	static char *data,*p;

	data = readFile("map1.dat");
	if (data == NULL)
	{
		printf("Error Data\n");
	}
	p = data;
	for (y = 0 ; y < 20 ; y++)
	{
		for (x = 0 ; x < 20 ; x++)
		{
			sscanf(p, "%d", &stage->map_ground[x][y]);

			do {p++;} while (*p != ' ' && *p != '\n');
		}
	}
	free(data);
	*/
}

void Map_Change(Stage *stage,int number)
{
	stage->number=number;
	Map_InitTab(stage);
}

char *readFile(const char *filename)
{
	char *buffer = 0;
	unsigned long length;
	FILE *file = fopen(filename, "rb");

	if (file)
	{
		fseek(file, 0, SEEK_END);
		length = ftell(file);
		fseek(file, 0, SEEK_SET);

		buffer = malloc(length + 1);
		memset(buffer, 0, length + 1);
		fread(buffer, 1, length, file);

		fclose(file);
		
		buffer[length] = '\0';
	}
	return buffer;
}

