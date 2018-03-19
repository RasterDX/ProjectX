//
// Created by Raster on 3/19/2018.
//

namespace player_constants {
    const float WALK_SPEED = 0.2f;
}

#include "../classes/player.h"
#include "../classes/graphics.h"

Player::Player() {}

Player::Player(Graphics &graphics, float x, float y) :
AnimatedSprite(graphics, "res/img/player.png", 0, 0, 32, 60, x, y, 100) {
    graphics.loadImage("res/img/player.png");
    this->setupAnimation();
    this->playAnimation("RunRight");
}

void Player::setupAnimation() {
    this->addAnimation(1, 0, 60, "IdleLeft", 32, 60, Vector2(0, 0));
    this->addAnimation(1, 0, 60, "IdleRight", 32, 60, Vector2(0, 0));
    this->addAnimation(6, 0, 0, "RunRight", 32, 60, Vector2(0, 0));
    this->addAnimation(6, 0, 0, "RunLeft", 32, 60, Vector2(0, 0));
}

void Player::moveLeft() {
    this->_dx = -player_constants::WALK_SPEED;
    this->_flipType = SDL_FLIP_HORIZONTAL;
    this->playAnimation("RunLeft");
    this->_facing = LEFT;
}

void Player::moveRight() {
    this->_dx = player_constants::WALK_SPEED;
    this->playAnimation("RunRight");
    this->_facing = RIGHT;
}

void Player::stopMoving() {
    this->_dx = 0.0f;
    this->playAnimation(this->_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::animationDone(std::string currenAanimation) {}

void Player::update(float elapsedTime) {
    //  Move by _dx.
    this->_x += this->_dx * elapsedTime;
    AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics) {
    AnimatedSprite::draw(graphics, this->_x, this->_y);
}