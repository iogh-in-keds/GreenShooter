#ifndef UNTITLED3_TURRET_H
#define UNTITLED3_TURRET_H

#include "Monster.h"
#include "Character.h"

class Turret : public Monster {
public:
    Turret(float heal, float damage, float x, float y);

    Turret();

    void attack() override;

    void bulletFly(std::vector<Wall*> wall);

    bool characterShot(Character &character);

    Sprite getSprite();

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool mIsBulletsDraw;

    Texture mTexture;

    Bullet mBullet[4];
};


#endif //UNTITLED3_TURRET_H
