#include "showTime.h"



void showTime(struct ArrayLike *array, int length, int low)
{
	int timeScale = 4;

	for(int i=low; i!= length; i++){
		for(int a=0;a!= 2; a++){
			printf("%d", a);
			fflush(stdout);
			printf("\b \b");

			sleep_ms(TIMESTOP / timeScale);	
			fflush(stdout);	
		}
		printf("%d ", array->array[i]);
	}
	printf("\n");
}
