#include "showTime.h"


void showTime(struct ArrayLike *array, int length, int low)
{
	
	for(int i=low; i!= length; i++){
		for(int a=0;a!= 2; a++){
			printf("%d", a);
			fflush(stdout);
			//sleep_ms(1);
			printf("\b \b");
			sleep_ms(1);	
			fflush(stdout);	
		}
		printf("%d ", array->array[i]);
	}
	printf("\n");
}