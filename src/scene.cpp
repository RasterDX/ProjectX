//
// Created by Raster on 2/22/2018.
//

#include <utility>

#include "../classes/scene.h"
#include "../classes/globals.h"

Scene::Scene(std::string sceneTitle) {
    this->sceneTitle = std::move(sceneTitle);
}

Scene::~Scene() {

}

std::string Scene::getName(){
    return this->sceneTitle;
}