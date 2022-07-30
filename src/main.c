#include "draw.h"
#include "image.h"

int main() {
	TIM_IMAGE *img_Jenny;
	draw_setup(0, 256, 240);
	load_images();
	img_Jenny = get_image(IMG_JENNY);
	while (1) {
		draw_begin();
		for (int i = 16; i <= 160; i += 16) {
			draw_sprite(i, i, 32, 32, img_Jenny, 0, 0);
			// draw_rect(i, i, 64, 64);
		}
		set_draw_sprite_page(img_Jenny);
		draw_end();
	}
	return 0;
}
