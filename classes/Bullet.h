//
// Created by Ivan on 04.02.2020.
//

#ifndef UNTITLED3_BULLET_H
#define UNTITLED3_BULLET_H

#include "Wall.h"

class Character;
using namespace sf;

class Bullet : public Drawable {
public:
    Bullet(float x, float y, float directionX, float directionY);

    Bullet();

    float getX();

    float getY();

    void flying();

    void setDirection(float directionx, float directiony);

    void setPosition(float X, float Y);

    bool checkWalls();

    bool checkWalls(std::vector<Wall*> wall);

    bool checkCharacterShot(Character& character);

    CircleShape getSprite();

private:
    float mDirectionX;
    float mDirectionY;
    float mX;
    float mY;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    CircleShape mSprite;
};


#endif //UNTITLED3_BULLET_H
