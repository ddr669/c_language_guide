
#ifndef SHOWTIME_h
#define ShOWTIME_h

#include <stdio.h>
#include <stdlib.h>
#include "sleep_ms.h"

#include "array_struct.h"

#define TIMESTOP 1

#define CLS_STDIO printf("\033c");


#define RESET_CLI							printf("\x1b[0m")

#define MOD_AUX_TXT(r,g,b) 					printf("\e[38;2;%d;%d;%dm", r,g,b) 	
#define MOD_BG_COLORRGB(string, r, g, b) 	printf("\e[48;2;%d;%d;%dm", r,g,b); printf(string); RESET_CLI

#define TXT_MOD_RGB(string, r, g, b) 		MOD_AUX_TXT(r, g, b); printf(string); RESET_CLI


#define TXT_BLUE(string) 					printf("\x1b[34m"); printf(string); RESET_CLI
#define TXT_RED(string) 					printf("\x1b[31m"); printf(string); RESET_CLI


void showTime(struct ArrayLike *array, int length, int low);

void interactShell();

#endif
