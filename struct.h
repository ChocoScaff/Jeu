#include <SDL2/SDL.h>
#include "defs.h"

typedef struct 
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	const Uint8 *key;
	int etat;
	char exit;
}App;


typedef struct 
{
	int x;
	int y;
	int xp;
	int yp;
	int dx;
	int dy;
	char life;
	SDL_Texture *texture;
	SDL_Surface* image;
}Entite;

typedef struct 
{
	int x;
	int y;
	int vitesseX;
	int vitesseY;
	char move;
	SDL_Texture *texture;
	SDL_Surface* image;
}Background;


typedef struct 
{
	int map_ground[200][200];
	int map_collision[200][200];
	int map_foreground[200][200];
	int x,y;
	int number;
	int height,width;
	SDL_Texture *texture;
	SDL_Surface *image;
}Stage;

typedef struct 
{
	int x,y;
	SDL_Texture *texture;
	SDL_Surface *image;
}Text;

typedef struct 
{
	int up;
	int down;
	int left;
	int right;
}Key;

enum letter
{
	a,
	b,
	c,
	d,
	e,
	f,
	g,
	h,
	i,
	j,
	k,
	l,
	m,
	n,
	o,
	p,
	q,
	r,
	s,
	t,
	u,
	v,
	w,
	x,
	y,
	z,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
};