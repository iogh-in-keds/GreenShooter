#ifndef UNTITLED3_MONSTER_H
#define UNTITLED3_MONSTER_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"

using namespace sf;

class Monster : public Drawable {
public:
    Monster();

    bool checkHeal() const;

    virtual void attack() = 0;

    void hit(float damage);

protected:
    Monster(float heal, float damage, float x, float y);

    float mHeal;
    float mDamage;
    float mX;
    float mY;
    Sprite mSprite;
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //UNTITLED3_MONSTER_H