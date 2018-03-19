cmake_minimum_required(VERSION 3.2)

project(ProjectX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32 -mwindows")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES src/main.cpp classes/graphics.h src/graphics.cpp classes/game.h src/game.cpp classes/input.h src/input.cpp classes/sprite.h src/sprite.cpp classes/globals.h classes/scene.h  src/scene.cpp classes/titleScene.h src/animatedsprite.cpp classes/animatedsprite.h src/player.cpp classes/player.h classes/level.cpp classes/level.h)
add_executable(ProjectX ${SOURCE_FILES} classes/scene.h)

target_link_libraries(ProjectX SDL2main SDL2 SDL2_image)