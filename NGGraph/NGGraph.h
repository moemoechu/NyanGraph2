/*
 * NGGraph.h
 *
 *  Created on: 2014年2月25日
 *      Author: nyan
 */

#ifndef NGGRAPH_H_
#define NGGRAPH_H_

#include "../common/NGDef.h"
#include "../NGBaseLib/NGBaseLib.h"

void NGInit();
void NGUninit();
void NGCreateWindow();
void NGMainLoop();
void NGDisplayFunc(void (*disp)());

void NGPoint(INT32 x, INT32 y);

#endif /* NGGRAPH_H_ */
