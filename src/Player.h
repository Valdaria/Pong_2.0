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
        sf::RectangleShape* getRect() const;

    protected:
        float _speed;
        float _defaultSpeed;
        sf::RectangleShape* _rect;
    private:
};
