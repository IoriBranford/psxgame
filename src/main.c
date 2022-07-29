#include "draw.h"

int main() {
	draw_setup();
	while (1) {
		draw_begin();
		for (int i = 16; i <= 160; i += 16) {
			draw_rect(i, i, 64, 64, i, i, 0);
		}
		draw_end();
	}
	return 0;
}
