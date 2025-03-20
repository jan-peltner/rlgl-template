#include <raylib.h>
#include "window.h"

static Vector2 resolution = {
	.x = (float)WINDOW_WIDTH, 
	.y = (float)WINDOW_HEIGHT
};

Vector2* getResolution(void) {
	return &resolution;
};
