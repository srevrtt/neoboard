cmake_minimum_required(VERSION 3.23)
project(Neoboard VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CORE_SRCS src/core/wire.cpp)
set(UI_SRCS src/ui/window.cpp)
set(SRCS ${UI_SRCS} ${CORE_SRCS} src/main.cpp)

include_directories(/usr/include/SDL2)

add_executable(Neoboard ${SRCS})
target_link_libraries(Neoboard SDL2 SDL2main SDL2_image SDL2_ttf)
