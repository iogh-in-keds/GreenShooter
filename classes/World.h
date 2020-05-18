//
// Created by Ivan on 28.02.2020.
//

#ifndef UNTITLED3_WORLD_H
#define UNTITLED3_WORLD_H

#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Room.h"
#include "MyQueue.h"
#include "Boss.h"
#include "Gun.h"

class Character;

using namespace sf;

class World {
public:
    World();

    void Event(RenderWindow &window, Event event);

    void setWait(int i);

    int getWait();

private:
    void checkExitFromRoom();

    void draw(RenderWindow &window);

    friend Boss;

    Character* mCharacter;
    Music mLobbyMusic;
    Music mFightMusic;
    Music mWin;
    Music mLose;
    Room mRoom[2][2];
    Font mFont;
    Text mText;
    int mWait = 0, mX = 0, mY = 0;
    bool mDefeat;
    int mBossWait = 0;
    View mView;
    bool mIsInLobby = true;
    bool mIsMiniMapOpen = false;
    Sprite mRules;
    Texture mTexture;
    SoundBuffer mBuffer;
    Sound mShot;
};

#endif //UNTITLED3_WORLD_H
