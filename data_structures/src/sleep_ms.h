// sleep_ms.h

#ifndef __WIN64__
    #include <windows.h>
    //#define usleep Sleep
    #include <unistd.h>
#elif __linux__
    #include <unistd.h>
#endif

#ifndef SLEEP_MS /* */
#define SLEEP_MS_H
void sleep_ms(int mil);
#endif