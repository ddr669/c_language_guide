#include "showTime.h"

#define TIMESTOP 0.2

void showTime(struct ArrayLike *array, int length, int low)
{
	
	for(int i=low; i!= length; i++){
		for(int a=0;a!= 2; a++){
			printf("%d", a);
			fflush(stdout);
			printf("\b \b");
			sleep_ms(TIMESTOP);	
			fflush(stdout);	
		}
		printf("%d ", array->array[i]);
	}
	printf("\n");
}
