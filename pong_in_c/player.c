#include "player.h"
#include <SDL3/SDL.h>

void drawPlayer(SDL_FRect *rect, SDL_Renderer *renderer){ // that function assume that the render is on default scale 
	SDL_SetRenderDrawColorFloat(renderer, 0.9, 0.9, 0.9, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, rect);
}
void initPlayer(struct playerStruct *player, int who){
	player->player = who;
	player->score = 0;
	player->wasd = 0;	
	player->speed = 8;
	SDL_FRect *ptr;

	if (player->player == 0){
		ptr = &player->rect;
		ptr->x = 20.0f;
		ptr->y = 200.0f;
		ptr->h = 80.0f;
		ptr->w = 20.0f;
	}else{
		ptr = &player->rect;
		ptr->x = 680.0f;
		ptr->y = 200.0f;
		ptr->h = 80.0f;
		ptr->w = 20.0f;
	}
}
void event_handler(struct playerStruct *player)
{
	switch (player->wasd){
		case 1:
			if (player->rect.y > 5){
				player->rect.y -= player->speed;
			}
			break;
		
		case 4:
			if (player->rect.y < 720-320){ // what ?
				player->rect.y += player->speed;
			}
			break;
	}
}
