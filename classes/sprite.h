//
// Created by Raster on 2/20/2018.
//

#ifndef PROJECTX_SPRITE_H
#define PROJECTX_SPRITE_H


#include <c++/string>
#include <SDL2/SDL.h>
#include "graphics.h"

/*  Sprite class
 *  Holds all information for individual sprites.
 */

class Sprite {
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string&filePath, int sourceX, int sourceY, int width, int height,
           float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, int x, int y);
private:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;

    float _x, _y;
};


#endif //PROJECTX_SPRITE_H
