#include "graphics.h"

int main() {
	graphics_setup();
	while (1) {
		graphics_begin();
		for (int i = 16; i <= 160; i += 16) {
			graphics_rect(i, i, 64, 64, i, i, 0);
		}
		graphics_end();
	}
	return 0;
}
