#ifndef UNTITLED3_CHARACTER_H
#define UNTITLED3_CHARACTER_H

//#include "World.h"
#include "Bullet.h"
#include "Weapons.h"
#include "Automatic.h"
#include "Inventory.h"
#include <SFML/Graphics.hpp>

class World;
class Chest;

using namespace sf;

class Character : public Drawable {
public:
    Character(float x, float y);

    Character();

    bool go(const std::vector<Wall*> &wall);

    bool shot(World &world);

    void setPosition(float X, float Y);

    float getX();

    float getY();

    void update(Event event, Chest& chest);

    void setInventoryPosition(Vector2f position);

    void stop();

    Sprite getSprite();

    Weapons weapon;

private:
    bool mMoveRight(std::vector<Wall*> wall);

    bool mMoveLeft(std::vector<Wall*> wall);

    bool mMoveUp(std::vector<Wall*> wall);

    bool mMoveDown(std::vector<Wall*> wall);

    bool mShotUp(World &world);

    bool mShotDown(World &world);

    bool mShotLeft(World &world);

    bool mShotRight(World &world);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    Sprite mSprite;
    String mGo = "Front";
    int mWaitGo;
    int mAnim = 1;
    Texture mTexture;
    float mX;
    float mY;
    Inventory mInventory;
};


#endif //UNTITLED3_CHARACTER_H
