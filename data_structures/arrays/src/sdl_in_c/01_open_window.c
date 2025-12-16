#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

/* -------------- */
SDL_AppResult SDL_AppInit(void **appstate,
	int argc,
	char *argv[]){
	SDL_SetAppMetadata("GUI to virtualizate a array sort", "1.0", "/x00");
	if(!SDL_Init(SDL_INIT_VIDEO)){
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	} 
	if(!SDL_CreateWindowAndRenderer("Array/data_structure",720,480, 0,&window, &renderer)){
		SDL_Log("Couldn't Initialize window: %s",SDL_GetError());
		return SDL_APP_FAILURE;
	}
	return SDL_APP_CONTINUE;
}
/* ----------- */
SDL_AppResult SDL_AppEvent(void *appstate,SDL_Event *event){
	if(event->type == SDL_EVENT_QUIT){
		return SDL_APP_SUCCESS;
	}
	switch(event->type){
		//case SDL_KEYDOWN:
		//	printf("%c %d", event->key, event->key);
	}
		
	return SDL_APP_CONTINUE;
}
/* ----------- */
SDL_AppResult SDL_AppIterate(void *appstate){
	SDL_Delay(1000/60);
	const double now = ((double)SDL_GetTicks()) / 1000.0;
	
	float red, green, blue;
	red = 0.25;green = 0.25;blue = 0.25;

	SDL_SetRenderDrawColorFloat(renderer,
			red,
			green,
			blue,
			SDL_ALPHA_OPAQUE_FLOAT);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result){
}



