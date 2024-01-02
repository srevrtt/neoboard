#pragma once

#include <SDL2/SDL.h>

namespace UI {

class Window {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;

  void (*keyupCallback)(SDL_Renderer*, SDL_Keycode);
  void (*mouseUpCallback)(SDL_Renderer*, int btn);
  void (*mouseMoveCallback)(SDL_Renderer*, int x, int y);
  void (*renderCallback)(SDL_Renderer*);

  SDL_Event event;
  bool isOpen;
public:
  Window(unsigned int width, unsigned int height, const char *title);
  
  void setKeyupCallback(void (*callback)(SDL_Renderer*, SDL_Keycode));
  void setMouseUpallback(void (*callback)(SDL_Renderer*, int btn));
  void setMouseMoveallback(void (*callback)(SDL_Renderer*, int x, int y));
  void setRenderCallback(void (*callback)(SDL_Renderer*));

  void run();

  ~Window();
};

} // namespace UI
