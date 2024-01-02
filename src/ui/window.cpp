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
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (!renderer) {
    std::cerr << "ERROR: Failed to create an SDL2 renderer! Aborting." << std::endl;
    exit(1);
  }

  isOpen = true;
}

void Window::run() {
  while (isOpen) {
    SDL_WaitEvent(&event);

      switch (event.type) {
      case SDL_QUIT:
        isOpen = false;
        break;

      SDL_RenderClear(renderer);
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
