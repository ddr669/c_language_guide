#include <stdlib.h>
#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_main.h>
#include "bola.h"
#include "draw_circle.h"

struct playerStruct player1;
struct playerStruct player2;	

SDL_Window *window;
SDL_Renderer *renderer;

float half_size = (float) 720/2;

void drawLines();
void drawScore();

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
	SDL_SetAppMetadata("Pong with SDL3", "1.0", "/x00"); // set metadata
	if(!SDL_Init(SDL_INIT_VIDEO)) { // try to initializate VIDEO library
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError()); // if cant Show a Error and quit
		return SDL_APP_FAILURE;
	} 
	int _dump = SDL_CreateWindowAndRenderer("Pong with SDL3",720,480,0,&window, &renderer); 
	if (!_dump){ // try to initializate a window with renderer 
		SDL_Log("Couldn't Initialize window: %s",SDL_GetError());
		return SDL_APP_FAILURE;
	}
	initPlayer(&player1, 0); // init player 1 variables 
	initPlayer(&player2, 1); // init player 2 variables 
	initBola(&bola); // init bola struct, variables and Vector2 struct 

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
	if(event->type == SDL_EVENT_QUIT){
		return SDL_APP_SUCCESS;
	}
	else if(event->type == SDL_EVENT_KEY_DOWN){
		SDL_Keycode sym = event->key.key;
		if (sym == SDLK_W){
			player1.wasd |= 1;
		}
		if (sym == SDLK_S){
			player1.wasd |= 4;
		}
		if (sym == SDLK_UP){
			player2.wasd |= 1;
		}
		if (sym == SDLK_DOWN){
			player2.wasd |= 4;
		}
		
	}
	else if(event->type == SDL_EVENT_KEY_UP){
		SDL_Keycode sym = event->key.key;
		if (sym == SDLK_W){
			player1.wasd &= 30;
		}
		if (sym == SDLK_S){
			player1.wasd &= 27;
		}
		if (sym == SDLK_UP){
			player2.wasd &= 30;
		}
		if (sym == SDLK_DOWN){
			player2.wasd &= 27;
		}		
	}
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate){

	float red, green, blue; // set background color 
	red = 0.0f; // #000000 -> black
	green = 0.0f; // #FFFFFF -> white
	blue = 0.0f;	
	SDL_Delay(10);
	double now = SDL_GetTicks();
	SDL_SetRenderDrawColorFloat(renderer,1.0f,1.0f,1.0f,SDL_ALPHA_OPAQUE_FLOAT);
	SDL_RenderFillCircle(renderer, bola.rect.x, bola.rect.y, 5);

	event_handler(&player2); // verify last input from player2
	event_handler(&player1); // verify last input from player1
	drawPlayer(&player1.rect, renderer); // draw player1 in player1.rect
	drawPlayer(&player2.rect, renderer); // draw player2 in player2.rect 

	moveBola(&bola, &player1, &player2); 
	drawLines();
	drawScore();
	// Draw on screen what is on *renderer
	SDL_RenderPresent(renderer);
	// clear and paint background 
	SDL_SetRenderDrawColorFloat(renderer,red,green,blue,SDL_ALPHA_OPAQUE_FLOAT); 
	// clear what is on *render
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}
void SDL_AppQuit(void *appstate, SDL_AppResult result){
}
void drawLines(){
	/* Draw 3 lines between players */
	SDL_SetRenderDrawColorFloat(renderer,1.0f,1.0f,1.0f,SDL_ALPHA_OPAQUE_FLOAT);
	SDL_RenderLine(renderer, half_size, 0.0f, half_size, 720.0f);
	SDL_RenderLine(renderer, half_size+1, 0.0f, half_size+1, 720.0f);
	SDL_RenderLine(renderer, half_size-1, 0.0f, half_size-1, 720.0f);
}
void drawScore(){
	// set render scale to zoom the text and render into surface
	SDL_SetRenderScale(renderer, 4.0f, 4.0f); // x4 zoom na letra para ampliar e desenhar na tela
	SDL_RenderDebugTextFormat(renderer, 50.0f, 5.0f, "%" SDL_PRIu64, player1.score); // render basic text format in x: 50.0f y: 5.0f
	SDL_RenderDebugTextFormat(renderer, 120.0f, 5.0f, "%" SDL_PRIu64, player2.score); // render basic text format in x: 120.0f y: 5.0f
	SDL_SetRenderScale(renderer, 1.0f, 1.0f); // set render scale to default, so draw other objs in same scale
}
