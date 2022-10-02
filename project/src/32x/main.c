//#include "32x.h"
//#include "hw_32x.h"
#include "swmain.h"

#ifdef WIN32
#include "32x.h"
unsigned char fake32xFrameBuffer[(320 * 224) + 0x200];
#endif
#include "32x.h"

#include "timer.h"

int main(void)
{
	//MARS_SYS_CPU2_CMD = 0;

	Timer_Init();

	swmain(0 /*argc*/, NULL /*argv*/);



    return 0;
} // end of main function


void secondary(void)
{
	while (1)
	{
	}
}
