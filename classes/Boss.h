#ifndef UNTITLED3_BOSS_H
#define UNTITLED3_BOSS_H


#include "Monster.h"
#include "Bullet.h"
#include "Wall.h"

class World;

class Boss : public Monster {
public:
    Boss();
    void attack() override;
    void setPosition(float x, float y);
    void bulletFly(const std::vector<Wall*>& floor, World& world);
    void hit(World& world);
    bool checkHeal();
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    Bullet mArray[8];
    RectangleShape mHP[51];
    Texture mTexture;
};


#endif //UNTITLED3_BOSS_H
