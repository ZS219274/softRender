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

  Point p1{ 0, 100, RGBA(255, 0, 0, 255)};
	Point p2{ 500, 100, RGBA(0, 255, 0, 255) };
	Point p3{ 250, 500, RGBA(0, 0, 255, 255) };

	sgl->drawTriangle(p1, p2, p3);
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