#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "window.h"

namespace UI {

Window::Window(unsigned int width, unsigned int height, const char *title) {
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
    width, height, SDL_WINDOW_SHOWN);

  if (!window) {
    std::cerr << "ERROR: Failed to create a window! Aborting." << std::endl;
    exit(1);
  }

  renderer = SDL_CreateRenderer(window, -1, 
    SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    std::cerr << "ERROR: Failed to create an SDL2 renderer! Aborting." << std::endl;
    exit(1);
  }

  isOpen = true;
}

void Window::setKeyupCallback(void (*callback)(SDL_Renderer*, SDL_Keycode)) {
  this->keyupCallback = callback;
}

void Window::setMouseUpallback(void (*callback)(SDL_Renderer*, int btn)) {
  this->mouseUpCallback = callback;
}

void Window::setMouseMoveallback(void (*callback)(SDL_Renderer*, int x, int y)) {
  this->mouseMoveCallback = callback;
}

void Window::setRenderCallback(void (*callback)(SDL_Renderer*)) {
  this->renderCallback = callback;
}

void Window::run() {
  while (isOpen) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        isOpen = false;
        break;
      case SDL_MOUSEBUTTONUP:
        mouseUpCallback(renderer, event.button.button);
        break;
      case SDL_MOUSEMOTION:
        mouseMoveCallback(renderer, event.motion.x, event.motion.y);
        break;
      case SDL_KEYUP:
        keyupCallback(renderer, event.key.keysym.sym);
        break;
      }

      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);
      renderCallback(renderer);
      SDL_RenderPresent(renderer);
    }
  }
}

Window::~Window() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}

} // namespace UI
