//
// Created by Raster on 2/20/2018.
//

#ifndef PROJECTX_GLOBALS_H
#define PROJECTX_GLOBALS_H

#include "../classes/scene.h"

#include <c++/stack>

namespace globals{
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    const float SPRITE_SCALE = 2.0f;

    const int TILE_WIDTH = 32;
    const int TILE_HEIGHT = 32;

    extern std::stack<Scene> _sceneStack;
}

enum Direction{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NEUTRAL
};

struct Vector2 {
    int x, y;
    Vector2() :
            x(0), y(0)
    {}

    Vector2(int x, int y) :
            x(x), y(y)
    {}

    Vector2 zero() {
        return Vector2(0, 0);
    }
};

class Globals {

};


#endif //PROJECTX_GLOBALS_H
