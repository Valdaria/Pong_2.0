#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player(sf::Color playerColor);
        virtual ~Player();

        bool canMoveUp();
        bool canMoveDown();
        void moveUp();
        void moveDown();
        float getSpeed() const;
        sf::RectangleShape* getRect() const;

    protected:
        float _speed;
        sf::RectangleShape* _rect;
    private:
};
