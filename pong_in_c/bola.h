#include <SDL3/SDL.h>
#include <time.h>
#include "player.h"
#ifndef Bola
struct Vector2 {
	int sx, sy;
	int dir;
};
struct Bola {
	struct Vector2 vec;
	SDL_FRect rect;
};
struct Bola bola;
void initBola(struct Bola *bola);
void moveBola(struct Bola *bola, struct playerStruct *player1, struct playerStruct *player2);
#endif