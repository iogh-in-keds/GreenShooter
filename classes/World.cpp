#include "World.h"
#include "Character.h"

World::World() {
    mCharacter = new Character(182.5, 82.5);
    mFont.loadFromFile("..\\programFiles\\comicbd.ttf");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            mRoom[i][j].setPosition(i, j);
            if (i != 1 || j != 1) {
                mRoom[i][j].setImage("..\\programFiles\\Map.png");
            }
        }
    }
    mRoom[1][1].setImage("..\\programFiles\\Map2.png");
    mText.setFont(mFont);
    mText.setScale(3, 3);
    mText.setFillColor(Color::Red);
    mText.setPosition(200, 300);
    mDefeat = false;
    mText.setString("YOU LOSE");
    mRoom[0][0].setChest(Vector2f(600, 80));
    mLobbyMusic.openFromFile("..\\programFiles\\Lobby.ogg");
    mLobbyMusic.setVolume(100);
    mLobbyMusic.setLoop(true);
    mFightMusic.openFromFile("..\\programFiles\\Fight.ogg");
    mFightMusic.setVolume(100);
    mFightMusic.setLoop(true);
    mWin.openFromFile("..\\programFiles\\Win.ogg");
    mWin.setVolume(100);
    mWin.setLoop(false);
    mLose.openFromFile("..\\programFiles\\Lose.ogg");
    mLose.setVolume(100);
    mLose.setLoop(false);
    mLobbyMusic.play();
    mTexture.loadFromFile("..\\programFiles\\Rules.png");
    mRules.setTexture(mTexture);
    mRules.setScale(1.65, 1.65);
    mBuffer.loadFromFile("..\\programFiles\\Shot.ogg");
    mShot.setBuffer(mBuffer);
    mShot.setVolume(100);
}

void World::Event(RenderWindow& window, class Event event) {
    if (mIsInLobby) {
        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
            mLobbyMusic.stop();
            mFightMusic.play();
            mIsInLobby = false;
        }
    } else {
        mRoom[mX][mY].turretHit(mCharacter->weapon.bullets, mCharacter->weapon.getDamage());
        mRoom[mX][mY].turretAttack();
        mRoom[0][0].chest.isOpen(*mCharacter);
        if (!mCharacter->go(mRoom[mX][mY].getWall())) {
            mCharacter->stop();
        }
        mCharacter->update(event, mRoom[0][0].chest);
        mView = window.getDefaultView();
        mView.setCenter(mCharacter->getX() + 15, mCharacter->getY() + 15);
        mView.zoom(0.5);
        mCharacter->setInventoryPosition(Vector2f(mCharacter->getX() - 35, mCharacter->getY() + 115));
        if (!mDefeat) {
            if (mCharacter->shot(*this)) {
                mShot.play();
            }
            mDefeat = mRoom[mX][mY].characterHit(*mCharacter);
            if (mDefeat) {
                mFightMusic.stop();
                mLose.play();
            }
        }
        if (mWait != 0) {
            mWait--;
        }
        if (mBossWait == 0) {
            mRoom[1][1].boss.attack();
            mBossWait = 200;
        } else {
            mBossWait--;
        }
        mRoom[1][1].boss.bulletFly(mRoom[1][1].getWall(), *this);
        if (mX == 1 && mY == 1) {
            mRoom[1][1].boss.hit(*this);
            if (!mRoom[1][1].boss.checkHeal() && !mDefeat) {
                mText.setString("YOU WIN");
                mText.setFillColor(Color::Green);
                mFightMusic.stop();
                mWin.play();
                mDefeat = true;
            }
        }
        if (mDefeat) {
            if (!mIsMiniMapOpen) {
                mView.zoom(2);
            }
            mView.setCenter(450, 450);
        }
        if (mIsMiniMapOpen) {
            mView.zoom(2);
            mView.setCenter(450, 450);
            if (Keyboard::isKeyPressed(Keyboard::N)) {
                mIsMiniMapOpen = false;
            }
        } else {
            if (Keyboard::isKeyPressed(Keyboard::M)) {
                mIsMiniMapOpen = true;
            }
        }
        window.setView(mView);
        this->checkExitFromRoom();
    }
    this->draw(window);
}

void World::checkExitFromRoom() {
    if (mCharacter->getX() > 720) {
        mX = 1;
        mCharacter->setPosition(150, mCharacter->getY());
    }
    if (mCharacter->getY() > 620) {
        mY = 1;
        mCharacter->setPosition(mCharacter->getX(), 50);
    }
    if (mCharacter->getY() < 50) {
        mY = 0;
        mCharacter->setPosition(mCharacter->getX(), 620);
    }
    if (mCharacter->getX() < 150) {
        mX = 0;
        mCharacter->setPosition(720, mCharacter->getY());
    }
}

void World::draw(RenderWindow& window) {
    if (mIsInLobby) {
        window.clear(Color::White);
        window.draw(mRules);
    } else {
        window.clear();
        window.draw(mRoom[mX][mY]);
        mRoom[mX][mY].checkAndDrawBullets(mCharacter->weapon.bullets, window);
        if (mX == 1 && mY == 1) {
            window.draw(mRoom[1][1].boss);
        }
        window.draw(*mCharacter);
        if (mDefeat) {
            window.clear();
            window.draw(mText);
        }
    }
    window.display();
}

void World::setWait(int i) {
    mWait = i;
}

int World::getWait() {
    return mWait;
}
