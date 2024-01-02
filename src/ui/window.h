#pragma once

#include <SDL2/SDL.h>

namespace UI {

class Window {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_Event event;
  bool isOpen;
public:
  Window(unsigned int width, unsigned int height, const char *title);
  void run();

  ~Window();
};

} // namespace UI
