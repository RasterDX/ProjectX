//
// Created by Raster on 2/20/2018.
//

#ifndef PROJECTX_GLOBALS_H
#define PROJECTX_GLOBALS_H

#include "../classes/scene.h"

#include <c++/stack>

namespace globals{
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    const float SPRITE_SCALE = 2.0f;

    extern std::stack<Scene> _sceneStack;
}

class Globals {

};


#endif //PROJECTX_GLOBALS_H
