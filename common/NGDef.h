/*
 * NGDef.h
 *
 *  Created on: 2014年2月25日
 *      Author: nyan
 */

#ifndef NGDEF_H_
#define NGDEF_H_

typedef unsigned int UINT32;
typedef int INT32;
typedef unsigned short UINT16;
typedef short INT16;

typedef float REAL32;
typedef double REAL64;

typedef union
{
	struct
	{
		char red;
		char green;
		char blue;
		char reserve;
	};
	UINT32 rgb;
} COLOR_RGB;

typedef union
{
	struct
	{
		char red;
		char green;
		char blue;
		char alpha;
	};
	UINT32 rgba;
} COLOR_RGBA;

#endif /* NGDEF_H_ */
