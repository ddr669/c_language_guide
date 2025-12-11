#include "headers/binary_search.h"

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
