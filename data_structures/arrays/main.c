#include <stdio.h>
#include <time.h>

#include "src/headers/binary_search.h"
#include "src/headers/showTime.h"
#include "src/headers/random_number.h"
#include "src/headers/array_struct.h"
#include "src/headers/cocktail.h"
#include "src/headers/sortArray.h"
#include "src/headers/randPopArray.h"

int main(int args, char **argv[]){
	
	int inputArraySize = 25;
	int arraysize = inputArraySize;

	srand(time(NULL));
	randPopArray(&array, arraysize);
	struct ArrayLike copy = array; 

	//	sort to make a BinarySearch
	sortArray(&array, arraysize);
	
	printf("<Press Enter to continue to Cocktail_Sort>");
	fflush(stdout);
	getchar();
	printf("\n");
	printf("BinarySearch->\n");

	int some_number = 25;
	int resultado = binarySearch(&array, some_number, 0, arraysize);
	
	if(resultado == -1){
		printf("The value %d is not in array\n", some_number);
	}else{
		printf("value %d in cell %d\n", some_number ,resultado);
	}


	cocktailSort(&copy, arraysize);
	//	interactShell();
	return 0;
};
