#include <stdio.h>
#include <time.h>

#include "src/showTime.h"
#include "src/random_number.h"
#include "src/array_struct.h"
#include "src/cocktail.h"




void sortArray(struct ArrayLike *array, int length){
	int arraysize = length;
	int not_sorted = 1;
	 
	showTime(array, arraysize, 0);
	int compare_check = 0;
	int temp_check;

	for(int i=0; i!= arraysize; i++){
		if(i > 0){
			if(array->array[i] >= array->array[i-1]){
				compare_check = compare_check + 1;
			}else{
				temp_check = array->array[i];
				array->array[i] = array->array[i-1];
				array->array[i-1] = temp_check;
				compare_check = 0;		
			}
		}else{
			if(array->array[i] <= array->array[i+1]){
				compare_check = compare_check + 1;
			}else{
				temp_check = array->array[i];
				array->array[i] = array->array[i+1];
				array->array[i+1] = temp_check;
				compare_check = 0;
			}	
		}
	}
	if(compare_check == arraysize){
		return;
	}
	else{
		sortArray(array, arraysize);
	}	
	
};

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
		numbers[a] = random_number(0, 999);
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

int main(int args, char **argv[]){
	// 
	struct ArrayLike array;
	void sortArray(struct ArrayLike*, int length);
	void showArray(struct ArrayLike*);
	void randPopArray(struct ArrayLike*, int toPop);



	int arraysize = ARRAYSIZE01 - (255);

	srand(time(NULL));
	randPopArray(&array, arraysize);
	struct ArrayLike copy = array;
/////////////////////////////////////////////// 
///	BinarySearch with quicksort:
//	sort to make a BinarySearch
	sortArray(&array, arraysize);
	
	//printf("<Press Enter to continue to Cocktail_Sort>");
	//fflush(stdout);

//	printf("\n");
//	printf("BinarySearch->\n");
//	int some_number = 25;
//	int resultado = binarySearch(&array, some_number, 0, arraysize);
//	if(resultado == -1){
//		printf("The value %d is not in %d#~:array", some_number, &array);
//	}else{
//		printf("value %d in cell %d\n", some_number ,resultado);
//	}
//	
/////////////////////////////////////////////////////

	cocktailSort(&copy, arraysize);

	return 0;
};
