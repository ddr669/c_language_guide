// sleep_ms.h

#include <unistd.h>
#include <stdlib.h>
#if defined (_WIN64)
    #include <windows.h>
    #define usleep Sleep
#elif defined __WIN64__
	#include <windows.h>
#elif defined __CYGWIN__
	#include <windows.h>
#elif defined __linux__
    #define _ 0 
#endif

#ifndef SLEEP_MS /* */
#define SLEEP_MS_H
void sleep_ms(int mil);
#endif
