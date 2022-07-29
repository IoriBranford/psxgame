#ifndef __draw_H
#define __draw_H

#include <types.h>

void draw_setup();

void draw_begin();

void draw_rect(short x, short y, short w, short h, u_char r, u_char g, u_char b);

void draw_end();

#endif