#include "Bullet.h"
#include "Character.h"

Bullet::Bullet() {
    this->mX = -1000;
    this->mY = -1000;
    this->mDirectionX = 0;
    this->mDirectionY = 0;
    mSprite.setPosition(mX, mY);
    mSprite.setFillColor(Color::Yellow);
    mSprite.setRadius(3);
}

void Bullet::flying() {
//    if ()
    mX += mDirectionX;
    mY += mDirectionY;
    mSprite.setPosition(mX, mY);
}

void Bullet::setDirection(float direction_x, float direction_y) {
    mDirectionX = direction_x;
    mDirectionY = direction_y;
}

void Bullet::setPosition(float X, float Y) {
    mX = X;
    mY = Y;
    mSprite.setPosition(mX, mY);
}

bool Bullet::checkWalls() {
    return !((mX > 900) || (mX < 0) || (mY > 900) || (mY < 0));
}

bool Bullet::checkWalls(std::vector<Wall*> wall) {
    for (auto &i : wall) {
        if (i->getGlobalBounds().intersects(mSprite.getGlobalBounds())) {
            return false;
        }
    }
    return true;
}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}

Bullet::Bullet(float x, float y, float directionX, float directionY) {
    this->mX = x;
    this->mY = y;
    this->mDirectionX = directionX;
    this->mDirectionY = directionY;
    mSprite.setRadius(3.f);
    mSprite.setFillColor(Color::Yellow);
}

bool Bullet::checkCharacterShot(Character &character) {
    return mSprite.getGlobalBounds().intersects(character.getSprite().getGlobalBounds());
}

CircleShape Bullet::getSprite() {
    return mSprite;
}

float Bullet::getX() {
    return mX;
}

float Bullet::getY() {
    return mY;
}
