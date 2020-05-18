#ifndef UNTITLED3_WALL_H
#define UNTITLED3_WALL_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Wall : public Drawable {
public:
    Wall(Vector2f position);

    Wall();

    FloatRect getGlobalBounds();

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    Vector2f mPosition;
    Texture mTexture;
    Sprite mSprite;
};


#endif //UNTITLED3_WALL_H
