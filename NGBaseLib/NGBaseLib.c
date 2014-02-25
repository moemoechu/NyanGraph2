/*
 * NGBaseLib.c
 *
 *  Created on: 2014年2月25日
 *      Author: nyan
 */

#include "NGBaseLib.h"
#include <xcb/xcb.h>
#include <stdio.h>
#include <stdlib.h>

void (*DisplayFunc)();

xcb_connection_t *con;
xcb_screen_t *screen;
xcb_drawable_t win;
xcb_gcontext_t foreground;
xcb_generic_event_t *event;
uint32_t mask;
uint32_t values[2];

void NGBInit()
{
	event = NULL;
	mask = 0;
	con = xcb_connect(":0.0", NULL); //打开连接
	if(xcb_connection_has_error(con))
	{
		printf("Cannot open display\n");
		exit(1);
	}
	screen = xcb_setup_roots_iterator(xcb_get_setup(con)).data;

	win = screen->root;
	foreground = xcb_generate_id(con);
	mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
	values[0] = screen->black_pixel;
	values[1] = 0;

	xcb_create_gc(con, foreground, win, mask, values);

	win = xcb_generate_id(con);

	mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
	values[0] = screen->white_pixel;
	values[1] = XCB_EVENT_MASK_EXPOSURE;

}

void NGBUninit()
{
	if(event)
	{
		free(event);
	}
	xcb_disconnect(con);
}

void NGBCreateWindow()
{
	xcb_create_window(con,
					XCB_COPY_FROM_PARENT,
					win,
					screen->root,
					0, 0,
					640, 480,
					10,
					XCB_WINDOW_CLASS_INPUT_OUTPUT,
					screen->root_visual,
					mask, values);

	xcb_map_window(con, win);

	xcb_flush(con);
}

void NGBMainLoop()
{
	while((event = xcb_wait_for_event(con)))
	{
		switch(event->response_type & ~0x80)
		{
		case XCB_EXPOSE:
			//xcb_poly_point(con, XCB_COORD_MODE_ORIGIN, win, foreground, 4, points);
			DisplayFunc();
			xcb_flush(con);
			break;
		default:
			break;
		}
	}
}

void NGBDisplayFunc(void (*disp)())
{
	DisplayFunc = disp;
}

void NGBPoint(INT16 x, INT16 y)
{
	xcb_point_t points[] =
	{
	{ x, y } };
	xcb_poly_point(con, XCB_COORD_MODE_ORIGIN, win, foreground, 1, points);
}
