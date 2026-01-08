#include <filesystem>
#include <iostream>

#include "application/application.h"
#include "application/image.h"
#include "gpu/gpu.h"

Image* texture;
Point p1;
Point p2;
Point p3;

Point q1;
Point q2;
Point q3;

float speed = 0.01;
void changeUV() {
  p1.uv.x += speed;
  p2.uv.x += speed;
  p3.uv.x += speed;
  q1.uv.x += speed;
  q2.uv.x += speed;
  q3.uv.x += speed;
}

void render() {
  changeUV();

  sgl->clear();
  sgl->setTexture(texture);
  sgl->setWrapMode(TEXTURE_WRAP_MIRROR);

  sgl->drawTriangle(p1, p2, p3);
  sgl->drawTriangle(q1, q2, q3);
}

void prepare() {
  texture = Image::createImage("textures/goku.jpg");

  p1.x = 0;
  p1.y = 0;
  p1.color = RGBA(255, 0, 0, 255);
  p1.uv = math::vec2f(0.0f, 0.0f);

  p2.x = 400;
  p2.y = 300;
  p2.color = RGBA(0, 255, 0, 255);
  p2.uv = math::vec2f(1.0f, 1.0f);

  p3.x = 400;
  p3.y = 0;
  p3.color = RGBA(0, 0, 255, 255);
  p3.uv = math::vec2f(1.0f, 0.0f);

  q1.x = 0;
  q1.y = 0;
  q1.color = RGBA(255, 0, 0, 255);
  q1.uv = math::vec2f(0.0f, 0.0f);

  q2.x = 0;
  q2.y = 300;
  q2.color = RGBA(0, 255, 0, 255);
  q2.uv = math::vec2f(0.0f, 1.0f);

  q3.x = 400;
  q3.y = 300;
  q3.color = RGBA(0, 0, 255, 255);
  q3.uv = math::vec2f(1.0f, 1.0f);
}

int main(int argc, char* argv[]) {
  if (!app->initApplication(800, 600)) {
    return -1;
  }

  sgl->initSurface(app->getWidth(), app->getHeight(), app->getCanvas());

  prepare();

  bool alive = true;
  while (alive) {
    alive = app->peekMessage();
    render();
    app->show();
  }

  Image::destroyImage(texture);
  return 0;
}