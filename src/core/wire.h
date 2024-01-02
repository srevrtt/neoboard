#pragma once

#include "../position.h"
#include <SDL2/SDL.h>

namespace Core {

class Wire {
private:
  Position start;
  Position end;

  int colorR{};
  int colorG{};
  int colorB{};

  int width{}, height{};
public:
  Wire(Position start);

  void update(Position end);
  void draw(SDL_Renderer *renderer);

  Position getStart();
};

} // namespace Core
