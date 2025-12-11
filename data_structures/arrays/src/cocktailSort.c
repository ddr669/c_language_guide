#include "headers/cocktail.h"
/*--------------*
 *		*
 *		*
 *		*
 *		*
 *		*
 *		*
 *		*
 *		*
 *		*
 *--------------*/

void showBubble(struct ArrayLike *array,
		int length,
		int pos_colored,
		int red_colored){
	int color_grade = 0;
	int timeScale   = 4;
	for(int i=0;i!=length;i++){
		if(i==pos_colored){
			printf("\033[0;32m%d\033[0m ", array->array[i]);
			//printf("\b \b");
			fflush(stdout);
		}else if(i==red_colored){
			printf("\033[0;31m%d\033[0m ", array->array[i]);
			//printf("\b \b");
			fflush(stdout);
		}else{
			color_grade = (30 + 0);
			printf("\033[0;%dm%d\033[0m ",
					color_grade,
					array->array[i]);
			//printf("\b \b");
			fflush(stdout);
		}
		sleep_ms(TIMESTOP/timeScale);
	}
	sleep_ms(TIMESTOP/timeScale);
	printf("\n");
}


void cocktailSort(struct ArrayLike *array, int length){
	int arraysize = length;
	int compare_check = 0;
	int pivot = 0;
	int last_value = 0;
	int red_value = arraysize;
	int temp_value;
	int tmp_val;
	int right = 0;
	showTime(array, arraysize, 0);
	while(compare_check != arraysize-1){
		showBubble(array, arraysize, last_value, red_value);
		if (right == 0 && pivot < arraysize-1){
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
			pivot = pivot - 1;
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
		}else if(pivot == arraysize-1 && right == 0){
			right = 1;
			tmp_val = pivot;
			pivot = last_value;
			last_value = tmp_val;
			compare_check = 0;
			red_value = 0;
		}else if(pivot == 0 && right == 1){
			right = 0;
			tmp_val = pivot;
			pivot = last_value;
			last_value = tmp_val;
			compare_check = 0;
			red_value = arraysize;
		}
	}
	
}
