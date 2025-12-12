#include "headers/showTime.h"


void showTime(struct ArrayLike *array, int length, int low)
{
	int timeScale = 4;

	for(int i=low; i!= length; i++){
		for(int a=0;a!= 2; a++){
			printf("%d", a);
			fflush(stdout);
			printf("\b \b");

			sleep_ms(TIMESTOP / timeScale);	
			fflush(stdout);	
		}
		printf("%d ", array->array[i]);
	}
	printf("\n");
}

void interactShell(){
	MOD_AUX_TXT(5,5,255); 							// change text font color 
	MOD_BG_COLORRGB("Hello MODCOLOR", 255, 2, 2);	// change BG color
	printf("\n\r");

	TXT_MOD_RGB("Hello, world", 32, 12, 72);		// change font color, print string and reset color
	printf("\n\r");

	MOD_BG_COLORRGB("\n\r\n\r\n\r", 20, 20, 10);	// 

	TXT_BLUE("I'm BLUE"); 							// blue text
	printf("\n\r");

	TXT_RED("KKKKKKKKKKKKRED");						// red text
	printf("\n\r");
	printf("hi\t[enter]");

	//getchar();
	CLS_STDIO;										// clean STDIO
	char event[255];
	char *ptr = (char *) calloc(255, sizeof(char));
	
	//ptr = &event;	
	//char *ptr = (char *) calloc(255, sizeof(char));
	while (event != "o"){
		CLS_STDIO;
		printf("%d\n\r", event);
		scanf("%d", &event);
	}
}
