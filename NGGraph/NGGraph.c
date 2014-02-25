/*
 * NGGraph.c
 *
 *  Created on: 2014年2月25日
 *      Author: nyan
 */

#include "NGGraph.h"

void NGInit()
{
	NGBInit();
}

void NGUninit()
{
	NGBUninit();
}

void NGCreateWindow()
{
	NGBCreateWindow();
}

void NGMainLoop()
{
	NGBMainLoop();
}

void NGDisplayFunc(void (*disp)())
{
	NGBDisplayFunc(disp);
}

void NGPoint(INT32 x, INT32 y)
{
	NGBPoint(x, y);
}
