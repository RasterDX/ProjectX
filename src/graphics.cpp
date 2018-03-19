//
// Created by Raster on 2/20/2018.
//

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../classes/graphics.h"
#include "../classes/globals.h"

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Project X");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string&filePath){
    if(this->_spriteSheets.count(filePath) == 0) {
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle) {
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::blitSurfaceL(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle) {
    SDL_RenderCopyEx(this->_renderer, texture, sourceRectangle, destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
}

void Graphics::flip() {
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const{
    return this->_renderer;
}

SDL_Window* Graphics::getWindow() const{
    return this->_window;
}