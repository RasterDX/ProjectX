//
// Created by Raster on 2/22/2018.
//

#include <utility>

#include "../classes/scene.h"
#include "../classes/globals.h"

Scene::Scene(){}

Scene::Scene(std::string sceneTitle, int width, int height) {
    this->sceneTitle = std::move(sceneTitle);
    this->_sceneWidth = width;
    this->_sceneHeight = height;
}

Scene::~Scene() = default;

std::string Scene::getName(){
    return this->sceneTitle;
}