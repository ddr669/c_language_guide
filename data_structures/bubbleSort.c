#include "src/array_struct.h"
#include <stdio.h>
#include "src/sleep_ms.h"

void showBubble(struct ArrayLike *array, int length,int pos_colored, int red_colored){
	
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


void bubbleSort(struct ArrayLike *array, int length){
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
