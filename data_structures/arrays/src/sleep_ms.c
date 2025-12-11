
#include "headers/sleep_ms.h"

// #if
// #include <unistd.h>

void sleep_ms(int mil){
	usleep(mil * 1000);
}
