//
// Created by Raster on 3/19/2018.
//

#include "../classes/animatedsprite.h"
#include "../classes/graphics.h"

/*
 *  AnimatedSprite class - animates our sprites.
 */

AnimatedSprite::AnimatedSprite() : _timeElapsed(0) {}

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY,
                               int width, int height, float posX, float posY, float timeToUpdate) :
        Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
        _frameIndex(0),
        _timeToUpdate(timeToUpdate),
        _visible(true),
        _currentAnimationOnce(false),
        _currentAnimation("")
{}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset) {
    std::vector<SDL_Rect> rectangles;
    for (int i = 0; i < frames; i++) {
        SDL_Rect newRect = { (i + x) * width, y, width, height };
        rectangles.push_back(newRect);
    }
    this->_animations.insert(std::pair<std::string, std::vector<SDL_Rect> >(name, rectangles));
    this->_offsets.insert(std::pair<std::string, Vector2>(name, offset));
}

void AnimatedSprite::resetAnimation() {
    this->_animations.clear();
    this->_offsets.clear();
}

void AnimatedSprite::playAnimation(std::string animation, bool once) {
    this->_currentAnimationOnce = once;
    if (this->_currentAnimation != animation) {
        this->_currentAnimation = animation;
        this->_frameIndex = 0;
    }
}

void AnimatedSprite::setVisible(bool visible) {
    this->_visible = visible;
}

void AnimatedSprite::stopAnimation() {
    this->_frameIndex = 0;
    this->animationDone(this->_currentAnimation);
}

void AnimatedSprite::update(int elapsedTime) {
    Sprite::update();

    this->_timeElapsed += elapsedTime;
    if (this->_timeElapsed > this->_timeToUpdate) {
        this->_timeElapsed -= this->_timeToUpdate;
        if (this->_frameIndex < this->_animations[this->_currentAnimation].size() - 1) {
            this->_frameIndex++;
        }
        else {
            if (this->_currentAnimationOnce) {
                this->setVisible(false);
            }
            this->stopAnimation();
        }
    }
}

void AnimatedSprite::draw(Graphics &graphics, int x, int y) {
    if (this->_visible) {
        SDL_Rect destinationRectangle{};
        destinationRectangle.x = x + this->_offsets[this->_currentAnimation].x;
        destinationRectangle.y = y + this->_offsets[this->_currentAnimation].y;
        destinationRectangle.w = static_cast<int>(this->_sourceRect.w * globals::SPRITE_SCALE);
        destinationRectangle.h = static_cast<int>(this->_sourceRect.h * globals::SPRITE_SCALE);

        SDL_Rect sourceRect = this->_animations[this->_currentAnimation][this->_frameIndex];
        if(this->_flipType == SDL_FLIP_NONE) {
            graphics.blitSurface(this->_spriteSheet, &sourceRect, &destinationRectangle);
        }
        else {
            graphics.blitSurfaceL(this->_spriteSheet, &sourceRect, &destinationRectangle);
        }
    }
}

void AnimatedSprite::animationDone(std::string currentAnimation) {}

void AnimatedSprite::toggleFlipHorizontal() {
    if(getFacingDirection() == LEFT) {
        _facing = RIGHT;
    }
    else if(getFacingDirection() == RIGHT) {
        _facing = LEFT;
    }
    if(_flipType == SDL_FLIP_HORIZONTAL) {
        _flipType = SDL_FLIP_NONE;
    }
    else if(_flipType == SDL_FLIP_NONE) {
        _flipType = SDL_FLIP_HORIZONTAL;
    }
}

Direction AnimatedSprite::getFacingDirection() {
    return this->_facing;
}