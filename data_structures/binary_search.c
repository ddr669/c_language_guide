#include <stdio.h>
#define ARRAYSIZE 6
// change the const value if change tha arraysize 
// 
// i know that a array isn't a BinaryTree
// BUT soon will have a REAL BinaryTree created with that array

struct BinaryTree {
	int array[ARRAYSIZE];
};

int compare(int x, int y){
	if(x > y){
		return 1;
	}else if (x < y){
		return 0;
	}else{
		return 1;
	};
};
void sortTree(struct BinaryTree *array, int length){
	int compare(int x, int y);
	int arraysize = length;
	int not_sorted = 1;
	// SHOW THE PROCESS ALL TIMEs THE FUNCTION IS CALLED :3 
	printf("%d %d %d %d %d %d\n", array->array[0],
		array->array[1],
		array->array[2],
		array->array[3],
		array->array[4],
		array->array[5]);
	int compare_check;
	int temp_check;
	for(int i=0; i!= arraysize; i++){
		if(i > 0){
			if(compare(array->array[i],array->array[i-1])==0){
				temp_check = array->array[i];array->array[i] = array->array[i-1];
				array->array[i-1] = temp_check;compare_check = 0;		
			}else{compare_check = compare_check + 1;}
		}else{
			if (compare(array->array[i],array->array[i+1])==1){
				temp_check = array->array[i];array->array[i] = array->array[i+1];
				array->array[i+1] = temp_check;compare_check = 0;

			}else {compare_check = compare_check + 1;}
		}
	}
	if (compare_check == arraysize){
		return;
	}
	else{
		sortTree(array, arraysize-1);
	}	
};
int binarySearch(struct BinaryTree array, int target){
	// TODO 
	int half_array = (sizeof(array.array) / 4) / 2;
	int mid_array[half_array];
	int array_size = sizeof(array.array) / 4;

	/*if (array.array < target){
	}
	else if (array.array > target){
	}*/
	return 0;
};

void showArray(struct BinaryTree array){
	// Pass through the array and show The Value and The Key //
	int len_array = sizeof(array.array) / 4;
	for(int i=0; i!= len_array; i++){
		printf("[%d]->%d\n", i,array.array[i]);
	};
};
void getArray(struct BinaryTree *array){
	int len_array = sizeof(array->array) / 4;
	int numbers[len_array];numbers[0] = 1;numbers[1] = 4;numbers[2] = 6;numbers[3] = 5;numbers[4] = 2;numbers[5] = 0;

	for(int i =0; i!= len_array; i++){
		array->array[i] = numbers[i];
	};
};


int main(int args, char **argv[]){
	struct BinaryTree array;
	void sortTree(struct BinaryTree*, int length);
	void showArray(struct BinaryTree);
	void getArray(struct BinaryTree*);
	int numbers[10];
	int arraysize = ARRAYSIZE;
	numbers[0] = 1;numbers[1] = 4; 
	numbers[2] = 6;numbers[3] = 2;
	numbers[4] = 1;
	numbers[5] = 2;
	// change the BinaryTree->array to the same as numbers 
	getArray(&array);
	// SHOW 
	showArray(array);
	// sort to make a BinarySearch
	sortTree(&array, arraysize);
	showArray(array);
	return 0;
};
