#include "Character.h"
#include "World.h"
#include "Gun.h"

Character::Character(float x, float y) {
    mTexture.loadFromFile(R"(..\programFiles\Player\playerFront1.png)");
    mSprite.setTexture(mTexture);
    mSprite.setScale(0.390625, 0.390625);
    mSprite.setPosition(x, y);
    this->mX = x;
    this->mY = y;
    weapon = *(new Gun());
    mWaitGo = 0;
}

bool Character::mMoveDown(std::vector<Wall*> wall) {
    bool result = false;
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        mGo = "Front";
        mY += 2;
        mSprite.setPosition(mX, mY);
        result = true;
        if (mWaitGo == 0) {
            mAnim++;
            if (mAnim > 3) {
                mAnim = 1;
                mTexture.loadFromFile(R"(..\programFiles\Player\playerFront1.png)");
            }
            if (mAnim == 2) {
                mTexture.loadFromFile(R"(..\programFiles\Player\playerFront2.png)");
            }
            if (mAnim == 3) {
                mTexture.loadFromFile(R"(..\programFiles\Player\playerFront3.png)");
            }
            mSprite.setTexture(mTexture);
            mWaitGo = 20;
        } else {
            mWaitGo--;
        }

        for (auto &i : wall) {
            if (mSprite.getGlobalBounds().intersects(i->getGlobalBounds())) {
                mY -= 2;
                result = false;
            }
        }
        mSprite.setPosition(mX, mY);
    }
    return result;
}

bool Character::mMoveRight(std::vector<Wall*> wall) {
    bool result = false;
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        mGo = "Right";
        mX += 2;
        mSprite.setPosition(mX, mY);
        result = true;
        if (mWaitGo == 0) {
            mAnim++;
            if (mAnim > 3) {
                mAnim = 1;
                mTexture.loadFromFile(R"(..\programFiles\Player\playerRight1.png)");
            }
            if (mAnim == 2) {
                mTexture.loadFromFile(R"(..\programFiles\Player\playerRight2.png)");
            }
            if (mAnim == 3) {
                mTexture.loadFromFile(R"(..\programFiles\Player\playerRight3.png)");
            }
            mSprite.setTexture(mTexture);
            mWaitGo = 20;
        } else {
            mWaitGo--;
        }
        for (auto &i : wall) {
            if (mSprite.getGlobalBounds().intersects(i->getGlobalBounds())) {
                mX -= 2;
                result = false;
                break;
            }
        }
        mSprite.setPosition(mX, mY);
    }
    return result;
}

bool Character::mMoveLeft(std::vector<Wall*> wall) {
    bool result = false;
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        mGo = "Left";
        mX -= 2;
        mSprite.setPosition(mX, mY);
        result = true;
        if (mWaitGo == 0) {
            mAnim++;
            if (mAnim > 3) {
                mAnim = 1;
                mTexture.loadFromFile(R"(..\programFiles\Player\playerLeft1.png)");
            }
            if (mAnim == 2) {
                mTexture.loadFromFile(R"(..\programFiles\Player\playerLeft2.png)");
            }
            if (mAnim == 3) {
                mTexture.loadFromFile(R"(..\programFiles\Player\playerLeft3.png)");
            }
            mSprite.setTexture(mTexture);
            mWaitGo = 20;
        } else {
            mWaitGo--;
        }
        for (auto &i : wall) {
            if (mSprite.getGlobalBounds().intersects(i->getGlobalBounds())) {
                mX += 2;
                result = false;
            }
        }
        mSprite.setPosition(mX, mY);
    }
    return result;
}

bool Character::mMoveUp(std::vector<Wall*> wall) {
    bool result = false;
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        mGo = "Back";
        mY -= 2;
        mSprite.setPosition(mX, mY);
        result = true;
        if (mWaitGo == 0) {
            mAnim++;
            if (mAnim > 3) {
                mAnim = 1;
                mTexture.loadFromFile(R"(..\programFiles\Player\playerBack1.png)");
            }
            if (mAnim == 2) {
                mTexture.loadFromFile(R"(..\programFiles\Player\playerBack2.png)");
            }
            if (mAnim == 3) {
                mTexture.loadFromFile(R"(..\programFiles\Player\playerBack3.png)");
            }
            mSprite.setTexture(mTexture);
            mWaitGo = 20;
        } else {
            mWaitGo--;
        }
        for (auto &i : wall) {
            if (mSprite.getGlobalBounds().intersects(i->getGlobalBounds())) {
                mY += 2;
                result = false;
            }
        }
        mSprite.setPosition(mX, mY);
    }
    return result;
}

void Character::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite, states);
    target.draw(mInventory, states);
    target.draw(weapon.reloading, states);
}

float Character::getX() {
    return mX;
}

float Character::getY() {
    return mY;
}

Sprite Character::getSprite() {
    return mSprite;
}

void Character::setPosition(float X, float Y) {
    mSprite.setPosition(X, Y);
    mX = X;
    mY = Y;
}

Character::Character() {
    mX = 0;
    mY = 0;
    weapon = *(new Gun());
    mWaitGo = 0;
}

bool Character::go(const std::vector<Wall*> &wall) {
    bool a = this->mMoveLeft(wall);
    bool b = this->mMoveRight(wall);
    bool c = this->mMoveUp(wall);
    bool d = this->mMoveDown(wall);
    return a || b || c || d;
}

bool Character::shot(World &world) {
    weapon.setReloading(Vector2f(mX - 15, mY + 145));
    if (float(world.getWait()) == 100 * weapon.getWait() - 1) {
        weapon.reloadUpdate();
        mInventory.update();
    }
    return this->mShotDown(world) || this->mShotUp(world) || this->mShotLeft(world) || this->mShotRight(world);
}

bool Character::mShotUp(World &world) {
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        if (world.getWait() == 0) {
            weapon.shot(Vector2f(0, -5), *this);
            mInventory.shotThis();
            world.setWait(int(100 * weapon.getWait()));
            return true;
        }
    }
    return false;
}

bool Character::mShotDown(World &world) {
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        if (world.getWait() == 0) {
            weapon.shot(Vector2f(0, 5), *this);
            mInventory.shotThis();
            world.setWait(int(100 * weapon.getWait()));
            return true;
        }
    }
    return false;
}

bool Character::mShotLeft(World &world) {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        if (world.getWait() == 0) {
            weapon.shot(Vector2f(-5, 0), *this);
            mInventory.shotThis();
            world.setWait(int(100 * weapon.getWait()));
            return true;
        }
    }
    return false;
}

bool Character::mShotRight(World &world) {
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        if (world.getWait() == 0) {
            weapon.shot(Vector2f(5, 0), *this);
            mInventory.shotThis();
            world.setWait(int(100 * weapon.getWait()));
            return true;
        }
    }
    return false;
}

void Character::setInventoryPosition(Vector2f position) {
    mInventory.setPosition(position);
}

void Character::update(Event event, Chest &chest) {
    if (event.mouseWheelScroll.delta == 1 || event.mouseWheelScroll.delta == -1) {
        mInventory.ChangeSlot(int(event.mouseWheelScroll.delta));
        weapon = mInventory.object;
    }
    if (Keyboard::isKeyPressed(Keyboard::E) && chest.isOpen(*this) && !chest.getIsItBeOpen()) {
        mInventory.chestGive(chest.give());
        weapon = mInventory.object;
    }
}

void Character::stop() {
    mTexture.loadFromFile(R"(..\programFiles\Player\player)" + mGo + "1.png");
    mAnim = 1;
    mSprite.setTexture(mTexture);
}
