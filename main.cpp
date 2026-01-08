#include <iostream>
#include "application/application.h"
#include "gpu/gpu.h"

/*
* Course materials introduction:
* 1 GDI pixel rendering construction
* 2 Building rendering functions of simulated GPU
* 3 Pixel implementation
*/

void render() {
	sgl->clear();

	for (uint32_t i = 0; i < app->getWidth(); ++i) {
		for (uint32_t j = 0; j < app->getHeight(); ++j) {
			uint32_t v = std::rand() % 255;
			RGBA color(v, v, v, v);
			sgl->drawPoint(i, j, color);
		}
	}
}

int main(int argc, char* argv[]) {
	if (!app->initApplication(800, 600)) {
		return -1;
	}

	sgl->initSurface(app->getWidth(), app->getHeight(), app->getCanvas());

	bool alive = true;
	while (alive) {
		alive = app->peekMessage();
		render();
		app->show();
	}

	return 0;
}