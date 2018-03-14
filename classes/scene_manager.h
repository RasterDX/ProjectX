//
// Created by Raster on 2/23/2018.
//

#ifndef PROJECTX_SCENE_MANAGER_H
#define PROJECTX_SCENE_MANAGER_H

#include "../classes/globals.h"

void createScene(Scene scene) {
    globals::_sceneStack.push(scene);
}

void deleteLastScene() {
    globals::_sceneStack.pop();
}

bool isSceneStackEmpty() {
    return globals::_sceneStack.empty();
}

#endif //PROJECTX_SCENE_MANAGER_H
