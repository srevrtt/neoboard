#include <iostream>
#include <string>
#include <vector>

#include "ui/window.h"

#include "core/wire.h"

std::vector<Core::Wire*> wires;
Core::Wire *currentwire;

bool wireMode;
bool placingWire;
int currentWireIdx;

int mousePosX, mousePosY;

void onWindowKeyUp(SDL_Renderer *renderer, SDL_Keycode key) {
  if (key == SDLK_w && !wireMode) {
    wireMode = !wireMode;
  }
}

void onWindowMouseClick(SDL_Renderer *renderer, int button) {
  if (button == SDL_BUTTON_LEFT && wireMode && !placingWire) {
    placingWire = true;
    currentWireIdx++;

    Position start = { mousePosX, mousePosY };
    currentwire = new Core::Wire(start);
  } else if (button == SDL_BUTTON_LEFT && wireMode && placingWire) {
    placingWire = false;
    wires.push_back(currentwire);
  }
}

void onWindowMouseMove(SDL_Renderer *renderer, int x, int y) {
  mousePosX = x;
  mousePosY = y;

  if (placingWire) {
    Position newEnd = { currentwire->getStart().x, currentwire->getStart().y };

    if (mousePosX < currentwire->getStart().x - 6
        || mousePosX > currentwire->getStart().x + 6) {
      newEnd.x = mousePosX;
    }

    if (mousePosY < currentwire->getStart().y - 6
        || mousePosY > currentwire->getStart().y + 6) {
      newEnd.y = mousePosY;
    }

    currentwire->update(newEnd);
  }
}

void onWindowRender(SDL_Renderer *renderer) {
  if (placingWire) {
    currentwire->draw(renderer);
  }

  for (auto &wire : wires) {
    wire->draw(renderer);
  }
}

int main(int argc, char *argv[]) {
  wireMode = false;
  placingWire = false;
  currentWireIdx = -1;

  mousePosX = 0;
  mousePosY = 0;

  auto *window = new UI::Window(1280, 720, "Neoboard v0.1");

  window->setKeyupCallback(onWindowKeyUp);
  window->setMouseUpallback(onWindowMouseClick);
  window->setMouseMoveallback(onWindowMouseMove);
  window->setRenderCallback(onWindowRender);

  window->run();

  return 0;
}
