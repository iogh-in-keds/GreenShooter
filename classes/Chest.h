//
// Created by Ivan on 23.04.2020.
//

#ifndef UNTITLED3_CHEST_H
#define UNTITLED3_CHEST_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character.h"

using namespace sf;

class Chest : public Drawable {
public:
    explicit Chest(Vector2f position = Vector2f(-200, -200));
    bool isOpen(Character character);
    Weapons give();
    void setPosition(Vector2f position);
    bool getIsItBeOpen();
private:
    void draw(RenderTarget& target, RenderStates states) const override;
    Sprite mSprite;
    Texture mTexture;
    RectangleShape mSlot;
    RectangleShape mCollision;
    Sprite mWeaponSprite;
    Vector2f mPosition;
    Weapons* mWeapons;
    bool mIsOpen = false;
    bool mIsItBeOpen = false;
    SoundBuffer mBuffer;
    Sound mSound;

};


#endif //UNTITLED3_CHEST_H
