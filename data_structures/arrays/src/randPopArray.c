#include "headers/randPopArray.h"


void randPopArray(struct ArrayLike *array, int toPop, int rangeTarget){
	// Populate pointer to Array with random numbers
	if (toPop < 0){
		toPop = 1;
	}
	int len_array = toPop;
	int *numbers = (int *) calloc(len_array, sizeof(int));
	// Create a pointer to a memory andress with array size
	printf("loading random numbers ");
	fflush(stdout);

	for(int a =0; a!= len_array; a++){
	// Iterate through array size populate pointer
		numbers[a] = random_number(0, rangeTarget);
	// Draw a load bar with dots
		if (len_array < 100 && len_array < 300){
			if(a % 2 == 0){printf(".");fflush(stdout);}
		}else{
			if(a % 6 == 0){printf(".");fflush(stdout);}
		}
	}
	printf("100%; complete\n"); 
	fflush(stdout);
	// Show the random array
	printf("[");
	fflush(stdout);
	for(int i =0; i!= len_array; i++){
		printf("%d", numbers[i]);
		printf(",");
		fflush(stdout);
		// put these values into the array pointer
		array->array[i] = numbers[i];
	}
	printf("]\n");
	// clear memory
	free(numbers);
};
