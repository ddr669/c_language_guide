#include <stdlib.h>
#include <stdio.h>

int main(int argv, char **argc[]){
	int pointer[20];
	/* Needed to set in memory address base */
	int* ptr;

	ptr = &pointer[0];
	printf("pointer-size = %i\n", sizeof(&pointer));
	printf("Arraysize-> %i\n", sizeof(pointer));
	printf("item-size = %i\n", sizeof(pointer[0]));

	int passPointer(int *pointer, int target);
	passPointer(ptr, 19);

	return 0;
}

int passPointer(int *pointer, int target){
	int size = sizeof(&pointer);
	if (target>size){
		size = target;
	}
	for ( int i = 0; i <= size; i++){
		/*	Iterate thought pointer by index like a array */
		*(pointer + i) = i * 10;
		printf("%i -> %d\n", i, *(pointer + i));
	}
	return 0;
}
