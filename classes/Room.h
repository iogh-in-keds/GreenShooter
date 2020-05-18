#ifndef UNTITLED3_ROOM_H
#define UNTITLED3_ROOM_H

#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Turret.h"
#include "MyQueue.h"
#include "Character.h"
#include "Boss.h"
#include "Chest.h"

using namespace sf;

class Room : public Drawable {
public:
    Room();

    void setImage(const String &string);

    void setPosition(int x, int y);

    void turretHit(MyQueue &array, float damage);

    void turretAttack();

    bool characterHit(Character &character);

    Image getImage();

    void setChest(Vector2f position);

    void checkAndDrawBullets(MyQueue &myQueue, RenderWindow &window);
    std::vector<Wall*> getWall();
    Boss boss;
    Chest chest;
private:
    void draw(RenderTarget &target, RenderStates states) const override;
    Image mImage;
    std::vector<Wall*> mWall;
    std::vector<Turret*> mTurret;
    std::vector<int> mWaitTurret;
    int mX;
    int mY;
    int mNumberOfWall = 0;
    int mNumberOfTurret = 0;

};


#endif //UNTITLED3_ROOM_H
