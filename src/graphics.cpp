//
// Created by Raster on 2/20/2018.
//

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../classes/graphics.h"
#include "../classes/globals.h"

/*  Graphics class
 *  Holds information dealing with graphics for the game.
 */

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

void Graphics::blitSurfacer(SDL_Texture* texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle) {
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
    SDL_RenderPresent(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const{
    return this->_renderer;
}

SDL_Window* Graphics::getWindow() const{
    return this->_window;
}