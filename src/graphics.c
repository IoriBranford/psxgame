#include <sys/types.h>	// This provides typedefs needed by libgte.h and libgpu.h
#include <stdio.h>	// Not necessary but include it anyway
#include <libetc.h>	// Includes some functions that controls the display
#include <libgte.h>	// GTE header, not really used but libgpu.h depends on it
#include <libgpu.h>	// GPU library header

#define OTLEN 8         // Ordering table length (recommended to set as a define
                        // so it can be changed easily)

DISPENV disp[2];
DRAWENV draw[2];
int db = 0;

u_long ot[2][OTLEN];    // Ordering table length
char pribuff[2][32768]; // Primitive buffer
char *nextpri;          // Next primitive pointer

void graphics_setup() {
    // Reset graphics
    ResetGraph(0);

    // First buffer
    SetDefDispEnv(&disp[0], 0, 0, 320, 240);
    SetDefDrawEnv(&draw[0], 0, 240, 320, 240);
    // Second buffer
    SetDefDispEnv(&disp[1], 0, 240, 320, 240);
    SetDefDrawEnv(&draw[1], 0, 0, 320, 240);

    draw[0].isbg = 1;               // Enable clear
    setRGB0(&draw[0], 63, 0, 127);  // Set clear color (dark purple)
    draw[1].isbg = 1;
    setRGB0(&draw[1], 63, 0, 127);

    nextpri = pribuff[0];           // Set initial primitive pointer address
}

void graphics_begin() {
    ClearOTagR(ot[db], OTLEN);  // Clear ordering table
}

void graphics_rect(short x, short y, short w, short h, u_char r, u_char g, u_char b) {
    TILE *tile = (TILE*)nextpri;      // Cast next primitive

    setTile(tile);              // Initialize the primitive (very important)
    setXY0(tile, x, y);       // Set primitive (x,y) position
    setWH(tile, w, h);        // Set primitive size
    setRGB0(tile, r, g, b); // Set color yellow
    addPrim(ot[db], tile);      // Add primitive to the ordering table
    
    nextpri += sizeof(TILE);    // Advance the next primitive pointer
}

void graphics_end() {
    DrawSync(0);                // Wait for any graphics processing to finish
    
    VSync(0);                   // Wait for vertical retrace

    PutDispEnv(&disp[db]);      // Apply the DISPENV/DRAWENVs
    PutDrawEnv(&draw[db]);

    SetDispMask(1);             // Enable the display

    DrawOTag(ot[db]+OTLEN-1);   // Draw the ordering table
    
    db = !db;                   // Swap buffers on every pass (alternates between 1 and 0)
    nextpri = pribuff[db];      // Reset next primitive pointer
}
