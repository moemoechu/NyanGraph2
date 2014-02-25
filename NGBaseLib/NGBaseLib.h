/*
 * NGBaseLib.h
 *
 *  Created on: 2014年2月25日
 *      Author: nyan
 */

#ifndef NGBASELIB_H_
#define NGBASELIB_H_

#include "../common/NGDef.h"

//void XnPoint(INT16 x, INT16 y);

//void XnLine(INT16 x0, INT16 y0, INT16 x1, INT16 y1);

void NGBInit();
void NGBUninit();
void NGBCreateWindow();
void NGBMainLoop();
void NGBDisplayFunc(void (*disp)());

void NGBPoint(INT16 x, INT16 y);


#endif /* NGBASELIB_H_ */
