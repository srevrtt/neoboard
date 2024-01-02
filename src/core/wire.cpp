#include <iostream>
#include <string>
#include <random>

#include "wire.h"

namespace Core {

Wire::Wire(Position start) {
  this->start = start;
  end = start;

  // Generate random color
  std::srand(std::rand());
  colorR = std::rand() % 255;
  colorG = std::rand() % 255;
  colorB = std::rand() % 255;
}

void Wire::update(Position end) {
  this->end = end;

  width = end.x - start.x;
  height = end.y - start.y;
}

void Wire::draw(SDL_Renderer *renderer) {
  SDL_Rect rect = { start.x - 3, start.y - 3, width, 6 };

  if (width <= 6 && width >= -6) {
    rect = { start.x - 3, start.y - 3, 6, height };
  }

  SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
  SDL_RenderFillRect(renderer, &rect);
}

Position Wire::getStart() {
  return start;
}

} // namespace Core
