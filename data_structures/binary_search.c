#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define ARRAYSIZE 24
// change the const value if change tha arraysize 
// 
// i know that a array isn't a BinaryTree
// BUT soon will have a REAL BinaryTree created with that array
struct BinaryTree {
	int array[ARRAYSIZE];
};
void sleep_ms(int mil){
	usleep(mil * 1000);
}
void showTime(struct BinaryTree *array, int length, int low)
{
	void sleep_ms(int mil);
	for(int i=low; i!= length; i++){
		for(int a=0;a!= 2; a++){
			printf("%d", a);
			fflush(stdout);
			sleep_ms(1);
			printf("\b \b");
			sleep_ms(1);	
			fflush(stdout);	
		}
		printf("%d ", array->array[i]);
	}
	printf("\n");
}
void showBubble(struct BinaryTree *array, int length,int pos_colored, int red_colored){
	void sleep_ms(int mil);
	for(int i=0; i!= length; i++){
		if (i == pos_colored){
			printf("\033[0;32m %d \033[0m", array->array[i]);
		}else if(i == red_colored){
			printf("\033[0;31m %d \033[0m", array->array[i]);
		}else{
			printf(" %d ", array->array[i]);
			fflush(stdout);
		}
		sleep_ms(2);
	}
	sleep_ms(2);
	printf("\n");
}
void bubbleSort(struct BinaryTree *array, int length){
	// ini_value = array.array[0] whatever
	// method = 0 | 1 - 0 to pass through array by 0 : or on the contrary
	int arraysize = length;
	int compare_check = 0;
	int pivot = 0;
	int last_value = 0;
	int red_value = arraysize;
	int temp_value;
	int right = 0;
	showTime(array, arraysize, 0);
	while(compare_check != arraysize){
		showBubble(array, arraysize, last_value, red_value);
		if (right == 0 && pivot != arraysize){
			pivot = pivot + 1;
			red_value = red_value - 1;
			if (array->array[last_value] > array->array[pivot]){
				temp_value = array->array[pivot];
				array->array[pivot] = array->array[last_value];
				array->array[last_value] = temp_value;
				compare_check = 0;
			}else {
				compare_check = compare_check + 1;
			}
			last_value = last_value + 1;	
		}else if (right == 1 && pivot != 0){
			pivot = pivot -1;
			red_value = red_value + 1;
			if (array->array[last_value] < array->array[pivot]){
				temp_value = array->array[pivot];
				array->array[pivot] = array->array[last_value];
				array->array[last_value] = temp_value;
				compare_check = 0;

			}else {
				compare_check = compare_check + 1;
			}
			last_value = last_value - 1;
		}else if(pivot == arraysize && right == 0){
			right = 1;
			temp_value = pivot;
			pivot = last_value;
			last_value = temp_value;
			compare_check = 0;
			red_value = 0;
		}else if(pivot == 0 && right == 1){
			right = 0;
			temp_value = pivot;
			pivot = last_value;
			last_value = temp_value;
			compare_check = 0;
			red_value = arraysize;
		}
	}
	
}

void sortTree(struct BinaryTree *array, int length){
	void showTime(struct BinaryTree*, int length, int low);
	int arraysize = length;
	int not_sorted = 1;
	// SHOW THE PROCESS ALL TIMEs THE FUNCTION IS CALLED :3 
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
int binarySearch(struct BinaryTree *array, int target, int low, int high){
	if (high-low == 1){
		return -1;
	}
	if (high > low){
		int mid = low + (high -low) / 2;
		showTime(array, high, low);
		if(array->array[mid] == target){return mid;}
		if(array->array[mid] > target){return binarySearch(array, target, low, mid);}
		if (array->array[mid] < target){return binarySearch(array, target, mid, high);}
	}
	return -1;
};
void showArray(struct BinaryTree array){
	// Pass through the array and show The Value and The Key //
	int len_array = sizeof(array.array) / 4;
	for(int i=0; i!= len_array; i++){
		printf("[%d]->%d\n", i,array.array[i]);
	};
};
int random_number(int min_num, int max_num){
	int result = 0, low_num = 0, hi_num = 0;
	if ( min_num < max_num ){
		low_num = min_num;
		hi_num = max_num + 1;
	} else {
		low_num = max_num + 1;
		hi_num = min_num;
	}
	sleep_ms(25);
	result = (rand() % (hi_num- low_num)) + low_num;
	return result;
};

void getArray(struct BinaryTree *array){
	int random_number(int min_num, int max_num);
	void sleep_ms(int mil);
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

	struct BinaryTree array;
	void sortTree(struct BinaryTree*, int length);
	void showArray(struct BinaryTree);
	void getArray(struct BinaryTree*);
	void bubbleSort(struct BinaryTree*, int length);
	int binarySearch(struct BinaryTree*, int target, int low, int high);
	int arraysize = ARRAYSIZE;

	srand(time(NULL));
	getArray(&array);

/////////////////////////////////////////////// 
///	BinarySearch with quicksort:
//	sort to make a BinarySearch
//	sortTree(&array, arraysize);
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

	bubbleSort(&array, arraysize);
	return 0;
};
