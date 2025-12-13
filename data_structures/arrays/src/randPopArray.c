#include "headers/randPopArray.h"



void randPopArray(struct ArrayLike *array, int toPop){
	// Populate pointer to Array
	if (toPop < 0){
		toPop = 1;
	}
	int len_array = toPop;
	int numbers[len_array];
	printf("loading random numbers ");
	fflush(stdout);
	for(int a =0; a!= len_array; a++){
		numbers[a] = random_number(0, 99);
		if (len_array < 100 && len_array < 300){
			if(a % 2 == 0){
				printf(".");
				fflush(stdout);
			}
		}else{
			if(a % 6 == 0){
				printf(".");
				fflush(stdout);
			}
		}
	}
	printf("100%; complete\n"); 
	fflush(stdout);
	printf("[");
	fflush(stdout);
	for(int i =0; i!= len_array; i++){
		printf("%d", numbers[i]);
		printf(",");
		fflush(stdout);
		array->array[i] = numbers[i];
	}
	printf("]\n");
};
