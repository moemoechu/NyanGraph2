/*
 * test.c
 *
 *  Created on: 2014年2月18日
 *      Author: nyan
 */

#include "../common/NGDef.h"
#include "../NGGraph/NGGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void display()
{
	const REAL32 pi = 3.1415;
	//COLOR_RGB color;
	NGPoint(10, 10);
	NGPoint(10, 20);
	NGPoint(20, 10);
	for(float i = 0; i <= 2 * pi; i += 0.1)
	{
		NGPoint(50 + sin(i) * 20, 50 + cos(i) * 20);

	}
//	for(float i = 0; i <= 2 * pi; i += 0.1)
//	{
//		XnLine(200, 200, 200 + sin(i) * 50, 200 + cos(i) * 50);
//
//	}
}

int main()
{
	setbuf(stdout, NULL);

	NGInit();
	NGCreateWindow();
	NGDisplayFunc(display);
	NGMainLoop();
	NGUninit();

	return EXIT_SUCCESS;
}
