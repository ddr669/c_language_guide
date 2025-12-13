#include "headers/showTime.h"


void showTime(struct ArrayLike *array, int length, int low)
{
	int timeScale = 8;

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
	char quit[8] = {"q"};
	//ptr = &event;	
	//char *ptr = (char *) calloc(255, sizeof(char));
	int color_c = 0;
	while (event != quit){
		sleep_ms(800);
		CLS_STDIO;
		for (int i=0; i!= 120; i++){
			switch(color_c){
				case 1:
					MOD_BG_COLORRGB("\n\r",i, 20, 20);
				case 2:
					MOD_BG_COLORRGB("\n\r",20, i, 20);
				case 3:
					MOD_BG_COLORRGB("\n\r",20, 20, i);
				default:
					MOD_BG_COLORRGB("\n\r",i,i,i);
			}
			//fflush(stdout);
		}
		if (color_c > 3){
			color_c = 0;
		}else{
			color_c = color_c + 1;
		}
		//printf("%s\n\r", event);
		//scanf("%s", &event);
	}
}
