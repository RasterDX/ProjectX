//
// Created by Raster on 2/22/2018.
//

#ifndef PROJECTX_SCENE_H
#define PROJECTX_SCENE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <c++/string>
#include <c++/stack>

class Scene {
public:
    Scene();
    Scene(std::string sceneTitle, int width, int height);
    virtual ~Scene();

    virtual std::string getName() = 0;
protected:
    std::string sceneTitle;
    int _sceneWidth;
    int _sceneHeight;
private:
};

#endif //PROJECTX_SCENE_H
