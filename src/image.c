#include "image.h"

void load_image(u_long * tim, TIM_IMAGE * tparam){     // This part is from Lameguy64's tutorial series : lameguy64.net/svn/pstutorials/chapter1/3-textures.html login/pw: annoyingmous
    OpenTIM(tim);                                   // Open the tim binary data, feed it the address of the data in memory
    ReadTIM(tparam);                                // This read the header of the TIM data and sets the corresponding members of the TIM_IMAGE structure
    LoadImage(tparam->prect, tparam->paddr);        // Transfer the data from memory to VRAM at position prect.x, prect.y
    DrawSync(0);                                    // Wait for the drawing to end
    if (is_indexed_image(tparam)){ // check 4th bit       // If 4th bit == 1, TIM has a CLUT
        LoadImage(tparam->crect, tparam->caddr);    // Load it to VRAM at position crect.x, crect.y
        DrawSync(0);                                // Wait for drawing to end
    }
}

extern unsigned long _binary_img_Jenny_tim_start[];
extern unsigned long _binary_img_Jenny_tim_end[];
extern unsigned long _binary_img_Jenny_tim_length;

TIM_IMAGE images[NUM_IMGS];
unsigned long *imagedatastarts[NUM_IMGS] = {
    _binary_img_Jenny_tim_start
};

void load_images() {
    for (int i = 0; i < NUM_IMGS; ++i) {
        load_image(imagedatastarts[i], &images[i]);
    }
}

TIM_IMAGE* get_image(IMGID id) {
    return &images[id];
}