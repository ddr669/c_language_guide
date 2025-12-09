#include <stdio.h>
#include <time.h>

#include "src/showTime.h"
#include "src/random_number.h"
#include "src/array_struct.h"

#if !defined ARRAYSIZE
#define ARRAYSIZE 20
#endif

void sortTree(struct ArrayLike *array, int length){
	int arraysize = length;
	int not_sorted = 1;
	 
	showTime(array, ARRAYSIZE, 0);
	int compare_check = 0;
	int temp_check;

	for(int i=0; i!= arraysize; i++){
		if(i > 0){
			if (array->array[i] >= array->array[i-1]){
				compare_check = compare_check + 1;
			}else{
				temp_check = array->array[i];
				array->array[i] = array->array[i-1];
				array->array[i-1] = temp_check;
				compare_check = 0;		
			}
		}else{
			if (array->array[i] <= array->array[i+1]){
				compare_check = compare_check + 1;
			}else{
				temp_check = array->array[i];
				array->array[i] = array->array[i+1];
				array->array[i+1] = temp_check;
				compare_check = 0;
			}	
		}
	}
	if (compare_check == arraysize){
		return;
	}
	else{
		sortTree(array, arraysize);
	}	
	
};
int binarySearch(struct ArrayLike *array, int target, int low, int high){
	if (high-low == 1){
		return -1;
	}
	if (high > low){
		int mid = low + (high -low) / 2;
		showTime(array, high, low);
		if(array->array[mid] == target){
			return mid;
		}
		if(array->array[mid] > target){
			return binarySearch(array, target, low, mid);
		}
		if (array->array[mid] < target){
			return binarySearch(array, target, mid, high);
		}
	}
	return -1;
};
void showArray(struct ArrayLike array){
	int len_array = sizeof(array.array) / 4;
	for(int i=0; i!= len_array; i++){
		printf("[%d]->%d\n", i,array.array[i]);
	};
};

void getArray(struct ArrayLike *array){

	int len_array = sizeof(array->array) / 4;
	int numbers[ARRAYSIZE];
	printf("loading random numbers ");
	fflush(stdout);
	for(int a =0; a!= len_array; a++){
		numbers[a] = random_number(0, 50);
		if (len_array < 100 && len_array < 300){
			if (a % 2 == 0){printf(".");fflush(stdout);}
		}else{
			if (a % 6 == 0){printf(".");fflush(stdout);}
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
		
	};
	printf("]\n");
	
};

int main(int args, char **argv[]){

	struct ArrayLike array;
	void sortTree(struct ArrayLike*, int length);
	void showArray(struct ArrayLike);
	void getArray(struct ArrayLike*);
	void bubbleSort(struct ArrayLike*, int length);
	int binarySearch(struct ArrayLike*, int target, int low, int high);
	int arraysize = ARRAYSIZE;

	srand(time(NULL));
	getArray(&array);
	struct ArrayLike copy = array;
/////////////////////////////////////////////// 
///	BinarySearch with quicksort:
//	sort to make a BinarySearch
    sortTree(&array, arraysize-1);
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

	bubbleSort(&copy, arraysize-1);
    getchar();
	return 0;
};
