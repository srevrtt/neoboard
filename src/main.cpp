#include <iostream>
#include <string>

#include "ui/window.h"

int main(int argc, char *argv[]) {
  auto *window = new UI::Window(1280, 720, "Neoboard v0.1");
  window->run();

  return 0;
}
