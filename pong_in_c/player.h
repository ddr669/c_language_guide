#include <SDL3/SDL.h>
#include <stdlib.h>
#ifndef playerStruct
struct playerStruct{
	int player;			// player1 or player2 (0, 1)
	Uint64 score; 		// score
	unsigned char wasd; // last player input 
	SDL_FRect rect;     // player position on cartesian (x, y)
	int speed;
};
#endif
#ifndef event_handler
void drawPlayer(SDL_FRect*,SDL_Renderer*);
void event_handler(struct playerStruct *player);
void initPlayer(struct playerStruct *player, int who);
#endif
