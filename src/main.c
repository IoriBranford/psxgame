#include "graphics.h"

int main() {
	graphics_setup();
	while (1) {
		graphics_begin();
		graphics_rect(32, 32, 64, 64, 255, 255, 0);
		graphics_end();
	}
	return 0;
}
