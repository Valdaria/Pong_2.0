#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player(sf::Color playerColor);
        virtual ~Player();

        float getSpeed() const;

        bool canMoveUp();
        bool canMoveDown();
        void moveUp();
        void moveDown();
        void increaseSpeed();
        void decreaseSpeed();
        void resetSpeed();
        void increaseSize();
        void decreaseSize();
        void resetSize();
        sf::RectangleShape* getRect() const;

    protected:
        float _speed;
        float const _defaultSpeed = 6.f;
        sf::Vector2f* _defaultSize;
        sf::RectangleShape* _rect;
    private:
};
