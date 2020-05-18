//
// Created by Ivan on 04.02.2020.
//

#include "Wall.h"

Wall::Wall(Vector2f position) {
    mPosition = position;
    mTexture.loadFromFile("..\\programFiles\\Wall.png");
    mSprite.setTexture(mTexture);
    mSprite.setScale(0.46875, 0.46875);
    mSprite.setPosition(mPosition);
}

FloatRect Wall::getGlobalBounds() {
    return mSprite.getGlobalBounds();
}

void Wall::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}

Wall::Wall() {
    mPosition = Vector2f(-30, -30);
}
