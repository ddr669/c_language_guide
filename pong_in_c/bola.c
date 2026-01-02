#include "bola.h"

void initBola(struct Bola *bola){
	SDL_FRect *ptr = &bola->rect;
	int random;
	srand(time(NULL));
	random = rand();

	int r_d = (random%2);
	int sp_x = (random%4)+2;
	int sp_y = (random%1)+1;

	ptr->x = 800.0f/2.0f;
	ptr->y = 400.0f/2.0f;
	ptr->h = 10.0f;
	ptr->w = 10.0f;

	bola->vec.dir = 0;
	bola->vec.sy  = 0.5f;
	bola->vec.sx  = sp_x;
}
void moveBola(struct Bola *bola,
			  struct playerStruct *player1, 
			  struct playerStruct *player2)
{
	SDL_FRect *ptr9 = &bola->rect;
	float size = player1->rect.h;

	if (ptr9->y >= 475)
	{
		bola->vec.sy = -1-(bola->vec.sy)*-1;
	}
	if (ptr9->y <= 10)
	{
		bola->vec.sy = 1+(bola->vec.sy)*1;
	}

	if (bola->vec.dir == 0)
	{
		if (bola->rect.x >= 10.0f)
		{
			ptr9->x -= bola->vec.sx;
			ptr9->y += bola->vec.sy;
		}else{
			initBola(bola);
			player2->score += 1;
			bola->vec.dir = 0;
		}

		if ( ptr9->y >= player1->rect.y )
		{
			if(ptr9->y <= player1->rect.y + size)
			{
				if (ptr9->x <= player1->rect.x + player1->rect.w)
				{
					SDL_Log("tocou player1");
					bola->vec.dir = 1;	
					bola->vec.sx += 1;
					if (ptr9->y >= player1->rect.y + size/2)
					{
						bola->vec.sy += bola->vec.sy;
					}else if (ptr9->y <= player1->rect.y - size/2){
						bola->vec.sy -= bola->vec.sy;
					}
				}
			}
		}

	}else if (bola->vec.dir == 1){
		
		if (ptr9->x < 720){
			ptr9->x += bola->vec.sx;
			ptr9->y += bola->vec.sy;
		}else{
			initBola(bola);
			player1->score += 1;
			bola->vec.dir = 1;
		}

		if (ptr9->y >= player2->rect.y){
			if (ptr9->y <= player2->rect.y + size){
				if (ptr9->x >= player2->rect.x){
					SDL_Log("tocou player2");
					bola->vec.sx += 1;
					bola->vec.dir = 0;
					if (ptr9->y >= player2->rect.y + size/2){
						bola->vec.sy += bola->vec.sy;
					}else if(ptr9->y <= player2->rect.y - size/2){
						bola->vec.sy -= bola->vec.sy;
					}
				}
			}
		}	
	}
}