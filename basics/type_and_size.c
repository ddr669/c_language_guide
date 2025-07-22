#include <stdio.h>

int main(int argc, char **argv[]){

	int counter = 0;
	int sizeof_int, sizeof_float, sizeof_double, sizeof_char;


	sizeof_int 	= sizeof(int);
	sizeof_float 	= sizeof(float);
	sizeof_double   = sizeof(double);
	sizeof_char 	= sizeof(char);
	
	char var[2][4][6] = {{"int","float","double","char"},
		{sizeof_int, sizeof_float, sizeof_double, sizeof_char}};	



	printf("type int have %i bytes \ntype float have %i bytes \ntype double have %i bytes\ntype char have %i byte\n",sizeof_int, sizeof_float, sizeof_double, sizeof_char);


	int i;

	// that is a exemple of how c is not a good language //

	for(i=0;i<=4;i++){
		printf("type %s random value because c is shit %i\n", var[0][i], var[1][counter]);
		counter += 1;

	};


	return 0;

};
