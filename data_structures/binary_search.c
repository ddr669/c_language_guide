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
		sleep_ms(1);
		for(int a=0;a!= 9; a++){
			sleep_ms(1);
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
			}
			else{
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
//	srand(time(NULL));
	
//	sleep_ms(160);
	result = (rand() % (hi_num- low_num)) + low_num;
	

	return result;
};

void getArray(struct BinaryTree *array){
	int random_number(int min_num, int max_num);
	void sleep_ms(int mil);
	int len_array = sizeof(array->array) / 4;
	int numbers[ARRAYSIZE];
	printf("loading random numbers ");fflush(stdout);
	for(int a =0; a!= len_array; a++){
		numbers[a] = random_number(0, 955);
//		sleep_ms(160);
		if (len_array < 100 && len_array < 300){
			if (a % 2 == 0){printf(".");fflush(stdout);}
		}else{
			if (a % 6 == 0){printf(".");fflush(stdout);}
		}
		//sleep_ms(85*6);
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
	char argvs_[10];
	struct BinaryTree array;
	void sortTree(struct BinaryTree*, int length);
	void showArray(struct BinaryTree);
	void getArray(struct BinaryTree*);
	int binarySearch(struct BinaryTree*, int target, int low, int high);
	int arraysize = ARRAYSIZE;
	
	// change the BinaryTree->array to the same as numbers 
	getArray(&array);
	// SHOW 
	// sort to make a BinarySearch
	sortTree(&array, arraysize);
	printf("\n");
	printf("BinarySearch->\n");
	int some_number;
	some_number = 200;
	int resultado = binarySearch(&array, some_number, 0, arraysize);
	if(resultado == -1){
		printf("The value %d is not in %d#~:array", some_number, &array);
	}else{
		printf("value %d in cell %d\n", some_number ,resultado);
	}

	return 0;
};
