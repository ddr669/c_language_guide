
#include "headers/sortArray.h"



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