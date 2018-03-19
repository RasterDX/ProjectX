//
// Created by Raster on 3/19/2018.
//

#include "../classes/player.h"
#include "../classes/graphics.h"

Player::Player() {}

Player::Player(Graphics &graphics, float x, float y) :
AnimatedSprite(graphics, "res/img/player.png", 0, 0, 32, 60, x, y, 10) {
    graphics.loadImage("res/img/player.png");
    this->setupAnimation();
    this->playAnimation("RunRight");
}

void Player::setupAnimation() {
    this->addAnimation(6, 0, 0, "RunRight", 32, 60, Vector2(0, 0));
    this->addAnimation(6, 0, 0, "RunLeft", 32, 60, Vector2(0, 0));
}

void Player::animationDone(std::string currenAanimation) {}

void Player::update(float elapsedTime) {
    AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics) {
    AnimatedSprite::draw(graphics, this->_x, this->_y);
}