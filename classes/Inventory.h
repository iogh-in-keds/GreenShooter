//
// Created by Ivan on 23.04.2020.
//

#ifndef UNTITLED3_INVENTORY_H
#define UNTITLED3_INVENTORY_H


#include "Weapons.h"
#include "Gun.h"
#include "Automatic.h"

class Inventory : public Drawable {
public:
    Inventory();
    void ChangeSlot(int delta);
    Weapons object;
    void chestGive(Weapons weapons);
    void setPosition(Vector2f position);
    void shotThis();
    void update();
    std::string getType();
private:
    int mNumber = 0;
    Weapons* mInventory[3]{};
    RectangleShape mObjects[3];
    Sprite mSprites[3];
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //UNTITLED3_INVENTORY_H
