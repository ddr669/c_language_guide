#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define __SIZE 1020

struct Array2D{
	int (*array)[__SIZE+4][__SIZE+4];
};

int populateArray(int *ptr_y, int *ptr_x, struct Array2D *array){
	int *pointer = array->array[*ptr_x][*ptr_y];
	for(int xy = 1; xy != __SIZE*__SIZE; xy++){
		pointer = array->array[*ptr_x][*ptr_y];
		if (*ptr_x >= __SIZE-5){
			*ptr_y = *ptr_y + 1;
			*ptr_x = 0;
		}
		*pointer = xy;
		
		//printf("%d %d %d\n",
		//	*ptr_x,
		//	array->array[*ptr_x][*ptr_y],
		//	*ptr_y);
		*ptr_x = *ptr_x + 1;
	}
	return 0;
}


int main(int argc, char *argv[]){

	struct Array2D array;
	struct Array2D *ptr_array = (struct Array2D*) &array;
	int populateArray(int *ptr_y, int *ptr_x, struct Array2D *array);
	int x, y;
	x = 0;
	y = 0;
	int *ptr_y = &y;
	int *ptr_x = &x;

	float start = (float) time(NULL);
	float st_df = (float) clock();
	populateArray(ptr_y, ptr_x, &array);
	

	float now = (float) time(NULL);
	printf("tempo de exec: %fms\n\n", now-start);
	now = (float) clock();
	printf("tempo em clocks: %fms\n\n", now-st_df);
	getchar();


	return 0;
}
