
#include "sleep_ms.h"
#include <unistd.h>

void sleep_ms(int mil){
	usleep(mil * 1000);
}