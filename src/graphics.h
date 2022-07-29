#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#include <types.h>

void graphics_setup();

void graphics_begin();

void graphics_rect(short x, short y, short w, short h, u_char r, u_char g, u_char b);

void graphics_end();

#endif