//
// Created by Raster on 2/22/2018.
//

#ifndef PROJECTX_SCENE_H
#define PROJECTX_SCENE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../classes/sceneLayer.h"
#include <c++/string>
#include <c++/stack>

class Scene {
public:
    Scene(std::string sceneTitle);
    ~Scene();

    void setSceneColor(unsigned red_RGB, unsigned green_RGB, unsigned blue_RGB, unsigned alpha, unsigned duration);

    std::string getName();
private:
    std::string sceneTitle;

    std::stack<Scene_Layer> layerStack;

    /*  void setSceneColor
     *  Sets the background color of the scene.
     */
};

#endif //PROJECTX_SCENE_H
